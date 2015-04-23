#ifndef __c3_EngineSystemSubmodel_h__
#define __c3_EngineSystemSubmodel_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_EngineSystemSubmodelInstanceStruct
#define typedef_SFc3_EngineSystemSubmodelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c3_is_active_c3_EngineSystemSubmodel;
  real_T c3_omegaEMax;
  real_T c3_coeffMechEff[2];
  real_T *c3_omegaE;
  real_T *c3_effMech;
} SFc3_EngineSystemSubmodelInstanceStruct;

#endif                                 /*typedef_SFc3_EngineSystemSubmodelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_EngineSystemSubmodel_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_EngineSystemSubmodel_get_check_sum(mxArray *plhs[]);
extern void c3_EngineSystemSubmodel_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
