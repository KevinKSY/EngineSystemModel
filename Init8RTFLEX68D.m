addpath('E:\DBox\Dropbox\Study\D2V Project\Matlab\Turbocharger')
addpath('code');
addpath('data');

%% Model file name
mdl             = 'EngSimulation8RTFLEX68D_Test';

%% Environmental conditions
pAmb0            = 1e5;      % Ambient conditions
TAmb0            = 298.15;
FAmb             = 0;
pBack           = 1.02e5;
TCW0            = 300;

%% Simulation cases
runCaseNo = 1;

%% Parameters User Input
% * General
nStroke         = 2;        % Number of stroke of the engine 
nCyl            = 8;        % Number of cylinders 
RPMMax         = 95;       % Maximum engine speed [RPM]
fs              = 0.0683;   % Stoichiometric fuel-air ratio 
hn              = 42707000; % LHV of the fuel [J/kg]
Veps            = 19.2; 	% Compression ratio
powMax          = 25040e3;  % Power at MCR

% Engine cylinder 
% * Dimension
stroke            = 2.72;     % Length of stroke [m]
lambdaCrank     = 0.5056;   % Ratio of crank rod to conneting rod
B               = 0.68;     % Bore size [m]
%   Combustion 
mqfCycMax       = 9.5547e-2; % Maximum fuel injected per cycle [kg]
wiebePara       = [0.07;0.57;3.05;11;24;56.3;1.5;1;0.7];

                            % 3-Wiebe function coefficients
% * Intake port
nPort           = 28;       % No of ports
Y               = 0.16;		% Height of the ports [m]
X               = 0.07;		% Width of the ports [m]
r               = 0.035;    % Raidus of fillets of the port [m]
% * Parameters for purity calculation
kai             = 1.7;      % Shape factor for 'S-type' curve;
delta           = 2;        % Shape factor for 'S-type' curve;
% * Exhaust valve dimension
liftMax         = 0.17;     % Maximum lift of the valve [m]
Dv              = 0.425;    % Valve head diameter [m]
beta            = 0.75;     % Seat angle [rad]
w               = 0.021;    % Valve seat width [m]
Dp              = 0.383;    % Inner seat diameter
Ds              = 0.079;    % Stem diameter  
% * Exhaust valve profile
cAStartRef      = 104.8;    % Reference start CA for start of valve lift [deg]
dCALiftTopRef   = 63.5;     % Reference duration for lift up [deg]
load ExhVVProfileRTFLEX68D; % Valve profile arrays for lifting and closing
dCALiftUp       = cAVVUpRef(end) - cAVVUpRef(1);     
                            % Lift up duration (should be inline with the profile) [deg]
dCALiftDown     = cAVVDownRef(end) - cAVVDownRef(1);
                            % Lift down duration (should be inline with the profile) [deg]
exh_VV_start    = 1.2;      % Exhaust valve opening start (nomalized value)

% * Heat transfer at the cylinder walls
mCp             = 10000;    % Heat capacity of the cylinder (J/K)
cCylHT          = [5.3040e-4;-1.1493e0;8.3165e2;-1.9799e5];	
                            % Coefficients of the 3rd order polynomial
                            % model of heat rejection from the cylinder
cAlpha          = 1;        % Fitting coefficient for convective heat transfer coefficient

% # Turbocharger
% * General
jTC             = 2;        % Mass moment of inertia of the turbine [kgm2]
% * Turbine
flow_coeff_turb = [-1.585326540339;-4.823836967181;1.5853156139822]; 
                            % Coefficient for flow model 
eff_coeff       = [-1.0889528323728;0.91854258409396;-0.10659748546926; ...
                   0.21229452390244;-0.053186221596493;-0.005451194709834];
                            % Coefficient for efficiency model
% * Compressor        
nameFileSAEComp =  'SAE_map_comp_ABB_A175_L35_LLT.mat';
nameFileSAETurb =  'SAE_map_turb_ABB_A175_L35_LLT.mat';

% * Blower
effBlower = 0.8;
coeffBlowerFlow = [-193.24048255339;4.1357602501571;0.65950308947414];

% # Pipe and receiver
vPipe           = 1.15;     % Volume of pipe after compressor [m3]
vScav           = 15;       % Volume of scavenge receiver [m3]
vExh            = 15.6;     % Volume of exhaust receiver [m3]

