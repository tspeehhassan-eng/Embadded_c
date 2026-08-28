/*
 * Buzzer_Program.c
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */
#include "Buzzer_Interface.h"
#include "Buzzer_Private.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/DIO/DIO_Private.h"

Buzzer_Config_t Buzzer_Config;


void Buzzer_Off(void)
{       DIO_WriteValueForPin(Buzzer_Config.GroupName,
        Buzzer_Config.PinNo,
        DIO_Low);
}



void Buzzer_Init(Buzzer_Config_t *Config)
{
    Buzzer_Config = *Config;

    DIO_SelectDirectionForPin(
        Buzzer_Config.GroupName,
        Buzzer_Config.PinNo,
        DIO_Output
    );

    Buzzer_Off();
}

void Buzzer_On(void)
{
    DIO_WriteValueForPin(Buzzer_Config.GroupName,
        Buzzer_Config.PinNo,
        DIO_High);
}

void Buzzer_Toggle(void)
{
    DIO_ToggleAtPin(Buzzer_Config.GroupName,
        Buzzer_Config.PinNo);
}
