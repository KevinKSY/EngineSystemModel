#ifndef __c2_EngSimulation8CylInline2TC_Transient_h__
#define __c2_EngSimulation8CylInline2TC_Transient_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c2_ResolvedFunctionInfo
#define typedef_c2_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c2_ResolvedFunctionInfo;

#endif                                 /*typedef_c2_ResolvedFunctionInfo*/

#ifndef typedef_SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct
#define typedef_SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c2_is_active_c2_EngSimulation8CylInline2TC_Transient;
  real_T c2_omegaEMax;
  real_T c2_coeffMechEff[2];
} SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct;

#endif                                 /*typedef_SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_EngSimulation8CylInline2TC_Transient_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_EngSimulation8CylInline2TC_Transient_get_check_sum(mxArray
  *plhs[]);
extern void c2_EngSimulation8CylInline2TC_Transient_method_dispatcher(SimStruct *
  S, int_T method, void *data);

#endif