% # Air Cooling
cdCool          = 0.8;		% Discharge coefficient of the charge air cooler
aAirPath        = 0.2627;   % Effective sectional area of air path
dmCW            = 46.944;	% Mass flow of coolant
coeffAHTTCW     = [1.3032;-156.657]; 
                            % Coefficient for effective heat transfer area
                            % w.r.t. coolant temperature (2x1)
cpCW            = 4185.5; 	% Heat capacity of coolant
dPipeCW         = 0.008;	% Diameter of the tube in the cooler

% # Propulsion system
jShaft          = 323000;   % Mass moment of inertia of the enging, propulsion shaft and propeller
coeffMechEff    = [0.135;0.155]; 
                            % Coefficient for the engine friction model
coeffProp       = [25.3685;0.534066;0.0317713];
                            % Coefficient for quadratic propeller model
                            
% # Engine controller
% * Speed controller
BWomegaE        = 0.66;        % Cutoff frequency for low pass filter [Hz]
KpSpeed         = 1.0;        % Proportional gain for controller
TdSpeed         = 2.5;        % Derivative time constant
TiSpeed         = 2.5;        % Integral gain for controller
KbSpeed         = 1;        % Back-calculation gain for anti-wind up 
NSpeed          = 1.0;      % Dirty derivative gain
uSpeedMin       = 0.1;      % Minimum output
uSpeedMax       = 1.1;      % Maximum output

% * Injection controller
deltaPCombRef   = 40;       % Reference pressure rise due to combustion [bar]
KpPhiInj        = 0.008;    % Proportional gain for injection control
TiPhiInj        = 0.66;     % Integral time constant [s]
phiInjMax       = 10;       % Maximum allowable injection timing [deg]
phiInjMin       = -8;        % Minimum allowable injection timing [deg]
phiInjRef       = [0.062957; -0.42114; -1.7037; -2.2529; -2.5997; -2.9539; ...
						-3.3680; -4.1241; -4.4972; -5.3514; -6.9719; ...
						-8.0000; -8.0000];
                    
% * Exhaust valve controller
KpEVC           = 0.002;    % Proportional gain
TiEVC           = 0.66;     % Integral time constant [s]
EVCMax          = 1.9;      % Maximum allowable duration of valve open
EVCMin          = 0.5;      % Minimum allowable duration of valve open 
EVORef          = [	1.3608; 1.3441;1.1429; 1.0445; 1.0701; ...
                    1.0422; 0.99251; 0.78144; 0.78227; 0.89018; ...
                    1.0227; 1.1185; 1.0580];                    
                            % Exhaust valve open duration for different
                            % load

% * Maximum cylinder pressure control
KpPMax          = 0.5;      % Proportional gain 
TiPMax          = 0.66;     % Integral time constant
pMaxMax         = 200;      % Maximum allowable maximum cylinder pressure [bar]
pMaxMin         = 60;       % Minimum allowable maximum cylinder pressure [bar]
BWPow           = 0.5;     % Cutoff frequency for LP filter for power output [Hz]
BWdmf           = 0.5;     % Cutoff frequency for LP filter for fuel flow [Hz]

% * Waste gate control          
wasteGateRatio  = 0.04;     % Ratio of the bypass flow (set point)
KpWG            = 0.1;      % Proportional gain for the controller
TiWG            = 1.0;      % Integral time constant for the controller
KbWG            = 0.1;      % Back calculation gain for anti-windup
wasteGateMax    = 10;       % Maximum output of the controller
wasteGateMin    = 0;        % Minimum output of the controller
BWdmExhBypass = 0.66;       % Cutoff frequency for LP filter for waste gate bypass flow [Hz]
BWdmExh = 0.66;           % Cutoff frequency for LP filter for exhaust flow [Hz]
upperOpenSPWG = 2.1e5;      % Upper threshold value of scavenge air pressure to open waste gate
lowerCloseSPWG = 1.9e5;     % Lower threshold value of scavenge air pressure to close waste gate

% * Blower control
blowerRunSPUpper = 210000;   % Upper threshold value of scavenge air pressure to turn off the blower
blowerRunSPLower = 190000;   % Lower threshold value of scavenge air pressure to turn on the blower 
tauBlower = 10;           % Time constant for blower starting / stop [s]
%% Parameters Calculation
%{
TC_exist = exist('TC','var');
if TC_exist ~= 1
    load(nameFileSAEComp);
    load(nameFileSAETurb);
    TC = turbocharger(SAE_map_comp,SAE_map_turb);
end;
%}
load comp_map.mat
npr = length(pr_rep);
nsp = length(n288_rep);
clear RPM_max_turb                     

