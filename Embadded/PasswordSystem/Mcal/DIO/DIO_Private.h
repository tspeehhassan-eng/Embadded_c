/*
 * DIO_Private.h
 *
 *  Created on: Aug 25, 2026
 *      Author: zbook g8
 */
// any value the user can select it
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_


typedef enum
{
	DIO_Input =0,
    DIO_Output= 1,
	DIO_AllOutput=0xFF,
	DIO_AllInput=0x00


}DIO_Direction_t;

typedef enum{
	DIO_Low,
	DIO_High,
	DIO_AllHigh=0xFF,
	DIO_AllLow=0x00,

}DIO_OutputValue_t;

typedef enum{
	DIO_GroupA=1,
	DIO_GroupB,
	DIO_GroupC,
	DIO_GroupD,
}DIO_GroupName_t;

typedef enum{
	DIO_pin0,
	DIO_pin1,
	DIO_pin2,
	DIO_pin3,
	DIO_pin4,
	DIO_pin5,
	DIO_pin6,
	DIO_pin7,

}DIO_PinNo_t;


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
