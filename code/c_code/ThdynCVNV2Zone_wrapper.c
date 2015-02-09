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
void ThdynCVNV2Zone_Output_wrapper(const real_T     *FComb,
                                 const real_T       *phi,
                                 real_T             *p,
                                 real_T             *Tu,
                                 real_T             *Fu,
                                 real_T             *Vu,
                                 real_T             *Tb,
                                 real_T             *Fb,
                                 real_T             *Vb,
								 real_T             *pb,
                                 const real_T       *xC, 
                                 const real_T       *p_prev,        
                                 const real_T       *Tu_prev,
                                 const real_T       *Fu_prev,
                                 const real_T       *Ru_prev,
                                 const real_T       *uu_prev,
                                 const real_T       *Cvu_prev,
                                 const real_T       *Tb_prev,
                                 const real_T       *Fb_prev,
                                 const real_T       *Rb_prev,
                                 const real_T       *ub_prev,
                                 const real_T       *Cvb_prev,
                                 const real_T       *mCyl_prev,
                                 const real_T       *mbCyl_prev,
                                 const real_T       *VCyl_prev,
                                 const real_T       *QCyl_prev,
                                 const real_T       *HCyl_prev,        
                                 const real_T       *WCyl_prev,        
                                 const real_T       *mu_prev,
                                 const real_T       *mub_prev,
                                 const real_T       *Vu_prev,
                                 const real_T       *mfb_prev,
                                 const real_T       *mMix_prev,
                                 const real_T       *mb0,
                                 const real_T  *fs,  const int_T  p_width0,
                                 const real_T *DPhiMix, const int_T p_width1,
                                 const real_T *phiMix0, const int_T p_width2,
                                 const real_T *alpha, const int_T p_width3,
								 const real_T  *hn, const int_T p_width4,
								 const real_T *nStroke, const int_T p_width6)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
real_T mCyl, mbCyl, VCyl, mfb, QCyl, HCyl, WCyl;
real_T dmCyl, dVCyl, dmbCyl, dmfb, dQCyl, dHCyl, dWCyl;
real_T Ffs;
real_T dmu, dmub, dmb, dmbb, dVu, dVb, dWu, dHu, dQu, dWb, dHb, dQb;
real_T mMix, dmMix, dmbMix;
real_T phiCyc, q;
real_T EuPrev, EbPrev;
real_T puTemp, pbTemp;
real_T muTemp, mubTemp, EuTemp, mbTemp, mbbTemp, EbTemp;
real_T mb_prev, Vb_prev;
real_T errP, delP, dVuCorr, dVbCorr, noIter;

real_T Ru,hu,su,uu,RF1,RP1,RT1,uF1,uP1,uT1,sF1,sP1,sT1,Cp1,Cv1,K1;
real_T Rb,hb,sb,ub,RF2,RP2,RT2,uF2,uP2,uT2,sF2,sP2,sT2,Cp2,Cv2,K2;
real_T TU, TU1;
real_T pCyl, TCyl, FCyl;

const real_T pi = 3.141592653590;


mCyl = xC[0];
mbCyl = xC[1];
VCyl = xC[2];
mfb = xC[3];
QCyl = xC[4];
HCyl = xC[5];
WCyl = xC[6];

puTemp = p_prev[0];  
Tu[0] = Tu_prev[0];    Fu[0] = Fu_prev[0];    Vu[0] = Vu_prev[0];
Tb[0] = Tb_prev[0];    Fb[0] = Fb_prev[0];    Vb[0] = VCyl_prev[0] - Vu_prev[0];

GetPTF(mCyl, mbCyl, -QCyl+HCyl-WCyl, VCyl, Tu_prev[0], Ru_prev[0], uu_prev[0],
	Cvu_prev[0], fs[0], &pCyl, &TCyl, &FCyl);

GetThdynCombGasZachV1(puTemp,Tu[0],Fu[0],fs[0],&Ru,&hu,&su,&uu,
        &RF1,&RP1,&RT1,&uF1,&uP1,&uT1,&sF1,&sP1,&sT1,
        &Cp1,&Cv1,&K1);
GetThdynCombGasZachV1(puTemp,Tb[0],Fb[0],fs[0],&Rb,&hb,&sb,&ub,
        &RF2,&RP2,&RT2,&uF2,&uP2,&uT2,&sF2,&sP2,&sT2,
        &Cp2,&Cv2,&K2);

//Calculate mass, energy balance for cylinder
dmCyl = mCyl - mCyl_prev[0];
dQCyl = QCyl - QCyl_prev[0];
dHCyl = HCyl - HCyl_prev[0];
dmbCyl = mbCyl - mbCyl_prev[0];
dVCyl = VCyl - VCyl_prev[0];
dWCyl = WCyl - WCyl_prev[0];
dmfb = mfb - mfb_prev[0];

