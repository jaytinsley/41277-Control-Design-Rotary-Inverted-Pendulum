%% Upright pendulum transfer: G_{uα}(s) = α(s)/V_m(s)

% Given parameters
Vnom = 18;
Tnom = 22.0e-3;
wnom = 3050;
Inom = 0.540;

Rm = 8.4;
kt = 0.042;
km = 0.042;
Jm = 4.0e-6;
Lm = 1.16e-3;
mh = 0.0106;
rh = 0.0111;
Jh = 0.6e-6;

md = 0.053;
rd = 0.0248;

m_r = 0.095;      % rotary arm mass
Lr = 0.085;       % rotary arm length (m)
mp = 0.024;       % pendulum link mass (kg)
Lp = 0.129;       % pendulum link length (m)
g  = 9.8;         % gravity (m/s^2)

Jr = 2.51e-4;     % rotary inertia (kg·m^2)
Jp = 2.6e-5;      % pendulum inertia (kg·m^2)
Dr = 0.0015;      % rotary damping (N·m·s/rad)
Dp = 0.0005;      % pendulum damping (N·m·s/rad)

%% Derived shorthand constants
A  = mp*Lr^2 + Jr;
B  = 0.5*mp*Lp*Lr;
C  = Jp + 0.25*mp*Lp^2;
Gg = -0.5*mp*Lp*g;     % negative for upright (inverted) configuration

%% Transfer function definition
s = tf('s');
num = -B*km*s;     % numerator
den = Rm*(B^2)*s^3 + (C*s^2 + Dp*s + Gg) * (Rm*(A*s + Dr) + km^2);

G_ualpha = num/den

pole(G_ualpha)
rltool(G_ualpha)