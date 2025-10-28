%% Old equations used before compensating for spring effect of cable 
%Gvt = ((- km*mp*Lp^2 - 4*Jp*km)*s^2 - 4*Dp*km*s - 2*Lp*g*km*mp)/((2*Rm*Lp^2*Lr^2*mp^2 + Jr*Rm*Lp^2*mp + 4*Jp*Rm*Lr^2*mp + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (2*Lp*Rm*g*Lr^2*mp^2 + 4*Dp*km^2 + 2*Jr*Lp*Rm*g*mp + 4*Dp*Dr*Rm)*s^2 + (2*Lp*g*mp*km^2 + 2*Dr*Lp*Rm*g*mp)*s);
%Gta = (2*Lp*Lr*mp*s^2)/((mp*Lp^2 + Jp)*s^2 + 4*Dp*s + 2*Lp*g*mp);


syms s mp Lr Jr theta alpha Dr Jp g Dp km Vm Rm Lp kt

equation1 = (mp * Lr^2+Jr)*s^2*theta-1/2*(mp*Lp*Lr)*s^2*alpha==km*(Vm-km*s*theta)/Rm-Dr*s*theta;
equation2 = -1/2*(mp*Lp*Lr*s^2*theta)+(Jp+1/4*mp*Lp^2)*s^2*alpha-1/2*mp*Lp*g*alpha==-Dp*s*alpha;

vars = solve([equation1, equation2],[theta,alpha]);
%%
[num,den] = numden(simplify(vars.theta / Vm));
num = collect(num);
den = collect(den);

G_V_T = (km*(mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*km*s - 2*Lp*g*km*mp)/((Jr*Rm*mp*Lp^2 + 4*Jp*Rm*mp*Lr^2 + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (- 2*Lp*Rm*g*Lr^2*mp^2 + 4*Dp*km^2 - 2*Jr*Lp*Rm*g*mp + 4*Dp*Dr*Rm)*s^2 + (- 2*Lp*g*mp*km^2 - 2*Dr*Lp*Rm*g*mp)*s)

%%
[num,den] = numden(simplify(vars.alpha / Vm / G_V_T));
num = collect(num);
den = collect(den);

G_T_A = (s^2*2*Lp*Lr*mp)/((mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*s - 2*Lp*g*mp)

G_V_A = G_V_T * G_T_A
%%

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

G_V_T_Tf = (km*(mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*km*s - 2*Lp*g*km*mp)/((Jr*Rm*mp*Lp^2 + 4*Jp*Rm*mp*Lr^2 + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (- 2*Lp*Rm*g*Lr^2*mp^2 + 4*Dp*km^2 - 2*Jr*Lp*Rm*g*mp + 4*Dp*Dr*Rm)*s^2 + (- 2*Lp*g*mp*km^2 - 2*Dr*Lp*Rm*g*mp)*s)

G_T_A_Tf = (s^2*2*Lp*Lr*mp)/((mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*s - 2*Lp*g*mp)

G_V_A_Tf = G_V_T_Tf*G_T_A_Tf;

G_V_A_Min = minreal(G_V_A)