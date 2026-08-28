/*
 * main.c

 *
 *  Created on: Aug 26, 2026
 *      Author: zbook g8
 *      ctrl+shift+f format code
 *      alt + up/down move
 *
 */
#include "Mcal/DIO/DIO_Interface.h"
#include "Mcal/DIO/DIO_Private.h"

#include "Common/BitMath.h"
#include <util/delay.h>
#include "Mcal/AtMega32Registers.h"
#include <stdint.h>
#include "Hal/Btn/Btn_Interface.h"
#include "Hal/Btn/Btn_Private.h"
#include "Hal/LED/LED_Interface.h"
#include "Hal/LED/LED_Private.h"
#include "Hal/SevenSegment/SevenSegment_Interface.h"
#include "Hal/SevenSegment/SevenSegment_Config.h"
#include "Hal/SevenSegment/SevenSegment_Private.h"
#include "Hal/BUZZER/Buzzer_Interface.h"
#include "Hal/BUZZER/Buzzer_Private.h"

//shift+ctrl+c comment for block of code
#define notPressed 1
#define Pressed    0
//
//#define AnodeZero   0xC0
//#define AnodeOne    0xF9
//#define AnodeTwo    0xA4
//#define AnodeThree  0xB0
//#define AnodeFour   0x99
//#define AnodeFive   0x92
//#define AnodeSix    0x82
//#define AnodeSeven  0xF8
//#define AnodeEight  0x80
//#define AnodeNine   0x90
Buzzer_Config_t myBuzzer = {
    .GroupName = DIO_GroupC,
    .PinNo = DIO_pin4
};

int main(void) {
    Btn_Init(BUTTON_SINK,Btn1);
	//DIO_EnableInternalPullUp(DIO_GroupC, DIO_pin0);
    Btn_Init(BUTTON_SINK,Btn2);
	//DIO_EnableInternalPullUp(DIO_GroupC, DIO_pin1);
    Btn_Init(BUTTON_SINK,Btn3);
	//DIO_EnableInternalPullUp(DIO_GroupC, DIO_pin2);

	//set(DDRC_Reg, 3);
    LED_Init(LED1,DIO_GroupC,DIO_pin3);
	//DIO_SelectDirectionForPin(DIO_GroupC, DIO_pin3, DIO_Output);

	//set(DDRC_Reg, 4);
    Buzzer_Init(&myBuzzer);
	//DIO_SelectDirectionForPin(DIO_GroupC, DIO_pin4, DIO_Output);

	// DDRD_Reg = 0xFF;

	//DIO_SelectDirectionForAll(DIO_GroupD, DIO_AllOutput);

	//uint8_t State = notPressed;
	//uint8_t oldState = notPressed;
	uint8_t counter = 0;
	//uint8_t State2 = notPressed;
	//uint8_t State3 = notPressed;
	uint8_t State = SinkNotPressed;
	uint8_t oldState = SinkNotPressed;
	uint8_t State2 = SinkNotPressed;
	uint8_t State3 = SinkNotPressed;
	while (1) {

		State =Btn_GetState(Btn1,BUTTON_SINK);
		//DIO_ReadValueForPin(DIO_GroupC, DIO_pin0, &State);
		// read(PINC_Reg, 0);
		//State2 = read(PINC_Reg, 1);
		State2 =Btn_GetState(Btn2,BUTTON_SINK);

		//DIO_ReadValueForPin(DIO_GroupC, DIO_pin1, &State2);
		//State3 = read(PINC_Reg,2);
		State3 =Btn_GetState(Btn3,BUTTON_SINK);
		//DIO_ReadValueForPin(DIO_GroupC, DIO_pin2, &State3);

		if (oldState == SinkNotPressed && State == SinkPressed) {
			SS_WriteNumber(counter,SS2);
			counter++;
			if (counter > 9) {
				counter = 0;
			}
		}
		oldState = State;
		if (State2 == SinkPressed) {
			//set(PORTC_Reg, 3);
			LED_ON(LED1,LED_SOURCE);
			//DIO_WriteValueForPin(DIO_GroupC, DIO_pin3, DIO_High);
		}
		else if (State2 == SinkNotPressed) {            //clear(PORTC_Reg, 3);
			LED_OFF(LED1,LED_SOURCE);

			//DIO_WriteValueForPin(DIO_GroupC, DIO_pin3, DIO_Low);
		}

		if (State3 == Pressed) {
			//toggle(PORTC_Reg,4);
			Buzzer_Toggle();
			//DIO_ToggleAtPin(DIO_GroupC, DIO_pin4);
			_delay_ms(100);
		}
		else if (State3 == notPressed) {
			//clear(PORTC_Reg,4);
			Buzzer_Off();
			//DIO_WriteValueForPin(DIO_GroupC, DIO_pin4, DIO_Low);

		}
	}
}

