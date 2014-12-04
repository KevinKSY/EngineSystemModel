
% init()
%
% Set initial parameters for motion.slx
%
%
%    Copyright: 	NTNU, Trondheim, Norway
%    Created:  	2014.07.02	Torstein Ingebrigtsen B?
%    Revised:	<date>	<author> <description>
%    		<date>	<author> <description>
%
%busSpec
%load rig
%addpath('TA_aleksander')

% Initial position x, y, z, theta, phi, psi
eta0 = [0,0,0,0,0,0]';
% Initial velocity u, v, w, p, q, r
nu0 = [0,0,0,0,0,0]';
%vessel = struct('D',D,'G',G,'MA',MA,'MRB',MRB,'eta0',eta0,'nu0',nu0);

% Prefix for log files
savename = 'log';


%% Switchboard parameters
% number of switchboards
nSwitchboard = 3;
% number of gensets
engines = 6;
% number of thrusters
nThrusters = 6;

% Water density
rho = 1025;

% Generator sets connected
ConnectedGensets = [1;1;0;1;1;1].';
ConnectedGensetsAfter = [1;1;1;1;1;1].';
ConnectedGensetsSwitchTime = 100;

%% Loads
% Static load which should not be reduced, in Watt
PowerHighPriority = .6*sum(ConnectedGensets)*.85*9.1e6/6*ones(nSwitchboard,1); 
powerFactorHighPriorityLoad = .85*ones(nSwitchboard,1); 
% Static load which will be reduced if the available power is too low
PowerLowPriority = PowerHighPriority;
powerFactorLowPriorityLoad = powerFactorHighPriorityLoad; 

% Current speed in m/s
u_c = [-2.;
    0;
    0];
% Wind force in Newton
%windForce = D([1 2 6],[1 2 6])*u_c*1;
% Wave
%waveFrequency = .3*2*pi;
%waveForceAmplitude = 0*waveFrequency^2*.2*(vessel.MA(1,1)+vessel.MA(1,1))*[1;0;0];

%% DP parameters
% reference position
x_ref = [0; 0; 0];


% Initial value of I-term in PID
%Thrust0 = -D([1 2 6],[1 2 6])*u_c-windForce;

% Observer and controller
%[Observer, DP] = initDP(waveFrequency,vessel,Thrust0);
%UseObserver = 0;

for i = 1:engines
    generators(i).Sb  = 9.1e6;      % Rated value of generator
end

%% Initial values of Thrusters
%addpath(num2str([pwd '/' 'thruster']));
%% Position of thrusters [m] (x,y) 
x_spread = 35; %Distance from co to thrusters in x-direction
y_spread = 27; % Distance from co to thrusters in y-direction (for those not on x-axis)
thruster_pos_x = [-x_spread, -x_spread, 0, 0, x_spread, x_spread].';
thruster_pos_y = [-y_spread, y_spread, -y_spread, y_spread, -y_spread,  y_spread].';
thruster2swb = [1 1 2 2 3 3];
rotable = [1 1 1 1 1 1];

%% Initial Azimuth-angle of thrusters
T_alpha = [180+45
    -45
    180
    0
    180-45
    45]*pi/180;
%thrusters = thrusterInit(Thrust0,nThrusters,thruster_pos_x,thruster_pos_y,T_alpha);

%% Initial values of electrical system
% Initial consumed power (not a parameter, only help variable)
% TODO: make it work when bus ties are opened
aux1 = 0;
aux2 = 0;
%for i = 1:length(thrusters)
%    aux1 = aux1 + thrusters(i).motor.omega0*thrusters(i).motor.torque0;
%end
for i = 1:engines
    aux2 = aux2 + generators(i).Sb * ConnectedGensets(i);
end

aux3 = sum(PowerLowPriority+PowerHighPriority);


initialPowerFactor = .85;
AvrDroop = .01;
p0 = (aux1+aux3)/aux2;
q0 = p0*sqrt(1-initialPowerFactor^2)/initialPowerFactor;
clear aux1 aux2 aux3;

