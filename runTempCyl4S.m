addpath(genpath('data'));
addpath(genpath('code'));
initHybrid;
genset = generators(1);
load_system('tempCyl4s');
open('tempCyl4s');
close all
%%
uGov = 0.2;
tic
simOut = sim('tempCyl4s','StopTime', '0.005','RelTol','1e-6');
toc

%%
log = simOut.get('logsout');
EfSim = log.get('Ef').Values;
pTFCylSim = log.get('pTFCyl').Values;
phiSim = log.get('phi').Values;
dmbSim = log.get('dmb').Values;
ECylSim = log.get('ECyl').Values;
dmdSim = log.get('<dmd>').Values;
dmuSim = log.get('<dmu>').Values;
phi720 = mod(phiSim.Data*180/pi,720);
figure
plotyy(phi720,dmbSim.Data,phi720,pTFCylSim.p.Data);
figure
plotyy(phi720,EfSim.Data,phi720,pTFCylSim.T.Data);
figure
plotyy(phi720,ECylSim.Data,phi720,pTFCylSim.T.Data);
figure
plotyy(phi720,dmdSim.Data,phi720,dmuSim.Data);
