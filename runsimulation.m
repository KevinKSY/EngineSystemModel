addpath(genpath('code'));
addpath('data');
mdl = 'MVEM.mdl';

LoadStep = 2:2:50;
InitialLoad = 0.15;
for i = 1:length(LoadStep);
Load_index = 1;  %1-Step,      2-Sine,  3-Ramp,       4-User input, 5-External input, 6-Constant;
Load_amp = 0.55;  %1-Final,     2-amp,   3-Slope,       4-N/A,        5-N/A,            6-N/A   
Load_bias = 0.15; %1-Initial,   2-bias,  3-Initial,    4-Initial,    5-initial,        6-Load;
Start_time = 50;  %1-Step time, 2-Delay, 3-Start time, 4-Delay,      5-Delay,          6-N/A;
T_load = 1;      %1-N/A,       2-Period 3-N/A         4-N/A         5-N/A             6-N/A;
Tq_hist = struct('time',0,'signals',[]);
Tq_hist.signals = struct('values',0,'dimensions',1);
initMV;
%Uc_opt = 0.47;
%%

tic;
simOut = sim(mdl,'SaveOutput','on',...
        'SaveFormat','StructureWithTime',...
        'ReturnWorkspaceOutputs','on',...
        'StartTime','0','StopTime', '100');
toc;
%%
close all
log = simOut.get('logsout');
omegaGensetPU = log.get('omegaGensetPU').Values;
omegaEnd = omegaGensetPU.Data(end);
omegaSteady = 0.99 * omegaEnd;
timeIdxTransEnd = find((omegaGensetPU.time >= Start_time  & ...
                        omegaGensetPU.Data < omegaSteady));
if isempty(timeIdxTransEnd)
    recoveryTime = 0;
else
    if omegaEnd < 0.95
        recoveryTime = 0;
        speedDrop = 100;
else
    timeIdxTransEnd = timeIdxTransEnd(end);
    timeIdxTransStart = find(omegaGensetPU.time >= Start_time);
    timeIdxTransStart = timeIdxTransStart(1);
    recoveryTime = omegaGensetPU.time(timeIdxTransEnd) - ...
                    omegaGensetPU.time(timeIdxTransStart);
    speedDrop = min(omegaGensetPU.Data(timeIdxTransStart:timeIdxTransEnd));
    speedDrop = (omegaEnd - speedDrop) / omegaEnd * 100;
end;
figure            
plot(omegaGensetPU);
hold on
plot([Start_time+recoveryTime Start_time+recoveryTime],[0.95 1.05]);
            
%%

