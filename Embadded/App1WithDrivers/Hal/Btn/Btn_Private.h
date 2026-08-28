/*
 * Btn_Private.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BTN_BTN_PRIVATE_H_
#define HAL_BTN_BTN_PRIVATE_H_

typedef enum
{
    BUTTON_SINK,
    BUTTON_SOURCE
} Button_Type;

typedef enum
{
	 SinkPressed,
	 SinkNotPressed
} Button_Sink;

typedef enum
{
 SourceNotPressed,
SourcePressed ,
} Button_Source;


typedef enum
{ 	Btn1=1,
	Btn2,
	Btn3

} Button_Number;

#endif /* HAL_BTN_BTN_PRIVATE_H_ */
