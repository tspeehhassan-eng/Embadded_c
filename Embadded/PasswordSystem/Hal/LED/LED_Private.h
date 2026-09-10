/*
 * LED_Private.h
 *
 *  Created on: Aug 27, 2026
 *      Author: zbook g8
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_
#include "../../Mcal/DIO/DIO_Private.h"

typedef enum
{
    LED1,
    LED2,
    LED3,
    LED4,
    LED5,
    LED6,
    LED7,
    LED8,

} LED_ID_t;

typedef struct
{
	DIO_GroupName_t GroupName;
	    DIO_PinNo_t PinNo;
} LED_Config_t;

typedef enum
{
    LED_SINK,
    LED_SOURCE
} LED_Type;

typedef enum
{
	 SinkLED_ON,
	 SinkLED_OFF
} LED_Sink;

typedef enum
{
	SourceLED_OFF,
	SourceLED_ON

} LED_Source;


#endif /* HAL_LED_LED_PRIVATE_H_ */
