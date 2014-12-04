addpath(genpath('code'));
addpath('data');
mdl = 'MVEM.mdl';

LoadStep = 0.02:0.01:0.50;
InitialLoad = 0.15:0.01:0.50;
nStepLoad = length(LoadStep);
nStepInit = length(InitialLoad);

recoveryTime = zeros(nStepInit,nStepLoad);
speedDrop = zeros(nStepInit,nStepLoad);

figure
for jj = 1:nStepInit
for ii = 1:nStepLoad
    Load_index = 1;  %1-Step,      2-Sine,  3-Ramp,       4-User input, 5-External input, 6-Constant;
    Load_amp = InitialLoad(jj) + LoadStep(ii);  %1-Final,     2-amp,   3-Slope,       4-N/A,        5-N/A,            6-N/A   
    Load_bias = InitialLoad(jj); %1-Initial,   2-bias,  3-Initial,    4-Initial,    5-initial,        6-Load;
    Start_time = 50;  %1-Step time, 2-Delay, 3-Start time, 4-Delay,      5-Delay,          6-N/A;
    T_load = 1;      %1-N/A,       2-Period 3-N/A         4-N/A         5-N/A             6-N/A;
    Tq_hist = struct('time',0,'signals',[]);
    Tq_hist.signals = struct('values',0,'dimensions',1);
    initMV;
    %Uc_opt = 0.47;
    %%

    %tic;
    simOut = sim(mdl,'SaveOutput','on',...
            'SaveFormat','StructureWithTime',...
            'ReturnWorkspaceOutputs','on',...
            'StartTime','0','StopTime', '100');
    %toc;
    %%
    close all
    log = simOut.get('logsout');
    omegaGensetPU = log.get('omegaGensetPU').Values;
    omegaEnd = omegaGensetPU.Data(end);
    omegaSteady = 0.99 * omegaEnd;
    timeIdxTransEnd = find((omegaGensetPU.time >= Start_time  & ...
                            omegaGensetPU.Data < omegaSteady));
    if isempty(timeIdxTransEnd)
        recoveryTime(jj,ii) = 0;
        timeIdxTransStart = find(omegaGensetPU.time >= Start_time);
        timeIdxTransStart = timeIdxTransStart(1);
        speedDrop(jj,ii) = min(omegaGensetPU.Data(timeIdxTransStart:end));
    else
        if omegaEnd < 0.95
            recoveryTime(jj,ii) = 0;
            speedDrop(jj,ii) = 0;
        else
            timeIdxTransEnd = timeIdxTransEnd(end);
            timeIdxTransStart = find(omegaGensetPU.time >= Start_time);
            timeIdxTransStart = timeIdxTransStart(1);
            recoveryTime(jj,ii) = omegaGensetPU.time(timeIdxTransEnd) - ...
                            omegaGensetPU.time(timeIdxTransStart);
            speedDrop(jj,ii) = min(omegaGensetPU.Data(timeIdxTransStart:timeIdxTransEnd));
            speedDrop(jj,ii) = (omegaEnd - speedDrop(jj,ii)) / omegaEnd * 100;
        end;
    end;
    plot(omegaGensetPU);
end;
end;
%%
 load('MAN32StepResp.mat')
figure            
set(0,'DefaultAxesColorOrder',[1 0 0;0 0 1],...
      'DefaultAxesLineStyleOrder','-|-.|--|:')
for i = 1:nStepInit
    idx = recoveryTime(i,:) > 0;
    y = InitialLoad(i)*ones(length(find(idx)),1);
    plot3(LoadStep(idx),y,recoveryTime(i,idx));
    hold all
end;
plot3(MAN32_44CR_StepResp(:,1)/100,0.5*ones(length(MAN32_44CR_StepResp),1),...
    MAN32_44CR_StepResp(:,2),'black');
hold off
set(0,'DefaultAxesColorOrder',[1 0 0;1 0 0;1 0 0;0 0 1;0 0 1;0 0 1;0 0 1],...
      'DefaultAxesLineStyleOrder','-|-.|--|:')
figure
plot(LoadStep,speedDrop);
%%
save(strcat('speedDropTCInert05.mat'),'speedDrop');
save(strcat('recoveryTimeTCInert05',num2str(generators(1).H),'.mat'),'recoveryTime');

%%