%% Model input
% Run below for transient 
load TransientMeasurement
load TransientData
simin = simCase{runCaseNo}(:,1:6);

% Run below for steady state
%{
simin = 
%}
%% Performance reference data
TAmb            = 300;   % Ambient temperature [K]
TCW             = 302.15;
pAmb            = 1e5;
pBack           = 102942;
powLRef         = [1.1;1;0.9;0.85;0.80;0.75;0.70;0.65;0.60;0.50;0.40;0.30;0.25];
BSFCRef         = [175;174;167.7;165.7;164.9;164.5;163.9;161.7;162.2; ...
                   163.9;166.8;168.9;170];
RPMRef          = [98.1;95;91.7;90;88.2;86.3;84.4;82.3;80.1;75.4;70;63.6;59.8];               
pScavRef        = [4.81;4.5;4.13;3.92;4.09;3.91;3.64;3.35;3.10;2.63;2.18;]*1e5;
pExhRef         = [4.58;4.27;3.90;3.70;3.87;3.69;3.43;3.14;2.90;2.46;2.04;]*1e5;
TScavRef         = [308.95;308.15;307.15;306.55;306.85;306.35;305.75;305.05;304.45;303.55;302.85;0;0];
TExhRef         = [744.15;713.15;682.45;667.15;651.85;640.15;625.95;612.15;602.15;589.15;583.15;0;0];
RPMtRef         = [23826.948669101;23075.590456361;22179.969249561;21629.839035369;22051.753666653;21588.065947035;20858.386295708;20017.440934603;19230.714233523;17546.171007497;15505.129011985;0;0];
caseInit            = 5;

%% Initial conditions
% * User input
powL0            = powLRef(caseInit);      % Initial power [p.u.]
phi0            = [0.1;45.1;90.1;135.1;180.1;225.1;270.1;315.1];		
                            % Initial crank angle of cylinders [deg]
pScav0          = pScavRef(caseInit);   % Initial scavenge pressure [Pa]
pExh0           = pExhRef(caseInit);   % Initial exhaust receiver pressure [Pa]
pPipe0          = pScav0;   % Initial pipe pressure [Pa]
TScav0          = TScavRef(caseInit);      % Initial scavenge temperature [K]
TExh0           = TExhRef(caseInit);      % Initial exhaust temperature [K]
TPipe0          = 459;      % Initial pipe temperature [K]
FScav0          = 0;        % Initial scavenge fuel-air equivalent ratio
FExh0           = 0;      % Initial exhaust fuel-air equivalent ratio
FPipe0          = 0;        % Initial pipe fuel-air equivalent ratio
RPM0            = simin(1,2);     % Initial engine speed [RPM]
RPMT0           = RPMtRef(caseInit);    % Initial turbine speed [RPM]



% * Calculation of initial conditions
tq0 = simin(1,3);
uSpeed0         = RPM0 / RPMMax;         % Initial output for speed controller
phi0rad = phi0*pi/180;
a = stroke/2;
l = a/lambdaCrank;
xpSPO = stroke - Y;
cASPO = acos((2*a^2 + 2*a*l - 2*a*xpSPO - 2*l*xpSPO + ...
            xpSPO^2) / (2*a*(a+l-xpSPO)));
                            % Crank angle at scavenge port open [rad]
cASPC = 2*pi - cASPO;                            
cAEVO = cAStartRef*pi/180;  % Crank angle at exh V/V open [rad]
cAEVC = (cAStartRef + dCALiftUp + dCALiftTopRef + dCALiftDown)*pi/180; 
                            % Crank angle at valve close [rad]
vComp = pi*B^2/4.0*stroke/(Veps-1);
                            % Compression volume [m3]
vEVC = vComp + pi*B^2/4.0*(stroke/2.0*(1.0-cos(cAEVC) + ...
            1.0/lambdaCrank*(1.0-sqrt(1.0- ...
            lambdaCrank^2*sin(cAEVC)^2)))); 
                            % Volume at exh V/V cose [m3]
