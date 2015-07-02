################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HC-SR04/hc-sr04.c" \

C_SRCS += \
../Sources/HC-SR04/hc-sr04.c \

OBJS += \
./Sources/HC-SR04/hc-sr04.o \

C_DEPS += \
./Sources/HC-SR04/hc-sr04.d \

OBJS_QUOTED += \
"./Sources/HC-SR04/hc-sr04.o" \

C_DEPS_QUOTED += \
"./Sources/HC-SR04/hc-sr04.d" \

OBJS_OS_FORMAT += \
./Sources/HC-SR04/hc-sr04.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/HC-SR04/hc-sr04.o: ../Sources/HC-SR04/hc-sr04.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HC-SR04/hc-sr04.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HC-SR04/hc-sr04.o"
	@echo 'Finished building: $<'
	@echo ' '


