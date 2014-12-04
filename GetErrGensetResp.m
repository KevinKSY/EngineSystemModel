function y = GetErrGensetResp(xRef, yRef, mdl, x, generators)
% x(1) : H (inertia in pu)
% x(2) : jTC (inertia of TC)
% x(3) : FMax
% x(4) : initial load
% x(5) : Control gain
    nRun = length(xRef);
    y = 0;
      
    generators(1).H = x(1)*generators(1).H;
    generators(1).eng.jTC = x(2)*generators(1).eng.jTC;
    generators(1).turbo.DeltaGain = x(2);
    generators(1).eng.FMax = x(3);
    generators(1).turbo.rateSatMax = x(3);
    generators(1).governor.Kp       = x(5)*generators(1).governor.Kp;     % PID Gains
    generators(1).governor.Ki       = x(5)*generators(1).governor.Ki;     % PID Gains
    generators(1).governor.Kd       = x(5)*generators(1).governor.Kd;     % PID Gains
    
    for i = 1:nRun
    %tic;
        Load_index = 1;  %1-Step,      2-Sine,  3-Ramp,       4-User input, 5-External input, 6-Constant;
        Load_amp = x(4) + xRef(i);  %1-Final,     2-amp,   3-Slope,       4-N/A,        5-N/A,            6-N/A   
        Load_bias = x(4); %1-Initial,   2-bias,  3-Initial,    4-Initial,    5-initial,        6-Load;
        Start_time = 50;  %1-Step time, 2-Delay, 3-Start time, 4-Delay,      5-Delay,          6-N/A;
        T_load = 1;      %1-N/A,       2-Period 3-N/A         4-N/A         5-N/A             6-N/A;
        Tq_hist = struct('time',0,'signals',[]);
        Tq_hist.signals = struct('values',0,'dimensions',1);
        simOut = sim(mdl,'SrcWorkspace','current','SaveOutput','on',...
                'SaveFormat','StructureWithTime',...
                'ReturnWorkspaceOutputs','on',...
                'StartTime','0','StopTime', '100');

        log = simOut.get('logsout');
        omegaGensetPU = log.get('omegaGensetPU').Values;
        omegaEnd = omegaGensetPU.Data(end);
        omegaSteady = 0.99 * omegaEnd;
        timeIdxTransEnd = find((omegaGensetPU.time >= Start_time  & ...
                                omegaGensetPU.Data < omegaSteady));
        if isempty(timeIdxTransEnd)
            recoveryTime = 0;
            timeIdxTransStart = find(omegaGensetPU.time >= Start_time);
            timeIdxTransStart = timeIdxTransStart(1);
            %speedDrop = min(omegaGensetPU.Data(timeIdxTransStart:end));
        else
            if omegaEnd < 0.95
                recoveryTime = 0;
                %speedDrop = 0;
            else
                timeIdxTransEnd = timeIdxTransEnd(end);
                timeIdxTransStart = find(omegaGensetPU.time >= Start_time);
                timeIdxTransStart = timeIdxTransStart(1);
                recoveryTime = omegaGensetPU.time(timeIdxTransEnd) - ...
                                omegaGensetPU.time(timeIdxTransStart);
                %speedDrop = min(omegaGensetPU.Data(timeIdxTransStart:timeIdxTransEnd));
                %speedDrop = (omegaEnd - speedDrop(jj,ii)) / omegaEnd * 100;
            end;
        end;
        y = y + (yRef(i) - recoveryTime)^2;
        plot(xRef(i),recoveryTime,'*');
        hold on
    end;
    y = 0.5*y;
    err = sqrt(y*2)/sum(yRef);
    plot(xRef,yRef);
    drawnow
    hold off;
    fprintf('%f %f %f %f %f %f \n',err, x(1),x(2),x(3),x(4),x(5));
    
end



