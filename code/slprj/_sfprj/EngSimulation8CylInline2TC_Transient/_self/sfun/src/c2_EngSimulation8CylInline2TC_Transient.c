/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EngSimulation8CylInline2TC_Transient_sfun.h"
#include "c2_EngSimulation8CylInline2TC_Transient.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(NULL,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void initialize_params_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void enable_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void disable_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void set_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void sf_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void initSimStructsc2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void registerMessagesc2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_effMech, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2_c_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_EngSimulation8CylInline2TC_Transient, const char_T
   *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_EngSimulation8CylInline2TC_Transient = 0U;
}

static void initialize_params_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  real_T c2_d0;
  real_T c2_dv0[2];
  int32_T c2_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'omegaEMax' in the parent workspace.\n");
  sf_mex_import_named("omegaEMax", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_omegaEMax = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'coeffMechEff' in the parent workspace.\n");
  sf_mex_import_named("coeffMechEff", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), c2_dv0, 0, 0, 0U, 1, 0U, 1, 2);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    chartInstance->c2_coeffMechEff[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_effMech;
  c2_effMech = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_u = *c2_effMech;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = chartInstance->c2_is_active_c2_EngSimulation8CylInline2TC_Transient;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_effMech;
  c2_effMech = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_effMech = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "effMech");
  chartInstance->c2_is_active_c2_EngSimulation8CylInline2TC_Transient =
    c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_EngSimulation8CylInline2TC_Transient");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
}

static void sf_c2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
  real_T c2_omega_nom;
  real_T *c2_effMech;
  real_T *c2_omegaE;
  c2_effMech = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_omegaE = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c2_omega_nom = *c2_omegaE / chartInstance->c2_omegaEMax;
  *c2_effMech = 1.0 - (chartInstance->c2_coeffMechEff[1] * c2_omega_nom -
                       chartInstance->c2_coeffMechEff[0] / (1.0 -
    chartInstance->c2_coeffMechEff[1]) * (c2_omega_nom -
    chartInstance->c2_coeffMechEff[1]) * c2_omega_nom);
}

static void initSimStructsc2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_EngSimulation8CylInline2TC_Transient
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray
  *sf_c2_EngSimulation8CylInline2TC_Transient_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[5];
  c2_ResolvedFunctionInfo (*c2_b_info)[5];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i1;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[5])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 1357951548U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 1319729966U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1346510388U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_scalexp_compatible";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c2_b_info)[2].fileTimeLo = 1286818796U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[3].name = "eml_div";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[3].fileTimeLo = 1313347810U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "mtimes";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[4].fileTimeLo = 1289519692U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c2_i1 = 0; c2_i1 < 5; c2_i1++) {
    c2_r0 = &c2_info[c2_i1];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i1);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i1);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static real_T c2_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_effMech, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_effMech), &c2_thisId);
  sf_mex_destroy(&c2_effMech);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_EngSimulation8CylInline2TC_Transient, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_EngSimulation8CylInline2TC_Transient), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_EngSimulation8CylInline2TC_Transient);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_EngSimulation8CylInline2TC_Transient_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3326309365U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3358884347U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3042340087U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3584531074U);
}

mxArray *sf_c2_EngSimulation8CylInline2TC_Transient_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MQ4WjKjekZ8ESAnRCQh7nG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_EngSimulation8CylInline2TC_Transient_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c2_EngSimulation8CylInline2TC_Transient(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"effMech\",},{M[8],M[0],T\"is_active_c2_EngSimulation8CylInline2TC_Transient\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_EngSimulation8CylInline2TC_Transient_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "wwpMjQaf5YlF2hTmsWTirF";
}

static void sf_opaque_initialize_c2_EngSimulation8CylInline2TC_Transient(void
  *chartInstanceVar)
{
  initialize_params_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
  initialize_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_EngSimulation8CylInline2TC_Transient(void
  *chartInstanceVar)
{
  enable_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_EngSimulation8CylInline2TC_Transient(void
  *chartInstanceVar)
{
  disable_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_EngSimulation8CylInline2TC_Transient(void
  *chartInstanceVar)
{
  sf_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_EngSimulation8CylInline2TC_Transient(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_EngSimulation8CylInline2TC_Transient();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_EngSimulation8CylInline2TC_Transient();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_EngSimulation8CylInline2TC_Transient(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_EngSimulation8CylInline2TC_Transient(S);
}

static void sf_opaque_set_sim_state_c2_EngSimulation8CylInline2TC_Transient
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_EngSimulation8CylInline2TC_Transient(S, st);
}

static void sf_opaque_terminate_c2_EngSimulation8CylInline2TC_Transient(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EngSimulation8CylInline2TC_Transient_optimization_info();
    }

    finalize_c2_EngSimulation8CylInline2TC_Transient
      ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*)
       chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_EngSimulation8CylInline2TC_Transient
    ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_EngSimulation8CylInline2TC_Transient
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_EngSimulation8CylInline2TC_Transient
      ((SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_EngSimulation8CylInline2TC_Transient(SimStruct
  *S)
{
  /* Actual parameters from chart:
     coeffMechEff omegaEMax
   */
  const char_T *rtParamNames[] = { "coeffMechEff", "omegaEMax" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for coeffMechEff*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for omegaEMax*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_EngSimulation8CylInline2TC_Transient_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(902749117U));
  ssSetChecksum1(S,(2232131462U));
  ssSetChecksum2(S,(1787517880U));
  ssSetChecksum3(S,(3812104301U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_EngSimulation8CylInline2TC_Transient(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_EngSimulation8CylInline2TC_Transient(SimStruct *S)
{
  SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *chartInstance;
  chartInstance = (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct *)
    utMalloc(sizeof(SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_EngSimulation8CylInline2TC_TransientInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_EngSimulation8CylInline2TC_Transient;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c2_EngSimulation8CylInline2TC_Transient_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_EngSimulation8CylInline2TC_Transient(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_EngSimulation8CylInline2TC_Transient(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_EngSimulation8CylInline2TC_Transient(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_EngSimulation8CylInline2TC_Transient_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
