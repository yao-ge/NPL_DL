
# -*-Makefile-*-

ifndef NCS_ROOT
    $(error NCS_ROOT environment variable not set)
endif

NPL_DIR          = npl
NPL_PROGRAM_NAME = bus.npl
NLC_CONFIG       = ${NPL_DIR}/config.ini
NLC_OUTPUT_DIR   = fe_output
APP_TARGET       =
APP_DEFINES      =

usage :
	# Need a target, try "make help" for more information

include ${NCS_ROOT}/bmi/scripts/Mkinc.env

help ::
	# ----------------------------------------------------------------------
	# NPL_PROGRAM_NAME=$(NPL_PROGRAM_NAME)
	#

clean::
	@rm -f *_classes.cpp *_classes.h
	@rm -f mhc.cpp mhc.h header.yml
	@rm -f *~
