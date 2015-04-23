/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Wartsila2StrokeSim_7S82XSSTune_sfun.h"
#include "c2_Wartsila2StrokeSim_7S82XSSTune.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Wartsila2StrokeSim_7S82XSSTune_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[14] = { "nargin", "nargout", "u11",
  "u12", "u13", "u21", "u22", "u23", "dmu", "dEu", "dmbu", "dmd", "dEd", "dmbd"
};

/* Function Declarations */
static void initialize_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void initialize_params_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void enable_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void disable_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void set_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void sf_gateway_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void mdl_start_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void initSimStructsc2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_b_dmbd, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_Wartsila2StrokeSim_7S82XSSTune, const char_T
   *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_Wartsila2StrokeSim_7S82XSSTune = 0U;
}

static void initialize_params_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  uint8_T c2_g_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(7, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_dEd;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_dEu;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *chartInstance->c2_dmbd;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *chartInstance->c2_dmbu;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *chartInstance->c2_dmd;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *chartInstance->c2_dmu;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal =
    chartInstance->c2_is_active_c2_Wartsila2StrokeSim_7S82XSSTune;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_dEd = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "dEd");
  *chartInstance->c2_dEu = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "dEu");
  *chartInstance->c2_dmbd = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "dmbd");
  *chartInstance->c2_dmbu = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "dmbu");
  *chartInstance->c2_dmd = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 4)), "dmd");
  *chartInstance->c2_dmu = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 5)), "dmu");
  chartInstance->c2_is_active_c2_Wartsila2StrokeSim_7S82XSSTune =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
    "is_active_c2_Wartsila2StrokeSim_7S82XSSTune");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Wartsila2StrokeSim_7S82XSSTune(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_b_u11;
  real_T c2_b_u12;
  real_T c2_b_u13;
  real_T c2_b_u21;
  real_T c2_b_u22;
  real_T c2_b_u23;
  uint32_T c2_debug_family_var_map[14];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 6.0;
  real_T c2_b_dmu;
  real_T c2_b_dEu;
  real_T c2_b_dmbu;
  real_T c2_b_dmd;
  real_T c2_b_dEd;
  real_T c2_b_dmbd;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u11, 0U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_u11;
  c2_b_hoistedGlobal = *chartInstance->c2_u12;
  c2_c_hoistedGlobal = *chartInstance->c2_u13;
  c2_d_hoistedGlobal = *chartInstance->c2_u21;
  c2_e_hoistedGlobal = *chartInstance->c2_u22;
  c2_f_hoistedGlobal = *chartInstance->c2_u23;
  c2_b_u11 = c2_hoistedGlobal;
  c2_b_u12 = c2_b_hoistedGlobal;
  c2_b_u13 = c2_c_hoistedGlobal;
  c2_b_u21 = c2_d_hoistedGlobal;
  c2_b_u22 = c2_e_hoistedGlobal;
  c2_b_u23 = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u11, 2U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u12, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u13, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u21, 5U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u22, 6U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_u23, 7U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dmu, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dEu, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dmbu, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dmd, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dEd, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_dmbd, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_b_u11, 0.0, -1, 2U,
        c2_b_u11 < 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
    c2_b_dmu = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
    c2_b_dEu = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
    c2_b_dmbu = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
    c2_b_dmd = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
    c2_b_dEd = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
    c2_b_dmbd = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
    c2_b_dmu = c2_b_u11;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
    c2_b_dEu = c2_b_u12;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    c2_b_dmbu = c2_b_u13;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    c2_b_dmd = c2_b_u21;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    c2_b_dEd = c2_b_u22;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    c2_b_dmbd = c2_b_u23;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_dmu = c2_b_dmu;
  *chartInstance->c2_dEu = c2_b_dEu;
  *chartInstance->c2_dmbu = c2_b_dmbu;
  *chartInstance->c2_dmd = c2_b_dmd;
  *chartInstance->c2_dEd = c2_b_dEd;
  *chartInstance->c2_dmbd = c2_b_dmbd;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Wartsila2StrokeSim_7S82XSSTuneMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dmu, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u12, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dEu, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u13, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u21, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u22, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_u23, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dmbu, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dmd, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dEd, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_dmbd, 11U);
}