%% Low pass filter for switchboard
TV0 = .001; % Time constant for low pass filter for calculation of bus voltage
V_no_q = 1;
VT0 = V_no_q*(1-AvrDroop*q0)*ones(nSwitchboard,1); % Initial voltage on bus
loadAngle0 =0 *ones(nSwitchboard,1); % Initial loadangle on bus

%% Generator sets parameter

% % Fuel index to torque gain
% ku = 1+Dfw+r;
for i = 1:engines;
    generators(i).ID  = i;          % Generator ID
    generators(i).powerFactor = .85;% Power factor of thruster
    generators(i).w_b = 60*2*pi;    % Rated speed of generator
    generators(i).r   = 0.0019;     % Stator resistance [p.u.]
    generators(i).xs  = 0.480;      % Synchronous reactance [p.u.]
    generators(i).H   = 2;          % Intertia time constant [seconds]
    generators(i).D   = 0.025;      % Damping [p.u.]
end

% * Diesel engine parameters

addpath(genpath('Engine_Model'));

load comp_map_Garrett3788R2;
load turbDataGarrett3788R2;
load CoolerPerf_ScaniaD1102;
load initial_condition_SCANIA;
load SAE_map_comp_Garrett_3788R;
load SAE_map_turb_Garrett_3788R2;

fs = 0.0683;
if ~exist('TC','var')
    TC = turbocharger(SAE_map_comp, SAE_map_turb);
end;

powL0 = 0.5;            % Initial power load (0~1.0)
tCW = 298.15;
dmCW = 0.92; % in kg/s
cpCW = 4185.5; %Heat capacity of water in J/kgK
pAmb = 1e5;
tAmb = 300;
fAmb = 0;
pBack = 1.01e5;


p_ac_init = interp1(PL,p_ac_init,powL0)*1e5;
p_exh_init = interp1(PL,p_exh_init,powL0)*1e5;
F_initial = interp1(PL,F_initial,powL0);
RPM_TC_initial = interp1(PL,RPM_TC_initial,powL0);
omegaT0 = RPM_TC_initial*pi/30;
T_bcool = TC.GetToutComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5,tAmb);
m_dot_TC = TC.GetFlowComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5);

p_acool = p_ac_init;
T_acool = T_bcool + 0.95*(tCW - T_bcool);
m_dot_cool_init = m_dot_TC;

p_bcool = p_acool + 2000;
[R,~,~,~,~,~,~,~,~,~,~,~,k] = GetThdynCombGasZach(p_acool, T_bcool, 0);
err_p_bcool = 1;
while err_p_bcool > 0.001
    err_m_dot = m_dot_cool_init - GetIdealNozzleFlowPTF( Cd_cool, A_air_path, p_bcool, p_acool, T_bcool, 0, 0); 
    dm_dotdp2 = -(1/2)*Cd_cool*A_air_path*sqrt(2)*(2*(p_acool./p_bcool).^(1./k).*p_bcool-p_acool)./ ...
        (sqrt(R.*T_bcool).*sqrt((p_acool./p_bcool).^(-1./k).*k.*((p_acool./p_bcool).^(1./k).*p_bcool-p_acool)./((k-1).*p_bcool)).*p_bcool);
    dp_bcool_temp = -err_m_dot./dm_dotdp2;
    err_p_bcool = max(abs(dp_bcool_temp)./p_bcool);
    p_bcool = max(p_bcool + dp_bcool_temp,p_acool*1.001);
end;

p0_pipe = p_bcool;
p0_AR = p_acool;
p0_ER = p_exh_init;
T0_pipe = T_bcool;
T0_AR = T_acool;
T0_ER = 800;
F0_ER = F_initial;

vPipe = 0.004;
vAR = 0.01;
vER = 0.01;


