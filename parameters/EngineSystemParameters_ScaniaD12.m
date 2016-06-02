load initial_condition_SCANIA;
load SAE_map_comp_Garrett_3788R;
load SAE_map_turb_SCANIA_D12;

if ~exist('TC','var')
    TC = turbocharger(SAE_map_comp, SAE_map_turb);
end;

powL0 = 0.5; % initial load level
p_ac_init = interp1(PL,p_ac_init,powL0)*1e5;
p_exh_init = interp1(PL,p_exh_init,powL0)*1e5;
F_initial = interp1(PL,F_initial,powL0);
RPM_TC_initial = interp1(PL,RPM_TC_initial,powL0);
omegaT0 = RPM_TC_initial*pi/30;
T_bcool = TC.GetToutComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5,300);
m_dot_TC = TC.GetFlowComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5);

%% General
jShaft = 0;          %Mass moment of inertia of the engine shaft [kgm2]
eng.fs = 0.0683;          %Fuel-air equivalent ratio
eng.hn = 42700000;   %Low heating value of the fuel (J/kg)
eng.coeffMechEff = []; %Coefficient for mechanical efficiency curvefitting (2x1)
omegaE0 = 1500/30*pi;         %Initial speed of the engine (rad/s)
eng.RPMMax = 1500;      %Max. Rated RPM
eng.nStroke = 4;
eng.nCyl = 6;
eng.phi0 = [0.01;480.01;240.01;600.01;120.01;360.01];


%% Charge air cooler parameters
eng.cAC.Cd = 0.8;                 %Discharge coefficient of the cooler
eng.cAC.areaAirPath = 0.0032;        %Effective area of the air path [m2]
eng.cAC.dmCW = 0.92;               %Cooling water flow [kg/s]
eng.cAC.coeffTCWK = [-0.003894501462398,2.891539900422413];          %Coefficient for curvefitting 
                                %for cooling water temp. vs. effective heat
                                %exchange area [m2]
eng.cAC.CpCW = 4185.5;               %Cooling water heat capacity [J/kgK]
eng.cAC.dCWPipe = 0.0040;            %Coolant tube diameter [m]
%% Control volumes 
% (Should be defined for each control volume with a specific name replacing
% "CV")
% 
% 
% eng.CV.m0 = 0;                  %Initial mass [kg]
% eng.CV.E0 = 0;                  %Initial internal energy [J]
% eng.CV.mb0 = 0;                 %Initial burned fuel mass [kg]
% eng.CV.V0 = 0;                  %Initial Volume
% In case using conventional methods
%eng.CV.p0 = 0;                  %Initial mass [kg]
%eng.CV.T0 = 0;                  %Initial internal energy [J]
%eng.CV.F0 = 0;                 %Initial burned fuel mass [kg]

%% Turbocharger parameters
    
% Compressor 
load('comp_map_Garrett3788R2');

eng.turbo.comp.flowMap = comp_flow_map;    %Compressor map for corrected flow
eng.turbo.comp.effMap = comp_eff_map;     %Compressor map for efficiency
eng.turbo.comp.prRep = pr_rep;      %Pressure ratio array for look-up in 
                                %compressor map
eng.turbo.comp.n288Rep = n288_rep;    %Corrected speed array for look-up in 
                                %compressor map
eng.turbo.comp.npr = length(eng.turbo.comp.prRep);
eng.turbo.comp.nsp = length(eng.turbo.comp.n288Rep);
clear comp_flow_map comp_eff_map pr_rep n288_rep
% Turbine for map unknown but performance known
%{
eng.turbo.turb.flowCoeff = [];   %Turbine flow coefficient
eng.turbo.turb.effCoeff = [];    %Turbine efficiency coefficient
eng.turbo.jTC = 0;               %Rotor mass moment of inertia [kgm2]
%}
% Turbine for only flow curve known of a single RPM but efficiency unknown
load('turbDataScaniaDC12');
eng.turbo.turb.flowCoeff = coeff_turb_flow;  %Flow coefficient for turbine model(Flow
%                                 vs. ER)
eng.turbo.turb.dTurbWheel = D_turb_wheel;  %Diameter of the turbine wheel
eng.turbo.turb.ucOpt = Uc_opt;       %Optimal blade speed ratio
eng.turbo.turb.effMax = eff_turb_max;      %Maximum isentropic efficiency
eng.turbo.turb.tempRef = T_ref_turb;     %Reference temperature for turbine flow
clear coeff_turb_flow D_turb_wheel Uc_opt eff_turb_max T_ref_turb

