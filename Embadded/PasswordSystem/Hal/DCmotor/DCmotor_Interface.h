/*
 * DCmotor_Interface.h
 *
 *  Created on: Sep 5, 2026
 *      Author: zbook g8
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/DIO/DIO_Private.h"
#include "DCmotor_Private.h"

void DC_Init(DC_Config *config);
///////////
void DC_On(DC_Config *config);
void DC_OFF(DC_Config *config);
///////////
void DC_OnCW(DC_Config *config);
void DC_OnCCW(DC_Config *config);
#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
