%% Prerequisite variables
% engLoad0 : initial load of the engine [0~1]
 
load('7X82.mat');
%% General
eng.jShaft = 425900*2;          %Mass moment of inertia of the engine shaft [kgm2]
eng.fs = 0.0683;          %Fuel-air equivalent ratio
eng.hn = 42700000;   %Low heating value of the fuel (J/kg)
eng.coeffMechEff = [0.135;0.155]; %Coefficient for mechanical efficiency curvefitting (2x1)

eng.RPMMax = 79;      %Max. Rated RPM
eng.nStroke = 2;
eng.nCyl = 7;
eng.Pe = 32543e3;

eng.omegaE0 = interp1(eng_data.perf.Pe,eng_data.perf.RPM,eng.Pe/1000*eng.engLoad0,'pchip')*pi/30;         %Initial speed of the engine (rad/s)
eng.BSFC0 = interp1(eng_data.perf.Pe,eng_data.perf.ref.BSFC,eng.Pe/1000*eng.engLoad0,'pchip');         %Initial speed of the engine (rad/s)    
eng.dQCylRef = interp1(eng_data.perf.Pe,eng_data.HB.Cyl + eng_data.HB.Radiation,eng.Pe/1000*eng.engLoad0,'pchip')*1000;         %Reference heat transfer rate    

eng.pAmb = 1e5;  %Ambient conditions
eng.tAmb = 25 + 273.15;  %Ambient conditions
eng.fAmb =   0;  %Ambient conditions
eng.pBack = 1.03e5;  %Ambient conditions
eng.tCW = 29 + 273.15; %Cooling water temperature
%% Charge air cooler parameters
eng.cAC.Cd = 0.8;                 %Discharge coefficient of the cooler
eng.cAC.areaAirPath = 0.3628;        %Effective area of the air path [m2]
eng.cAC.dmCW = 72.78;               %Cooling water flow [kg/s]
eng.cAC.coeffTCWK = [-15.6973914238822,5074.68648335995]*1.5; 
                                %Coefficient for curvefitting 
                                %for cooling water temp. vs. effective heat
                                %exchange area [m2]
eng.cAC.CpCW = 4185.5;               %Cooling water heat capacity [J/kgK]
eng.cAC.dCWPipe = 0.008;            %Coolant tube diameter [m]
%% Control volumes 
% (Should be defined for each control volume with a specific name replacing
% "CV")
pScav = interp1(eng_data.TC.Pe,eng_data.TC.p_scvg,eng.Pe/1000*eng.engLoad0,'pchip');
TScav = interp1(eng_data.TC.Pe,eng_data.TC.T_acool,eng.Pe/1000*eng.engLoad0,'pchip');
pScav = pScav*1e5;
TScav = TScav + 273.15;
eng.scavRec.p0 = pScav;                  %Initial pressure [Pa]
eng.scavRec.T0 = TScav;                  %Initial temperature [K]
eng.scavRec.F0 = 0;                 %Initial FAER
eng.scavRec.V0 = 15;                   %Volume
[m0, E0, mb0] = GetMEMbZach(eng.scavRec.p0,eng.scavRec.T0,eng.scavRec.F0,...
    eng.scavRec.V0,eng.fs);
eng.scavRec.m0 = m0;                  %Initial mass [kg]
eng.scavRec.E0 = E0;                  %Initial internal energy [J]
eng.scavRec.mb0 = mb0;                 %Initial burned fuel mass [kg]

eng.pipeACool.p0 = pScav;                  %Initial pressure [Pa]
eng.pipeACool.T0 = TScav;                  %Initial temperature [K]
eng.pipeACool.F0 = 0;                 %Initial FAER
eng.pipeACool.V0 = 5;                   %Volume
[m0, E0, mb0] = GetMEMbZach(eng.pipeACool.p0,eng.pipeACool.T0,...
    eng.pipeACool.F0,eng.pipeACool.V0,eng.fs);
eng.pipeACool.m0 = m0;                  %Initial mass [kg]
eng.pipeACool.E0 = E0;                  %Initial internal energy [J]
eng.pipeACool.mb0 = mb0;                 %Initial burned fuel mass [kg]


