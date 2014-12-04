%busSpec
%load MDGmodels/rig
%addpath('TA_aleksander')
% number of gensets
%engines = 6;
% number of thrusters
%nThrusters = 6;
%{
% Prefix for log files
savename = 'log';

%% Switchboard parameters
% number of switchboards
nSwitchboard = 3;


% Water density
rho = 1025;

% Generator sets connected
ConnectedGensets = [1 1 1 1 1 1].';

%% Loads
% Static load which should not be reduced, in Watt
PowerHighPriority = 1e5*ones(nSwitchboard,1);
% Static load which will be reduced if the available power is too low
PowerLowPriority = PowerHighPriority;
% Current speed in m/s
u_c = [-1;
    0;
    0];
% Wind force in Newton
%windForce = D([1 2 6],[1 2 6])*u_c*1;

%% DP parameters
% reference position
x_ref = [0; 0; 0];
% PID gains in controller
w0Control = diag(1/30*[1 1 1]); % Eigenfrequency of DP
XiControl = diag([1 1 1]);      % Relativ damping of DP
dim = [1 2 6];                  % Dimmensions of interest
%M = MRB(dim,dim)+MA(dim,dim);   % Total mass
Pcontrol = w0Control.^2*M;      % P-gain in DP
Dcontrol = (2*XiControl*w0Control*M-D(dim,dim)); % D-gain in DP
Icontrol = Pcontrol*1/300;      % I-gain in DP
% Initial value of I-term in PID
Thrust0 = -D([1 2 6],[1 2 6])*u_c-windForce;

%}

%% Generator sets parameter

% % Fuel index to torque gain
% ku = 1+Dfw+r;
%for i = 1:engines;
    genset.ID  = i;          % Generator ID
    genset.Sb  = 9.1e6;      % Rated value of generator
    genset.w_b = 60*2*pi;    % Rated speed of generator
    genset.r   = 0.0025;     % Stator resistance [p.u.]
    genset.xs  = 1.5;        % Synchronous reactance [p.u.]
    genset.H   = 2;          % Intertia time constant [seconds]
    genset.D   = 0.025;      % Damping [p.u.]
%end

%% Governor parameters
% PID gains
Kp = 20; %
Ki = 20; %
Kd = 20; %
% Dirty derivative gain
N = .1;  %
% Droop value
Droop = .02; %
% No-load frequency [pu]
wNL0 =  1./(1-Droop*.5);
% Maximum fuel rate [pu]
uMax = 1.1; %
% Minimum fuel rate [pu]
uMin = 0.1; %
% Maximum value for power available signal [pu]
pMax = 1.1;
% Back-calculation gain
Kb = 1;%

%for i = 1:engines;
    genset.governor.Kp       = 20;     % PID Gains
    genset.governor.Ki       = 20;     % PID Gains
    genset.governor.Kd       = 20;     % PID Gains
    genset.governor.N        = .1;     % Dirty derivative gain
    genset.governor.droop    = 0.02;    % Governor droop value
    genset.governor.Kb       = 1;      % Back-calculation gain
    genset.u_min             = 0.1;      % Minimum fuel rate [pu]
    genset.u_max             = 1.1;    % Maximum fuel rate [pu]
    genset.p_max             = 1.1;    % Maximum value for power available signal [p.u.]
    genset.governor.w_noload = 1/(1-genset.governor.droop*.5);    % No load frequency    
%end

%% Air dynamics parameter

% Lower limit of air-to-fuel ratio for combustion
AFlow = 14;
% Lower limit of air-to-fuel ratio for full combustion
AFhigh = 23;
% Air-to-fuel ratio at rated values
AFn = 27;
% Minimum required air-to-fuel ratio (used to saturate fuel index)
AFhighc = 23;
ma0 = .2;
Tin = 7;

%% Automatic Voltage Regulator
%{
for i = 1:engines;
    genset.avr.v0       = 1;       % Initial voltage of AVR
    genset.avr.max_fv   = 20;      % Maximum field voltage
    genset.avr.min_fv   = 0.01;    % Minimum field voltage
    genset.avr.Kp       = 400;     % PI Gains
    genset.avr.Ki       = 100;     % PI Gains
    genset.avr.T        = 0.001;   % Low pass filter time constant for AVR
    genset.avr.v_noload = 1;       % Voltage at no reactive load
    genset.avr.droop    = 0.05;    % AVR Droop
end
%}
%% Low pass filter for switchboard
%{
TV0 = 0.001; % Time constant for low pass filter for calculation of bus voltage
VT0 = 1; % Initial voltage on bus

% Sampling time of Thruster Allocation [s] or 0 for continous
TA_sampling_time = 1;
%}



%% Power Available
%{
TLowPriorityLoadLPPowerAvailable = .1; % Time constant for Low Priority Power Available reduction
THighPriorityLoadLPPowerAvailable = .1; % Time constant for High Priority Power Available reduction
TDPLPPowerAvailable = .1; % Time constant for DP Power Available reduction
TThrusterFLR = .01*ones(nThrusters,1); % Time constant for DP Power Available reduction
%}

%% Efficiency coefficients of generator sets [g/h]:
%for i = 1:engines;
    % FC = dm0 + dm1*u + dm2*u^2
    genset.turbo.dm0   = 15.939/1000;    % zero order fuel consumption
    genset.turbo.dm1   = 155.79/1000;    % first order fuel consumption (FC/P)
    genset.turbo.dm2   = 25.497/1000;    % second order fuel consumption (FC/P^2)
    genset.turbo.FCmax = (genset.turbo.dm0+genset.turbo.dm1+genset.turbo.dm2)*1.5;
    
    % Fuel efficiency, frequency variations gain
    % FC = (...)*(FCdw2*(dw/dt)^2)
    genset.turbo.FCdw2 = 6.09;
    
    % Power variations
    % FC = (...)*(FCdp1*(dp/dt) + FCdp2*(dp/dt)^2)
    genset.turbo.FCdp1 = .5279;
    genset.turbo.FCdp2 = 10.471;
%end

%addpath('thruster');
%thrusters = thrusterInit(Thrust0);
%{
%% Initial values of electrical system
% Initial consumed power (not a parameter, only help variable)
% TODO: make it work when bus ties are opened
aux1 = 0;
aux2 = 0;
for i = 1:engines
    aux1 = aux1 + thrusters(i).motor.omega0*thrusters(i).motor.torque0;
    aux2 = aux2 + genset.Sb * ConnectedGensets(i);
end
aux3 = sum(PowerLowPriority+PowerHighPriority);
%}
clear aux1 aux2 aux3;

% Initial pressure in inlet manifold [p.u.]
% pin0 = 1*ones(engines,1);

%for i = 1:engines;
% Initial mechanical angle of gensets [rad]    
    genset.theta0 = 0;
% Initial speed of gensets [pu]    
    genset.omega0 = genset.governor.w_noload * (1-genset.governor.droop*P0);
% Initial value of fuel index for generator sets    
    genset.u0 = (P0+P0.^2*genset.r)./genset.omega0 + genset.D*genset.omega0;
    
    
%end

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
powerDesiredDPBias = .00;

% Power available demand for DP in percentage of used power by thrusters
powerDesiredDPGain = 1.1;
nr = 1;
AFlowcontrol=AFhighc;
