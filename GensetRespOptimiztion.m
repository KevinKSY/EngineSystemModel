addpath(genpath('code'));
addpath('data');
mdl = 'MVEM.mdl';

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
jTCMax = 2;
jTCMin = 0.2;
FMaxMax = 1;
FMaxMin = 0.7;
initLoadMax = 0.5;
initLoadMin = 0.15;
contGainMax = 2;
contGainMin = 0.5;

% initial value 1.553846 0.509070 1.000000 0.171099 0.604322
H0 = 1.553846;
jTC0 = 0.509070;
FMax0 = 1.0;
initLoad0 = 0.171099;
contGain0 = 0.604322;
x0 = [H0;jTC0;FMax0;initLoad0;contGain0];

A = eye(length(x0));
A = [A;-A];
B1 = [HMax;jTCMax;FMaxMax;initLoadMax;contGainMax]; 
B2 = [-HMin;-jTCMin;-FMaxMin;-initLoadMin;-contGainMin];
B = [B1;B2];

x = fmincon(myFunc,x0,A,B);