eng.pipeBCool.p0 = pScav;                  %Initial pressure [Pa]
eng.pipeBCool.T0 = TScav;                  %Initial temperature [K]
eng.pipeBCool.F0 = 0;                 %Initial FAER
eng.pipeBCool.V0 = 1.15;                   %Volume
[m0, E0, mb0] = GetMEMbZach(eng.pipeBCool.p0,eng.pipeBCool.T0, ...
    eng.pipeBCool.F0,eng.pipeBCool.V0,eng.fs);
eng.pipeBCool.m0 = m0;                  %Initial mass [kg]
eng.pipeBCool.E0 = E0;                  %Initial internal energy [J]
eng.pipeBCool.mb0 = mb0;                 %Initial burned fuel mass [kg]

pExh = interp1(eng_data.TC.Pe,eng_data.TC.p_exh,eng.Pe/1000*eng.engLoad0,'pchip');
TExh = interp1(eng_data.TC.Pe,eng_data.TC.T_exh_rec,eng.Pe/1000*eng.engLoad0,'pchip');
pExh = pExh*1e5;
TExh = TExh + 273.15;
eng.exhRec.p0 = pExh;                  %Initial pressure [Pa]
eng.exhRec.T0 = TExh;                  %Initial temperature [K]
eng.exhRec.F0 = 0.6;                 %Initial FAER
eng.exhRec.V0 = 10;                   %Volume
[m0, E0, mb0] = GetMEMbZach(eng.exhRec.p0,eng.exhRec.T0, ...
    eng.exhRec.F0,eng.exhRec.V0,eng.fs);
eng.exhRec.m0 = m0;                  %Initial mass [kg]
eng.exhRec.E0 = E0;                  %Initial internal energy [J]
eng.exhRec.mb0 = mb0;                 %Initial burned fuel mass [kg]


%% Turbocharger parameters
load('turb_mapABB A175-35L FitTo7X82.mat');
load('comp_mapABB A175-35L FitTo7X82.mat');
eng.turbo.jTC = 5.7;              %rotor inertia
eng.turbo.omegaT0 = interp1(eng_data.TC.Pe,eng_data.TC.RPMTC,eng.Pe/1000*eng.engLoad0)*pi/30;
% Compressor 
eng.turbo.comp.flowMap = comp_flow_map;    %Compressor map for corrected flow
eng.turbo.comp.effMap = comp_eff_map;     %Compressor map for efficiency
eng.turbo.comp.prRep = prComp_rep;      %Pressure ratio array for look-up in 
                                %compressor map
eng.turbo.comp.n298Rep = n288Comp_rep;    %Corrected speed array for look-up in 
                                %compressor map
%eng.turbo.comp.mDotRep = mDotComp_rep;    %Corrected speed array for look-up in                                 
eng.turbo.comp.npr = length(eng.turbo.comp.prRep);
eng.turbo.comp.nsp = length(eng.turbo.comp.n298Rep);
%eng.turbo.comp.nflow = length(eng.turbo.comp.mDotRep);

% Turbine for map unknown but performance known
%eng.turbo.turb.flowCoeff = [];   %Turbine flow coefficient
%eng.turbo.turb.effCoeff = [];    %Turbine efficiency coefficient
%eng.turbo.jTC = 0;               %Rotor mass moment of inertia [kgm2]

% Turbine for only flow curve known of a single RPM but efficiency unknown
%eng.turbo.turb.flowCoeff = [];  %Flow coefficient for turbine model(Flow
%                                 vs. ER)
%eng.turbo.turb.dTurbWheel = 0;  %Diameter of the turbine wheel
%eng.turbo.turb.ucOpt = 0;       %Optimal blade speed ratio
%eng.turbo.turb.effMax = 0;      %Maximum isentropic efficiency
%eng.turbo.turb.tempRef = 0;     %Reference temperature for turbine flow

% Turbine for map known
eng.turbo.turb.flowMap = turb_flow_map;    %Compressor map for corrected flow
eng.turbo.turb.effMap = turb_eff_map;     %Compressor map for efficiency
eng.turbo.turb.prRep = prTurb_rep;      %Pressure ratio array for look-up in compressor map
eng.turbo.turb.n298Rep = n288Turb_rep;    %Corrected speed array for look-up in compressor map
eng.turbo.turb.npr = length(eng.turbo.turb.prRep);
eng.turbo.turb.nsp = length(eng.turbo.turb.n298Rep);

% Mechainical efficiency in case not included in the turbine efficiency
eng.turbo.fricCoeff = [9.79860e-06,0.0179043,-0.75512];       %Mechanical efficiency in polynomial function of speed
clearLoadedFile('turb_mapABB TPL_BFitTo7X82.mat');
clearLoadedFile('comp_mapABB TPL_BFitTo7X82.mat');
%% Blower

eng.blower.effBlower = 0.8;
eng.blower.coeffBlowerFlow = [-193.24048255339;4.1357602501571;0.65950308947414];
eng.blower.areaFlap = 0.5;     % Area of the air passage through the flap valves in the scavenge receiver

%% Cylinder parameters
% General
% Cylinder dimension
                            % Volume at exh V/V cose [m3]

for i = 1:eng.nCyl
    eng.cyl(i).dim.B = 0.820;            %Cylinder bore [m]
    eng.cyl(i).dim.S = 3.375;            %Cylinder stroke [m]
    eng.cyl(i).dim.lambda = 0.4973;       %Ratio of length of crank rod to connecting rod 
    eng.cyl(i).dim.CR = 17.4;             %Compression Ratio
    % Scavenge port dimension
    eng.cyl(i).scavPort.X = 0.08;          %Scavenge port width [m]
    eng.cyl(i).scavPort.Y = 0.2;          %Scavenge port height [m]
    eng.cyl(i).scavPort.r = 0.04;          %Radius of fillet of the opening [m]
    eng.cyl(i).scavPort.nPort = 28;      %Number of scanvenge ports
    % Exhaust valve dimenstion
    eng.cyl(i).exhVVDim.liftMax = 0.25;    %Exhaust valve maximum lift [m]
    eng.cyl(i).exhVVDim.Dv = 0.6;%.422;         %Exhaust valve head diameter [m]
    eng.cyl(i).exhVVDim.beta = 0.6632;       %Exhaust valve seat angle [rad]
    eng.cyl(i).exhVVDim.w = .021;          %Exhaust valve seat width [m]
    eng.cyl(i).exhVVDim.Dp = 0.504;%.380;         %Exhaust valve inner seat diameter [m]
    eng.cyl(i).exhVVDim.Ds = .086;         %Exhaust valve stem diameter [m]
    %eng.cyl(i).exhVVDim.AEffFactor = 0.2140; %If necessary
    % Exhaust valve profile
    load('ExhVVProfileRTFLEX68D');
    eng.cyl(i).exhVVProf.cAVVUpRef = cAVVUpRef;  %Exhaust valve crank angle array for opening [deg]
    eng.cyl(i).exhVVProf.cAVVDownRef = cAVVDownRef;   %Exhaust valve crank angle array for closing [deg]
    eng.cyl(i).exhVVProf.liftUpRef = liftUpRef;    %Exhaust normalized lift array for opening [0~1]
    eng.cyl(i).exhVVProf.liftDownRef = liftDownRef;  %Exhaust normalized lift array for closing [0~1]
    eng.cyl(i).exhVVProf.cAStartRef = 104.8;   %Nominal crank angle at start of valve lif [deg]
    eng.cyl(i).exhVVProf.dCALiftUp = cAVVUpRef(end) - cAVVUpRef(1);     %Nominal duration of crank angle for valve opening [deg]
    eng.cyl(i).exhVVProf.dCALiftDown = cAVVDownRef(end) - cAVVDownRef(1);   %Nominal duration of crank angle for valve closing [deg]
    eng.cyl(i).exhVVProf.dCALiftTopRef = 63.5; %Nominal duration of crank angle for valve open [deg]
    clearLoadedFile('ExhVVProfileRTFLEX68D');
    % Heat transfer
    eng.cyl(i).HT.mCp = 10000;              %Heat capacity of te cylinder [J/K]
    slope = 80;
    eng.cyl(i).HT.cCylHT = [0;0.003;slope;-slope*600+1000];
    %[5.3040e-4;-1.1493e0;8.3165e2;-1.9799e5];%[5.1517e-4,-0.92207,549.84,-109640]; %Polynomial coefficient for heat rejection model from the cylinder (4 x 1)
                            
    
    eng.cyl(i).HT.cAlpha = 1.5;           %Fitting coefficient for convective heat transfer coefficient
    eng.cyl(i).HT.tempWall0 = 550;      %Initial wall temperature of the cylinder [K]
    % Combustion
    eng.cyl(i).comb.mqfCycMax = 0.17705;      %Maximum fuel mass injected per cycle [kg]
    eng.cyl(i).comb.wiebePara = [0.07;0.57;3.05;10;22;50;1.5;1;0.7];%[0.07;0.57;3.05;11;24;56.3;1.5;1;0.7];      %3-Wiebe Parameters (9x1)        
    % Gas exchange
    eng.cyl(i).gasEx.kai = 2.5;             %Shape parameter for instantaneous exhaust gas composition for S model by Sher
    eng.cyl(i).gasEx.delta = 2.0;          % Shape parameter for instantaneous exhaust gas composition for S model by Sher
    
    
    % CYLINDER Initial conditions (Common for all cylinders)
    eng.cyl(i).init.phi0 = zeros(eng.nCyl,1);
    eng.cyl(i).init.p0 = eng.cyl(i).init.phi0;
    eng.cyl(i).init.T0 = eng.cyl(i).init.phi0;
    eng.cyl(i).init.F0 = eng.cyl(i).init.phi0;
    eng.cyl(i).init.phi0rad = eng.cyl(i).init.phi0;
    eng.cyl(i).init.V0 = eng.cyl(i).init.phi0;
    % 2 stroke engine valve opening/close calculation
    a = eng.cyl(i).dim.S/2;
    l = a/eng.cyl(i).dim.lambda;
    xpSPO = eng.cyl(i).dim.S - eng.cyl(i).scavPort.Y;
    eng.cyl(i).scavPort.cASPO = acos((2*a^2 + 2*a*l - 2*a*xpSPO - 2*l*xpSPO + ...
                xpSPO^2) / (2*a*(a+l-xpSPO)));
                                % Crank angle at scavenge port open [rad]
    eng.cyl(i).scavPort.cASPC = 2*pi - eng.cyl(i).scavPort.cASPO;                            
    eng.cyl(i).exhVVProf.cAEVO = eng.cyl(i).exhVVProf.cAStartRef*pi/180;  % Crank angle at exh V/V open [rad]
    eng.cyl(i).exhVVProf.cAEVC = (eng.cyl(i).exhVVProf.cAStartRef + ...
        eng.cyl(i).exhVVProf.dCALiftUp + eng.cyl(i).exhVVProf.dCALiftTopRef + ...
        eng.cyl(i).exhVVProf.dCALiftDown)*pi/180; 
                                % Crank angle at valve close [rad]
    eng.cyl(i).dim.vDisp = pi*eng.cyl(i).dim.B^2/4.0*eng.cyl(i).dim.S;
    eng.cyl(i).dim.vComp = eng.cyl(i).dim.vDisp/(eng.cyl(i).dim.CR-1);
                                % Compression volume [m3]
    vEVC = eng.cyl(i).dim.vComp + eng.cyl(i).dim.vDisp/2.0*...
        (1.0-cos(eng.cyl(i).exhVVProf.cAEVC) + 1.0/eng.cyl(i).dim.lambda* ...
        (1.0-sqrt(1.0 - eng.cyl(i).dim.lambda^2*sin(eng.cyl(i).exhVVProf.cAEVC)^2))); 


    eng.cyl(i).init.phi0 = 360*(i-1)/eng.nCyl + 0.1;       %Initial crank angle array [deg]
    eng.cyl(i).init.phi0rad = eng.cyl(i).init.phi0*pi/180;   
    eng.cyl(i).init.V0 = eng.cyl(i).dim.vComp + eng.cyl(i).dim.vDisp/2* ...
        (1.0-cos(eng.cyl(i).init.phi0rad) + ...
        1.0/eng.cyl(i).dim.lambda*(1.0-sqrt(1.0 - ...
        eng.cyl(i).dim.lambda^2*sin(eng.cyl(i).init.phi0rad).^2)));    
                            % Initial volume of cylinders [m3]
    if (eng.cyl(i).init.phi0rad > eng.cyl(i).exhVVProf.cAEVC) ...
            || (eng.cyl(i).init.phi0rad < eng.cyl(i).scavPort.cASPO)
        eng.cyl(i).init.p0 = pScav*(vEVC/eng.cyl(i).init.V0)^1.4;
    else if abs(pi - eng.cyl(i).init.phi0rad) < abs(pi - eng.cyl(i).scavPort.cASPO)
            eng.cyl(i).init.p0 = pExh;
        else
            eng.cyl(i).init.p0 = pScav;
        end;
    end;
    eng.cyl(i).init.T0 = TScav*(eng.cyl(i).init.p0/pScav)^(1-1/1.4);
    eng.cyl(i).init.F0 = 0;
    [R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZachV1(eng.cyl(i).init.p0,eng.cyl(i).init.T0,eng.cyl(i).init.F0,eng.fs);
    eng.cyl(i).init.m0 = eng.cyl(i).init.p0.*eng.cyl(i).init.V0 ./ (R.*eng.cyl(i).init.T0); 
    eng.cyl(i).init.E0 = eng.cyl(i).init.m0.*u;           
    eng.cyl(i).init.mb0 = eng.cyl(i).init.m0.*eng.cyl(i).init.F0 * eng.fs./(1 + eng.cyl(i).init.F0*eng.fs); 
end;

clear TScav pScav FScav pExh TExh FExh vEVC R u xpSPO a l
clear E0 m0 mb0 i



%% # Engine controller
% * engine governor
eng.control.gov.LPBW        = 1.0;        % Cutoff frequency for low pass filter [Hz]
eng.control.gov.Kp         = 0.5;        % Proportional gain for controller //0.8
eng.control.gov.Td         = 1.0;        % Derivative time constant
eng.control.gov.Ti         = 5.0;        % Integral gain for controller
eng.control.gov.N          = 1.0;      % Dirty derivative gain
eng.control.gov.uMin       = 0.1;      % Minimum output
eng.control.gov.uMax       = 1.1;      % Maximum output
eng.control.gov.u0         = eng.engLoad0; % Initial output of the controller
eng.control.gov.Kb         = 2.0;        %Back propagation gain (Anti-winding)
% * vessel speed controller
eng.control.speed.LPBW        = 100;        % Cutoff frequency for low pass filter [Hz]
eng.control.speed.Kp         = 0.1;        % Proportional gain for controller //0.8
eng.control.speed.Td         = 0.05;        % Derivative time constant
eng.control.speed.Ti         = 100.0;        % Integral gain for controller
eng.control.speed.N          = 2.0;      % Dirty derivative gain
eng.control.speed.uMin       = 0.1;      % Minimum output
eng.control.speed.uMax       = 1.1;      % Maximum output
eng.control.speed.u0         = eng.engLoad0; % Initial output of the controller
eng.control.speed.Kb        = 10;       %Back propagation gain (Anti-winding)
% * Injection controller
eng.control.inj.deltaPCombRef   = 50;       % Reference pressure rise due to combustion [bar]
eng.control.inj.Kp        = 0.008;    % Proportional gain for injection control
eng.control.inj.Ti        = 0.66;     % Integral time constant [s]
eng.control.inj.uMax       = 10;       % Maximum allowable injection timing [deg]
eng.control.inj.uMin       = -8;        % Minimum allowable injection timing [deg]
eng.control.inj.phiInjxRef  = [	1.1; 1.0; 0.9; 0.85; 0.8; ...
                    0.75; 0.7; 0.65; 0.6; 0.5; ...
                    0.4; 0.3; 0.25];                    
eng.control.inj.phiInjyRef  = [0.17194;-0.54814;-1.3524;-1.7890;-2.2412; ...
    -2.6465;-2.8950;-3.1654;-3.4797;-4.2672;-5.4270];
eng.control.EVO =  1.2;                   
% * Exhaust valve controller
eng.control.EVC.Kp           = 0.002;    % Proportional gain
eng.control.EVC.Ti           = 0.66;     % Integral time constant [s]
eng.control.EVC.uMax          = 1.9;      % Maximum allowable duration of valve open
eng.control.EVC.uMin          = 0.2;      % Minimum allowable duration of valve open 
eng.control.EVC.EVCxRef       = [	1.1; 1.0; 0.9; 0.85; 0.8; ...
                    0.75; 0.7; 0.65; 0.6; 0.5; ...
                    0.4; 0.3; 0.2];                    
eng.control.EVC.EVCyRef          = [0.97568;0.85588;0.56557;0.47186; ...
    0.37639;0.2;0.2;0.2;0.2;0.2;0.25];                    
                            % Exhaust valve open duration for different
                            % load

% * Maximum cylinder pressure control
eng.control.pMax.Kp          = 0.5;      % Proportional gain 
eng.control.pMax.Ti          = 0.66;     % Integral time constant
eng.control.pMax.uMax         = 200;      % Maximum allowable maximum cylinder pressure [bar]
eng.control.pMax.uMin         = 60;       % Minimum allowable maximum cylinder pressure [bar]
eng.control.pMax.LPBWPow      = 0.5;     % Cutoff frequency for LP filter for power output [Hz]
eng.control.pMax.LPBWdmf      = 0.5;     % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.pMax.LPBWdme      = 0.5;     % Cutoff frequency for LP filter for fuel flow [Hz]

% * Waste gate control          
eng.control.WG.Ratio  = 0.04;     % Ratio of the bypass flow (set point)
eng.control.WG.Kp            = 0.002;      % Proportional gain for the controller
eng.control.WG.Ti            = 0.5;      % Integral time constant for the controller
eng.control.WG.Kb            = 5e2;      % Back calculation gain for anti-windup
eng.control.WG.uMax    = 1;       % Maximum output of the controller
eng.control.WG.uMin    = 0;        % Minimum output of the controller
eng.control.WG.LPBWdmExhBypass = 0.66;       % Cutoff frequency for LP filter for waste gate bypass flow [Hz]
eng.control.WG.LPBWdmExh = 0.66;           % Cutoff frequency for LP filter for exhaust flow [Hz]
eng.control.WG.upperOpenSPWG = 4e5;      % Upper threshold value of scavenge air pressure to open waste gate
eng.control.WG.lowerCloseSPWG = 3.7e5;     % Lower threshold value of scavenge air pressure to close waste gate
eng.control.WG.tau = 10;

% * Blower control
eng.control.blower.upper = 210000;   % Upper threshold value of scavenge air pressure to turn off the blower
eng.control.blower.lower = 190000;   % Lower threshold value of scavenge air pressure to turn on the blower 
eng.control.blower.tau = 10;           % Time constant for blower starting / stop [s]

% * Blower fitting                                                               
eng.control.blowerFit.Kp = 1e-4;   % Proportional gain for blower fitting        
eng.control.blowerFit.Td = 10000;                                                
eng.control.blowerFit.N = 1;                                                     
eng.control.blowerFit.Ti = 10;   % Integral time constatn for blower fitting     
eng.control.blowerFit.uMax = 2;   % maximum mass flow for blower fitting         
eng.control.blowerFit.uMin = 0;     % minimum mass flow for blower fitting       
eng.control.blowerFit.u0 = 0;                                                    
eng.control.blowerFit.Kb = 1e4;           % back propagation gain for blower fit
  
% * Heat Rejection Model Identification
eng.control.HRejId.Kp            = 0.0005;      % Proportional gain for the controller
eng.control.HRejId.Ti            = 5;      % Integral time constant for the controller
eng.control.HRejId.sw            = 1;        % Switch on/off for the identification
eng.control.HRejId.LPBWQCyl      = 0.66;        % Bandwidth for LP filter for heat transfer (Hz)

% * Low pass filter for fuel and exhaust flow
eng.control.dmfLP.BW                = 0.66;  % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.dmeLP.BW                = 0.66;  % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.powLP.BW                = 1.5;     % Cutoff frequency for LP filter for power output [Hz]

eng.control.dmeLP.dmf0              = 0;  % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.dmeLP.dme0              = 0;  % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.powLP.pow0              = eng.engLoad0*eng.Pe;     % Cutoff frequency for LP filter for power output [Hz]

% * smoke limiter
eng.control.smokeLim.LPBW       = 0.66;        % Cutoff frequency for LP filter for fuel flow [Hz]
eng.control.smokeLim.FMax       = 0.7;     % Maximum allowable F in the cylinder

%% Load model
coeffProp = [57.37123;0.93965;-0.73220];
