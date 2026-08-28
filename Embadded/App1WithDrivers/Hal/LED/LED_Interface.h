/*
 * LED_Interface.h
 *
 *  Created on: Aug 27, 2026
 *      Author: zbook g8
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include <stdint.h>

void LED_Init(uint8_t LED_ID, uint8_t GroupName, uint8_t PinNo);
void LED_ON(uint8_t LED_ID,uint8_t ConnectionState);
void LED_OFF(uint8_t LED_ID,uint8_t ConnectionState);
void LED_Toggle(uint8_t LED_ID);

#endif /* HAL_LED_LED_INTERFACE_H_ */