[R_pipe,~,~,u_pipe,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_pipe,T0_pipe,0);
[R_AR,~,~,u_AR,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_AR,T0_AR,0);
[R_ER,~,~,u_ER,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_ER,T0_ER,F0_ER);

rho_pipe = p0_pipe/R_pipe/T0_pipe;
m0_pipe = rho_pipe*vPipe;
E0_pipe = m0_pipe*u_pipe;
mb0_pipe = 0;

rho_AR = p0_AR/R_AR/T0_AR;
m0_AR = rho_AR*vAR;
E0_AR = m0_AR*u_AR;
mb0_AR = 0;

rho_ER = p0_ER/R_ER/T0_ER;
m0_ER = rho_ER*vER;
mb0_ER = F0_ER*fs/(1+F0_ER*fs)*m0_ER;
E0_ER = m0_ER*u_ER;

npr = length(pr_rep);
nsp = length(n288_rep);
%% Genset engine parameters
load('ExhVVProfileRTFLEX68D');
for i = 1:engines;
% Smoke limiter    
    generators(i).eng.fMax      = 0.75;% Maximum allowable fuel-air equivalent ratio
% Combustion
    generators(i).eng.LHV       = 42.7e6;% Low heating value of the fuel [J/kg]    
    generators(i).eng.mFCycMax  = 0.00021;% Mass of fuel injected per cycle at rated load [kg]
    generators(i).eng.fs        = fs;% Stoichiometric fuel-air ratio 
    generators(i).eng.SFC       = [67.04,-99.63,2.386e+02];% Quadratic SFC curve coefficient (3x1)
    generators(i).eng.tPe       = 0.01;% Time constant for the power development for SFC curve index [sec]
% Engine cylinder
    generators(i).eng.vD        = 0.010641;% Displacement volume per cylinder [m3]
    generators(i).eng.powNom    = 280000;% Rated shaft power [W]
    generators(i).eng.volEff1          = [0.068081887046403,-0.441624318651670,1.433550808813938];% Volumetric efficiency coefficient for higher inlet presssure
    generators(i).eng.volEff2          = [-0.261226296116146,0.960147637763599,-0.044560143433303];% Volumetric efficiency coefficient for lower inlet presssure
    generators(i).eng.nStroke          = 4;% Number of stroke
    generators(i).eng.C1               = 0.15;% Heat loss coefficient
    generators(i).eng.pAInf            = 1.925; % the point of change in fit curve for vol. eff [bar]
    generators(i).eng.powL0            = powL0;% Initial power load (0~1.0)
    generators(i).eng.omegaENom        = 1500/30*pi; %Rated engine speed [rad]
    generators(i).eng.tqShaftNom       = generators(i).eng.powNom / generators(i).eng.omegaENom; 
                                                     %Rated engine speed [Nm]
% Turbocharger
    generators(i).eng.jTC              = SAE_map_comp.inertia;% Mass moment of inertial of the turbine (kgm2)
    generators(i).eng.compFlowMap      = comp_flow_map;% Compressor map for corrected flow in table
    generators(i).eng.compEffMap       = comp_eff_map;% Compressor map for efficiency in table
    generators(i).eng.prRep            = pr_rep;% Pressure ratio array for look-up in compressor map
    generators(i).eng.n288Rep          = n288_rep;% Corrected speed array for look-up in compressor map
    generators(i).eng.npr              = npr;% Length of pressure ratio array for look-up in compressor map
    generators(i).eng.nsp              = nsp;% Length of corrected speed array for look-up in compressor map
    generators(i).eng.flowCoeffTurb    = coeff_turb_flow;% Flow coefficient for turbine model
    generators(i).eng.dTurbWheel       = D_turb_wheel;% Turbine wheel diameter (m)
    generators(i).eng.ucOpt            = Uc_opt;% Optimal blade speed ratio of turbine for maximum efficiency
    generators(i).eng.effTurbMax       = eff_turb_max;% Maximum effciency of a turbine
    generators(i).eng.tempRef          = T_ref_turb;% Reference temperature for turbine flow
    generators(i).eng.omegaT0          = omegaT0;% Initial speed of a turbocharger (rad/s)
    generators(i).eng.RPMtMax          = n288_rep(end); % Maximum turbocharger speed [RPM]
