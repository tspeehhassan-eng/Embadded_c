/*
 * SevenSegment_Program.c
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */
#include <stdint.h>
#include "SevenSegment_Private.h"
#include "SevenSegment_Config.h"
#include "../../Mcal/DIO/DIO_Interface.h"
uint8_t Numbers[10] = {
 0xC0,
 0xF9,
 0xA4,
 0xB0,
 0x99,
 0x92,
 0x82,
 0xF8,
 0x80,
0x90 };

void SS_WriteNumber(uint8_t Number, uint8_t SS_No) {
	switch (SS_No) {
	case SS1:
		DIO_SelectDirectionForAll(SEGMENT1_GROUP, DIO_AllOutput);
		DIO_WriteValueForAll(SEGMENT1_GROUP,Numbers[Number]);
	break;
	case SS2:
		DIO_SelectDirectionForAll(SEGMENT2_GROUP, DIO_AllOutput);
		DIO_WriteValueForAll(SEGMENT2_GROUP,Numbers[Number]);

		break;
	}
}

