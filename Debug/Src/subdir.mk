################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO_prog.c \
../Src/Kernel_prog.c \
../Src/OSMCAL_prog.c \
../Src/RCC_prog.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/GPIO_prog.o \
./Src/Kernel_prog.o \
./Src/OSMCAL_prog.o \
./Src/RCC_prog.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/GPIO_prog.d \
./Src/Kernel_prog.d \
./Src/OSMCAL_prog.d \
./Src/RCC_prog.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/GPIO_prog.cyclo ./Src/GPIO_prog.d ./Src/GPIO_prog.o ./Src/GPIO_prog.su ./Src/Kernel_prog.cyclo ./Src/Kernel_prog.d ./Src/Kernel_prog.o ./Src/Kernel_prog.su ./Src/OSMCAL_prog.cyclo ./Src/OSMCAL_prog.d ./Src/OSMCAL_prog.o ./Src/OSMCAL_prog.su ./Src/RCC_prog.cyclo ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

