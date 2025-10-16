%% W04 - Mastery Demo
%% System Identification of a Cart-Pendulum System
%         
% 42177 Control Design
% University of Technology Sydney, Australia
% Spring 2025
%
% Coordinator: A/Prof Ricardo P. Aguilera
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;
clear;
format long
s = tf('s');

%% reading data
load('Teensy41_test_data_01.mat')
logsout

Nini = 1;
time = logsout{1}.Values.Time(Nini:end-1);
time = time - time(1);
Vm = logsout{1}.Values.Data(Nini:end-1);
alpha(:,1) = logsout{2}.Values.Data(Nini:end-1);
xc = logsout{3}.Values.Data(Nini:end-1);

alpha_deg = rad2deg(alpha);

%% sampling time from Teensy 4.1
ts = time(2);

%% plots saved data
figure(101)
subplot(311)
plot(time,Vm,'LineWidth',2)
title('SysId Data')
ylim([-8,8])
yticks([-6 0 6])
grid
ylabel('$u(t)$~[V]','FontSize',20,'Interpreter','latex')

subplot(312)
plot(time,xc,'LineWidth',2)
grid
ylabel('$x_c(t)$~[m]','FontSize',20,'Interpreter','latex')

subplot(313)
plot(time,alpha_deg,'LineWidth',2)
grid
ylabel('$\alpha (t)$~[deg]','FontSize',20,'Interpreter','latex')
xlabel('Time (s)','FontSize',20,'Interpreter','latex')

%% cart speed and acceleration
vc  = filtered_derivative(xc,ts,150);
ac = filtered_derivative(vc,ts,15);

figure(102)
subplot(311)
plot(time,xc)
title('Cart Position, Speed, and Acceleration')
grid
subplot(312)
plot(time,vc)
grid
subplot(313)
plot(time,ac)
grid

%% System Identification Gux(s)
%
% u -->[Guvc(s)]-- vc -->[1/s]-->xc
%
%               a
%  Guvc(s) = ------
%             s + b
%
%               a
%   Gux(s) = --------
%            s(s + b)
disp('**********************************')
disp('Identifying Gux(s) transfer function')
data = iddata(xc,Vm,ts);         %data format required by tfest;

np = 4;
nz = 2;

Guvc_id = tfest(data,np,nz)
Gux_id = Guvc_id

%% System Identification Gxa(s)
disp('**********************************')
disp('Identifying Gxa(s) transfer function')
%
%  xc-->[s^2]-- ac -->[Gaca(s)]-->alpha
%
data = iddata(xc,Vm,ts);         %data format required by tfest;
np=4;                           %Number of poles
nz=2;                           %Number of zeros

Gaca_id = tfest(data,np,nz)
Gxa_id = Gaca_id

%% Verification for Gux(s)
t   = (0:numel(Vm)-1).' * ts;      % column vector: 0, ts, 2*ts, ...
u_test = timeseries(Vm(:), t);     % timeseries object in base workspace
Tsim = t(end);

[num, den] = tfdata(Gux_id, 'v');
Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
xc_test = y_test;

%% Verification for Gxa(s)
u_test = timeseries(xc(:), t);   % timeseries object in base workspace

[num, den] = tfdata(Gxa_id, 'v');
Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
alpha_test = y_test;

%% Verification for Gua(s)
u_test = timeseries(Vm(:), t);        % timeseries object in base workspace

Gua_id = Gux_id*Gxa_id;
[num, den] = tfdata(Gua_id, 'v'); 

Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
alpha_test2 = y_test;


%% Comparison plot
figure(103)
subplot(311)
plot(time,Vm)
title('SysId Verification')
grid
subplot(312)
plot(time,xc,'b',time,xc_test,'r')
grid
subplot(313)
plot(time,alpha,'b',time,alpha_test,'r', time, alpha_test2,'g')
grid

%% Known System Parameters
M = 0.2;
m = 0.1;
g = 9.81;

%% Estimated System Parameters
L = 2;
bp = 2;
Kf = 2;
bc = 2;

%% Save identified parameters
%finally save your identified system parameters
save('InvPend_parameters.mat','M','m','g','Kf','L','bc','bp')
disp('done!')

%% Theoretical Transfer Functions
Gux = Kf/s;
Gxa = L*s/(s^2+g)
Gua = Gux*Gxa

%% Verification for Gux(s)
u_test = timeseries(Vm(:), t);     % timeseries object in base workspace

[num, den] = tfdata(Gux, 'v');
Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
xc_test = y_test;

%% Verification for Gxa(s)
u_test = timeseries(xc(:), t);   % timeseries object in base workspace

[num, den] = tfdata(Gxa, 'v');
Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
alpha_test = y_test;

%% Verification for Gua(s)
u_test = timeseries(Vm(:), t);        % timeseries object in base workspace

[num, den] = tfdata(Gua, 'v'); 
Gp_test.Numerator = num;
Gp_test.Denominator = den;
sim('SysId_verification')
alpha_test2 = y_test;

%% Comparison plot
figure(104)
subplot(311)
plot(time,Vm)
title('SysId Verification for Theoretical TFs')
grid
subplot(312)
plot(time,xc,'b',time,xc_test,'r')
grid
subplot(313)
plot(time,alpha,'b',time,alpha_test,'r', time, alpha_test2,'g')
grid
