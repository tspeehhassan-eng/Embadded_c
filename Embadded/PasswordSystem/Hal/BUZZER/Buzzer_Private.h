/*
 * Buzzer_Private.h
 *
 *  Created on: Aug 28, 2026
 *      Author: zbook g8
 */

#ifndef HAL_BUZZER_BUZZER_PRIVATE_H_
#define HAL_BUZZER_BUZZER_PRIVATE_H_

#include "../../Mcal/DIO/DIO_Private.h"
typedef struct
{
    DIO_GroupName_t GroupName;
    DIO_PinNo_t PinNo;
} Buzzer_Config_t;
typedef enum
{
    BUZZER_OFF ,
    BUZZER_ON

} Buzzer_State_t;
#endif /* HAL_BUZZER_BUZZER_PRIVATE_H_ */
