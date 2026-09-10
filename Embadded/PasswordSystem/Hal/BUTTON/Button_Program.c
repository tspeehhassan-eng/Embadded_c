/*
 * Button_Program.c
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */
#include "BUTTON_Interface.h"
#include "BUTTON_Private.h"


#include "../../Common/BitMath.h"
static Button_Config_t Button_Config[3];

void Button_Init(uint8_t Button_ID, uint8_t GroupName, uint8_t PinNo){
	Button_Config[Button_ID].GroupName=GroupName;
	Button_Config[Button_ID].PinNo=PinNo;

	DIO_EnableInternalPullUp(Button_Config[Button_ID].GroupName,Button_Config[Button_ID].PinNo);
}

uint8_t Button_GetState(uint8_t Button_ID)
{
    uint8_t InputValue;

    DIO_ReadValueForPin(
        Button_Config[Button_ID].GroupName,
        Button_Config[Button_ID].PinNo,
        &InputValue
    );

    if (InputValue == DIO_High)
    {
        return BUTTON_NOT_PRESSED;
    }
    else
    {
        return BUTTON_PRESSED;
    }
}
