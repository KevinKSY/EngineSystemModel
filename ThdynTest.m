p = 1e5;
T = 300;
F = 0;
VCV = 1;

[R,h,s,u,RF,RP,RT,uF,uP,uT,Cp,Cv,K] = GetThdynCombGasZach( p, T, F );

mCV = p*VCV / (R*T);
UCV = u*mCV;
mfCV = F*fs / (1+F*fs) * mCV;