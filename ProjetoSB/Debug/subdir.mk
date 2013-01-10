################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodigoIn.cpp \
../CodigoOut.cpp \
../Montador.cpp \
../Operacoes.cpp \
../main.cpp 

OBJS += \
./CodigoIn.o \
./CodigoOut.o \
./Montador.o \
./Operacoes.o \
./main.o 

CPP_DEPS += \
./CodigoIn.d \
./CodigoOut.d \
./Montador.d \
./Operacoes.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


