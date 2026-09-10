/*
 * DCmotor_Private.h
 *
 *  Created on: Sep 5, 2026
 *      Author: zbook g8
 */

#ifndef HAL_DCMOTOR_DCMOTOR_PRIVATE_H_
#define HAL_DCMOTOR_DCMOTOR_PRIVATE_H_
#include <stdint.h>
typedef enum {
	Dc_WithHBridge,
	Dc_WithoutHBridge,
}DC_ConnectionType;

typedef struct
{
	DC_ConnectionType Dc_Connection;
    uint8_t M1Pin;
    uint8_t M1Group;
    uint8_t M2Pin;
    uint8_t M2Group;
}DC_Config;
#endif /* HAL_DCMOTOR_DCMOTOR_PRIVATE_H_ */
