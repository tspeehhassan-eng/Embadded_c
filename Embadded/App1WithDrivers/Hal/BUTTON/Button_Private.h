/*
 * Button_Private.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BUTTON_BUTTON_PRIVATE_H_
#define HAL_BUTTON_BUTTON_PRIVATE_H_
#include"../../Mcal/DIO/DIO_Private.h"
typedef enum {
	BUTTON1, BUTTON2, BUTTON3
} Button_ID_t;
typedef enum {
	BUTTON_PRESSED,
	BUTTON_NOT_PRESSED
} Button_State_t;
typedef struct {
	DIO_GroupName_t GroupName;
	DIO_PinNo_t PinNo;
} Button_Config_t;

#endif /* HAL_BUTTON_BUTTON_PRIVATE_H_ */
