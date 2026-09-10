/*
 * Button_Interface.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_
#include <stdint.h>
void Button_Init(uint8_t Button_ID, uint8_t GroupName, uint8_t PinNo);
uint8_t Button_GetState(uint8_t Button_ID);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
