/*
 * LED_Program.c
 *
 *  Created on: Aug 27, 2026
 *      Author: zbook g8
 */
#include "LED_Interface.h"
#include "LED_Private.h"

#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/AtMega32Registers.h"
#include "../../Common/BitMath.h"

static LED_Config_t LED_Config[8];
void LED_Init(uint8_t LED_ID, uint8_t GroupName, uint8_t PinNo) {

	LED_Config[LED_ID].GroupName = GroupName;
	LED_Config[LED_ID].PinNo = PinNo;
	DIO_SelectDirectionForPin(GroupName, PinNo, DIO_Output);
}
void LED_ON(uint8_t LED_ID, uint8_t ConnectionState) {
	if (ConnectionState == LED_SINK) {
		DIO_WriteValueForPin(LED_Config[LED_ID].GroupName,
						LED_Config[LED_ID].PinNo,  SinkLED_ON);
	}
	if (ConnectionState == LED_SOURCE) {
		DIO_WriteValueForPin(LED_Config[LED_ID].GroupName,
				LED_Config[LED_ID].PinNo, SourceLED_ON);
	}

}

void LED_OFF(uint8_t LED_ID, uint8_t ConnectionState) {
	if (ConnectionState == LED_SINK) {
			DIO_WriteValueForPin(LED_Config[LED_ID].GroupName,
							LED_Config[LED_ID].PinNo, SinkLED_OFF);
		}
		if (ConnectionState == LED_SOURCE) {
			DIO_WriteValueForPin(LED_Config[LED_ID].GroupName,
					LED_Config[LED_ID].PinNo, SourceLED_OFF);
		}
}

void LED_Toggle(uint8_t LED_ID) {
	DIO_ToggleAtPin(LED_Config[LED_ID].GroupName, LED_Config[LED_ID].PinNo);
}

