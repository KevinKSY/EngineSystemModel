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
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void ThdynCV2ZoneConv_Outputs_wrapper(real_T *p,
                          real_T *Tu,
                          real_T *Fu,
                          real_T *Vu,
                          real_T *Tb,
                          real_T *Fb,
                          real_T *Vb,
                          const real_T *xC)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
p[0] = xC[0];
Tu[0] = xC[1];
Fu[0] = xC[2];
Vu[0] = xC[3];
Tb[0] = xC[4];
Fb[0] = xC[5];
Vb[0] = xC[6];

/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

void ThdynCV2ZoneConv_Update_wrapper(const real_T *FComb,
                          const real_T *combState,
                          const real_T *mqf0,
                          const real_T *xC,
                          real_T *mb0,
                          real_T *ResetMix,        
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T *alpha, const int_T p_widht3)
{
    real_T F_fs;
    real_T p, T1, F1, V1, T2, F2, V2;
    real_T R1, h1, s1, u1, RF, RP, RT, uF, uP, uT, sF, sP, sT, Cp, Cv, K;
    real_T R2, h2, s2, u2;
    real_T muTemp, mbTemp;
    
    if(combState[0] == 2 && ResetMix[0] == 0)
    {
        ResetMix[0] = 1;
    }
    if(combState[0] == 5 && ResetMix[0] == 1)
    {
        ResetMix[0] = 0;
        p = xC[0];
        T1 = xC[1];
        F1 = xC[2];
        V1 = xC[3];
        T2 = xC[4];
        F2 = xC[5];
        V2 = xC[6];
        GetThdynCombGasZachV1(p,T1,F1,fs[0],&R1,&h1,&s1,&u1,
            &RF,&RP,&RT,&uF,&uP,&uT,&sF,&sP,&sT,&Cp,&Cv,&K);            
        GetThdynCombGasZachV1(p,T2,F2,fs[0],&R2,&h2,&s2,&u2,
            &RF,&RP,&RT,&uF,&uP,&uT,&sF,&sP,&sT,&Cp,&Cv,&K);  
        muTemp = p*V1/(R1*T1);
        mbTemp = p*V2/(R2*T2);
        mb0[0] = mbTemp - alpha[0]*(muTemp + mbTemp);
    }
    
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
                          const real_T *combState,
                          const real_T *mqf0,
                          const real_T *p,
                          const real_T *Tu,
                          const real_T *Fu,
                          const real_T *Vu,
                          const real_T *Tb,
                          const real_T *Fb,
                          const real_T *Vb,
                          real_T *dx ,
                          real_T *xC, 
                          const real_T *mb0,
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T  *DPhiMix,  const int_T  p_width1,
                          const real_T  *phiMix0,  const int_T  p_width2,
                          const real_T  *alpha,  const int_T  p_width3,
                          const real_T  *hn,  const int_T  p_width4,
                          const real_T  *p0,  const int_T  p_width5,
                          const real_T  *T0,  const int_T  p_width6,
                          const real_T  *F0,  const int_T  p_width7,
                           const real_T *V0, const int_T  p_width8,
                          const real_T *nStroke, const int_T p_width9)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
double Ffs;
double q, y;
double dmMix, dmbMix;
double Ru,hu,su,uu,RF1,RP1,RT1,uF1,uP1,uT1,sF1,sP1,sT1,Cp1,Cv1,K1;
double Rb,hb,sb,ub,RF2,RP2,RT2,uF2,uP2,uT2,sF2,sP2,sT2,Cp2,Cv2,K2;
double pTemp, TuTemp, FuTemp, VuTemp, TbTemp, FbTemp, VbTemp;
double muTemp, mbTemp, mubTemp, mbbTemp;
double dmu, dmb, dmub, dmbb, dFu, dFb;
double dHu, dHb, dQu, dQb;
double rho1, rho2, rhoP1, rhoP2, rhoT1, rhoT2, rhoF1, rhoF2, V1, V2, m1, m2; 
double u1, u2, u3, u4, u5, u6, u7;
double detA, RtimesT, RtimesTSq;
double phiCyc;
double err1, err2, err3;
const double pi = 3.14159265359;

phiCyc = phi[0]*180.0/pi;
phiCyc = ((int)(floor(phiCyc)) % ((int)(nStroke[0]*180))) + phiCyc - floor(phiCyc);

pTemp = xC[0];
TuTemp = xC[1];    FuTemp = xC[2];
VuTemp = xC[3];    TbTemp = xC[4]; 
FbTemp = xC[5];    VbTemp = xC[6];

