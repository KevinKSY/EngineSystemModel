addpath(genpath('code'));
addpath('data');
mdl = 'EngModelJumpRamp.slx';

load('MAN32StepResp');
xRef = MAN32_44CR_StepResp(:,1)/100;
yRef = MAN32_44CR_StepResp(:,2);

initMV;

%load SAE_map_comp_Garrett_3788R;
%load SAE_map_turb_Garrett_3788R2;
%if ~exist('TC','var')
%    TC = turbocharger(SAE_map_comp, SAE_map_turb);
%end;

myFunc = @(x)GetErrGensetResp(xRef, yRef, mdl, x, generators);
% constraint 
HMax = 2;
HMin = 0.8;
jumpDeltaMax = 0.4;
jumpDeltaMin = 0.1;
rateMax = 0.1;
rateMin = 0.02;
initLoadMax = 0.5;  
initLoadMin = 0.15;
contGainMax = 2;
contGainMin = 0.5;

% initial value 1.553846 0.509070 1.000000 0.171099 0.604322

H0 = 1.898447;
jumpDelta0 = 1.194036;
rate0 = 0.060000;
initLoad0 = 0.15;
contGain0 = 0.604454;

x0 = [1.20272608078500;0.198817474156616;0.0810974083160270;0.164382732987300;0.502279358688131];
%[H0;jumpDelta0;rate0;initLoad0;contGain0];

A = eye(length(x0));
A = [A;-A];
B1 = [HMax;jumpDeltaMax;rateMax;initLoadMax;contGainMax]; 
B2 = [-HMin;-jumpDeltaMin;-rateMin;-initLoadMin;-contGainMin];
B = [B1;B2];

x = fmincon(myFunc,x0,A,B);