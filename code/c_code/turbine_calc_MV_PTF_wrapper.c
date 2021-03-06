/*
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is a wrapper S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_wrapper_XXXXX_Changes_BEGIN 
  *            Your Changes go here
  *        %%%-SFUNWIZ_wrapper_XXXXXX_Changes_END
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder User's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *   Created: Thu Jun 19 00:37:34 2014
  */


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "GetThdynCombGasZachV1.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void turbine_calc_MV_PTF_Outputs_wrapper(const real_T *pu,
                          const real_T *Tu,
                          const real_T *Fu,
                          const real_T *pd,
                          const real_T *Td,
                          const real_T *Fd,
                          const real_T *omegat,
                          real_T *dmu,
                          real_T *deu,
                          real_T *dmbu,
                          real_T *dmd,
                          real_T *ded,
                          real_T *dmbd,
                          real_T *Tqt,
                          real_T *Td_calc,
                          real_T *eta_t  , 
                          const real_T  *fs, const int_T  p_width0, 
                          const real_T  *flow_coeff_turb, const int_T  p_width1, 
                          const real_T  *D_turb_wheel, const int_T  p_width2, 
                          const real_T  *Uc_opt, const int_T  p_width3, 
                          const real_T  *eta_turb_max, const int_T  p_width4, 
                          const real_T  *T_ref,  const int_T p_width5)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
// parameters
//	flow_coeff_turb[3] :  Flow coefficient for the flow model a*x^b+c
//	double *fs : stoichiometric fuel-air ratio 
//  double *D_turb_wheel
// variables
double er, Tdi;     // Expansion ratio, isentropic discharge temperature(K)
double Uc_nom;   // Normalized blade speed ratio, isentropic efficiency of turbine
double dhi, dh;     // Isentropic enthalpy change, actual enthalpy change  
double dmt_corr;    // Corrected mass flow(kg/s) 
double dmt, dmbt;   // Actual mass flow, burned fuel mass flow (kg/s)
double err_td, dtd; // Variables for calculating the discharge temperature

double hu,su,uu,Ru,RFu,Rpu,RTu,uFu,upu,uTu,sFu,spu,sTu,Cpu,Cvu,Ku;
double hdi,sdi,udi,Rdi,RFdi,Rpdi,RTdi,uFdi,updi,uTdi,sFdi,spdi,sTdi,Cpdi,Cvdi,Kdi;
double hd,hd_temp,sd,ud,RFd,Rd,Rpd,RTd,uFd,upd,uTd,sFd,spd,sTd,Cpd,Cvd,Kd;
                    // Thermodynamic properties of the upstream, downstream 
                    // at isentropic expansion and downstream gas.
const double pi = 3.14159265358979323846;

// Calculate the mass flow based on the flow model 
er = *pu / *pd;
dmt_corr = flow_coeff_turb[0]*pow(er,(flow_coeff_turb[1])) + flow_coeff_turb[2];
dmt = dmt_corr*er/sqrt(*Tu/ *T_ref);
dmbt = dmt*(*Fu)*(*fs)/(1+(*Fu)*(*fs));

// Calculate the discharge temperature at isentropic expansion
GetThdynCombGasZachV1(*pu,*Tu,*Fu,fs[0],&Ru,&hu,&su,&uu,&RFu,&Rpu,&RTu,&uFu,&upu,
                    &uTu,&sFu,&spu,&sTu,&Cpu,&Cvu,&Ku);
Tdi = *Tu*pow(er,((1-Ku)/Ku));

// Calculate the discharge enthalpy with the efficiency from the efficiency model
GetThdynCombGasZachV1(*pd,Tdi,*Fu,fs[0],&Rdi,&hdi,&sdi,&udi,&RFdi,&Rpdi,&RTdi,&uFdi,
                    &updi,&uTdi,&sFdi,&spdi,&sTdi,&Cpdi,&Cvdi,&Kdi);
dhi = hu - hdi;
Uc_nom = 0.5*(*D_turb_wheel)*(*omegat)/sqrt(2*dhi) / *Uc_opt;
*eta_t = *eta_turb_max*Uc_nom*(2 - Uc_nom);
dh = *eta_t*dhi;
hd = hu - dh;
	
// Assign outputs
*Tqt = dmt*dh / *omegat;
*dmu = dmt;
*deu = dmt*hu;
*dmbu = dmbt;
*dmd = dmt;
*ded = dmt*hd;
*dmbd = dmbt;
	
// Calculating the discharge temperature
*Td_calc = Tdi / *eta_t;
err_td = 1;
while (err_td > 0.001) {
    GetThdynCombGasZachV1(*pd,*Td_calc,*Fu,fs[0],&Rd,&hd_temp,&sd,&ud,&RFd,&Rpd,
                &RTd,&uFd,&upd,&uTd,&sFd,&spd,&sTd,&Cpd,&Cvd,&Kd);
    dtd = (hd_temp - hd)/(uTd + Rd);
    err_td = abs(dtd)/(*Td_calc);
    *Td_calc = *Td_calc - dtd;
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