% Pipe after compressor    
    generators(i).eng.vPipeAComp       = vPipe;% Volume [m3]
    generators(i).eng.m0PipeAComp      = m0_pipe;% Initial mass [kg]
    generators(i).eng.e0PipeAComp      = E0_pipe;% Initial internal energy [J]
    generators(i).eng.mb0PipeAComp     = mb0_pipe;% Initial burned fuel mass [kg]
% Charge air cooler
    generators(i).eng.cdCool           = 0.8; % Discharge coefficient
    generators(i).eng.aAirPath         = A_air_path; % Effective sectional area of air path [m2]
    generators(i).eng.dmCW             = dmCW; % Coolant mass flow [kg/s]
    generators(i).eng.coeffKTCW        = coeff_T_cw_K; % Coefficient for effective heat transfer area w.r.t. coolant temperature (2x1)
    generators(i).eng.cpCW             = cpCW; % Specific heat capacity of coolant [J/kgK]
    generators(i).eng.dPipeCW          = D_cw_pipe; % Pipe diameter of the cooling water pipe in the cooler [m]
    generators(i).eng.tCW              = tCW; % Coolant temperature
% Air receiver 
    generators(i).eng.vAR              = vAR; % Volume [m3]
    generators(i).eng.m0AR             = m0_AR; % Initial mass [kg]
    generators(i).eng.E0AR             = E0_AR; % Initial internal energy [J]
    generators(i).eng.mb0AR            = mb0_AR; % Iniital burned fuel mass [kg]
% Exhaust receiver 
    generators(i).eng.vER              = vER; % Volume [m3]
    generators(i).eng.m0ER             = m0_ER; % Initial mass [kg]
    generators(i).eng.E0ER             = E0_ER; % Initial internal energy [J]
    generators(i).eng.mb0ER            = mb0_ER; % Iniital burned fuel mass [kg]
% Ambient conditions
    generators(i).eng.pAmb             = pAmb; % Ambient pressure [Pa a]
    generators(i).eng.tAmb             = tAmb; % Ambient temperature [K]
    generators(i).eng.fAmb             = fAmb; % Ambient fuel-air equivalent ratio
    generators(i).eng.pBack            = pBack; % Back pressure at the turbine outlet [Pa a]
% Cylinder parameters - General
    generators(i).eng.hn               = 42.7e6; % Low heating value of the fuel (J/kg)
    generators(i).eng.nCyl             = 6;      % number of cylinders 
% Cylinder parameters - Dimension    
    generators(i).eng.B                = 0.127; % Bore [m]
    generators(i).eng.stroke           = 0.14;  % stroke [m]
    generators(i).eng.lambdaCrank      = 0.27451; % connecting rod vs. crank radius
    generators(i).eng.veps             = 18;
    generators(i).eng.vDisp            = (generators(i).eng.B)^2/4*pi*generators(i).eng.stroke;
    generators(i).eng.vComp            = generators(i).eng.vDisp / (generators(i).eng.veps - 1);
