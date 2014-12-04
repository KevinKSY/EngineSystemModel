% Initialize parameters and initial conditions for the simulation of
% 'TCDieselEngine_MV_Model.mdl'

clc;

addpath('E:\DBox\Dropbox\Study\D2V Project\Matlab\ThermoDynCalc\')

%% Engine Parameters (Scania Engine D11 02)
S = 0.14;   %stroke
B = 0.127;  %Bore
L = 0.51;   %length of connecting rod
%alam = S/2/L;
nstroke = 4; %Number of stroke
nCyl = 6;
Vd = nCyl * pi*0.25*B^2 * S;  %Total discplacement volume
comp_ratio = 14; %Compression ratio
Vc = Vd / (comp_ratio - 1);
RPM = 1500;   %Engine speed (ref)
omega_eng_nom = RPM*pi/30;
Pe_nom = 280e3; %Nominal power 
Tq_nom = Pe_nom/omega_eng_nom;
clear S B L comp_ratio Vc RPM nCyl

% fit SFOC vs. Pe_norm curve
Pe_test = [60,62.2222222222222,64.4444444444444,66.6666666666667,68.8888888888889,71.1111111111111,73.3333333333333,75.5555555555556,77.7777777777778,80,82.2222222222222,84.4444444444444,86.6666666666667,88.8888888888889,91.1111111111111,93.3333333333333,95.5555555555556,97.7777777777778,100,102.222222222222,104.444444444444,106.666666666667,108.888888888889,111.111111111111,113.333333333333,115.555555555556,117.777777777778,120,122.222222222222,124.444444444444,126.666666666667,128.888888888889,131.111111111111,133.333333333333,135.555555555556,137.777777777778,140,142.222222222222,144.444444444444,146.666666666667,148.888888888889,151.111111111111,153.333333333333,155.555555555556,157.777777777778,160,162.222222222222,164.444444444444,166.666666666667,168.888888888889,171.111111111111,173.333333333333,175.555555555556,177.777777777778,180,182.222222222222,184.444444444444,186.666666666667,188.888888888889,191.111111111111,193.333333333333,195.555555555556,197.777777777778,200,202.222222222222,204.444444444444,206.666666666667,208.888888888889,211.111111111111,213.333333333333,215.555555555556,217.777777777778,220,222.222222222222,224.444444444444,226.666666666667,228.888888888889,231.111111111111,233.333333333333,235.555555555556,237.777777777778,240,242.222222222222,244.444444444444,246.666666666667,248.888888888889,251.111111111111,253.333333333333,255.555555555556,257.777777777778,260];
SFOC_test = [NaN;NaN;NaN;NaN;NaN;NaN;NaN;NaN;NaN;NaN;NaN;NaN;215.266632305393;214.537136802852;213.879644549839;213.214751200147;212.575334805045;211.996685002392;211.509803668002;211.050771407560;210.604707603466;210.172614134935;209.755072331306;209.352341188957;208.964419067050;208.591079532870;208.231887019915;207.886194480829;207.553122263623;207.231514213512;206.919862574232;206.621781977223;206.342695856344;206.079473329922;205.829603393997;205.591150480287;205.362650842088;205.143039145164;204.931597979123;204.727925582682;204.531918922403;204.343770690822;204.163980014925;203.993377865813;203.833169506519;203.684998010598;203.551035210910;203.434109826947;203.331543691126;203.221856360944;203.106955004690;202.990329089046;202.874426156251;202.760872066675;202.650607966410;202.543966009598;202.440695174663;202.339940677142;202.240173456849;202.139058251354;202.033237737247;201.923934573245;201.823260942069;201.732824824572;201.653940409369;201.588214661844;201.537587262476;201.504411515960;201.491588933079;201.502783606047;201.542764941103;201.610055808414;201.676125382078;201.740045383231;201.804158372054;201.870351947348;201.940173403709;202.014904236268;202.095607101178;202.183152316793;202.278227331232;202.381329700770;202.492741213417;202.550101279954;NaN;NaN;NaN;NaN;NaN;NaN;NaN];
idx = find(SFOC_test > 0);
SFOC_test_fit = SFOC_test(idx);
Pe_test_fit = Pe_test(idx)*1e3/Pe_nom;
SFOC_fit = fit(Pe_test_fit',SFOC_test_fit,'poly2');
plot(Pe_test_fit',SFOC_test_fit);
hold on
plot(SFOC_fit);
SFC = coeffvalues(SFOC_fit);
m_f_cyc_max = Pe_nom*SFOC_fit(1)/3.6e9*pi*nstroke/omega_eng_nom;
clear Pe_test SFOC_test idx SFOC_test_fit Pe_test_fit SFOC_fit

LHV = 42.7e6; % LHV of fuel in J/kg
C1 = 0.15; %Heat loss coefficient
%eta_m = 0.95; %Mechanical efficiency
fs = 0.0682925799314788; %For fuel of C1H1.816 

%Volumetric efficiency
p_a_inf = 1.925; % the point of change in fit curve for vol. eff (use 0.65 as default)
vol_eff_coeff2 = [-0.261226296116146,0.960147637763599,-0.044560143433303]; % polynomial coeff for vol eff curve vs. inlet pressure
vol_eff_coeff1 = [0.068081887046403,-0.441624318651670,1.433550808813938]; %% if not sure put [0, 0, 0.8]

%J_eng = 1.5*3; %moment of inertia including flywheel

T_pe = 0.01; %Time constant for Pe used for fuel index
P0 = Load_bias;      %Initial Pe used for fuel index

% Engine governor
droop = 0.02;
F_max = 0.75;
wNL = 1/(1-droop*.5);
Kp = 10;
Ki = 10;
Kd = 10;
NN = .1;
uMax = 1.1;
uMin = 0.1;
Kb = 1;
u0 = 0.2;

%% Subsystem parameters
% Turbocharger
TC_exist = exist('TC','var');
if TC_exist ~= 1
    load SAE_map_comp_Garrett_3788R
    load SAE_map_turb_Garrett_3788R2

    TC = turbocharger(SAE_map_comp,SAE_map_turb);
    load comp_map.mat
    
    %pr_max_turb = max(TC.TC_map.comp.PR;
    RPM_max_turb = max(TC.TC_map.comp.RPM);
    omega_TC_nom = RPM_max_turb*pi/30; 
%    Tq_mech_loss_nom = 0;
    J_tc = TC.SAE_map_comp.inertia;
    
    Uc_opt = TC.TC_map.turb.Uc_opt;
    flow_coeff_turb = TC.TC_map.turb.flow_fit_coeff;
    eta_turb_max = TC.TC_map.turb.eff_max;
    D_turb_wheel = TC.TC_map.turb.D_wheel;
    T_ref_turb = TC.TC_map.turb.T_ref;
end;
load comp_map.mat
npr = length(pr_rep);
nsp = length(n288_rep);
clear RPM_max_turb
%%
% Charge Air Cooler
load('CoolerPerf_ScaniaD1102.mat')
% Coolant
dm_cw = 0.92; % in kg/s
T_cw = 298.15; % in K
Cp_cw = 4185.5; %Heat capacity of water in J/kgK
V_air_cooler = 10*sqrt(A_air_path)^3;
% Pipe and Receivers
V_pipe = 0.004;
V_AR = 0.01;
V_ER = 0.01;

clear K_f_cool
%% Environment
p_amb = 1e5;
T_amb = 298;
F_amb = 0;
p_back = 1.01e5;
%% Initialization
load initial_condition_SCANIA;
% Thermodynamic Control Volumes (pipe, receivers)
p_ac_init = interp1(PL,p_ac_init,Load_bias)*1e5;
p_exh_init = interp1(PL,p_exh_init,Load_bias)*1e5;
F_initial = interp1(PL,F_initial,Load_bias);
RPM_TC_initial = interp1(PL,RPM_TC_initial,Load_bias);
m_dot_TC = TC.GetFlowComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5);
T_bcool = TC.GetToutComp_RPM_PR(RPM_TC_initial,p_ac_init/1e5,T_amb);

p_acool = p_ac_init;
T_acool = T_bcool + 0.9*(T_cw - T_bcool);
%%
T_mean = 0.5*(T_bcool + T_acool);
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
%p_drop = p_bcool - p_acool;
%rho_cool = 0.5*(p_acool + p_bcool) / R / T_mean;
%v_CAC_init = m_dot_cool_init / rho_cool / A_air_path;

%%
p0_pipe = p_bcool;
p0_AR = p_acool;
p0_ER = p_exh_init;
%p_air_cooler_init = 2e5;
T0_pipe = T_bcool;
T0_AR = T_acool;
T0_ER = 800;
F0_ER = F_initial;
%T_air_cooler_init = 320;


[R_pipe,~,~,u_pipe,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_pipe,T0_pipe,0);
[R_AR,~,~,u_AR,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_AR,T0_AR,0);
[R_ER,~,~,u_ER,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p0_ER,T0_ER,F0_ER);
%[R_air_cooler,~,~,u_air_cooler,~,~,~,~,~,~,~,~,~] = GetThdynCombGasZach(p_air_cooler_init,T_air_cooler_init,0);

rho_pipe = p0_pipe/R_pipe/T0_pipe;
m0_pipe = rho_pipe*V_pipe;
E0_pipe = m0_pipe*u_pipe;
mb0_pipe = 0;

rho_AR = p0_AR/R_AR/T0_AR;
m0_AR = rho_AR*V_AR;
E0_AR = m0_AR*u_AR;
mb0_AR = 0;

rho_ER = p0_ER/R_ER/T0_ER;
m0_ER = rho_ER*V_ER;
mb0_ER = F0_ER*fs/(1+F0_ER*fs)*m0_ER;
E0_ER = m0_ER*u_ER;

%rho_air_cooler = p_air_cooler_init/R_air_cooler/T_air_cooler_init;
%m_air_cooler_init = rho_air_cooler*V_air_cooler;
%E_air_cooler_init = m_air_cooler_init*u_air_cooler;


% Initial flow of CAC

% Mechanical
%RPM_eng_init = 1500;
%H_eng_init = RPM_eng_init*pi/30*J_eng; %Angular momentum of the engine

omegat0 = RPM_TC_initial/30*pi;

clear p_ac_init p_exh_init RPM_TC_initial F_initial PL m_dot_TC T_bcool
clear T_acool p_acool p_bcool T_mean m_dot_cool_init R k err_p_bcool 
clear err_m_dot dm_dotdp2 dp_bcool_temp 
clear R_pipe u_pipe R_AR u_AR R_ER u_ER

%% Compressor plot



