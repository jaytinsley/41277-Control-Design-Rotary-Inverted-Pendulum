###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          Arduino ARM M7


###########################################################################
## FILE INCLUSIONS
###########################################################################
-include arduino_macros.mk
-include codertarget_assembly_flags.mk


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PACKAGES_TOOLS_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_M7_TOOLS = $(ARDUINO_TEENSY_ROOT)/tools/teensy-compile/$(TEENSY_GCC_VERSION)/arm/bin
ARDUINO_TEENSY_TOOLS = $(ARDUINO_TEENSY_ROOT)/tools/teensy-tools/$(TEENSY_TOOLS_VERSION)
ELF2EEP_OPTIONS = -O/ ihex/ -j/ .eeprom/ --set-section-flags=.eeprom=alloc,load/ --no-change-warnings/ --change-section-lma/ .eeprom=0


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM M7 Assembler
AS_PATH := $(ARDUINO_M7_TOOLS)
AS := $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM M7 C Compiler
CC_PATH := $(ARDUINO_M7_TOOLS)
CC := $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM M7 Linker
LD_PATH = $(ARDUINO_M7_TOOLS)
LD := $(LD_PATH)/arm-none-eabi-gcc


# C++ Compiler: Arduino ARM M7 C++ Compiler
CPP_PATH := $(ARDUINO_M7_TOOLS)
CPP := $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM M7 C++ Linker
CPP_LD_PATH = $(ARDUINO_M7_TOOLS)
CPP_LD := $(CPP_LD_PATH)/arm-none-eabi-gcc

# Archiver: Arduino ARM M7 Archiver
AR_PATH := $(ARDUINO_M7_TOOLS)
AR := $(AR_PATH)/arm-none-eabi-ar

# Indexing: Arduino ARM M7 Ranlib
RANLIB_PATH := $(ARDUINO_M7_TOOLS)
RANLIB := $(RANLIB_PATH)/arm-none-eabi-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = /Applications/MATLAB_R2024b.app/bin/maca64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = rcs
ASFLAGS              = -MMD -MP  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = $(ELF2EEP_OPTIONS) $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -O2 \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections \
                       -nostdlib \
                       -MMD -MP 
CPPFLAGS             = -std=gnu++14 -fno-exceptions -fpermissive -fno-rtti -fno-threadsafe-statics -felide-constructors -Wno-error=narrowing \
                       -O2 \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections \
                       -nostdlib \
                       -MMD -MP 
CPP_LDFLAGS          =  -O2 -Wl,--gc-sections,--relax
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex -R .eeprom $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              =  -O2 -Wl,--gc-sections,--relax
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =


###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################
#---------------
# C Compiler
#---------------
CFLAGS_SKIPFORSIL = -Wall -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -MMD -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10819 -DARDUINO_TEENSY41 -DF_CPU=$(TEENSY_CPU_FREQ) -DUSB_SERIAL -DLAYOUT_US_ENGLISH
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)
#-----------------
# C++ Compiler
#-----------------
CPPFLAGS_SKIPFORSIL = -Wall -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -MMD -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10819 -DARDUINO_TEENSY41 -DF_CPU=$(TEENSY_CPU_FREQ) -DUSB_SERIAL -DLAYOUT_US_ENGLISH
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)
#---------------
# C++ Linker
#---------------
CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_TEENSY_ROOT)/hardware/avr/$(TEENSY_LIB_VERSION)/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -larm_cortexM7lfsp_math -lm -lstdc++
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_TEENSY_ROOT)/hardware/avr/$(TEENSY_LIB_VERSION)/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -larm_cortexM7lfsp_math -lm -lstdc++
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL = -T$(ARDUINO_TEENSY_ROOT)/hardware/avr/$(TEENSY_LIB_VERSION)/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -larm_cortexM7lfsp_math -lm -lstdc++
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_TEENSY_ROOT)/hardware/avr/$(TEENSY_LIB_VERSION)/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -larm_cortexM7lfsp_math -lm -lstdc++
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=/Users/jaytinsley/Documents/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase/staticmakefiles
MODELMK=SFC.mk
SLIB_PATH=/Users/jaytinsley/Documents/MATLAB/R2024b/ArduinoStaticLibrary/Teensy4.1ArduinoCompatible/FasterRuns
VARIANT_HEADER_PATH=$(ARDUINO_TEENSY_ROOT)/hardware/avr/1.58.2/cores/teensy4
ARDUINO_SKETCHBOOK_ROOT=/Users/jaytinsley/Documents/MATLAB/SupportPackages/R2024b/3P.instrset/arduinoide.instrset/aCLI/user/libraries
ARDUINO_BASESUPPORTPKG_ROOT=/Users/jaytinsley/Documents/MATLAB/SupportPackages/R2024b/toolbox/target/supportpackages/arduinobase


###########################################################################
## Export Variables
###########################################################################
export AR
export RANLIB
export AS
export CC
export CPP
export ASFLAGS
export CFLAGS
export CPPFLAGS
export ARFLAGS
export SLIB_PATH
export VARIANT_HEADER_PATH
export ARDUINO_SKETCHBOOK_ROOT
export ARDUINO_BASESUPPORTPKG_ROOT


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j15 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f teensycomm.mk all
	"$(MAKE)" -j15 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f teensycore.mk all
	"$(MAKE)" -j15 SHELL="$(SHELL)" -f "$(MODELMK)" all

