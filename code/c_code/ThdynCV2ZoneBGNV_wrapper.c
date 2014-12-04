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
  *   Created: Wed Oct  8 20:44:00 2014
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
void ThdynCV2ZoneBGNV_Outputs_wrapper(real_T *p,
                          real_T *Tu,
                          real_T *Fu,
                          real_T *Vu,
                          real_T *Tb,
                          real_T *Fb,
                          real_T *Vb,
                          real_T *errP  ,
                          real_T *Tavg, 
                          const real_T *xC,
                          const real_T  *fs, const int_T  p_width0, 
                          const real_T  *DPhiMix, const int_T  p_width1, 
                          const real_T  *phiMix0, const int_T  p_width2, 
                          const real_T  *alpha, const int_T  p_width3, 
                          const real_T  *hn, const int_T  p_width4, 
                          const real_T  *p0, const int_T  p_width5, 
                          const real_T  *T0, const int_T  p_width6, 
                          const real_T  *F0, const int_T  p_width7, 
                          const real_T  *V0, const int_T p_width8,
                          const real_T *Tu_prev,
                          const real_T *Ru_prev,
                          const real_T *uu_prev,
                          const real_T *Cvu_prev,
                          const real_T *Tb_prev,
                          const real_T *Rb_prev,
                          const real_T *ub_prev,
                          const real_T *Cvb_prev,
                          const real_T *mb0,
                          const int *resetMix)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
const double pi = 3.14159265359;    
double mu, Uu, mub, mb, Ub, mbb;
double pu, pb;
double Ru,hu,su,uu,RFu,RPu,RTu,uFu,uPu,uTu,sFu,sPu,sTu,Cpu,Cvu,Ku;
double Ru1,hu1,su1,uu1,RFu1,RPu1,RTu1,uFu1,uPu1,uTu1,sFu1,sPu1,sTu1,Cpu1,Cvu1,Ku1;
double Rb,hb,sb,ub,RFb,RPb,RTb,uFb,uPb,uTb,sFb,sPb,sTb,Cpb,Cvb,Kb;

mu = xC[0];
Uu = xC[1];
mub = xC[2];
Vu[0] = xC[3];
mb = xC[4];
Ub = xC[5];
mbb = xC[6];
Vb[0] = xC[7];

GetPTFV1(mu,mub,Uu,Vu[0],Tu_prev[0],Ru_prev[0],uu_prev[0],Cvu_prev[0],fs[0], &pu,Tu,Fu);
GetPTFV1(mb,mbb,Ub,Vb[0],Tb_prev[0],Rb_prev[0],ub_prev[0],Cvb_prev[0],fs[0], &pb,Tb,Fb);

GetThdynCombGasZachV1(p[0],Tu[0],Fu[0],fs[0],&Ru,&hu,&su,&uu,&RFu,&RPu,&RTu,&uFu,&uPu,&uTu,
        &sFu,&sPu,&sTu,&Cpu,&Cvu,&Ku);
GetThdynCombGasZachV1(p[0],Tb[0],Fb[0],fs[0],&Rb,&hb,&sb,&ub,&RFb,&RPb,&RTb,&uFb,&uPb,&uTb,
        &sFb,&sPb,&sTb,&Cpb,&Cvb,&Kb);

errP[0] = (pu - pb)/pu;
p[0] = (pu + pb)/2;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
Tavg[0] = p[0]*(Vu[0] + Vb[0])/(mu*Ru + mb*Rb);
}

/*
  * Updates function
  *
  */
void ThdynCV2ZoneBGNV_Update_wrapper(const real_T *dmHmb,
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
                          const real_T *errP ,
                          const real_T *Tavg,        
                          const real_T *xC,        
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T  *DPhiMix,  const int_T  p_width1,
                          const real_T  *phiMix0,  const int_T  p_width2,
                          const real_T  *alpha,  const int_T  p_width3,
                          const real_T  *hn,  const int_T  p_width4,
                          const real_T  *p0,  const int_T  p_width5,
                          const real_T  *T0,  const int_T  p_width6,
                          const real_T  *F0,  const int_T  p_width7,
                           const real_T *V0, const int_T  p_width8,
                          real_T *Tu_prev,
                          real_T *Ru_prev,
                          real_T *uu_prev,
                          real_T *Cvu_prev,
                          real_T *Tb_prev,
                          real_T *Rb_prev,
                          real_T *ub_prev,
                          real_T *Cvb_prev,
                          real_T *mb0,
                          int *resetMix)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
