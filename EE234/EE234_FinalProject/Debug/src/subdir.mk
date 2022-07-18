################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/UARTmodule.c \
../src/interruptModule.c \
../src/main.c \
../src/req1.c \
../src/req2.c \
../src/req3.c \
../src/xil_exception.c 

OBJS += \
./src/UARTmodule.o \
./src/interruptModule.o \
./src/main.o \
./src/req1.o \
./src/req2.o \
./src/req3.o \
./src/xil_exception.o 

C_DEPS += \
./src/UARTmodule.d \
./src/interruptModule.d \
./src/main.d \
./src/req1.d \
./src/req2.d \
./src/req3.d \
./src/xil_exception.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -ID:/Workspace/blackboard_bist/export/blackboard_bist/sw/blackboard_bist/standalone_domain/bspinclude/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

