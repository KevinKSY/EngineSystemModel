Init8RTFLEX68D;

mdl = 'TestCVCalcBG';

load_system(mdl);

tic;
simOut = sim(mdl,'SaveOutput','on',...
        'SaveFormat','StructureWithTime',...
        'ReturnWorkspaceOutputs','on',...
        'StartTime','0','StopTime', '1000');
toc;

