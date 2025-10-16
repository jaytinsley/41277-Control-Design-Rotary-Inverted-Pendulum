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
load('Teensy41_test_data_10.mat')
logsout

Nini = 1;
time = logsout{1}.Values.Time(Nini:end-1);
time = time - time(1);
Vm = logsout{1}.Values.Data(Nini:end-1);

alpha_deg(:,1) = logsout{4}.Values.Data(Nini:end-1);
theta_deg = logsout{5}.Values.Data(Nini:end-1);

% alpha_rad = logsout{4}.Values.Data(Nini:end-1);
% theta_rad = logsout{5}.Values.Data(Nini:end-1);

%% sampling time from Teensy 4.1
ts = time(2);

% plots saved data
figure(101)
subplot(311)
plot(time,Vm,'LineWidth',2)
title('SysId Data')
ylim([-8,8])
yticks([-1 0 1])
grid
ylabel('$u(t)$~[V]','FontSize',20,'Interpreter','latex')

subplot(312)
plot(time,theta_deg,'LineWidth',2)
grid
ylabel('$x_c(t)$~[m]','FontSize',20,'Interpreter','latex')

subplot(313)
plot(time,alpha_deg,'LineWidth',2)
grid
ylabel('$\alpha (t)$~[deg]','FontSize',20,'Interpreter','latex')
xlabel('Time (s)','FontSize',20,'Interpreter','latex')

%% cart speed and acceleration
theta_deg_velocity  = filtered_derivative(theta_deg,ts,150);
theta_deg_accel = filtered_derivative(theta_deg_velocity,ts,15);
%% System Identification G_u_Theta(s)

disp('**********************************')
disp('Identifying G_u_Theta(s) transfer function')
data = iddata(theta_deg,Vm,ts);         %data format required by tfest;

np = 4;
nz = 2;

G_u_Theta = tfest(data,np,nz)


%% System Identification G_Theta_Alpha(s)
v_theta_deg = filtered_derivative(theta_deg,ts,150);
a_theta_deg = filtered_derivative(v_theta_deg,ts,150);

disp('**********************************')
disp('Identifying G_Theta_Alpha(s) transfer function')

data = iddata(alpha_deg,a_theta_deg,ts);         %data format required by tfest;
np=2;                           %Number of poles
nz=0;                           %Number of zeros

Gaca_id = tfest(data,np,nz)
G_Theta_Alpha = Gaca_id*s^2

%% Verification for Gux(s)
    t   = (0:numel(Vm)-1).' * ts;      % column vector: 0, ts, 2*ts, ...
    u_test = timeseries(Vm(:), t);     % timeseries object in base workspace
    Tsim = t(end);
    
    [num, den] = tfdata(G_u_Theta, 'v');
    Gp_test.Numerator = num;
    Gp_test.Denominator = den;
    sim('SysId_verification')
    theta_deg_test = y_test;

%% Verification for Gxa(s)
    u_test = timeseries(theta_deg(:), t);   % timeseries object in base workspace
    
    [num, den] = tfdata(G_Theta_Alpha, 'v');
    Gp_test.Numerator = num;
    Gp_test.Denominator = den;
    sim('SysId_verification')
    alpha_test = y_test;

%% Verification for Gua(s)
u_test = timeseries(Vm(:), t);        % timeseries object in base workspace

Gua_id = G_u_Theta*G_Theta_Alpha;
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
plot(time,theta_deg,'b',time,theta_deg_test,'r')
grid
subplot(313)
plot(time,alpha_deg,'b',time,alpha_test,'r', time, alpha_test2, 'g')
grid



% 
% %% Known System Parameters
% M = 0.2;
% m = 0.1;
% g = 9.81;
% 
% %% Estimated System Parameters
% L = 2;
% bp = 2;
% Kf = 2;
% bc = 2;
% 
% %% Save identified parameters
% %finally save your identified system parameters
% save('InvPend_parameters.mat','M','m','g','Kf','L','bc','bp')
% disp('done!')
% 
% %% Theoretical Transfer Functions
% Gux = Kf/s;
% Gxa = L*s/(s^2+g)
% Gua = Gux*Gxa
% 
% %% Verification for Gux(s)
% u_test = timeseries(Vm(:), t);     % timeseries object in base workspace
% 
% [num, den] = tfdata(Gux, 'v');
% Gp_test.Numerator = num;
% Gp_test.Denominator = den;
% sim('SysId_verification')
% theta_deg_test = y_test;
% 
% %% Verification for Gxa(s)
% u_test = timeseries(theta_deg(:), t);   % timeseries object in base workspace
% 
% [num, den] = tfdata(Gxa, 'v');
% Gp_test.Numerator = num;
% Gp_test.Denominator = den;
% sim('SysId_verification')
% alpha_test = y_test;
% 
% %% Verification for Gua(s)
% u_test = timeseries(Vm(:), t);        % timeseries object in base workspace
% 
% [num, den] = tfdata(Gua, 'v'); 
% Gp_test.Numerator = num;
% Gp_test.Denominator = den;
% sim('SysId_verification')
% alpha_test2 = y_test;
% 
% %% Comparison plot
% figure(104)
% subplot(311)
% plot(time,Vm)
% title('SysId Verification for Theoretical TFs')
% grid
% subplot(312)
% plot(time,theta_deg,'b',time,theta_deg_test,'r')
% grid
% subplot(313)
% plot(time,alpha_deg,'b',time,alpha_test,'r', time, alpha_test2,'g')
% grid
