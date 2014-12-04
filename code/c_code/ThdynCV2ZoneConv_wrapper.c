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
  *   Created: Sun Oct  5 23:33:58 2014
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
#define u_width 3
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
extern void GetThdynCombGasZach(real_T P, real_T T, real_T F, real_T *R, real_T *h,
  real_T *s, real_T *u, real_T *RF, real_T *RP, real_T *RT, real_T *uF, real_T
  *uP, real_T *uT, real_T *Cp, real_T *Cv, real_T *K);
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void ThdynCV2ZoneConv_Outputs_wrapper(const real_T *dmEmb,
                          const real_T *dV,
                          const real_T *dmfb,
                          const real_T *FComb,
                          const real_T *dQCyl,
                          const real_T *omega,
                          const real_T *phi,
                          real_T *p,
                          real_T *Tu,
                          real_T *Fu,
                          real_T *Vu,
                          real_T *Tb,
                          real_T *Fb,
                          real_T *Vb ,
			   const real_T *xC,
                          const real_T  *fs, const int_T  p_width0, 
                          const real_T  *uBR, const int_T  p_width1, 
                          const real_T  *DPhiMix, const int_T  p_width2, 
                          const real_T  *phiMix0, const int_T  p_width3, 
                          const real_T  *alpha, const int_T  p_width4, 
                          const real_T  *hn, const int_T  p_width5, 
                          const real_T  *p0, const int_T  p_width6, 
                          const real_T  *T0, const int_T  p_width7, 
                          const real_T  *F0, const int_T  p_width8, 
                          const real_T  *V0, const int_T p_width9)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
p[0] = xC[0];
Tu[0] = xC[1];
Fu[0] = xC[7] / ((xC[5] - xC[7])*fs[0]);
Vu[0] = xC[2];
Tb[0] = xC[3];
Fb[0] = xC[8] / ((xC[6] - xC[8])*fs[0]);
Vb[0] = xC[4];

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void ThdynCV2ZoneConv_Derivatives_wrapper(const real_T *dmEmb,
                          const real_T *dV,
                          const real_T *dmfb,
                          const real_T *FComb,
                          const real_T *dQCyl,
                          const real_T *omega,
                          const real_T *phi,
                          const real_T *p,
                          const real_T *Tu,
                          const real_T *Fu,
                          const real_T *Vu,
                          const real_T *Tb,
                          const real_T *Fb,
                          const real_T *Vb,
                          real_T *dx ,
                          real_T *xC, 
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T  *uBR,  const int_T  p_width1,
                          const real_T  *DPhiMix,  const int_T  p_width2,
                          const real_T  *phiMix0,  const int_T  p_width3,
                          const real_T  *alpha,  const int_T  p_width4,
                          const real_T  *hn,  const int_T  p_width5,
                          const real_T  *p0,  const int_T  p_width6,
                          const real_T  *T0,  const int_T  p_width7,
                          const real_T  *F0,  const int_T  p_width8,
                           const real_T *V0, const int_T  p_width9)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
double Ffs;
double q, y;
double dmMix;
const double mb0 = 1;
const double Fb0 = 1;
double Ru,hu,su,uu,RFu,RPu,RTu,uFu,uPu,uTu,Cpu,Cvu,Ku;
double Rb,hb,sb,ub,RFb,RPb,RTb,uFb,uPb,uTb,Cpb,Cvb,Kb;
double pTemp, TuTemp, FuTemp, VuTemp, TbTemp, FbTemp, VbTemp;
double muTemp, mbTemp, mubTemp, mbbTemp;
double dmu, dmb, dmub, dmbb, dFu, dFb;
double dHu, dHb, dQu, dQb;
double a11, a12, a13, a21, a22, a23, a31, a34, a35, a41, a44, a45, a53, a55;
double u1, u2, u3, u4, u5;

pTemp = xC[0];
TuTemp = xC[1];    VuTemp = xC[2];
TbTemp = xC[3];    VbTemp = xC[4]; 
muTemp = xC[5];    mbTemp = xC[6];
mubTemp = xC[7];   mbbTemp = xC[8];

// Calculate the the mix rate
q = (phi[0] - phiMix0[0]) / DPhiMix[0];
if (q < 0)
{
    q = 0;
}
else
{
    if (q > 1)
    {
        q = 1;
    }
}
dmMix = alpha[0]*mb0*6*q*(q-1)*omega[0]*DPhiMix[0];

