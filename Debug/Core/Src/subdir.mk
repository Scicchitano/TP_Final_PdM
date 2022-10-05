################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/API_Control_Estados.c \
../Core/Src/API_debounce.c \
../Core/Src/API_delay.c \
../Core/Src/API_uart.c \
../Core/Src/Buzzer.c \
../Core/Src/SensorTemp.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/stm32f4xx_nucleo_144.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/API_Control_Estados.o \
./Core/Src/API_debounce.o \
./Core/Src/API_delay.o \
./Core/Src/API_uart.o \
./Core/Src/Buzzer.o \
./Core/Src/SensorTemp.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/stm32f4xx_nucleo_144.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/API_Control_Estados.d \
./Core/Src/API_debounce.d \
./Core/Src/API_delay.d \
./Core/Src/API_uart.d \
./Core/Src/Buzzer.d \
./Core/Src/SensorTemp.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/stm32f4xx_nucleo_144.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/API_Control_Estados.d ./Core/Src/API_Control_Estados.o ./Core/Src/API_Control_Estados.su ./Core/Src/API_debounce.d ./Core/Src/API_debounce.o ./Core/Src/API_debounce.su ./Core/Src/API_delay.d ./Core/Src/API_delay.o ./Core/Src/API_delay.su ./Core/Src/API_uart.d ./Core/Src/API_uart.o ./Core/Src/API_uart.su ./Core/Src/Buzzer.d ./Core/Src/Buzzer.o ./Core/Src/Buzzer.su ./Core/Src/SensorTemp.d ./Core/Src/SensorTemp.o ./Core/Src/SensorTemp.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/stm32f4xx_nucleo_144.d ./Core/Src/stm32f4xx_nucleo_144.o ./Core/Src/stm32f4xx_nucleo_144.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

