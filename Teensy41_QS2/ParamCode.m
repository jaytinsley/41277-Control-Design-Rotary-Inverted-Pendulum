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


Jr = 2.51 * 10^-4;
Jp = 2.6 * 10^-5;

Dr = 0.0015; % In RADIANS
Dp = 0.0005;

s = tf('s');

%%
Gvt = minreal((km*(mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*km*s + 2*Lp*g*km*mp) / ((2*Rm*Lp^2*Lr^2*mp^2 + Jr*Rm*Lp^2*mp + 4*Jp*Rm*Lr^2*mp + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (Rm*kt*Lp^2*mp + 2*Rm*g*Lp*Lr^2*mp^2 + 2*Jr*Rm*g*Lp*mp + 4*Dp*km^2 + 4*Dp*Dr*Rm + 4*Jp*Rm*kt)*s^2 + (2*Lp*g*mp*km^2 + 4*Dp*Rm*kt + 2*Dr*Lp*Rm*g*mp)*s + 2*Lp*Rm*g*kt*mp));
Gta = minreal((-2*Lp*Lr*mp)*s^2 / ((mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*s - 2*Lp*g*mp));

G_U_Alpha_param = -(2*Lp*Lr*mp*s^2*(km*(mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*km*s + 2*Lp*g*km*mp))/(((mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*s - 2*Lp*g*mp)*((2*Rm*Lp^2*Lr^2*mp^2 + Jr*Rm*Lp^2*mp + 4*Jp*Rm*Lr^2*mp + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (Rm*kt*Lp^2*mp + 2*Rm*g*Lp*Lr^2*mp^2 + 2*Jr*Rm*g*Lp*mp + 4*Dp*km^2 + 4*Dp*Dr*Rm + 4*Jp*Rm*kt)*s^2 + (2*Lp*g*mp*km^2 + 4*Dp*Rm*kt + 2*Dr*Lp*Rm*g*mp)*s + 2*Lp*Rm*g*kt*mp))

% rltool(G_U_Alpha_param);

MR_GUA = minreal(G_U_Alpha_param);

