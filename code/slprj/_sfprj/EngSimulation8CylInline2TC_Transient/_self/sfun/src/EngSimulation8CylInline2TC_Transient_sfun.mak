# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = EngSimulation8CylInline2TC_Transient
TARGET      = sfun
CHART_SRCS 	= c2_EngSimulation8CylInline2TC_Transient.c
MACHINE_SRC	= EngSimulation8CylInline2TC_Transient_sfun.c
MACHINE_REG = EngSimulation8CylInline2TC_Transient_sfun_registry.c
MAKEFILE    = EngSimulation8CylInline2TC_Transient_sfun.mak
MATLAB_ROOT	= E:\Program Files (x86)\MATLAB\R2013a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "E:\Program Files (x86)\MATLAB\R2013a\extern\include"
SL_INCLUDES     = /I "E:\Program Files (x86)\MATLAB\R2013a\simulink\include"
SF_INCLUDES     = /I "E:\Program Files (x86)\MATLAB\R2013a\stateflow\c\mex\include" /I "E:\Program Files (x86)\MATLAB\R2013a\stateflow\c\debugger\include"

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES)\
 $(SL_INCLUDES) $(SF_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /MANIFEST /dll /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = EngSimulation8CylInline2TC_Transient_sfun.mol
SFCLIB = "E:\Program Files (x86)\MATLAB\R2013a\stateflow\c\mex\lib\win32\sfc_mexmsvc80.lib" "E:\Program Files (x86)\MATLAB\R2013a\stateflow\c\debugger\lib\win32\sfc_debugmsvc80.lib" 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libmx.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libmex.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libmat.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libfixedpoint.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libut.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libmwmathutil.lib" "E:\Program Files (x86)\MATLAB\R2013a\extern\lib\win32\microsoft\libemlrt.lib" "E:\Program Files (x86)\MATLAB\R2013a\lib\win32\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

