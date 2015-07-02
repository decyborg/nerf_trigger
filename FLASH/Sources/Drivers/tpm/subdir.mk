################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Drivers/tpm/tpm.c" \

C_SRCS += \
../Sources/Drivers/tpm/tpm.c \

OBJS += \
./Sources/Drivers/tpm/tpm.o \

C_DEPS += \
./Sources/Drivers/tpm/tpm.d \

OBJS_QUOTED += \
"./Sources/Drivers/tpm/tpm.o" \

C_DEPS_QUOTED += \
"./Sources/Drivers/tpm/tpm.d" \

OBJS_OS_FORMAT += \
./Sources/Drivers/tpm/tpm.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Drivers/tpm/tpm.o: ../Sources/Drivers/tpm/tpm.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Drivers/tpm/tpm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Drivers/tpm/tpm.o"
	@echo 'Finished building: $<'
	@echo ' '