// Calculate the the mix rate
phiCyc = phi[0]*180.0/pi;
phiCyc = ((int)(floor(phiCyc)) % ((int)(nStroke[0]*180))) + phiCyc - floor(phiCyc);
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
mMix = mb0[0]*q*q*(3-2*q);
dmMix = mMix - mMix_prev[0];
dmbMix = dmMix*(Fb_prev[0]*fs[0]/(1+Fb_prev[0]*fs[0]));
Ffs = FComb[0]*fs[0];
mb_prev = (mCyl_prev[0] - mu_prev[0]);

// Calculate mass, energy balance for unburned zone
dmu = dmCyl - (1+Ffs)/Ffs*dmfb + dmMix;
dmub = dmbCyl - dmfb + dmbMix;
dQu = dQCyl*Tu_prev[0]*mu_prev[0] / (Tu_prev[0]*mu_prev[0] + Tb_prev[0]*mb_prev);
dHu = dHCyl - (1/Ffs*hu + hn[0])*dmfb + dmMix*hb;
muTemp = mu_prev[0] + dmu;
mubTemp = mub_prev[0] + dmub;

// Calculate mass, energy balance for burned zone
dmb = (1+Ffs)/Ffs*dmfb - dmMix;
dmbb = dmfb - dmbMix;
dQb = dQCyl*Tb_prev[0]*mb_prev / (Tu_prev[0]*mu_prev[0] + Tb_prev[0]*mb_prev);
dHb = (1/Ffs*hu + hn[0])*dmfb - dmMix*hb;
mbTemp = mCyl - muTemp;
mbbTemp = mbCyl - mubTemp;

// Iterate Vu and Vb for the common pressure
errP = 1;
noIter = 0;
dVuCorr = 0;
dVbCorr = 0;
EuPrev = mu_prev[0]*uu_prev[0];
EbPrev = -QCyl_prev[0] + HCyl_prev[0] - WCyl_prev[0] - EuPrev;
Vb_prev = VCyl_prev[0] - Vu_prev[0];
while (errP > 0.001 && noIter < 1000){
	++noIter;
    if (Vu_prev[0] < Vb_prev){
        Vu[0] = Vu[0] + dVuCorr;
        dVu = Vu[0] - Vu_prev[0];
        Vb[0] = VCyl - Vu[0];
        dVb = Vb[0] - Vb_prev;
        if (dVCyl == 0){
            dWu = 0;
            dWb = 0;
        }
        else {
            dWu = fabs(dWCyl/dVCyl)*dVu;
            dWb = dWCyl - dWu;
        }
    }
    else {
        Vb[0] = Vb[0] + dVbCorr;
        dVb = Vb[0] - Vb_prev;
        Vu[0] = VCyl - Vb[0];
        dVu = Vu[0] - Vu_prev[0];
        if (dVCyl == 0){
            dWu = 0;
            dWb = 0;
        }
        else {
            dWb = fabs(dWCyl/dVCyl)*dVb;
            dWu = dWCyl - dWb;
        }
    }
    EuTemp = EuPrev - dQu - dWu + dHu;
    EbTemp = EbPrev - dQb - dWb + dHb;
    GetPTF(muTemp,mubTemp,EuTemp,Vu[0],Tu_prev[0],Ru_prev[0],uu_prev[0],
            Cvu_prev[0],fs[0],&puTemp,Tu,Fu);
    GetPTF(mbTemp,mbbTemp,EbTemp,Vb[0],Tb_prev[0],Rb_prev[0],ub_prev[0],
            Cvb_prev[0],fs[0],&pbTemp,Tb,Fb);
    delP = (puTemp - pbTemp);
    errP = fabs(delP/puTemp);
    if (dVCyl == 0){
        dVuCorr = 0;
        dVbCorr = 0;
    }
    else{
        if (Vu_prev[0] < Vb_prev){
            GetThdynCombGasZachV1(puTemp,Tu[0],Fu[0],fs[0],&Ru,&hu,&su,&uu,
                &RF1,&RP1,&RT1,&uF1,&uP1,&uT1,&sF1,&sP1,&sT1,&Cp1,&Cv1,&K1);
            TU1 = (RP1*sF1-RF1*sP1) / 
                    (RP1*(uT1*sF1-uF1*sT1)+RT1*(uF1*sP1-uP1*sF1) +
                    RF1*(uP1*sT1-uT1*sP1));
			TU = 1 / uT1;
            dVuCorr = Vu[0]*Vu[0] * delP/2 / 
                    (muTemp*Ru*(Vu[0]*TU*fabs(dWCyl/dVCyl) + Tu[0]) + 
                    Vu[0]*delP/2);                    
            dVbCorr = 0;
        }
        else{
            GetThdynCombGasZachV1(pbTemp,Tb[0],Fb[0],fs[0],&Rb,&hb,&sb,&ub,
                &RF2,&RP2,&RT2,&uF2,&uP2,&uT2,&sF2,&sP2,&sT2,&Cp2,&Cv2,&K2);
            TU1 = (RP2*sF2-RF2*sP2) / 
                    (RP2*(uT2*sF2-uF2*sT2)+RT2*(uF2*sP2-uP2*sF2) +
                    RF2*(uP2*sT2-uT2*sP2));
			TU = 1 / uT2;
            dVbCorr = -Vb[0]*Vb[0] * delP/2 / 
                    (mbTemp*Rb*(Vb[0]*TU*fabs(dWCyl/dVCyl) + Tb[0]) + 
                    Vb[0]*delP/2);                    
            dVuCorr = 0;
        }
    }
	if (noIter > 1000){
		
	}
}
p[0] = puTemp;
pb[0] = pbTemp;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void ThdynCVNV2Zone_Derivatives_wrapper(const real_T *dm,
                          const real_T *dmb,
                          const real_T *dV,
                          const real_T *dmfb,
                          const real_T *dQCyl,
                          const real_T *dHCyl,
                          const real_T *dWCyl,  
                          real_T *dx)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
    dx[0] = dm[0];
    dx[1] = dmb[0];
    dx[2] = dV[0];
    dx[3] = dmfb[0];
    dx[4] = dQCyl[0];
    dx[5] = dHCyl[0];
    dx[6] = dWCyl[0];
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}

