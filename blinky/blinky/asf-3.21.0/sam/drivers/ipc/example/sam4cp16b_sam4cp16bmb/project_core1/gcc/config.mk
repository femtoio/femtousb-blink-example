#
# Copyright (c) 2011 Atmel Corporation. All rights reserved.
#
# \asf_license_start
#
# \page License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an
#    Atmel microcontroller product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# \asf_license_stop
#

# Path to top level ASF directory relative to this project directory.
PRJ_PATH = ../../../../../../..

# Target CPU architecture: cortex-m3, cortex-m4
ARCH = cortex-m4

# Target part: none, sam3n4 or sam4l4aa
PART = sam4cp16b_1

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET_FLASH = ipc_example_core1_flash.elf
TARGET_SRAM = ipc_example_core1_sram.elf

# List of C source files.
CSRCS = \
       common/services/clock/sam4cp/sysclk.c              \
       common/services/delay/sam/cycle_counter.c          \
       common/utils/interrupt/interrupt_sam_nvic.c        \
       sam/boards/sam4cp16bmb/init.c                      \
       sam/drivers/ipc/example/src_core1/ipc_example_core1.c \
       sam/drivers/ipc/ipc.c                              \
       sam/drivers/pmc/pmc.c                              \
       sam/drivers/pmc/sleep.c                            \
       sam/drivers/supc/supc.c                            \
       sam/drivers/usart/usart.c                          \
       sam/utils/cmsis/sam4cp/source/templates/gcc/startup_sam4cp.c \
       sam/utils/cmsis/sam4cp/source/templates/system_sam4cp.c \
       sam/utils/syscalls/gcc/syscalls.c

# List of assembler source files.
ASSRCS = 

# List of include paths.
INC_PATH = \
       common/boards                                      \
       common/services/clock                              \
       common/services/delay                              \
       common/services/ioport                             \
       common/utils                                       \
       sam/boards                                         \
       sam/boards/sam4cp16bmb                             \
       sam/drivers/ipc                                    \
       sam/drivers/ipc/example/sam4cp16b_sam4cp16bmb/conf_src/common \
       sam/drivers/ipc/example/sam4cp16b_sam4cp16bmb/conf_src/core1 \
       sam/drivers/ipc/example/sam4cp16b_sam4cp16bmb/project_core1 \
       sam/drivers/ipc/example/src_core1                  \
       sam/drivers/pmc                                    \
       sam/drivers/supc                                   \
       sam/drivers/usart                                  \
       sam/utils                                          \
       sam/utils/cmsis/sam4cp/include                     \
       sam/utils/cmsis/sam4cp/source/templates            \
       sam/utils/fpu                                      \
       sam/utils/header_files                             \
       sam/utils/preprocessor                             \
       thirdparty/CMSIS/Include                           \
       thirdparty/CMSIS/Lib/GCC \
       sam/drivers/ipc/example/sam4cp16b_sam4cp16bmb/project_core1/gcc

# Additional search paths for libraries.
LIB_PATH =  \
       thirdparty/CMSIS/Lib/GCC                          

# List of libraries to use during linking.
LIBS =  \
       arm_cortexM4lf_math                                \
       m                                                 

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT_FLASH = sam/utils/linker_scripts/sam4cp/gcc/sam4cp16b_1_sram.ld
LINKER_SCRIPT_SRAM  = sam/utils/linker_scripts/sam4cp/gcc/sam4cp16b_1_sram.ld

# Path relative to top level directory pointing to a linker script.
DEBUG_SCRIPT_FLASH = sam/boards/sam4cp16bmb/debug_scripts/gcc/sam4cp16bmb_sram_1.gdb
DEBUG_SCRIPT_SRAM  = sam/boards/sam4cp16bmb/debug_scripts/gcc/sam4cp16bmb_sram_1.gdb

# Project type parameter: all, sram or flash
PROJECT_TYPE        = flash

# Additional options for debugging. By default the common Makefile.in will
# add -g3.
DBGFLAGS = 

# Application optimization used during compilation and linking:
# -O0, -O1, -O2, -O3 or -Os
OPTIMIZATION = -O1

# Extra flags to use when archiving.
ARFLAGS = 

# Extra flags to use when assembling.
ASFLAGS =  \
       -mfloat-abi=softfp                                 \
       -mfpu=fpv4-sp-d16                                 

# Extra flags to use when compiling.
CFLAGS =  \
       -mfloat-abi=softfp                                 \
       -mfpu=fpv4-sp-d16                                 

# Extra flags to use when preprocessing.
#
# Preprocessor symbol definitions
#   To add a definition use the format "-D name[=definition]".
#   To cancel a definition use the format "-U name".
#
# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
       -D ARM_MATH_CM4=true                               \
       -D BOARD=SAM4CP16BMB                               \
       -D __SAM4CP16B_1__                                 \
       -D printf=iprintf                                  \
       -D scanf=iscanf

# Extra flags to use when linking
LDFLAGS = \

# Pre- and post-build commands
PREBUILD_CMD = 
POSTBUILD_CMD = cp -f $(project).bin ./../../../src_core0/core1_image.bin