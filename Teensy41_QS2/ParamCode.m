Vnom = 18;
Tnom = 22.0*10^-3;
wnom = 3050;
Inom = 0.540;

Rm = 8.4;
kt = 0.042;
km = 0.042;
Jm = 4.0*10^-6;
Lm = 1.16*10^-3;
mh = 0.0106;
rh = 0.0111;
Jh = 0.6 * 10^-6;

md = 0.053;
rd = 0.0248;

% Rotary arm mass 
m_r = 0.095;
%Rotary arm length (pivot to end of metal rod)
Lr = 0.085;
%Pendulum link mass
mp = 0.024;
% Pendulum link length
Lp = 0.129;

g = 9.8;
%%

Jr = 2.51 * 10^-4;
Jp = 2.6 * 10^-5;

Dr = 0.0015; % In RADIANS
Dp = 0.0005;

s = tf('s');
