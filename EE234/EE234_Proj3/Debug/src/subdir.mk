################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

S_UPPER_SRCS += \
../src/TTCmodule.S \
../src/readData.S \
../src/req4.S \
../src/sevSegDispController.S 

OBJS += \
./src/TTCmodule.o \
./src/readData.o \
./src/req4.o \
./src/sevSegDispController.o 

S_UPPER_DEPS += \
./src/TTCmodule.d \
./src/readData.d \
./src/req4.d \
./src/sevSegDispController.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -ID:/Workspace/blackboard_bist/export/blackboard_bist/sw/blackboard_bist/standalone_domain/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