const double pi = 3.14159265359;
double Ru,hu,su,uu,RFu,RPu,RTu,uFu,uPu,uTu,sFu,sPu,sTu,Cpu,Cvu,Ku;
double Rb,hb,sb,ub,RFb,RPb,RTb,uFb,uPb,uTb,sFb,sPb,sTb,Cpb,Cvb,Kb;
double phi360, phiComb, q;

phi360 = phi[0]*180/pi;
phi360 = (((int)floor(phi360))%360) + (phi360 - floor(phi360));
if (phi360 > 180) {
    phiComb = phi360 - 360;
}
else {
    phiComb = phi360;
}

GetThdynCombGasZachV1(p[0],Tu[0],Fu[0],fs[0],&Ru,&hu,&su,&uu,&RFu,&RPu,&RTu,&uFu,&uPu,&uTu,
        &sFu,&sPu,&sTu,&Cpu,&Cvu,&Ku);
GetThdynCombGasZachV1(p[0],Tb[0],Fb[0],fs[0],&Rb,&hb,&sb,&ub,&RFb,&RPb,&RTb,&uFb,&uPb,&uTb,
        &sFb,&sPb,&sTb,&Cpb,&Cvb,&Kb);

Tu_prev[0] = Tu[0];
Ru_prev[0] = Ru;
uu_prev[0] = uu;
Cvu_prev[0] = Cvu;
Tb_prev[0] = Tb[0];
Rb_prev[0] = Rb;
ub_prev[0] = ub;
Cvb_prev[0] = Cvb;

q = (phiComb - phiMix0[0]) / DPhiMix[0];
if ((q > 0)&(resetMix[0] == 1))
{
    mb0[0] = xC[4];
    resetMix[0] = 0;
}

if ((phiComb < 0) & (resetMix[0] == 0))
{
    resetMix[0] = 1;
}
    


/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void ThdynCV2ZoneBGNV_Derivatives_wrapper(const real_T *dmHmb,
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
                          const real_T *errP,
                          const real_T *Tavg,                
                          real_T *dx ,
                          real_T *xC, 
                          const real_T  *fs,  const int_T  p_width0,
                          const real_T  *DPhiMix,  const int_T  p_width1,
                          const real_T  *phiMix0,  const int_T  p_width2,
                          const real_T  *alpha,  const int_T  p_width3,
                          const real_T  *hn,  const int_T  p_width4,
                          const real_T  *p0,  const int_T  p_width5,
                          const real_T  *T0,  const int_T  p_width6,
                          const real_T  *F0,  const int_T  p_width7,
                           const real_T *V0, const int_T  p_width8,
                          const real_T *Tu_prev,
                          const real_T *Ru_prev,
                          const real_T *uu_prev,
                          const real_T *Cvu_prev,
                          const real_T *Tb_prev,
                          const real_T *Rb_prev,
                          const real_T *ub_prev,
                          const real_T *Cvb_prev,
                          const real_T *mb0,
                          const int *resetMix)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
const double pi = 3.14159265359;    
double Ffs;
double phi360, phiComb, q;
double dmMix;
double Ru,hu,su,uu,RFu,RPu,RTu,uFu,uPu,uTu,sFu,sPu,sTu,Cpu,Cvu,Ku;
double Rb,hb,sb,ub,RFb,RPb,RTb,uFb,uPb,uTb,sFb,sPb,sTb,Cpb,Cvb,Kb;
double mu, mb, mub, mbb;
double Uu, Ub;
double dmu, dmb, dmub, dmbb, dFu, dFb;
double dHu, dHb, dQu, dQb;
double a1, a2;
double u1, u2, u3, u4, u5;
double pu, pb;
double Tuu, Tub; // Partial derivative of T w.r.t. u;
double detJu, detJb; // determinant of Jacobian of (p,T,F) -> (R,u,s)

phi360 = phi[0]*180/pi;
phi360 = (((int)floor(phi360))%360) + (phi360 - floor(phi360));
if (phi360 > 180) {
    phiComb = phi360 - 360;
}
else {
    phiComb = phi360;
}

