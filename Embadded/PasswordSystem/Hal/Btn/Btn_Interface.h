/*
 * Btn_Interface.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BTN_BTN_INTERFACE_H_
#define HAL_BTN_BTN_INTERFACE_H_

void Btn_Init( uint8_t ConnectionState, uint8_t BtnNo);
uint8_t Btn_GetState(uint8_t ConnectionState, uint8_t BtnNo);

#endif /* HAL_BTN_BTN_INTERFACE_H_ */
