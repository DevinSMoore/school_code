#
# This file was created by Xilinx Vitis tool.
#


#
# tools
#

RM = rm -f
RMDIR = rm -rf



#
# variables
#

SDCARD_GEN = sdcard_gen
GENERATE_BIF = ::scw::generate_bif

XPFM_PATH = D:/Workspace/blackboard_bist/export/blackboard_bist/blackboard_bist.xpfm
SYS_CONFIG = blackboard_bist
DOMAINS = standalone_domain
BIF_PATH = D:/Workspace/EE234_proj4req5_system/Debug/system.bif

BITSTREAM_PATH = D:/Workspace/EE234_proj4req5/_ide/bitstream/bist.bit
SD_FILES = --elf D:/Workspace/EE234_proj4req5/Debug/EE234_proj4req5.elf,ps7_cortexa9_0

#
# primary build targets
#

all: package

package:
	-@echo Generating bif file for the system project
	generate_system_bif.bat 59960 ${XPFM_PATH} ${DOMAINS} ${BIF_PATH}
	${SDCARD_GEN} --xpfm ${XPFM_PATH} --sys_config ${SYS_CONFIG} --bif ${BIF_PATH} --bitstream ${BITSTREAM_PATH} ${SD_FILES}

clean:
	$(RMDIR) ./_sds
	${RMDIR} package
	${RM} system.bif

.PHONY: all package clean