void ThdynCVNV2Zone_Update_wrapper(const real_T *phi,
                          const real_T *FComb,
                          const real_T *combState,
                          const real_T *p,
                          const real_T *Tu,
                          const real_T *Fu,
                          const real_T *Vu,
                          const real_T *Tb,
                          const real_T *Fb,
                          const real_T *Vb,
                          const real_T *xC,        
                          real_T *p_prev,        
                          real_T *Tu_prev,
                          real_T *Fu_prev,
                          real_T *Ru_prev,
                          real_T *uu_Prev,
                          real_T *Cvu_prev,
                          real_T *Tb_prev,
                          real_T *Fb_prev,
                          real_T *Rb_prev,
                          real_T *ub_prev,
                          real_T *Cvb_prev,
                          real_T *mCyl_prev,
                          real_T *mbCyl_prev,
                          real_T *VCyl_prev,
                          real_T *QCyl_prev,
                          real_T *HCyl_prev,        
                          real_T *WCyl_prev,        
                          real_T *mu_prev,
                          real_T *mub_prev,
                          real_T *Vu_prev,
                          real_T *mfb_prev,
                          real_T *mMix_prev,
                          real_T *mb0,
                          real_T *ResetMix,        
                          const real_T  *fs,  const int_T  p_width1,
                          const real_T *DPhiMix, const int_T p_width3,
                          const real_T *phiMix0, const int_T p_width4,
                          const real_T *alpha, const int_T p_width5,
                          const real_T *nStroke, const int_T p_width6)
{
    real_T R,h,s,u,RF,RP,RT,uF,uP,uT,sF,sP,sT,Cp,Cv,K;
    real_T phiCyc, q;
    const real_T pi = 3.141592653590;
    
    p_prev[0] = p[0];    
    Tu_prev[0] = Tu[0];    Fu_prev[0] = Fu[0];      Vu_prev[0] = Vu[0];
    GetThdynCombGasZachV1(p[0],Tu[0],Fu[0],fs[0],&R,&h,&s,&u,
                &RF,&RP,&RT,&uF,&uP,&uT,&sF,&sP,&sT,&Cp,&Cv,&K);
    Ru_prev[0] = R;    uu_Prev[0] = u;    Cvu_prev[0] = Cv;
    mu_prev[0] = p[0]*Vu[0]/(R*Tu[0]);    
    mub_prev[0] = mu_prev[0]*Fu[0]*fs[0]/(1+Fu[0]*fs[0]);
    Tb_prev[0] = Tb[0];    Fb_prev[0] = Fb[0];     
    GetThdynCombGasZachV1(p[0],Tb[0],Fb[0],fs[0],&R,&h,&s,&u,
                &RF,&RP,&RT,&uF,&uP,&uT,&sF,&sP,&sT,&Cp,&Cv,&K);
    Rb_prev[0] = R;    ub_prev[0] = u,	Cvb_prev[0] = Cv;
    mCyl_prev[0] = xC[0];  mbCyl_prev[0] = xC[1];   VCyl_prev[0] = xC[2];
    mfb_prev[0] = xC[3];
    
	QCyl_prev[0] = xC[4];
	HCyl_prev[0] = xC[5];
	WCyl_prev[0] = xC[6];

    // Calculate the the mix rate
    phiCyc = phi[0]*180.0/pi;
    phiCyc = ((int)(floor(phiCyc)) % ((int)(nStroke[0]*180))) + phiCyc - floor(phiCyc);
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
    mMix_prev[0] = mb0[0]*q*q*(3-2*q);

    if(combState[0] == 2 && ResetMix[0] == 0)
    {
        ResetMix[0] = 1;
    }
    if(combState[0] == 5 && ResetMix[0] == 1)
    {
        
        ResetMix[0] = 0;
        mb0[0] = xC[0] - mu_prev[0] - alpha[0]*(xC[0]);
        mMix_prev[0] = 0;
    }
}