// Calculate the thermal dynamic properties of the zones
GetThdynCombGasZachV1(pTemp,TuTemp,FuTemp,fs[0],&Ru,&hu,&su,&uu,
        &RF1,&RP1,&RT1,&uF1,&uP1,&uT1,&sF1,&sP1,&sT1,
        &Cp1,&Cv1,&K1);
GetThdynCombGasZachV1(pTemp,TbTemp,FbTemp,fs[0],&Rb,&hb,&sb,&ub,
        &RF2,&RP2,&RT2,&uF2,&uP2,&uT2,&sF2,&sP2,&sT2,
        &Cp2,&Cv2,&K2);
muTemp = pTemp*VuTemp/(Ru*TuTemp);

mbTemp = pTemp*VbTemp/(Rb*TbTemp);
mubTemp = muTemp*FuTemp*fs[0]/(1+FuTemp*fs[0]);
mbbTemp = mbTemp*FbTemp*fs[0]/(1+FbTemp*fs[0]);
rho1 = muTemp / VuTemp;
rho2 = mbTemp / VbTemp;
RtimesT = Ru*TuTemp;
RtimesTSq = RtimesT*RtimesT;
rhoP1 = (RtimesT - pTemp*RP1*TuTemp)/RtimesTSq;
rhoT1 = (-pTemp*(RT1*TuTemp + Ru))/RtimesTSq;
rhoF1 = (-pTemp*(RF1*TuTemp))/RtimesTSq;
RtimesT = Rb*TbTemp;
RtimesTSq = RtimesT*RtimesT;
rhoP2 = (RtimesT - pTemp*RP2*TbTemp)/RtimesTSq;
rhoT2 = (-pTemp*(RT2*TbTemp + Rb))/RtimesTSq;
rhoF2 = (-pTemp*(RF2*TbTemp))/RtimesTSq;
V1 = VuTemp;
V2 = VbTemp;
m1 = muTemp;
m2 = mbTemp;

// Calculate the the mix rate
q = (phiCyc - phiMix0[0]) / DPhiMix[0];
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
dmMix = mb0[0] * 6 * q*(1 - q)*omega[0] / (DPhiMix[0] * pi / 180);
dmbMix = dmMix*(FbTemp*fs[0]/(1+FbTemp*fs[0]));
// Calculate the fuel equivalent ratio and its derivative
Ffs = FComb[0]*fs[0];
dmu = dmEmb[0] - (1+Ffs)/Ffs*dmfb[0] + dmMix;
dmub = dmEmb[2] - dmfb[0] + dmbMix;
dmb = (1+Ffs)/Ffs*dmfb[0] - dmMix;
dmbb = dmfb[0] - dmbMix;
dFu = (dmub*muTemp - dmu*mubTemp)/(fs[0]*(muTemp - mubTemp)*(muTemp - mubTemp));
dFb = (dmbb*mbTemp - dmb*mbbTemp)/(fs[0]*(mbTemp - mbbTemp)*(mbTemp - mbbTemp));

// Calculate the enthalpy flow rate
dHu = dmEmb[1] - (1/Ffs*hu + hn[0])*dmfb[0] + dmMix*hb;
dHb = (1/Ffs*hu + hn[0])*dmfb[0] - dmMix*hb;

// Calculate the cylinder heat transfer
dQu = dQCyl[0]*TuTemp*muTemp / (TuTemp*muTemp + TbTemp*mbTemp);
dQb = dQCyl[0] - dQu;

u1 = dmu / muTemp;
u2 = (-dQu + dHu - uu*dmu)/muTemp;
u3 = dFu;
u4 = dmb / mbTemp;
u5 = (-dQb + dHb - ub*dmb)/mbTemp;
u6 = dFb;
u7 = dV[0];

detA = -(V1*V2*m1*pTemp*rhoT1*rhoT2*uP1 + V1*V2*m2*pTemp*rhoT1*rhoT2*uP2 - 
        V1*V2*m1*pTemp*rhoP1*rhoT2*uT1 - V1*V2*m2*pTemp*rhoP2*rhoT1*uT2 - 
        V1*m1*m2*rho2*rhoT1*uP1*uT2 - V2*m1*m2*rho1*rhoT2*uP2*uT1 + 
        V1*m1*m2*rho2*rhoP1*uT1*uT2 + V2*m1*m2*rho1*rhoP2*uT1*uT2);
