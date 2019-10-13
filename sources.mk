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

# SOURCES and INCLUDES depend upon platform, host or ARM processor
#
# sourcefile for assessment C1M2 of Boulder Colorado course 
# embedded C - student Patrick Fitzgerald
#

ifeq	($(PLATFORM),HOST)
# SOURCES to use if compiling for Ubuntu Host
# only the two source modules, main and memory are compiled to run
# on the host
#
SOURCES =	main.c \
		memory.c 
		
# Header files for Ubuntu Host
# once again, only one header directory, common is needed to generate
# the object files used on linux host
#
INCLUDES =	-I../include/common

# simple approach, if not host then MSP432 by default
else
# generates extraneous text 	($(PLATFORM),MSP432)
# SOURCES and Header files to use if compiling for MSP board
# all 5 source files will be compiled to object code to run
# on the ARM processor of the target board
#
SOURCES =	main.c \
		memory.c \
		startup_msp432p401r_gcc.c \
		system_msp432p401r.c \
	interrupts_msp432p401r_gcc.c
#
# more source files require more header files to generate
# the code for the ARM processor
#
INCLUDES =	-I../include/CMSIS \
		-I../include/common \
		-I../include/msp432

endif
