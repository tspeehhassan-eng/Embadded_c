/*
 * LCD_Config.h
 *
 *  Created on: Aug 29, 2026
 *      Author: zbook g8
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
#include"../../Mcal/DIO/DIO_Private.h"
#define Mode_8Bit    1
#define RS_Group 	DIO_GroupD
#define RS_Pin 		DIO_pin0

#define RW_Group 	DIO_GroupD
#define RW_Pin 		DIO_pin1

#define EN_Group 	DIO_GroupD
#define EN_Pin 		DIO_pin2
#if Mode_8Bit==1

#define Function_Set           0x38
#define Function_DisplayOnOff  0x0C
#define Function_DisplayClear  0x01
#define Function_EntryMode     0x06

#define LCD_DataPins_Group 	DIO_GroupC
#define D0_Pin 		DIO_pin0
#define D1_Pin 		DIO_pin1
#define D2_Pin 		DIO_pin2
#define D3_Pin 		DIO_pin3
#define D4_Pin 		DIO_pin4
#define D5_Pin 		DIO_pin5
#define D6_Pin 		DIO_pin6
#define D7_Pin 		DIO_pin7
#elif Mode_8Bit ==0
#define LCD_DataPins_Group 	DIO_GroupC
#define D4_Pin 		DIO_pin4
#define D5_Pin 		DIO_pin5
#define D6_Pin 		DIO_pin6
#define D7_Pin 		DIO_pin7
#endif

#endif /* HAL_LCD_LCD_CONFIG_H_ */
