################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Mcal/DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
App1WithDrivers.lss \

FLASH_IMAGE += \
App1WithDrivers.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: App1WithDrivers.elf secondary-outputs

# Tool invocations
App1WithDrivers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,App1WithDrivers.map -mmcu=atmega32 -o "App1WithDrivers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

App1WithDrivers.lss: App1WithDrivers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S App1WithDrivers.elf  >"App1WithDrivers.lss"
	@echo 'Finished building: $@'
	@echo ' '

App1WithDrivers.hex: App1WithDrivers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex App1WithDrivers.elf  "App1WithDrivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: App1WithDrivers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 App1WithDrivers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) App1WithDrivers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
