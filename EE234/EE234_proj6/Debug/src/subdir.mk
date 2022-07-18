################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/I2C.c \
../src/LSM9DS1_LM75B.c \
../src/UARTmodule.c \
../src/main.c \
../src/req1.c 

OBJS += \
./src/I2C.o \
./src/LSM9DS1_LM75B.o \
./src/UARTmodule.o \
./src/main.o \
./src/req1.o 

C_DEPS += \
./src/I2C.d \
./src/LSM9DS1_LM75B.d \
./src/UARTmodule.d \
./src/main.d \
./src/req1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -ID:/Workspace/blackboard_bist/export/blackboard_bist/sw/blackboard_bist/standalone_domain/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


