Init8RTFLEX68D;

% 2 Zone Calculation parameters
DPhiMix = 10;
phi0Mix = 90;
alpha = 0.99;
%
mdl1 = 'ThdynConvTest';
mdl2 = 'ThdynTest';

simTime = '1';
solver = 'ode4';
relTol = '1e-5';
absTol = '1e-5';
fixTimeStep = '1e-3';
%%

p = 1.5e5;
T = 320;
F = 0.3;
VCV = 1.2;

[R,h,s,u,RF,RP,RT,uF,uP,uT,Cp,Cv,K] = GetThdynCombGasZach( p, T, F );

mCV = p*VCV / (R*T);
UCV = u*mCV;
mfCV = F*fs / (1+F*fs) * mCV;

% Load the model

%{
load_system(mdl1);
if length(solver) == 4
    set_param(mdl1,'Solver',solver,'FixedStep',fixTimeStep);
else
    set_param(mdl1,'Solver',solver,'RelTol',relTol,'AbsTol',absTol);
end;

% Run the simulation
tic;
simOut1 = sim(mdl1,'SaveOutput','on',...
        'SaveFormat','StructureWithTime',...
        'ReturnWorkspaceOutputs','on',...
        'StartTime','0','StopTime', simTime);
toc;
save_system(mdl1);
close_system(mdl1);
%}
%{a
load_system(mdl2);
if length(solver) == 4
    set_param(mdl2,'Solver',solver,'FixedStep',fixTimeStep);
else
    set_param(mdl2,'Solver',solver,'RelTol',relTol,'AbsTol',absTol);
end;
tic;
simOut2 = sim(mdl2,'SaveOutput','on',...
        'SaveFormat','StructureWithTime',...
        'ReturnWorkspaceOutputs','on',...
        'StartTime','0','StopTime', simTime);
toc;
save_system(mdl2);
close_system(mdl2);
%}

% log1 = simOut1.get('logsout');
log2 = simOut2.get('logsout');

%{
pSim1 = log1.get('p').Values;
TSim1 = log1.get('T').Values;
FSim1 = log1.get('F').Values;

pSim2 = log2.get('p').Values;
TSim2 = log2.get('T').Values;
FSim2 = log2.get('F').Values;

figure
plot(pSim1,'r');
hold on
plot(pSim2,'b');
hold off
xlim([0 10]);

figure
plot(TSim1,'r');
hold on
plot(TSim2,'b');
hold off
xlim([0 10]);

figure
plot(FSim1,'r');
hold on
plot(FSim1,'b');
hold off
xlim([0 10]);
%}
%{a

%pTFSim1 = log1.get('pTFCyl').Values;
pTFSim2 = log2.get('pTFCyl').Values;
pCylSim2 = log2.get('pCyl').Values;
TuSim2 = log2.get('Tu').Values;
FuSim2 = log2.get('Fu').Values;
VuSim2 = log2.get('Vu').Values;
TbSim2 = log2.get('Tb').Values;
FbSim2 = log2.get('Fb').Values;
VbSim2 = log2.get('Vb').Values;
errPSim2 = log2.get('errP').Values;


figure
%plot(pTFSim1.time,pTFSim1.Data(:,1),'r');
plot(pCylSim2,'r');
hold on
plot(pTFSim2.time,pTFSim2.Data(:,1),'b');
hold off
xlim([0 10]);

figure
%plot(pTFSim1.time,pTFSim1.Data(:,2),'r');
plot(TuSim2,'g');
hold on
plot(TbSim2,'r');
hold on
plot(pTFSim2.time,pTFSim2.Data(:,2),'b');
hold off
xlim([0 10]);

figure
%plot(pTFSim1.time,pTFSim1.Data(:,3),'r');
plot(FuSim2,'g');
hold on
plot(FbSim2,'r');
hold on
plot(pTFSim2.time,pTFSim2.Data(:,3),'b');
hold off
xlim([0 10]);
%}