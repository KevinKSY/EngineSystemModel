

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
void scavenging1Zone_Outputs_wrapper(const real_T *FCyl,
			const real_T *pIn,
			const real_T *TIn,
			const real_T *FIn,
			const real_T *pOut,
			const real_T *TOut,
			const real_T *InPortOpen,
			const real_T *mDotIn,
			const real_T *combState,
			const real_T *phi,
			real_T *FOut,
			const real_T *xC,
			const real_T  *kai, const int_T  p_width0,
			const real_T  *delta, const int_T  p_width1,
			const real_T  *fs, const int_T  p_width2,
			const real_T  *volDisp, const int_T  p_width3,
            const int_T *resetIn,
            const int_T *resetOut,
            const real_T *mInPrev,
            const real_T *F0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
const double pi = 3.14159265359;
real_T beta;    // Purity of the exhaust gas
real_T lambdaS; // Delivery ratio
real_T RIn;       // Gas constant of inlet gas
real_T rho0;      // Density of inducted gas
real_T dummy;
real_T mIn;       // mass of inducted air
real_T mInTemp;       // mass of inducted air since opening of the port
real_T phiCyc0;       //Crank angle at IPO
real_T phiCyc;      //Crank angle in degree (0~360)

        
mIn = xC[0];

phiCyc = phi[0]*180.0/pi;
phiCyc = ((int)(floor(phiCyc)) % ((int)360)) + phiCyc - floor(phiCyc);


if (InPortOpen > 0){
    if (resetIn[0] == 1){
        GetThdynCombGasZachV1(pIn[0], TIn[0], FIn[0], fs[0], &RIn, &dummy, &dummy, &dummy, &dummy, 
        &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy);
        rho0 = pIn[0] / RIn / TIn[0];
        mInTemp = mIn - mInPrev[0];
        lambdaS = mInTemp / rho0 / volDisp[0];
        beta = 0;
        phiCyc0 = phiCyc;
    }
    else{
        mInTemp = mIn - mInPrev[0];
        lambdaS = mInTemp / rho0 / volDisp[0];
        beta = 1 - exp(-kai[0]*lambdaS*
                pow(((phiCyc - phiCyc0)/
                     (2*(180-phiCyc0))),delta[0]));
    }
}
else{
    beta = 0;
    lambdaS = 0;
}


if (FCyl > 0){
    if (InPortOpen[0] > 0){
        FOut[0] = (1-beta)*F0[0]/(beta*F0[0]*fs[0] + 1);
    }
    else{
    FOut[0] = FCyl[0];
    }
}
else{
    FOut[0] = 0;
}


/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void scavenging1Zone_Derivatives_wrapper(const real_T *FCyl,
			const real_T *pIn,
			const real_T *TIn,
			const real_T *FIn,
			const real_T *pOut,
			const real_T *TOut,
			const real_T *InPortOpen,
			const real_T *mDotIn,
			const real_T *combState,
			const real_T *phi,
			const real_T *FOut,
			real_T *dx,
			real_T *xC,
			const real_T  *kai,  const int_T  p_width0,
			const real_T  *delta,  const int_T  p_width1,
			const real_T  *fs,  const int_T  p_width2,
			const real_T  *volDisp,  const int_T  p_width3)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
dx[0] = mDotIn[0];
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}

void scavenging1Zone_Update_wrapper(const real_T *FCyl,
			const real_T *pIn,
			const real_T *TIn,
			const real_T *FIn,
			const real_T *pOut,
			const real_T *TOut,
			const real_T *InPortOpen,
			const real_T *mDotIn,
			const real_T *combState,
			const real_T *phi,
			const real_T *FOut,
			real_T *dx,
			real_T *xC,
			const real_T  *kai,  const int_T  p_width0,
			const real_T  *delta,  const int_T  p_width1,
			const real_T  *fs,  const int_T  p_width2,
			const real_T  *volDisp,  const int_T  p_width3,
            int_T *resetIn,
            int_T *resetOut,
            real_T *mInPrev,
            real_T *F0)
{
const double pi = 3.14159265359;
real_T beta;    // Purity of the exhaust gas
real_T lambdaS; // Delivery ratio
real_T RIn;       // Gas constant of inlet gas
real_T rho0;      // Density of inducted gas
real_T dummy;
real_T mIn;       // mass of inducted air
real_T mInTemp;       // mass of inducted air since opening of the port
real_T phiCyc0;       //Crank angle at IPO
real_T phiCyc;      //Crank angle in degree (0~360)

mIn = xC[0];

phiCyc = phi[0]*180.0/pi;
phiCyc = ((int)(floor(phiCyc)) % ((int)360)) + phiCyc - floor(phiCyc);


if (InPortOpen > 0){
    if (resetIn[0] == 1){
        resetIn[0] = 0;
    }

}
else{
    if (resetIn[0] == 0){
        resetIn[0] = 1;
        mInPrev[0] = mIn;
    }
}

if((combState[0] == 5)&(resetOut[0] == 1)) {
    F0[0] = FCyl[0];
    resetOut[0] = 0;
}
else if((combState[0] == 0)&(resetOut[0] == 0)){
    resetOut[0] = 1;
}


}