dx[0] = (V1*V2*(pTemp*pTemp)*rhoT1*rhoT2*u7 - V1*V2*m1*pTemp*rhoT1*rhoT2*u2 - 
        V1*V2*m2*pTemp*rhoT1*rhoT2*u5 + V1*m1*m2*rho2*rhoT1*u2*uT2 + 
        V2*m1*m2*rho1*rhoT2*u5*uT1 - V2*m1*pTemp*rho1*rhoT2*u7*uT1 - 
        V1*m2*pTemp*rho2*rhoT1*u7*uT2 + m1*m2*rho1*rho2*u7*uT1*uT2 + 
        V1*V2*m1*pTemp*rhoT1*rhoT2*u3*uF1 + V1*V2*m2*pTemp*rhoT1*rhoT2*u6*uF2 + 
        V1*V2*m1*pTemp*rho1*rhoT2*u1*uT1 + V1*V2*m2*pTemp*rho2*rhoT1*u4*uT2 - 
        V1*V2*m1*pTemp*rhoF1*rhoT2*u3*uT1 - V1*V2*m2*pTemp*rhoF2*rhoT1*u6*uT2 - 
        V1*m1*m2*rho2*rhoT1*u3*uF1*uT2 - V2*m1*m2*rho1*rhoT2*u6*uF2*uT1 -
        V1*m1*m2*rho1*rho2*u1*uT1*uT2 - V2*m1*m2*rho1*rho2*u4*uT1*uT2 +
        V1*m1*m2*rho2*rhoF1*u3*uT1*uT2 + V2*m1*m2*rho1*rhoF2*u6*uT1*uT2)
        /detA;
dx[1] = -(V1*V2*(pTemp*pTemp)*rhoP1*rhoT2*u7 - V1*V2*m1*pTemp*rhoP1*rhoT2*u2 - 
        V1*V2*m2*pTemp*rhoP1*rhoT2*u5 - V2*m1*m2*rho1*rhoT2*u2*uP2 + 
        V2*m1*m2*rho1*rhoT2*u5*uP1 + V1*m1*m2*rho2*rhoP1*u2*uT2 + 
        V2*m1*m2*rho1*rhoP2*u2*uT2 - V2*m1*pTemp*rho1*rhoT2*u7*uP1 - 
        V1*m2*pTemp*rho2*rhoP1*u7*uT2 + m1*m2*rho1*rho2*u7*uP1*uT2 + 
        V1*V2*m1*pTemp*rhoP1*rhoT2*u3*uF1 + V1*V2*m2*pTemp*rhoP1*rhoT2*u6*uF2 +
        V1*V2*m1*pTemp*rho1*rhoT2*u1*uP1 + V1*V2*m2*pTemp*rho1*rhoT2*u1*uP2 -
        V1*V2*m1*pTemp*rhoF1*rhoT2*u3*uP1 - V1*V2*m2*pTemp*rhoF1*rhoT2*u3*uP2 -
        V1*V2*m2*pTemp*rho1*rhoP2*u1*uT2 + V1*V2*m2*pTemp*rho2*rhoP1*u4*uT2 +
        V1*V2*m2*pTemp*rhoF1*rhoP2*u3*uT2 - V1*V2*m2*pTemp*rhoF2*rhoP1*u6*uT2 +
        V2*m1*m2*rho1*rhoT2*u3*uF1*uP2 - V2*m1*m2*rho1*rhoT2*u6*uF2*uP1 -
        V1*m1*m2*rho2*rhoP1*u3*uF1*uT2 - V2*m1*m2*rho1*rhoP2*u3*uF1*uT2 -
        V1*m1*m2*rho1*rho2*u1*uP1*uT2 - V2*m1*m2*rho1*rho2*u4*uP1*uT2 +
        V1*m1*m2*rho2*rhoF1*u3*uP1*uT2 + V2*m1*m2*rho1*rhoF2*u6*uP1*uT2)
        /detA;
dx[2] = u3;
dx[3] = V1*m1*(m2*rho2*rhoT1*u7*uP1*uT2 - m2*rho2*rhoP1*u7*uT1*uT2 - 
        V2*m2*rhoT1*rhoT2*u2*uP2 + V2*m2*rhoT1*rhoT2*u5*uP1 + 
        V2*m2*rhoP2*rhoT1*u2*uT2 - V2*m2*rhoP1*rhoT2*u5*uT1 - 
        V2*pTemp*rhoT1*rhoT2*u7*uP1 + V2*pTemp*rhoP1*rhoT2*u7*uT1 +
        V2*m2*rhoT1*rhoT2*u3*uF1*uP2 - V2*m2*rhoT1*rhoT2*u6*uF2*uP1 -
        V2*m2*rhoP2*rhoT1*u3*uF1*uT2 + V2*m2*rhoP1*rhoT2*u6*uF2*uT1 +
        V2*m2*rho1*rhoT2*u1*uP2*uT1 - V2*m2*rho2*rhoT1*u4*uP1*uT2 -
        V2*m2*rhoF1*rhoT2*u3*uP2*uT1 + V2*m2*rhoF2*rhoT1*u6*uP1*uT2 -
        V2*m2*rho1*rhoP2*u1*uT1*uT2 + V2*m2*rho2*rhoP1*u4*uT1*uT2 +
        V2*m2*rhoF1*rhoP2*u3*uT1*uT2 - V2*m2*rhoF2*rhoP1*u6*uT1*uT2)
        /detA;
