%% Old equations used before compensating for spring effect of cable 
%Gvt = ((- km*mp*Lp^2 - 4*Jp*km)*s^2 - 4*Dp*km*s - 2*Lp*g*km*mp)/((2*Rm*Lp^2*Lr^2*mp^2 + Jr*Rm*Lp^2*mp + 4*Jp*Rm*Lr^2*mp + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (2*Lp*Rm*g*Lr^2*mp^2 + 4*Dp*km^2 + 2*Jr*Lp*Rm*g*mp + 4*Dp*Dr*Rm)*s^2 + (2*Lp*g*mp*km^2 + 2*Dr*Lp*Rm*g*mp)*s);
%Gta = (2*Lp*Lr*mp*s^2)/((mp*Lp^2 + Jp)*s^2 + 4*Dp*s + 2*Lp*g*mp);

%% Adjusting for cable spring effect 
syms s mp Lr Jr theta alpha Dr Jp g Dp km Vm Rm Lp kt
equation1 = (mp * Lr^2+Jr)*s^2*theta-1/2*mp*Lp*Lr*s^2*alpha==km*(Vm-km*s*theta)/Rm-Dr*s*theta-kt*theta
equation2 = 1/2*mp*Lp*Lr*s^2*theta+(Jp+1/4*mp*Lp^2)*s^2*alpha+1/2*mp*Lp*g*alpha==-Dp*s*alpha
vars = solve([equation1, equation2],[theta,alpha])

[num,den] = numden(simplify(vars.theta / Vm))
num = collect(num)
den = collect(den)
Gvt = (km*(mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*km*s + 2*Lp*g*km*mp) / ((2*Rm*Lp^2*Lr^2*mp^2 + Jr*Rm*Lp^2*mp + 4*Jp*Rm*Lr^2*mp + 4*Jp*Jr*Rm)*s^4 + (mp*Lp^2*km^2 + Dr*Rm*mp*Lp^2 + 4*Dp*Rm*mp*Lr^2 + 4*Jp*km^2 + 4*Dp*Jr*Rm + 4*Dr*Jp*Rm)*s^3 + (Rm*kt*Lp^2*mp + 2*Rm*g*Lp*Lr^2*mp^2 + 2*Jr*Rm*g*Lp*mp + 4*Dp*km^2 + 4*Dp*Dr*Rm + 4*Jp*Rm*kt)*s^2 + (2*Lp*g*mp*km^2 + 4*Dp*Rm*kt + 2*Dr*Lp*Rm*g*mp)*s + 2*Lp*Rm*g*kt*mp)

[num,den] = numden(simplify(vars.alpha / Vm / Gvt))
num = collect(num)
den = collect(den)
Gta = (-2*Lp*Lr*mp)*s^2 / ((mp*Lp^2 + 4*Jp)*s^2 + 4*Dp*s + 2*Lp*g*mp)


