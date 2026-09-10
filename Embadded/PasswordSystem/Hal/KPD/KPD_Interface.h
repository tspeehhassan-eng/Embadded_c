/*
 * KPD_Interface.h
 *
 *  Created on: Sep 4, 2026
 *      Author: zbook g8
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_



#include <stdint.h>

#include "KPD_Private.h"
#include "KPD_Config.h"

void KPD_Init();
void KPD_GetKPDValue(uint8_t *KPD_Value);


#endif /* HAL_KPD_KPD_INTERFACE_H_ */
