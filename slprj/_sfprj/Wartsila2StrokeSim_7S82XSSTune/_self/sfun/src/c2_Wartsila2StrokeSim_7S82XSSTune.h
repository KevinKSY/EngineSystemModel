#ifndef __c2_Wartsila2StrokeSim_7S82XSSTune_h__
#define __c2_Wartsila2StrokeSim_7S82XSSTune_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct
#define typedef_SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Wartsila2StrokeSim_7S82XSSTune;
  real_T *c2_u11;
  real_T *c2_dmu;
  real_T *c2_u12;
  real_T *c2_dEu;
  real_T *c2_u13;
  real_T *c2_u21;
  real_T *c2_u22;
  real_T *c2_u23;
  real_T *c2_dmbu;
  real_T *c2_dmd;
  real_T *c2_dEd;
  real_T *c2_dmbd;
} SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct;

#endif                                 /*typedef_SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_check_sum(mxArray *plhs[]);
extern void c2_Wartsila2StrokeSim_7S82XSSTune_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif