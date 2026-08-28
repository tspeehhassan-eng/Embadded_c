/*
 * DIO_Interface.h
 *
 *  Created on: Aug 25, 2026
 *      Author: zbook g8
 */
#include <stdint.h>
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
/*Direction

√ﬁÊ· ··‹Pin:

Input
Output
Output Value

·Ê Output:

High
Low
Input Value

·Ê Input:

√ﬁ—√ ﬁÌ„ Â.
Toggle

·Ê Output:

√ﬁ·» Õ«· Â.

ÊÂ‰« »œ√‰« ‰ﬂ ‘› «·‹API » «⁄ ‰«.**/

void DIO_SelectDirectionForPin(uint8_t GroupName,uint8_t PinNo , uint8_t Direction);
void DIO_SelectDirectionForAll(uint8_t GroupName , uint8_t Direction);

void DIO_WriteValueForPin(uint8_t GroupName,uint8_t PinNo , uint8_t OutputValue);
void DIO_WriteValueForAll(uint8_t GroupName, uint8_t OutputValue);

void DIO_ReadValueForPin(uint8_t GroupName,uint8_t PinNo,uint8_t *Inputvalue );
void DIO_ReadValueForAll(uint8_t GroupName, uint8_t *Inputvalue );

void DIO_ToggleAtPin(uint8_t GroupName,uint8_t PinNo );
void DIO_ToggleAtAll(uint8_t GroupName);

void DIO_EnableInternalPullUp(uint8_t GroupName,uint8_t PinNo );
void DIO_DisableInternalPullUp(uint8_t GroupName, uint8_t PinNo);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
