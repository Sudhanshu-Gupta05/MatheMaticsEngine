################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AllTest.cpp \
../test.cpp 

OBJS += \
./AllTest.o \
./test.o 

CPP_DEPS += \
./AllTest.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/sudhanshu/nuTonomy/unit_testcase/gTestDir -I/home/sudhanshu/nuTonomy/Calculation_Engines/includes -I/home/sudhanshu/nuTonomy/Mathematics/includes -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


