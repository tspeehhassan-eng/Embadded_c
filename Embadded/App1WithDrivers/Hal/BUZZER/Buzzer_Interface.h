/*
 * Buzzer_Interface.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_
#include "Buzzer_Private.h"
void Buzzer_Init(Buzzer_Config_t *Config);
void Buzzer_On(void);

void Buzzer_Off(void);

void Buzzer_Toggle(void);
#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
