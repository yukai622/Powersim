.SUFFIXES:
.SUFFIXES: .cc .cpp .o .x

CC = g++
OPT =
DEBUG = 
OTHER = -Wall -O3

# Use this CFLAGS definition if you need to see debug output
# CFLAGS = -c -g -Wno-deprecated -Wall -D_DEBUG
	#../src/turbine.cpp ../src/environment.cpp \
	#../src/aerodynamic.cpp ../src/generator.cpp \
	#../src/mechanical.cpp ../src/mechanical_tdf.cpp \
	#../src/mechanical_lsf.cpp ../src/generator_Te.cpp \
	#../src/generator_lsf.cpp ../src/generator_eq.cpp \
	#../src/wind_turbine.cpp ../src/mechanical_delay.cpp 

CFLAGS = -c -g -Wno-deprecated 

MODULE = run
SRCS =  ../src/battery_voc.cpp ../src/battery_converter.cpp \
	../src/battery_char.cpp ../src/battery_fre.cpp ../src/battery.cpp \
	../src/pv_converter.cpp ../src/pv_panel.cpp \
	../src/wind_turbine.cpp ../src/wind_inverter.cpp \
	../src/house1.cpp ../src/house2.cpp ../src/house5.cpp\
 	../src/cti_bus.cpp ../src/main.cpp

#../src/main.cpp

OBJS = $(SRCS:../src/%.cpp=%.o)

include Makefile.defs
