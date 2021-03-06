

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
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void dNOxMol_Outputs_wrapper(const real_T *p,
			const real_T *T,
			const real_T *F,
			const real_T *V,
			const real_T *NOMol,
			real_T *dNOMol,
			const real_T  *fs, const int_T  p_width0,
			const real_T  *T_L, const int_T  p_width1,
			const real_T  *T_H, const int_T  p_width2,
			const real_T  *FC, const int_T  p_width3,
			const real_T  *xAir, const int_T  p_width4)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
real_T R,h,s,u,RF,RP,RT,uF,uP,uT,sF,sP,sT,Cp,Cv,K;
real_T m, N[12], x[12], nMol, MW;
int_T i;

//Calculate the composition of the gas
GetCompCombGas(p[0],T[0],F[0],T_L[0],T_H[0],FC,xAir,x);

GetThdynCombGasZachV1(p[0],T[0],F[0],fs[0],&R,&h,&s,&u,&RF,&RP,&RT,
        &uF,&uP,&uT,&sF,&sP,&sT,&Cp,&Cv,&K);

m = p[0]*V[0] / (R*T[0]);
MW = 8314.4 / R; // in kg/kmol
nMol = m / MW;
for (i=0;i<12;i++){
    N[i] = x[i]*nMol;   //in kmol
}

dNOx(T[0], N, V[0], NOMol[0], dNOMol);
dNOMol[0] = dNOMol[0]*(V[0]); //in kmol

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