vCyl0 = vComp + pi*B^2/4.0*(stroke/2.0*(1.0-cos(phi0rad) + ...
        1.0/lambdaCrank*(1.0-sqrt(1.0 - lambdaCrank^2*sin(phi0rad).^2))));    
                            % Initial volume of cylinders [m3]

%{
for i=1:nCyl                % Initial cylinder pressure and temperature
    if (phi0rad(i) > cAEVC) || (phi0rad(i) < cASPO)
        pCyl0(i) = pScav0*(vEVC/vCyl0(i))^1.4;
    else if abs(pi - phi0rad(i)) < abs(pi - cASPO)
            pCyl0(i) = pExh0;
        else
            pCyl0(i) = pScav0;
        end;
    end;
    TCyl0(i) = TScav0*(pCyl0(i)/pScav0)^(1-1/1.4);
end;
%}
pCyl0 = [10920275.666137;1192580.0340861;315597.47970568;263000;263000;263000;316717.3365704;1203306.4880679];
TCyl0 = [880.22832180914;467.53136066293;319.78085507511;303.55;303.55;303.55;320.10464534987;468.72898656505];
FCyl0 = [0;0;0;0;0;0;0;0]; 

[R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pCyl0,TCyl0,FCyl0);                            
mCyl0 = pCyl0.*vCyl0 ./ (R.*TCyl0); % Initial cylinder mass
ECyl0 = mCyl0.*u;              % Initial internal energy of the 
mbCyl0 = mCyl0.*FCyl0 * fs./(1 + FCyl0*fs);

[R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pPipe0,TPipe0,FPipe0);                            
mPipe0 = pPipe0.*vPipe ./ (R.*TPipe0); % Initial cylinder mass
EPipe0 = mPipe0.*u;              % Initial internal energy of the 
mbPipe0 = mPipe0.*FPipe0 * fs./(1 + FPipe0*fs);

[R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pPipe0,TPipe0,FPipe0);                            
mPipe0 = pPipe0.*vPipe ./ (R.*TPipe0); % Initial cylinder mass
EPipe0 = mPipe0.*u;              % Initial internal energy of the 
mbPipe0 = mPipe0.*FPipe0 * fs./(1 + FPipe0*fs);

[R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pExh0,TExh0,FExh0);                            
mExh0 = pExh0.*vExh ./ (R.*TExh0); % Initial cylinder mass
EExh0 = mExh0.*u;              % Initial internal energy of the 
mbExh0 = mExh0.*FExh0 * fs./(1 + FExh0*fs);

[R,~,~,u,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(pScav0,TScav0,FScav0);                            
mScav0 = pScav0.*vScav ./ (R.*TScav0); % Initial cylinder mass
EScav0 = mScav0.*u;              % Initial internal energy of the 
mbScav0 = mScav0.*FScav0 * fs./(1 + FScav0*fs);



xFinal = [];
%{


	
// Scavenge Air Cooling
	real global Cd = 0.8;									//Discharge coefficient of the charge air cooler
	real global A_air_path = 0.262681982928477;		//Effective area of air passage
	real global dm_cw = 46.944444444444;			//mass flow of coolant
	real global coeff_T_cw_K[2] = [1.30322634194411;-156.656919311284]; //HT coefficient correction factor WRT T_cw
	real global Cp_cw = 4185.5; 							//Heat capacity of coolant
	real global D_cw_pipe = 0.008;							//Diameter of the tube in the cooler
	
// Pressure drop 
//	real global dm_exh_max = 52.750266666667;	
//	real global dm_air_max = 51.54;

// Thermo package
	string global dll_ICE = 'DLL_ICElib.dll';

// initial conditions
	real global p0[8] = [10920275.666137;1192580.0340861;315597.47970568;263000;263000;263000;316717.3365704;1203306.4880679];
	real global T0[8] = [880.22832180914;467.53136066293;319.78085507511;303.55;303.55;303.55;320.10464534987;468.72898656505];
	real global F0[8] = [0;0;0;0;0;0;0;0]; 

// Performance data
	real global PL[13] = [1.1;1.0;0.9;0.85;0.8;0.75;0.7;0.65;0.6;0.5;0.4;0.3;0.25];
	real global mqf_max = 
pfi0[ncyl] = [0.1;45.1;90.1;135.1;180.1;225.1;270.1;315.1];		//Initial crank angle of cylinders
%}