#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Introduction to Embedded Systems Software and Development>
#
# Student Patrick Fitzgerald
# assessment C1M2 on using makefile and build systems
# goal of assessment is to generate an executable and support files from
# source and headers provided
#
# the makefile must provide tools to work with 2 different builds of the same
# software.  One build is intended for the x86_64 development host and the
# other will run on the TI MSP432 development board with ARM processor
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#  $ make build PLATFORM=HOST
#  creates the object code *.o modules needed to be linked into the 
#  target c1m2.out which will run from command line $ ./c1m2.out
#
#
#  $ make build PLATFORM=MSP432
#  also generates the object code modules, but this time the set of modules
#  needed for the ARM processor development board MSP432
#  target c1m2.out will not run on CLI.  It is to be uploaded to dev-board
#
# Build Targets:
# need PLATFORM=HOST or PLATFORM=MSP432 input
#
#      make objects => <file>.o generates object files
#      make prepro => <file>.i preprocessed files
#      make assembly => <file>.asm assembly language files
#      make depends <file>.generates depends files
#      make compile-all generates all of the <file>.o files
#      make build generates all <file>.o and links them into c1m2.out executable 
#
# Platform Overrides:
#      as shown in examples, above. Specify either PLATFORM=HOST or PLATFORM=MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides to provide a default 
PLATFORM = HOST

# values common to both platforms
TARGET = c1m2
FLAGS = -Wall -Werror -g -O0 -std=c99

# use for Ubuntu Linux on x86 default as HOST
ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE = size
	CPPFLAGS = -DHOST $(INCLUDES)
	CFLAGS = $(FLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif


# use for ARM processor on MSP board
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	CPPFLAGS = -DMSP432 $(INCLUDES)
	# linkerfile modified for final assignment in same folder
	# removed one period
	LINKERFILE = ./msp432p401r.lds
	LDFLAGS =  -Wl,-Map=$(TARGET).map -T $(LINKERFILE)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	ARM_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CFLAGS = $(FLAGS) $(ARM_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
endif

# 
# these aliases streamline both read-ability and logical flow of the program
# 
#
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)
ASSEMBS = $(SOURCES:.c=.asm)
PREPROS = $(SOURCES:.c=.i)

# 
#
#
# the -c flag makes the compiler generate an object code file without linking
#
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

# the -S flag generates assembly code files from sources
#
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

# the -E flag generates a preprocessed file
#
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

# flags -E -M generate dependency files
#
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

# generates object files alone *.o
#
.PHONY: objects
objects:$(OBJECTS)


# will generate the depends files alone *.d
# 
.PHONY: depends
depends:$(DEPENDS)

# generates assembly files *.asm
#
.PHONY:	assembly
assembly:$(ASSEMBS)


# single command generates preprocessor input, the *.i modules
#
.PHONY: prepro
prepro:$(PREPROS)



# compile-all will generate all of the object files *.o  without linking
# still needs PLATFORM
#
.PHONY: compile-all
compile-all:$(OBJECTS)

# single command to generate the target executable and the depends .d 
# information.  Still needs PLATFORM
#
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(CC) $(OBJECTS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@




# shows what program is actually using for input
#
.PHONY: list
list:
	@echo	$(shell ls)
	@echo	$(SOURCES)
	@echo	$(INCLUDES)

# removes all files generated in this assessmetn
#
.PHONY: clean
clean:
	@echo "cleaning .. "
	@echo $(SOURCES)  # useful tool
	@echo $(INCLUDES) # useful tool
	rm -rf *.o
	rm -rf *.d
	rm -rf *.i
	rm -rf *.s
	rm -rf *.asm
	rm -rf *.map
	rm -rf *.out


# end of makefile