dx[4] = -(V1*V2*(pTemp*pTemp)*rhoP2*rhoT1*u7 - V1*V2*m1*pTemp*rhoP2*rhoT1*u2 -
        V1*V2*m2*pTemp*rhoP2*rhoT1*u5 + V1*m1*m2*rho2*rhoT1*u2*uP2 -
        V1*m1*m2*rho2*rhoT1*u5*uP1 + V1*m1*m2*rho2*rhoP1*u5*uT1 +
        V2*m1*m2*rho1*rhoP2*u5*uT1 - V1*m2*pTemp*rho2*rhoT1*u7*uP2 -
        V2*m1*pTemp*rho1*rhoP2*u7*uT1 + m1*m2*rho1*rho2*u7*uP2*uT1 + 
        V1*V2*m1*pTemp*rhoP2*rhoT1*u3*uF1 + V1*V2*m2*pTemp*rhoP2*rhoT1*u6*uF2 +
        V1*V2*m1*pTemp*rho2*rhoT1*u4*uP1 + V1*V2*m2*pTemp*rho2*rhoT1*u4*uP2 - 
        V1*V2*m1*pTemp*rhoF2*rhoT1*u6*uP1 - V1*V2*m2*pTemp*rhoF2*rhoT1*u6*uP2 +
        V1*V2*m1*pTemp*rho1*rhoP2*u1*uT1 - V1*V2*m1*pTemp*rho2*rhoP1*u4*uT1 -
        V1*V2*m1*pTemp*rhoF1*rhoP2*u3*uT1 + V1*V2*m1*pTemp*rhoF2*rhoP1*u6*uT1 -
        V1*m1*m2*rho2*rhoT1*u3*uF1*uP2 + V1*m1*m2*rho2*rhoT1*u6*uF2*uP1 -
        V1*m1*m2*rho2*rhoP1*u6*uF2*uT1 - V2*m1*m2*rho1*rhoP2*u6*uF2*uT1 -
        V1*m1*m2*rho1*rho2*u1*uP2*uT1 - V2*m1*m2*rho1*rho2*u4*uP2*uT1 +
        V1*m1*m2*rho2*rhoF1*u3*uP2*uT1 + V2*m1*m2*rho1*rhoF2*u6*uP2*uT1)
        /detA;
dx[5] = u6;
dx[6] = V2*m2*(m1*rho1*rhoT2*u7*uP2*uT1 - m1*rho1*rhoP2*u7*uT1*uT2 + 
        V1*m1*rhoT1*rhoT2*u2*uP2 - V1*m1*rhoT1*rhoT2*u5*uP1 - 
        V1*m1*rhoP2*rhoT1*u2*uT2 + V1*m1*rhoP1*rhoT2*u5*uT1 - 
        V1*pTemp*rhoT1*rhoT2*u7*uP2 + V1*pTemp*rhoP2*rhoT1*u7*uT2 -
        V1*m1*rhoT1*rhoT2*u3*uF1*uP2 + V1*m1*rhoT1*rhoT2*u6*uF2*uP1 + 
        V1*m1*rhoP2*rhoT1*u3*uF1*uT2 - V1*m1*rhoP1*rhoT2*u6*uF2*uT1 - 
        V1*m1*rho1*rhoT2*u1*uP2*uT1 + V1*m1*rho2*rhoT1*u4*uP1*uT2 +
        V1*m1*rhoF1*rhoT2*u3*uP2*uT1 - V1*m1*rhoF2*rhoT1*u6*uP1*uT2 +
        V1*m1*rho1*rhoP2*u1*uT1*uT2 - V1*m1*rho2*rhoP1*u4*uT1*uT2 - 
        V1*m1*rhoF1*rhoP2*u3*uT1*uT2 + V1*m1*rhoF2*rhoP1*u6*uT1*uT2)
        /detA;

/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}