static void mdl_start_c2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_Wartsila2StrokeSim_7S82XSSTune
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
  chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_b_dmbd, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dmbd), &c2_thisId);
  sf_mex_destroy(&c2_b_dmbd);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_dmbd;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
  chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)
    chartInstanceVoid;
  c2_b_dmbd = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dmbd), &c2_thisId);
  sf_mex_destroy(&c2_b_dmbd);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
  chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
  chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_Wartsila2StrokeSim_7S82XSSTune, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Wartsila2StrokeSim_7S82XSSTune), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Wartsila2StrokeSim_7S82XSSTune);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance)
{
  chartInstance->c2_u11 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_dmu = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_u12 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_dEu = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_u13 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_u21 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_u22 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_u23 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_dmbu = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_dmd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_dEd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_dmbd = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
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

void sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3739029915U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(794941253U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2783587423U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(682086528U);
}

mxArray* sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_post_codegen_info(void);
mxArray *sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rssDzGDpsDdxv33PFm3Z3B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_Wartsila2StrokeSim_7S82XSSTune_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_Wartsila2StrokeSim_7S82XSSTune_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_Wartsila2StrokeSim_7S82XSSTune_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_Wartsila2StrokeSim_7S82XSSTune
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[14],T\"dEd\",},{M[1],M[7],T\"dEu\",},{M[1],M[15],T\"dmbd\",},{M[1],M[12],T\"dmbu\",},{M[1],M[13],T\"dmd\",},{M[1],M[5],T\"dmu\",},{M[8],M[0],T\"is_active_c2_Wartsila2StrokeSim_7S82XSSTune\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Wartsila2StrokeSim_7S82XSSTune_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Wartsila2StrokeSim_7S82XSSTuneMachineNumber_,
           2,
           1,
           1,
           0,
           12,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_Wartsila2StrokeSim_7S82XSSTuneMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Wartsila2StrokeSim_7S82XSSTuneMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Wartsila2StrokeSim_7S82XSSTuneMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u11");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dmu");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u12");
          _SFD_SET_DATA_PROPS(3,2,0,1,"dEu");
          _SFD_SET_DATA_PROPS(4,1,1,0,"u13");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u21");
          _SFD_SET_DATA_PROPS(6,1,1,0,"u22");
          _SFD_SET_DATA_PROPS(7,1,1,0,"u23");
          _SFD_SET_DATA_PROPS(8,2,0,1,"dmbu");
          _SFD_SET_DATA_PROPS(9,2,0,1,"dmd");
          _SFD_SET_DATA_PROPS(10,2,0,1,"dEd");
          _SFD_SET_DATA_PROPS(11,2,0,1,"dmbd");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,295);
        _SFD_CV_INIT_EML_IF(0,1,0,94,104,189,293);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,97,104,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_u11);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_dmu);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_u12);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_dEu);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_u13);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_u21);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_u22);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c2_u23);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_dmbu);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c2_dmd);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c2_dEd);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c2_dmbd);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Wartsila2StrokeSim_7S82XSSTuneMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3vYybSvcbprrQoWVr4WZdG";
}

static void sf_opaque_initialize_c2_Wartsila2StrokeSim_7S82XSSTune(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
  initialize_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Wartsila2StrokeSim_7S82XSSTune(void
  *chartInstanceVar)
{
  enable_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Wartsila2StrokeSim_7S82XSSTune(void
  *chartInstanceVar)
{
  disable_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Wartsila2StrokeSim_7S82XSSTune(void
  *chartInstanceVar)
{
  sf_gateway_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_Wartsila2StrokeSim_7S82XSSTune(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Wartsila2StrokeSim_7S82XSSTune_optimization_info();
    }

    finalize_c2_Wartsila2StrokeSim_7S82XSSTune
      ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Wartsila2StrokeSim_7S82XSSTune
    ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Wartsila2StrokeSim_7S82XSSTune(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c2_Wartsila2StrokeSim_7S82XSSTune
      ((SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Wartsila2StrokeSim_7S82XSSTune(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Wartsila2StrokeSim_7S82XSSTune_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(720910725U));
  ssSetChecksum1(S,(1491241717U));
  ssSetChecksum2(S,(619516678U));
  ssSetChecksum3(S,(1108811212U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Wartsila2StrokeSim_7S82XSSTune(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Wartsila2StrokeSim_7S82XSSTune(SimStruct *S)
{
  SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct *)utMalloc
    (sizeof(SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_Wartsila2StrokeSim_7S82XSSTuneInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Wartsila2StrokeSim_7S82XSSTune;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_Wartsila2StrokeSim_7S82XSSTune_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Wartsila2StrokeSim_7S82XSSTune(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Wartsila2StrokeSim_7S82XSSTune(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Wartsila2StrokeSim_7S82XSSTune(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Wartsila2StrokeSim_7S82XSSTune_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
