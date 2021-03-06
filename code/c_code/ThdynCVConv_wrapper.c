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
  *   Created: Mon Sep  8 13:42:35 2014
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
void ThdynCVConv_Outputs_wrapper(real_T *p,
                          real_T *T,
                          real_T *F,
                          real_T *V ,
			   const real_T *xC,
                          const real_T  *fs)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
p[0] = xC[0];
T[0] = xC[1];
F[0] = xC[2];
V[0] = xC[3];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void ThdynCVConv_Derivatives_wrapper(const real_T *dm,
                          const real_T *dE,
                          const real_T *dmf,
                          const real_T *dV,
                          const real_T *p,
                          const real_T *T,
                          const real_T *F,
                          const real_T *V,
                          real_T *dx ,
                          real_T *xC, 
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T  *p0,  const int_T  p_width1,
                          const real_T  *T0,  const int_T  p_width2,
                          const real_T  *F0,  const int_T  p_width3,
                           const real_T *V0, const int_T  p_width4)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
real_T pTemp, TTemp, FTemp, dF, m, mf, ma, VTemp;
real_T D;
real_T R1, h1, s1, uu1, RF1, RP1, RT1, uF1, uP1, uT1, sF1, sP1, sT1, Cp1, Cv1, K1; 
real_T rho, rhoP, rhoT, rhoF, RtimesT, RtimesTSq;
real_T u1, u2, u3, u4;
real_T a11, a12, a13, a21, a22, a23, a33, a44;

pTemp = xC[0];
TTemp = xC[1];
FTemp = xC[2];
VTemp = xC[3];
GetThdynCombGasZachV1(pTemp, TTemp, FTemp, fs[0], &R1, &h1, &s1, &uu1, &RF1, &RP1, &RT1, 
        &uF1, &uP1, &uT1, &sF1, &sP1, &sT1,&Cp1, &Cv1, &K1);
RtimesT = R1*TTemp;
RtimesTSq = RtimesT*RtimesT;
rho = pTemp / RtimesT;
rhoP = (RtimesT - pTemp*RP1*TTemp)/RtimesTSq;
rhoT = (-pTemp*(RT1*TTemp + R1))/RtimesTSq;
rhoF = (-pTemp*(RF1*TTemp))/RtimesTSq;

m = pTemp*VTemp/(R1*TTemp);
mf = (FTemp*fs[0])/(1+FTemp*fs[0])*m;
ma = m - mf;
dF = (dmf[0]*m - dm[0]*mf)/(fs[0]*pow(ma,2));

u1 = dm[0]/m - dV[0]/VTemp;
u2 = (dE[0] - uu1*dm[0])/m;
u3 = dF;
u4 = dV[0];

D = -(rhoT*uP1 - rhoP*uT1)/rho;
a11 = uT1/D;     a12 = -rhoT/(rho*D);  a13 = (rhoT*uF1 - rhoF*uT1)/(rho*D);
a21 = -uP1/D;    a22 = rhoP/(rho*D);   a23 = -(rhoP*uF1 - rhoF*uP1)/(rho*D);
dx[0] = a11*u1 + a12*u2 + a13*u3;
dx[1] = a21*u1 + a22*u2 + a23*u3;
dx[2] = u3;
dx[3] = u4;
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}