mu = xC[0];    Uu = xC[1];
mub = xC[2];   

mb = xC[4];    Ub = xC[5];
mbb = xC[6];   


// Calculate the the mix rate
q = (phiComb - phiMix0[0]) / DPhiMix[0];
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
dmMix = alpha[0]*mb0[0]*6*q*(q-1)*omega[0]*DPhiMix[0];

// Calculate the fuel equivalent ratio and its derivative
Ffs = FComb[0]*fs[0];

// Calculate the mass flow rate
dmu = dmHmb[0] - (1+Ffs)/Ffs*dmfb[0] + dmMix;
dmub = dmHmb[2] - dmfb[0] + dmMix*(Fb[0]*fs[0]/(1+Fb[0]*fs[0]));
dmb = (1+Ffs)/Ffs*dmfb[0] - dmMix;
dmbb = dmfb[0] - dmMix*(Fb[0]*fs[0]/(1+Fb[0]*fs[0]));

// Calculate the thermal dynamic properties of the zones
GetThdynCombGasZachV1(p[0],Tu[0],Fu[0],fs[0],&Ru,&hu,&su,&uu,&RFu,&RPu,&RTu,&uFu,&uPu,&uTu,
        &sFu,&sPu,&sTu,&Cpu,&Cvu,&Ku);
GetThdynCombGasZachV1(p[0],Tb[0],Fb[0],fs[0],&Rb,&hb,&sb,&ub,&RFb,&RPb,&RTb,&uFb,&uPb,&uTb,
        &sFb,&sPb,&sTb,&Cpb,&Cvb,&Kb);

// Calculate the enthalpy flow rate
dHu = dmHmb[1] - (1/Ffs*hu + hn[0])*dmfb[0] + dmMix*ub;
dHb = (1/Ffs*hu + hn[0])*dmfb[0] - dmMix*ub;

// Calculate the cylinder heat transfer
dQu = dQCyl[0]*Tu[0]*mu / (Tu[0]*mu + Tb[0]*mb);
dQb = dQCyl[0] - dQu;


detJu = RPu*(uTu*sFu-uFu*sTu)-RTu*(uPu*sFu-uFu*sPu)+RFu*(uPu*sTu-uTu*sPu);
detJb = RPb*(uTb*sFb-uFb*sTb)-RTb*(uPb*sFb-uFb*sPb)+RFb*(uPb*sTb-uTb*sPb);
Tuu = (RPu*sFu - RFu*sPu) / detJu;
Tub = (RPb*sFb - RFb*sPb) / detJb;
a1 = -(RTu*Tu[0]+Ru)/(p[0]*Ru*Tu[0])*Tuu;
a2 = -(RTb*Tb[0]+Rb)/(p[0]*Rb*Tb[0])*Tub;
        
u1 = -dQu + dHu; 
u2 = dmHmb[1] - dQCyl[0] - p[0]*dV[0];
u3 = (a1*Tuu*Uu*dmu/mu + dmu/p[0])/mu - (a2*Tub*Ub*dmb/mb + dmb/p[0])/mb;
u4 = dV[0];

dx[0] = dmu;
dx[1] = -(Vu[0] - Vb[0]) /  Vu[0] / p[0] / Vb[0] *  u1 +  a2 *  p[0] *  u2 -  p[0] *  u3 + 1 / Vb[0] *  u4;
dx[2] = dmub;
dx[3] = (- a1 +  a2) *  u1 -  (a2 * u2) +  u3 -1 / Vb[0] /  p[0] *  u4;
dx[4] = dmb;
dx[5] = ( Vu[0] - Vb[0]) /  Vu[0] /  p[0] / Vb[0] *  u1 -1 /  Vu[0] /  p[0] / Vb[0] * ( Vu[0] * Vb[0] *  a1 *  (p[0] * p[0]) +  Vu[0] - Vb[0]) *  u2 +  p[0] *  u3 -1 / Vb[0] *  u4;
dx[6] = dmbb;
dx[7] = (a1 - a2) * u1 + a2 * u2 - u3 - (a1 * p[0] * p[0] * Vu[0] - a2 * p[0] * p[0] * Vu[0] - 1) / Vu[0] / p[0] * u4;
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}