clear SAE_map_comp SAE_map_turb
% Turbine for map known
%eng.turbo.turb.flowMap = [];    %Compressor map for corrected flow
%eng.turbo.turb.effMap = [];     %Compressor map for efficiency
%eng.turbo.turb.prRep = [];      %Pressure ratio array for look-up in compressor map
%eng.turbo.turb.n288Rep = [];    %Corrected speed array for look-up in compressor map
%eng.turbo.turb.npr = length(turbo.comp.prRep);
%eng.turbo.turb.nsp = length(turbo.comp.n288Rep);
%
eng.turbo.jTC = TC.SAE_map_comp.inertia*0.509070;               %Rotor mass moment of inertia [kgm2]
eng.turbo.omega0 = RPM_TC_initial/30*pi*1.05;

%{a
%% Cylinder parameters
for i = 1:eng.nCyl
    % General
    % Cylinder dimension
    eng.cyl(i).dim.B = 0.127;            %Cylinder bore [m]
    eng.cyl(i).dim.S = 0.14;            %Cylinder stroke [m]
    eng.cyl(i).dim.lambda = 0.2745;       %Ratio of length of crank rod to connecting rod 
    eng.cyl(i).dim.CR = 18;
    eng.cyl(i).dim.vDisp = eng.cyl(i).dim.B^2*pi/4*eng.cyl(i).dim.S;
    %{
    % Scavenge port dimension
    eng.cyl.scavPort.X = 0;          %Scavenge port width [m]
    eng.cyl.scavPort.Y = 0;          %Scavenge port height [m]
    eng.cyl.scavPort.r = 0;          %Radius of fillet of the opening [m]
    eng.cyl.scavPort.nPort = 0;      %Number of scanvenge ports
    %}
    % Exhaust valve dimenstion
    eng.cyl(i).exhVVDim.no = 2;
    eng.cyl(i).exhVVDim.liftMax = 0.01425;    %Exhaust valve maximum lift [m]
    eng.cyl(i).exhVVDim.Dv =  0.041;         %Exhaust valve head diameter [m]
    eng.cyl(i).exhVVDim.beta = pi/6;       %Exhaust valve seat angle [rad]
    eng.cyl(i).exhVVDim.w = 0.002;          %Exhaust valve seat width [m]
    eng.cyl(i).exhVVDim.Dp = 0.038;         %Exhaust valve inner seat diameter [m]
    eng.cyl(i).exhVVDim.Ds = 0.0073;         %Exhaust valve stem diameter [m]
    % Exhaust valve profile
    eng.cyl(i).exhVVProf.liftUpRef = [0;0.007;0.021;0.046;0.07;0.105;0.161; ...
        0.211;0.267;0.323;0.372;0.435;0.491;0.547;0.604;0.653;0.702;0.744;...
        0.782;0.818;0.853;0.884;0.909;0.93;0.951;0.965;0.979;0.989;0.996; ...
        1];                 %Exhaust normalized lift array for opening [0~1]
    eng.cyl(i).exhVVProf.liftDownRef = [1;0.996;0.993;0.982;0.972;0.958;0.937;...
        0.912;0.884;0.856;0.821;0.786;0.744;0.702;0.656;0.614;0.565;0.509;...
        0.442;0.379;0.319;0.253;0.196;0.14;0.095;0.06;0.032;0.018;0.006;...
        0];                 %Exhaust normalized lift array for closing [0~1]
    eng.cyl(i).exhVVProf.cAStartRef = 137;   %Nominal crank angle at start of valve lif [deg]
    eng.cyl(i).exhVVProf.dCALiftUp = 111.5;     %Nominal duration of crank angle for valve opening [deg]
    eng.cyl(i).exhVVProf.dCALiftDown = 111.5;   %Nominal duration of crank angle for valve closing [deg]
    eng.cyl(i).exhVVProf.dCALiftTopRef = 0; %Nominal duration of crank angle for valve open [deg]
    eng.cyl(i).exhVVProf.cAVVUpRef = (0:eng.cyl(i).exhVVProf.dCALiftUp/(length(eng.cyl(i).exhVVProf.liftUpRef)-1):eng.cyl(i).exhVVProf.dCALiftUp)';  %Exhaust valve crank angle array for opening [deg]
    eng.cyl(i).exhVVProf.cAVVDownRef = (0:eng.cyl(i).exhVVProf.dCALiftDown/(length(eng.cyl(i).exhVVProf.liftDownRef)-1):eng.cyl(i).exhVVProf.dCALiftUp)';   %Exhaust valve crank angle array for closing [deg]
    % intake valve dimenstion
    eng.cyl(i).intakeVVDim.no = 2;
    eng.cyl(i).intakeVVDim.liftMax = 0.01425;    %intake valve maximum lift [m]
    eng.cyl(i).intakeVVDim.Dv = 0.041;         %intake valve head diameter [m]
    eng.cyl(i).intakeVVDim.beta = pi/6;       %intake valve seat angle [rad]
    eng.cyl(i).intakeVVDim.w = 0.002;          %intake valve seat width [m]
    eng.cyl(i).intakeVVDim.Dp = 0.038;         %intake valve inner seat diameter [m]
    eng.cyl(i).intakeVVDim.Ds = 0.0073;         %intake valve stem diameter [m]
    % intake valve profile
    eng.cyl(i).intakeVVProf.liftUpRef = [0;0.007;0.021;0.046;0.07;0.105;0.161; ...
        0.211;0.267;0.323;0.372;0.435;0.491;0.547;0.604;0.653;0.702;0.744;...
        0.782;0.818;0.853;0.884;0.909;0.93;0.951;0.965;0.979;0.989;0.996; ...
        1];                    %intake normalized lift array for opening [0~1]
    eng.cyl(i).intakeVVProf.liftDownRef = [1;0.996;0.993;0.982;0.972;0.958;0.937;...
        0.912;0.884;0.856;0.821;0.786;0.744;0.702;0.656;0.614;0.565;0.509;...
        0.442;0.379;0.319;0.253;0.196;0.14;0.095;0.06;0.032;0.018;0.006;...
        0];                 %intake normalized lift array for closing [0~1]
    eng.cyl(i).intakeVVProf.cAStartRef = 348;   %Nominal crank angle at start of valve lif [deg]
    eng.cyl(i).intakeVVProf.dCALiftUp = 115;     %Nominal duration of crank angle for valve opening [deg]
    eng.cyl(i).intakeVVProf.dCALiftDown = 115;   %Nominal duration of crank angle for valve closing [deg]
    eng.cyl(i).intakeVVProf.dCALiftTopRef = 0; %Nominal duration of crank angle for valve open [deg]
    eng.cyl(i).intakeVVProf.cAVVUpRef = (0:eng.cyl(i).intakeVVProf.dCALiftUp/(length(eng.cyl(i).intakeVVProf.liftUpRef)-1):eng.cyl(i).intakeVVProf.dCALiftUp)';  %Exhaust valve crank angle array for opening [deg]
    eng.cyl(i).intakeVVProf.cAVVDownRef = (0:eng.cyl(i).intakeVVProf.dCALiftDown/(length(eng.cyl(i).intakeVVProf.liftDownRef)-1):eng.cyl(i).intakeVVProf.dCALiftUp)';   %Exhaust valve crank angle array for closing [deg]
    % Heat transfer
    eng.cyl(i).HT.mCp = 100000;              %Heat capacity of the cylinder [Jkg/K]
    eng.cyl(i).HT.cCylHT = [0;0;0;6.5];  %Polynomial coefficient for heat rejection model from the cylinder (4 x 1)
    eng.cyl(i).HT.cAlpha = 2.5;           %Fitting coefficient for convective heat transfer coefficient
    eng.cyl(i).HT.tempWall0 = 550;      %Initial wall temperature of the cylinder [K]
    % Combustion
    eng.cyl(i).comb.mqfCycMax = 0.00021;      %Maximum fuel mass injected per cycle [kg]
    eng.cyl(i).comb.wiebePara = [0.02;0.8;0.5;12;52;60;2.2;1.8;2.7];      %3-Wiebe Parameters (9x1)        
    % Initial conditions (Common for all cylinders)
    
    eng.cyl(i).init.phi0 = eng.phi0(i);       %Initial crank angle array [deg]
    vComp = pi*eng.cyl(i).dim.B^2/4.0*eng.cyl(i).dim.S/(eng.cyl(i).dim.CR-1);                 
    eng.cyl(i).init.phi0rad = eng.cyl(i).init.phi0*pi/180;                                 
    eng.cyl(i).init.V0 = vComp + pi*eng.cyl(i).dim.B^2/4.0*(eng.cyl(i).dim.S/2.0*(1.0-cos(eng.cyl(i).init.phi0rad) ...
        + 1.0/eng.cyl(i).dim.lambda*(1.0-sqrt(1.0 - (eng.cyl(i).dim.lambda*sin(eng.cyl(i).init.phi0rad)).^2))));
    if  eng.cyl(i).init.phi0 > eng.cyl(i).exhVVProf.cAStartRef && ...
             eng.cyl(i).init.phi0 < (eng.cyl(i).intakeVVProf.cAStartRef + ...
            eng.cyl(i).intakeVVProf.dCALiftUp + ...
            eng.cyl(i).intakeVVProf.dCALiftDown + ...
            eng.cyl(i).intakeVVProf.dCALiftTopRef)
        eng.cyl(i).init.p0 = p_ac_init;
        eng.cyl(i).init.T0 = 310;
    else 
        eng.cyl(i).init.p0 = p_ac_init*((eng.cyl(i).dim.vDisp+vComp)/eng.cyl(i).init.V0)^1.4;          %Initial mass array [kg]    
        eng.cyl(i).init.T0 = 310*((eng.cyl(i).dim.vDisp+vComp)/eng.cyl(i).init.V0)^0.4;          %Initial internal energy array [J]
    end;
    eng.cyl(i).init.F0 = 0;         %Initial burned fuel mass array [kg]
    eng.cyl(i).init.phi0rad = eng.cyl(i).init.phi0*pi/180;       
    [eng.cyl(i).init.m0,eng.cyl(i).init.E0,eng.cyl(i).init.mb0] = GetMEMbZach(eng.cyl(i).init.p0,eng.cyl(i).init.T0, eng.cyl(i).init.F0,eng.cyl(i).init.V0,eng.fs);
end;
clear cAVVUpRef cAVVDownRef liftUpRef liftDownRef
%}
eng.pipeBCool.p0 = p_ac_init;
eng.pipeBCool.T0 = T_bcool;
eng.pipeBCool.F0 = 0;
eng.pipeBCool.V0 = 0.004;
[eng.pipeBCool.m0, eng.pipeBCool.E0, eng.pipeBCool.mb0] = GetMEMbZach(eng.pipeBCool.p0,eng.pipeBCool.T0, eng.pipeBCool.F0,eng.pipeBCool.V0,eng.fs);

eng.CARec.p0 = p_ac_init;
eng.CARec.T0 = 300;
eng.CARec.F0 = 0;
eng.CARec.V0 = 0.01;
[eng.CARec.m0, eng.CARec.E0, eng.CARec.mb0] = GetMEMbZach(eng.CARec.p0,eng.CARec.T0, eng.CARec.F0,eng.CARec.V0,eng.fs);

eng.exhRec.p0 = p_exh_init;
eng.exhRec.T0 = 800;
eng.exhRec.F0 = F_initial;
eng.exhRec.V0 = 0.01;
[eng.exhRec.m0, eng.exhRec.E0, eng.exhRec.mb0] = GetMEMbZach(eng.exhRec.p0,eng.exhRec.T0, eng.exhRec.F0,eng.exhRec.V0,eng.fs);

clear R u
clear F_initial PL RPM_TC_initial p_ac_init p_exh_init vComp

