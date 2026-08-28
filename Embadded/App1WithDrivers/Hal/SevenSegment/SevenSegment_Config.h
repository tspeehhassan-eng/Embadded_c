/*
 * SevenSegment_Config.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_CONFIG_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_CONFIG_H_
#include "../../Mcal/DIO/DIO_Private.h"
#include "../../Mcal/DIO/DIO_Interface.h"

#define SEGMENT1_GROUP    DIO_GroupC
#define SEGMENT2_GROUP    DIO_GroupD
#define SEGMENT_TYPE      COMMON_ANODE

#define SEGMENT1_A		DIO_pin0
#define SEGMENT1_B		DIO_pin1
#define SEGMENT1_C		DIO_pin2
#define SEGMENT1_D		DIO_pin3
#define SEGMENT1_E		DIO_pin4
#define SEGMENT1_F		DIO_pin5
#define SEGMENT1_G		DIO_pin6
#define SEGMENT1_H		DIO_pin7

#define SEGMENT2_A		DIO_pin0
#define SEGMENT2_B		DIO_pin1
#define SEGMENT2_C		DIO_pin2
#define SEGMENT2_D		DIO_pin3
#define SEGMENT2_E		DIO_pin4
#define SEGMENT2_F		DIO_pin5
#define SEGMENT2_G		DIO_pin6
#define SEGMENT2_H		DIO_pin7

#define AnodeZero   0xC0
#define AnodeOne    0xF9
#define AnodeTwo    0xA4
#define AnodeThree  0xB0
#define AnodeFour   0x99
#define AnodeFive   0x92
#define AnodeSix    0x82
#define AnodeSeven  0xF8
#define AnodeEight  0x80
#define AnodeNine   0x90



#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_CONFIG_H_ */