% Cylinder parameters - Valve
    generators(i).eng.cAVVUpRefIntake = cAVVUpRef;
    generators(i).eng.cAVVDownRefIntake = cAVVDownRef;
    generators(i).eng.liftUpRefIntake = liftUpRef;
    generators(i).eng.liftDownRefIntake = liftDownRef;
    generators(i).eng.startCARefIntake = 345;
    generators(i).eng.dCALiftUpRefIntake = 15;
    generators(i).eng.dCALiftDownIntake = 15;
    generators(i).eng.dCALiftTopRefIntake = 180;
    generators(i).eng.intakeLiftMaxRef = 0.015;
    generators(i).eng.intakeDV = 0.05;
    generators(i).eng.intakeBeta = pi/6;
    generators(i).eng.intakeW = 0.005;
    generators(i).eng.intakeDp = 0.04;
    generators(i).eng.intakeDs = 0.01;
    generators(i).eng.cAVVUpRefExh = cAVVUpRef;
    generators(i).eng.cAVVDownRefExh = cAVVDownRef;
    generators(i).eng.liftUpRefExh = liftUpRef;
    generators(i).eng.liftDownRefExh = liftDownRef;
    generators(i).eng.startCARefExh = 165;
    generators(i).eng.dCALiftUpRefExh = 15;
    generators(i).eng.dCALiftDownExh = 15;
    generators(i).eng.dCALiftTopRefExh = 180;
    generators(i).eng.exhLiftMax = 0.015;
    generators(i).eng.exhDV = 0.05;
    generators(i).eng.exhBeta = pi/6;
    generators(i).eng.exhW = 0.005;
    generators(i).eng.exhDp = 0.04;
    generators(i).eng.exhDs = 0.01;
% Cylinder parameters - Heat transfer
    generators(i).eng.mCp = 100;
    generators(i).eng.cCylHT = [0;0;0;97.5];
    generators(i).eng.cAlpha = 1;
% Cylinder parameters - Combustion
    generators(i).eng.wiebePara = [0.02;0.8;0.5;12;52;60;2.2;1.8;2.7];
% Cylinder parameters - Initial values
    generators(i).eng.phi0A = 0;
    generators(i).eng.V0A = generators(i).eng.vComp; 
    pCyl0 = p0_AR*(generators(i).eng.vDisp/generators(i).eng.vComp)^1.4;
    generators(i).eng.m0A = 0.8*p0_AR*generators(i).eng.vDisp/(R_AR*300);
    TCyl0 = pCyl0*generators(i).eng.vComp/(generators(i).eng.m0A*R_AR)*0.8;
    [R_pipe,~,~,uCyl,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pCyl0,TCyl0,0);
    generators(i).eng.E0A = generators(i).eng.m0A*uCyl;
    generators(i).eng.mb0A = 0;
end


%% Governor parameters
% PID gains
Kp = 20*ones(engines,1); %
Ki = 20*ones(engines,1); %
Kd = 20*ones(engines,1); %
% Dirty derivative gain
N = .1*ones(engines,1);  %
% Droop value
Droop = .02*ones(engines,1); %
% No-load frequency [pu]
wNL0 =  1./(1-Droop*.5);
% Maximum fuel rate [pu]
uMax = 1.5*ones(engines,1); %
% Minimum fuel rate [pu]
uMin = 0*ones(engines,1); %
% Maximum value for power available signal [pu]
pMax = 1.1*ones(engines,1);
% Back-calculation gain
Kb = 1*ones(engines,1);%

for i = 1:engines;
    generators(i).governor.Kp       = 20;     % PID Gains
    generators(i).governor.Ki       = 20;     % PID Gains
    generators(i).governor.Kd       = 20;     % PID Gains
    generators(i).governor.N        = .1;     % Dirty derivative gain
    generators(i).governor.droop    = 0.02;    % Governor droop value
    generators(i).governor.Kb       = 1;      % Back-calculation gain
    generators(i).u_min             = 0;      % Minimum fuel rate [pu]
    generators(i).u_max             = 1.5;    % Maximum fuel rate [pu]
    generators(i).p_max             = 1.1;    % Maximum value for power available signal [p.u.]
    generators(i).governor.w_noload = 1/(1-generators(i).governor.droop*.5);    % No load frequency    
end

%% Air dynamics parameter
% Lower limit of air-to-fuel ratio for combustion
AFlow = 14*ones(engines,1);
% Lower limit of air-to-fuel ratio for full combustion
AFhigh = 23*ones(engines,1);
% Air-to-fuel ratio at rated values
AFn = 27*ones(engines,1);
% Minimum required air-to-fuel ratio (used to saturate fuel index)
AFhighc = 23*ones(engines,1);
ma0 = .2*ones(engines,1);
Tin = 7*ones(engines,1);

