#ifndef __c6_Wartsila2StrokeSim_7S82XSSTune_h__
#define __c6_Wartsila2StrokeSim_7S82XSSTune_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct
#define typedef_SFc6_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c6_is_active_c6_Wartsila2StrokeSim_7S82XSSTune;
  real_T c6_omegaEMax;
  real_T c6_coeffMechEff[2];
  real_T *c6_omegaE;
  real_T *c6_effMech;
} SFc6_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct;

#endif                                 /*typedef_SFc6_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_Wartsila2StrokeSim_7S82XSSTune_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_Wartsila2StrokeSim_7S82XSSTune_get_check_sum(mxArray *plhs[]);
extern void c6_Wartsila2StrokeSim_7S82XSSTune_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
