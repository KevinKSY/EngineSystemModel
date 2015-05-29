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
  *   Created: Thu Jun 19 02:01:51 2014
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
void turbine_calc_PTFV1_Outputs_wrapper(const real_T *pu,
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
                          real_T *eta_ic  , 
                          real_T *Td_calc, 
                          const real_T *flow_prev,
                          const real_T *eta_prev,
                          const real_T  *fs, const int_T  p_width0, 
                          const real_T  *turb_flow_map, const int_T  p_width1, 
                          const real_T  *turb_eff_map, const int_T  p_width2, 
                          const real_T  *pr_rep, const int_T  p_width3, 
                          const real_T  *n288_rep, const int_T  p_width4, 
                          const int32_T  *npr, const int_T  p_width5, 
                          const int32_T  *nsp,  const int_T p_width6)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
double n288, dn288_intv, dpr_intv, dmDot_intv,dz1, dz11, dz2, dz21, z1, 
        z11, z2, z21, dz_flow, dz_eff;
int i, j, istart, iend, jstart, jend;        
double dm_corr;
double pr, pic, Tdi, delhc;
double hu,su,uu,Ru,RFu,Rpu,RTu,uFu,upu,uTu,sFu,spu,sTu,Cpu,Cvu,Ku;
double hdi,sdi,udi,Rdi,RFdi,Rpdi,RTdi,uFdi,updi,uTdi,sFdi,spdi,sTdi,
        Cpdi,Cvdi,Kdi;
double hd,sd,ud,RFd,Rd,Rpd,RTd,uFd,upd,uTd,sFd,spd,sTd,Cpd,Cvd,Kd;
double dtd, err_td, hd_temp;
const double pi = 3.14159265358979323846;

bool first;


// Calculating the pressure ratio
pr = *pu / *pd;
if (pr < 1.000001) {
    pic = 1.000001;
}
else{
    pic = pr;
}
//pic = max(1.000001,pr);

//Find the corrected flow and efficiency from the turbine map table
n288 = *omegat*60/(2.0*pi)/sqrt(*Tu);
// interpolate in the 2D speed table to find the corresponding 
// corrected flow (dm_corr) and isentropic efficiency (eta_ic)
i = 1;
if ((n288 <= n288_rep[0]) || (n288 >= n288_rep[nsp[0] - 1]) || (pic <= pr_rep[0]) || (pic >= pr_rep[npr[0] - 1]))
{
	dmu[0] = 0;
	deu[0] = 0;
	dmbu[0] = 0;
	dmd[0] = 0;
	ded[0] = 0;
	dmbd[0] = 0;
	Tqt[0] = 0;
	eta_ic[0] = 0;
	Td_calc[0] = 0;
}
else
{ 
	while ((pr_rep[i] < pic) && (i < *npr))
	{
		i++;
	}
	istart = i - 1;
	iend = i;
	j = 1;
	while ((n288_rep[j] < n288) && (j < *nsp))
	{
		j++;
	}        
	jstart = j - 1;
	jend = j;
	dn288_intv = n288_rep[jend] - n288_rep[jstart];
	dpr_intv = pr_rep[iend] - pr_rep[istart];

	dz1 = turb_flow_map[iend+(*nsp)*jstart] - turb_flow_map[istart+(*nsp)*jstart];
	dz11 = turb_eff_map[iend+(*nsp)*jstart] - turb_eff_map[istart+(*nsp)*jstart];
	dz2 = turb_flow_map[iend+(*nsp)*jend] - turb_flow_map[istart+(*nsp)*jend];
	dz21 = turb_eff_map[iend+(*nsp)*jend] - turb_eff_map[istart+(*nsp)*jend];
	z1 = turb_flow_map[istart+(*nsp)*jstart] + (dz1/dpr_intv)*(pic- pr_rep[istart]);
	z11 = turb_eff_map[istart+(*nsp)*jstart] + (dz11/dpr_intv)*(pic- pr_rep[istart]);
	z2 = turb_flow_map[istart+(*nsp)*jend] + (dz2/dpr_intv)*(pic- pr_rep[istart]);
	z21 = turb_eff_map[istart+(*nsp)*jend] + (dz21/dpr_intv)*(pic- pr_rep[istart]);
	dz_flow = z2 - z1;
	dz_eff = z21 - z11;
	dm_corr = z1 + (dz_flow/dn288_intv)*(n288- n288_rep[jstart]);
	*eta_ic = z11 + (dz_eff/dn288_intv)*(n288- n288_rep[jstart]);

	//Calculate the thermodynamic property of the upstream gas
	GetThdynCombGasZachV1(*pu,*Tu,*Fu,fs[0],&Ru,&hu,&su,&uu,&RFu,&Rpu,&RTu,
			&uFu,&upu,&uTu,&sFu,&spu,&sTu,&Cpu,&Cvu,&Ku);

	//Calculate the temperature and thermodynamic property of the downstream 
	//gas with isentropic expansion
	Tdi = *Tu*pow(pic,((1-Ku)/(Ku)));
	GetThdynCombGasZachV1(*pd,Tdi,*Fu,fs[0],&Rdi,&hdi,&sdi,&udi,&RFdi,&Rpdi,
			&RTdi,&uFdi,&updi,&uTdi,&sFdi,&spdi,&sTdi,&Cpdi,&Cvdi,&Kdi);

	//Calculate the actual increase in enthalpy using isentropic efficiency
	if (*eta_ic < 0.5) {
		delhc = -(hu-hdi)*eta_prev[0];
		eta_ic[0] = 0.5;
	}
	else {
		delhc = -(hu-hdi)*eta_ic[0];
	}
	hd = hu+delhc;
	// Calculating the flows and the mechanical torque
	if (dm_corr == 0) {
		dmu[0] = flow_prev[0];
	}
	else {
		*dmu = dm_corr * (*pu/1e3) / sqrt(*Tu);
	}
	*deu = *dmu * hu;
	*dmbu = (*dmu) * (*Fu) * (*fs) / (1.0 + (*Fu) * (*fs));
	*dmd = *dmu;
	*ded = *dmu*(hd);
	*dmbd = *dmbu;
	*Tqt = -delhc* *dmu/(*omegat+1.0e-6);
	// Calculating the discharge temperature
	*Td_calc = Tdi / eta_ic[0];
	err_td = 1;
	while (err_td > 0.001) {
		GetThdynCombGasZachV1(*pd, *Td_calc, *Fu, fs[0], &Rd, &hd_temp, &sd, &ud, &RFd, &Rpd,
			&RTd, &uFd, &upd, &uTd, &sFd, &spd, &sTd, &Cpd, &Cvd, &Kd);
		dtd = (hd_temp - hd) / (uTd + Rd);
		err_td = abs(dtd) / (*Td_calc);
		*Td_calc = *Td_calc - dtd;
	}
	/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
	}
}
