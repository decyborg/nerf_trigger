################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Drivers/lptmr/lptmr.c" \

C_SRCS += \
../Sources/Drivers/lptmr/lptmr.c \

OBJS += \
./Sources/Drivers/lptmr/lptmr.o \

C_DEPS += \
./Sources/Drivers/lptmr/lptmr.d \

OBJS_QUOTED += \
"./Sources/Drivers/lptmr/lptmr.o" \

C_DEPS_QUOTED += \
"./Sources/Drivers/lptmr/lptmr.d" \

OBJS_OS_FORMAT += \
./Sources/Drivers/lptmr/lptmr.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Drivers/lptmr/lptmr.o: ../Sources/Drivers/lptmr/lptmr.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Drivers/lptmr/lptmr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Drivers/lptmr/lptmr.o"
	@echo 'Finished building: $<'
	@echo ' '


