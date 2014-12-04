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
  *   Created: Wed Jul 23 13:28:12 2014
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
void EngCylHeatTransfer_Outputs_wrapper(const real_T *pCyl,
                          const real_T *tempCyl,
                          const real_T *vCyl,
                          const real_T *omega,
                          real_T *dQ,
                          real_T *tempWall ,
			   const real_T *xC,
                          const real_T  *stroke, const int_T  p_width0, 
                          const real_T  *B, const int_T  p_width1, 
                          const real_T  *cAlpha, const int_T  p_width2, 
                          const real_T  *mCp, const int_T  p_width3, 
                          const real_T  *tempWall0, const int_T  p_width4, 
                          const real_T  *cCylHT, const int_T  p_width5, 
                          const real_T  *nCyl, const int_T p_width6)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
const double pi = 3.14159265359;
double alpha, area;

*tempWall = xC[0] / *mCp;
area = 2*pi/4*(*B)*(*B) + *vCyl*4/(*B);
alpha = *cAlpha*sqrt(*pCyl/100000*(*tempCyl))*pow(*stroke*(*omega)/pi,0.333);
*dQ = alpha*area*(*tempCyl - *tempWall);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void EngCylHeatTransfer_Derivatives_wrapper(const real_T *pCyl,
                          const real_T *tempCyl,
                          const real_T *vCyl,
                          const real_T *omega,
                          const real_T *dQ,
                          const real_T *tempWall,
                          real_T *dx ,
                          real_T *xC, 
                          const real_T  *stroke,  const int_T  p_width0,
                          const real_T  *B,  const int_T  p_width1,
                          const real_T  *cAlpha,  const int_T  p_width2,
                          const real_T  *mCp,  const int_T  p_width3,
                          const real_T  *tempWall0,  const int_T  p_width4,
                          const real_T  *cCylHT,  const int_T  p_width5,
                           const real_T *nCyl, const int_T  p_width6)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
double dQOut;
dQOut = (((cCylHT[0]*(*tempWall) + cCylHT[1])*(*tempWall) + cCylHT[2])* 
        (*tempWall) + cCylHT[3])*1000/(*nCyl);
dx[0] = *dQ - dQOut;
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}