#John Taylor
#Project 2 Makefile
C_SRCS = \
../board/*.c \
../CMSIS/*.c \
../drivers/*.c \
../startup/*.c \
../utilities/*.c \
../source/*.c \
../source/LED/*.c \
../source/*.c \
../source/Pattern/*.c \
../source/MemoryTest/*.c \
../uCUnit/*.c \
../Tests/*.c \
../source/Logger/*.c \


OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_rtc.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_tsi_v4.o \
./CMSIS/system_MKL25Z4.o \
./startup/startup_mkl25z4.o \
./utilities/fsl_debug_console.o \
./source/Project_3.o \
./source/mtb.o \
./source/LED/RGB.o \
./source/Logger/logger.o \
./source/semihost_hardfault.o \
./source/MemoryTest/MemoryTest.o \
./source/Pattern/patternGenerator.o \
./uCUnit/System.o \

UT_OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_rtc.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_tsi_v4.o \
./CMSIS/system_MKL25Z4.o \
./startup/startup_mkl25z4.o \
./utilities/fsl_debug_console.o \
./Tests/tests.o \
./source/mtb.o \
./source/LED/RGB.o \
./source/Logger/logger.o \
./source/semihost_hardfault.o \
./source/MemoryTest/MemoryTest.o \
./source/Pattern/patternGenerator.o \
./uCUnit/System.o \

C_DEPS += \
./board/*.d \
./CMSIS/*.d \
./drivers/*.d \
./startup/*.d \
./utilities/*.d \
./source/*.d \
./source/LED/*.d \
./source/Pattern/*.d \
./source/Logger/*.d \
./source/MemoryTest/*.d \
./uCUnit/*.d \
./Tests/*.d \

CC = arm-none-eabi-gcc
LL = arm-none-eabi-gcc

PRE = -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG
INC = -I../board -I../source -I../ -I../drivers -I../CMSIS -I../utilities -I../startup -I../Pattern 
CFLG = -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
LFLG = -nostdlib -Xlinker -Map="Project_2.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m0plus -mthumb -T linkerfile.ld

# fb_debug Target
fb: CC += -DDB -DFREEDOM
fb: Project_3.axf 

# fb_run Target
fb: CC += -DFREEDOM
unit_test: unit_test.axf

pc: PRE =
pc: CFLG = -O0 -fno-common -g3 -Wall -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)"
pc: LFLG =
pc: INC = -I../source  
pc: C_SRCS =../source/Project_3.c ./source/Pattern/patternGenerator.c ./source/MemoryTest/MemoryTest.c ./source/Logger/logger.c
pc: OBJS = ./source/Project_3.o ./source/Pattern/patternGenerator.o ./source/MemoryTest/MemoryTest.o ./source/Logger/logger.o
pc: C_DEPS =./source/Project_3.d ./source/Pattern/patternGenerator.d ./source/MemoryTest/MemoryTest.d ./source/Logger/logger.d
pc: CC =gcc
pc: LL =gcc
pc: Project_3.o

# Tool invocations
Project_3.o:./source/Project_3.o ./source/Pattern/patternGenerator.o ./source/MemoryTest/MemoryTest.o ./source/Logger/logger.o
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(LL) $(LFLG) -o "P3.o" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	
unit_test.axf: $(UT_OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(LL) $(LFLG) -o "unit_test.axf" $(UT_OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Tool invocations
Project_3.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	$(LL) $(LFLG) -o "Project_3.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG) -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
Tests/%.o: ../Tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
uCUnit/%.o: ../uCUnit/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG)  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	$(CC) $(PRE) $(INC) $(CFLG) -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) Project_2.axf
	-$(RM) *.map
	-@echo ' '

