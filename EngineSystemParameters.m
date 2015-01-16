clear engCyl;
%% General
jShaft = 0;          %Mass moment of inertia of the engine shaft [kgm2]
eng.fs = 0;          %Fuel-air equivalent ratio
eng.hn = 42700000;   %Low heating value of the fuel (J/kg)
eng.coeffMechEff = []; %Coefficient for mechanical efficiency curvefitting (2x1)
omegaE0 = 0;         %Initial speed of the engine (rad/s)
eng.RPMMax = 0;      %Max. Rated RPM
%% Charge air cooler parameters
eng.cAC.Cd = 0;                 %Discharge coefficient of the cooler
eng.cAC.areaAirPath = 0;        %Effective area of the air path [m2]
eng.cAC.dmCW = 0;               %Cooling water flow [kg/s]
eng.cAC.coeffTCWK = 0;          %Coefficient for curvefitting 
                                %for cooling water temp. vs. effective heat
                                %exchange area [m2]
eng.cAC.CpCW = 0;               %Cooling water heat capacity [J/kgK]
eng.cAC.dCWPipe = 0;            %Coolant tube diameter [m]
%% Control volumes 
% (Should be defined for each control volume with a specific name replacing
% "CV")
eng.CV.m0 = 0;                  %Initial mass [kg]
eng.CV.E0 = 0;                  %Initial internal energy [J]
eng.CV.mb0 = 0;                 %Initial burned fuel mass [kg]
eng.CV.V = 0;                   %Volume

eng.CV.m0 = 0;                  %Initial mass [kg]
eng.CV.E0 = 0;                  %Initial internal energy [J]
eng.CV.mb0 = 0;                 %Initial burned fuel mass [kg]
eng.CV.V0 = 0;                  %Initial Volume
% In case using conventional methods
%eng.CV.p0 = 0;                  %Initial mass [kg]
%eng.CV.T0 = 0;                  %Initial internal energy [J]
%eng.CV.F0 = 0;                 %Initial burned fuel mass [kg]

%% Turbocharger parameters
% Compressor 
eng.turbo.comp.flowMap = [];    %Compressor map for corrected flow
eng.turbo.comp.effMap = [];     %Compressor map for efficiency
eng.turbo.comp.prRep = [];      %Pressure ratio array for look-up in 
                                %compressor map
eng.turbo.comp.n288Rep = [];    %Corrected speed array for look-up in 
                                %compressor map
eng.turbo.comp.npr = length(turbo.comp.prRep);
eng.turbo.comp.nsp = length(turbo.comp.n288Rep);
% Turbine for map unknown but performance known
eng.turbo.turb.flowCoeff = [];   %Turbine flow coefficient
eng.turbo.turb.effCoeff = [];    %Turbine efficiency coefficient
eng.turbo.jTC = 0;               %Rotor mass moment of inertia [kgm2]
% Turbine for only flow curve known of a single RPM but efficiency unknown
%eng.turbo.turb.flowCoeff = [];  %Flow coefficient for turbine model(Flow
%                                 vs. ER)
%eng.turbo.turb.dTurbWheel = 0;  %Diameter of the turbine wheel
%eng.turbo.turb.ucOpt = 0;       %Optimal blade speed ratio
%eng.turbo.turb.effMax = 0;      %Maximum isentropic efficiency
%eng.turbo.turb.tempRef = 0;     %Reference temperature for turbine flow
% Turbine for map known
%eng.turbo.turb.flowMap = [];    %Compressor map for corrected flow
%eng.turbo.turb.effMap = [];     %Compressor map for efficiency
%eng.turbo.turb.prRep = [];      %Pressure ratio array for look-up in compressor map
%eng.turbo.turb.n288Rep = [];    %Corrected speed array for look-up in compressor map
%eng.turbo.turb.npr = length(turbo.comp.prRep);
%eng.turbo.turb.nsp = length(turbo.comp.n288Rep);
%
%% Cylinder parameters
% General
eng.cyl.general.nStroke = 2;     %Number of stroke
eng.cyl.general.nCyl = 8;        %Number of cylinders
% Cylinder dimension
eng.cyl.dim.B = 0;            %Cylinder bore [m]
eng.cyl.dim.S = 0;            %Cylinder stroke [m]
eng.cyl.dim.lambda = 0;       %Ratio of length of crank rod to connecting rod 
% Scavenge port dimension
eng.cyl.scavPort.X = 0;          %Scavenge port width [m]
eng.cyl.scavPort.Y = 0;          %Scavenge port height [m]
eng.cyl.scavPort.r = 0;          %Radius of fillet of the opening [m]
eng.cyl.scavPort.nPort = 0;      %Number of scanvenge ports
% Exhaust valve dimenstion
eng.cyl.exhVVDim.liftMax = 0;    %Exhaust valve maximum lift [m]
eng.cyl.exhVVDim.Dv = 0;         %Exhaust valve head diameter [m]
eng.cyl.exhVVDim.beta = 0;       %Exhaust valve seat angle [rad]
eng.cyl.exhVVDim.w = 0;          %Exhaust valve seat width [m]
eng.cyl.exhVVDim.Dp = 0;         %Exhaust valve inner seat diameter [m]
eng.cyl.exhVVDim.Ds = 0;         %Exhaust valve stem diameter [m]
% Exhaust valve profile
eng.cyl.exhVVProf.cAVVUpRef = 0;  %Exhaust valve crank angle array for opening [deg]
eng.cyl.exhVVProf.cAVVDownRef = 0;   %Exhaust valve crank angle array for closing [deg]
eng.cyl.exhVVProf.liftUpRef = [];    %Exhaust normalized lift array for opening [0~1]
eng.cyl.exhVVProf.liftDownRef = [];  %Exhaust normalized lift array for closing [0~1]
eng.cyl.exhVVProf.cAStartRef = [];   %Nominal crank angle at start of valve lif [deg]
eng.cyl.exhVVProf.dCALiftUp = 0;     %Nominal duration of crank angle for valve opening [deg]
eng.cyl.exhVVProf.dCALiftDown = 0;   %Nominal duration of crank angle for valve closing [deg]
eng.cyl.exhVVProf.dCALiftTopRef = 0; %Nominal duration of crank angle for valve open [deg]
% Heat transfer
eng.cyl.HT.mCp = 0;              %Heat capacity of the cylinder [J/K]
eng.cyl.HT.cCylHT = 0;           %Polynomial coefficient for heat rejection model from the cylinder (4 x 1)
eng.cyl.HT.cAlpha = 0;           %Fitting coefficient for convective heat transfer coefficient
eng.cyl.HT.tempWall0 = 600;      %Initial wall temperature of the cylinder [K]
% Combustion
eng.cyl.comb.mqfCycMax = 0;      %Maximum fuel mass injected per cycle [kg]
eng.cyl.comb.wiebePara = [];      %3-Wiebe Parameters (9x1)        
% Initial conditions (Common for all cylinders)
eng.cyl.init.phi0rad = [];       %Initial crank angle array [deg]
eng.cyl.init.mCyl0 = 0;          %Initial mass array [kg]    
eng.cyl.init.ECyl0 = 0;          %Initial internal energy array [J]
eng.cyl.init.mbCyl0 = 0;         %Initial burned fuel mass array [kg]
eng.cyl.init.vCyl0 = 0;          %Initial volume array [m3]