// Calculate the fuel equivalent ratio and its derivative
FuTemp = mubTemp / ((muTemp - mubTemp)*fs[0]);
FbTemp = mbbTemp / ((mbTemp - mbbTemp)*fs[0]);
Ffs = FComb[0]*fs[0];
dmu = dmEmb[0] - (1+Ffs)/Ffs*dmfb[0] + dmMix;
dmub = dmEmb[2] - dmfb[0] + dmMix*(Fb0*fs[0]/(1+Fb0*fs[0]));
dmb = (1+Ffs)/Ffs*dmfb[0] - dmMix;
dmbb = dmfb[0] - dmMix*(Fb0*fs[0]/(1+Fb0*fs[0]));
dFu = (dmub*muTemp - dmu*mubTemp)/(fs[0]*(muTemp - mubTemp)*(muTemp - mubTemp));
dFb = (dmbb*mbTemp - dmb*mbbTemp)/(fs[0]*(mbTemp - mbbTemp)*(mbTemp - mbbTemp));

// Calculate the thermal dynamic properties of the zones
GetThdynCombGasZach(pTemp,TuTemp,FuTemp,&Ru,&hu,&su,&uu,&RFu,&RPu,&RTu,&uFu,&uPu,&uTu,
        &Cpu,&Cvu,&Ku);
GetThdynCombGasZach(pTemp,TbTemp,FbTemp,&Rb,&hb,&sb,&ub,&RFb,&RPb,&RTb,&uFb,&uPb,&uTb,
        &Cpb,&Cvb,&Kb);

// Calculate the enthalpy flow rate
dHu = dmEmb[1] - (1/Ffs*hu + hn[0])*dmfb[0] + dmMix*ub;
dHb = (1/Ffs*hu + hn[0])*dmfb[0] - dmMix*ub;

// Calculate the cylinder heat transfer
dQu = dQCyl[0]*TuTemp*muTemp / (TuTemp*muTemp + TbTemp*mbTemp);
dQb = dQCyl[0] - dQu;



a11 = 1/pTemp - 1/Ru*RPu;   a12 = -1/TuTemp - 1/Ru*RTu;     a13 = 1/VuTemp;
a21 = muTemp*uPu;           a22 = muTemp*uTu;               a23 = pTemp;
a31 = 1/pTemp - 1/Ru*RPu;   a34 = -1/TbTemp - 1/Rb*RTb;     a35 = 1/VbTemp;
a41 = mbTemp*uPb;           a44 = mbTemp*uTb;               a45 = pTemp;
a53 = 1;                a55 = 1;

u1 = 1/Ru*RFu*dFu + dmu/muTemp;
u2 = dQu + dHu - muTemp*uFu*dFu - uu*dmu;
u3 = 1/Rb*RFb*dFb + dmb/mbTemp;
u4 = dQb + dHb - mbTemp*uFb*dFb - ub*dmb;
u5 = dV[0];

dx[0] = a22 * (a34 * a45 - a35 * a44) * u1 - (a34 * a45 - a35 * a44) * a12 * u2 + a44 * (a12 * a23 - a13 * a22) * u3 - a34 * (a12 * a23 - a13 * a22) * u4 + (a34 * a45 - a35 * a44) * (a12 * a23 - a13 * a22) * u5;
dx[1] = (-a21 * a34 * a45 + a21 * a35 * a44 + a23 * a31 * a44 - a23 * a34 * a41) * u1 + (a11 * a34 * a45 - a11 * a35 * a44 - a13 * a31 * a44 + a13 * a34 * a41) * u2 - (a23 * a11 - a21 * a13) * a44 * u3 + (a23 * a11 - a21 * a13) * a34 * u4 - (a23 * a11 - a21 * a13) * (a34 * a45 - a35 * a44) * u5;
dx[2] = -a22 * (a44 * a31 - a41 * a34) * u1 + a12 * (a44 * a31 - a41 * a34) * u2 + a44 * (a22 * a11 - a21 * a12) * u3 - (a22 * a11 - a21 * a12) * a34 * u4 + (a22 * a11 - a21 * a12) * (a34 * a45 - a35 * a44) * u5;
dx[3] = -(a45 * a31 - a41 * a35) * a22 * u1 + (a45 * a31 - a41 * a35) * a12 * u2 + (a11 * a22 * a45 - a12 * a21 * a45 - a12 * a23 * a41 + a13 * a22 * a41) * u3 + (-a11 * a22 * a35 + a12 * a21 * a35 + a12 * a23 * a31 - a13 * a22 * a31) * u4 - (a45 * a31 - a41 * a35) * (a12 * a23 - a13 * a22) * u5;
dx[4] = a22 * (a44 * a31 - a41 * a34) * u1 - a12 * (a44 * a31 - a41 * a34) * u2 - a44 * (a22 * a11 - a21 * a12) * u3 + (a22 * a11 - a21 * a12) * a34 * u4 + (a12 * a23 - a13 * a22) * (a44 * a31 - a41 * a34) * u5;
dx[5] = dmu;
dx[6] = dmb;
dx[7] = dmub;
dx[8] = dmbb;

/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}