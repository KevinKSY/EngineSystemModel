#ifndef __c1_EngineSystemSubmodel_h__
#define __c1_EngineSystemSubmodel_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_EngineSystemSubmodelInstanceStruct
#define typedef_SFc1_EngineSystemSubmodelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c1_is_active_c1_EngineSystemSubmodel;
  real_T c1_coeffProp[3];
  real_T *c1_omegaE;
  real_T *c1_Tq;
} SFc1_EngineSystemSubmodelInstanceStruct;

#endif                                 /*typedef_SFc1_EngineSystemSubmodelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_EngineSystemSubmodel_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_EngineSystemSubmodel_get_check_sum(mxArray *plhs[]);
extern void c1_EngineSystemSubmodel_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif