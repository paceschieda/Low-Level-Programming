################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cp_assignment.c \
../src/honeypot.c \
../src/port_scanner.c 

OBJS += \
./src/cp_assignment.o \
./src/honeypot.o \
./src/port_scanner.o 

C_DEPS += \
./src/cp_assignment.d \
./src/honeypot.d \
./src/port_scanner.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