%E = findInitialE(generators,ConnectedGensets,VT0,p0,q0);
vNL0 = V_no_q*ones(engines,1); % No reactive load voltage
%% Automatic Voltage Regulator
for i = 1:engines;

    generators(i).avr.max_fv   = 20;      % Maximum field voltage
    generators(i).avr.min_fv   = 0.01;    % Minimum field voltage
    generators(i).avr.Kp       = 400;     % PI Gains
    generators(i).avr.Ki       = 100;     % PI Gains
    generators(i).avr.T        = 0.01;   % Low pass filter time constant for AVR
    generators(i).avr.droop    = AvrDroop;    % AVR Droop
%    generators(i).theta0       = angle(E(i));
end



% Sampling time of Thruster Allocation [s] or 0 for continous
TA_sampling_time = 1;

singularityAvoidanceCostGain = 5;
singularityAvoidanceCostSmoother = .0001;

% Sampling time of Power Management system [s] or 0 for continous
PMS_sampling_time = .1;
% Ramp time to upload load from zero to 100% load sharing
ramptimeUpload = 30;

%% Power Available
TLowPriorityLoadLPPowerAvailable = .1; % Time constant for Low Priority Power Available reduction
THighPriorityLoadLPPowerAvailable = .1; % Time constant for High Priority Power Available reduction
TDPLPPowerAvailable = .1; % Time constant for DP Power Available reduction
TThrusterFLR = .01*ones(nThrusters,1); % Time constant for DP Power Available reduction


%% Efficiency coefficients of generator sets [g/h]:
for i = 1:engines;
    % FC = dm0 + dm1*u + dm2*u^2
    generators(i).turbo.dm0   = 15.939/1000;    % zero order fuel consumption
    generators(i).turbo.dm1   = 155.79/1000;    % first order fuel consumption (FC/P)
    generators(i).turbo.dm2   = 25.497/1000;    % second order fuel consumption (FC/P^2)
    generators(i).turbo.FCmax = (generators(i).turbo.dm0+generators(i).turbo.dm1+generators(i).turbo.dm2)*1.5;
    
    % Fuel efficiency, frequency variations gain
    % FC = (...)*(FCdw2*(dw/dt)^2)
    generators(i).turbo.FCdw2 = 6.09*ones(engines,1);
    
    % Power variations
    % FC = (...)*(FCdp1*(dp/dt) + FCdp2*(dp/dt)^2)
    generators(i).turbo.FCdp1 = .5279;
    generators(i).turbo.FCdp2 = 10.471;
end




% Initial pressure in inlet manifold [p.u.]
% pin0 = 1*ones(engines,1);



for i = 1:engines;
% Initial speed of gensets [pu]    
    generators(i).omega0 = generators(i).governor.w_noload * (1-generators(i).governor.droop*p0);
% Initial value of fuel index for generator sets    
    generators(i).u0 = (p0+p0.^2*generators(i).r)./generators(i).omega0 + generators(i).D*generators(i).omega0;
    
%    generators(i).avr.v0 = abs(E(i))/generators(i).omega0;       % Initial voltage of AVR
    
end

%% Power Management System
% Time before FLR reacts
reactionTimePowerAvaialble = 1;
% Time from 0 to full load when ramping up load after load reduction
rampTimePowerAvaialble = 45;
% Time before FLR reacts
FlrRestoreTime = .2;
% Time from 0 to full load when ramping up load after fast load reduction
FlrRampTime = 5;

% Excess power available demand for DP in percentage of rated power of
% thrusters
powerDesiredDPBias = .05;

% Power available demand for DP in percentage of used power by thrusters
powerDesiredDPGain = 1.1;


if ~exist('xFinal','var')
    xFinal = [];
end