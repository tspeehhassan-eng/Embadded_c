
/*
 * DIO_Program.c
 *
 *  Created on: Aug 25, 2026
 *      Author: zbook g8
 */
#include "../AtMega32Registers.h"
#include "../../Common/BitMath.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_SelectDirectionForPin(uint8_t GroupName, uint8_t PinNo, uint8_t Direction)
{
	volatile uint8_t *ptr = 0;

	//if(GroupName<=DIO_GroupD && GroupName>=DIO_GroupA){ because i will check at group  name at switch case
		//if(PinNo>=DIO_pin0 && PinNo<=DIO_pin7){ because its unsigned positive only
		if(PinNo<=DIO_pin7)
		{
			switch(GroupName)
			{
				case DIO_GroupA: ptr=&DDRA_Reg; break;      //clear(DDRA_Reg, PinNo); break;//here
				case DIO_GroupB: ptr=&DDRB_Reg; break;      // clear(DDRB_Reg, PinNo); break;
				case DIO_GroupC: ptr=&DDRC_Reg; break;      //clear(DDRC_Reg, PinNo); break;
				case DIO_GroupD: ptr=&DDRD_Reg; break;      //clear(DDRD_Reg, PinNo); break;
				default: return;/*error code*/
			}

			if(Direction==DIO_Input)
			{
				clear(*ptr, PinNo);
			}
			else if(Direction==DIO_Output)
			{
				/*switch(GroupName){
				  case DIO_GroupA: set(DDRA_Reg, PinNo); break;// avoid Repetition
				  case DIO_GroupB: set(DDRB_Reg, PinNo); break;
				  case DIO_GroupC: set(DDRC_Reg, PinNo); break;
				  case DIO_GroupD: set(DDRD_Reg, PinNo); break;

								}*/
				set(*ptr, PinNo);
			}
			else
			{
				return;//error code
			}
		}
	}
//}


void DIO_SelectDirectionForAll(uint8_t GroupName , uint8_t Direction){

	switch(GroupName)
				{
					case DIO_GroupA: DDRA_Reg=Direction; break;      //clear(DDRA_Reg, PinNo); break;//here
					case DIO_GroupB: DDRB_Reg=Direction; break;      // clear(DDRB_Reg, PinNo); break;
					case DIO_GroupC: DDRC_Reg=Direction; break;      //clear(DDRC_Reg, PinNo); break;
					case DIO_GroupD: DDRD_Reg=Direction; break;      //clear(DDRD_Reg, PinNo); break;
					default: return;/*error code*/
				}

}

void DIO_WriteValueForPin(uint8_t GroupName,uint8_t PinNo , uint8_t OutputValue){

	volatile uint8_t *ptr= 0;
	if(PinNo<=DIO_pin7)
	{
		switch(GroupName)
					{
						case DIO_GroupA: ptr=&PORTA_Reg; break;      //clear(DDRA_Reg, PinNo); break;//here
						case DIO_GroupB: ptr=&PORTB_Reg;break;      // clear(DDRB_Reg, PinNo); break;
						case DIO_GroupC: ptr=&PORTC_Reg; break;      //clear(DDRC_Reg, PinNo); break;
						case DIO_GroupD: ptr=&PORTD_Reg; break;      //clear(DDRD_Reg, PinNo); break;
						default: return;/*error code*/
					}
		if(OutputValue==DIO_High){
			set(*ptr,PinNo);
		}
		else if(OutputValue==DIO_Low){
					clear(*ptr, PinNo);
				}
		else{
			return;
		}
	}






}

void DIO_WriteValueForAll(uint8_t GroupName, uint8_t OutputValue){
	switch(GroupName)
					{
						case DIO_GroupA: PORTA_Reg=OutputValue; break;
						case DIO_GroupB: PORTB_Reg=OutputValue; break;
						case DIO_GroupC: PORTC_Reg=OutputValue; break;
						case DIO_GroupD: PORTD_Reg=OutputValue; break;
						default: return;/*error code*/
					}

}

void DIO_ReadValueForPin(uint8_t GroupName,uint8_t PinNo,uint8_t *Inputvalue ){
	if(PinNo<=DIO_pin7){
		volatile uint8_t *ptr= 0;
		switch(GroupName)
							{
								case DIO_GroupA: ptr=&PINA_Reg; break;      //clear(DDRA_Reg, PinNo); break;//here
								case DIO_GroupB: ptr=&PINB_Reg;break;      // clear(DDRB_Reg, PinNo); break;
								case DIO_GroupC: ptr=&PINC_Reg; break;      //clear(DDRC_Reg, PinNo); break;
								case DIO_GroupD: ptr=&PIND_Reg; break;      //clear(DDRD_Reg, PinNo); break;
								default: return;/*error code*/
							}
		*Inputvalue=read(*ptr,PinNo);
	}
}
void DIO_ReadValueForAll(uint8_t GroupName, uint8_t *Inputvalue ){
	switch(GroupName)
								{
									case DIO_GroupA: *Inputvalue=PINA_Reg; break;
									case DIO_GroupB: *Inputvalue=PINB_Reg;break;
									case DIO_GroupC: *Inputvalue=PINC_Reg; break;
									case DIO_GroupD: *Inputvalue=PIND_Reg; break;
									default: return;/*error code*/
								}
}

void DIO_ToggleAtPin(uint8_t GroupName,uint8_t PinNo ){
	if(PinNo<=DIO_pin7){
		volatile uint8_t *ptr= 0;
				switch(GroupName)
									{
										case DIO_GroupA: ptr=&PORTA_Reg; break;      //clear(DDRA_Reg, PinNo); break;//here
										case DIO_GroupB: ptr=&PORTB_Reg;break;      // clear(DDRB_Reg, PinNo); break;
										case DIO_GroupC: ptr=&PORTC_Reg; break;      //clear(DDRC_Reg, PinNo); break;
										case DIO_GroupD: ptr=&PORTD_Reg; break;      //clear(DDRD_Reg, PinNo); break;
										default: return;/*error code*/
									}
				toggle(*ptr,PinNo);
	}
}


void DIO_ToggleAtAll(uint8_t GroupName)
{

				switch(GroupName)
									{
										case DIO_GroupA: PORTA_Reg^=0xFF; break;
										case DIO_GroupB: PORTB_Reg^=0xFF;break;
										case DIO_GroupC: PORTC_Reg^=0xFF; break;
										case DIO_GroupD: PORTD_Reg^=0xFF; break;
										default: return;/*error code*/
									}

}
/*
DDR = 0
PORT = 1  → Pull-up Enabled
PORT = 0  → Pull-up Disabled
*/
void DIO_EnableInternalPullUp(uint8_t GroupName, uint8_t PinNo)
{
    if (PinNo <= DIO_pin7)
    {
        DIO_SelectDirectionForPin(
            GroupName,
            PinNo,
            DIO_Input
        );

        DIO_WriteValueForPin(
            GroupName,
            PinNo,
            DIO_High
        );
    }
}
void DIO_DisableInternalPullUp(uint8_t GroupName, uint8_t PinNo)
{
    if (PinNo <= DIO_pin7)
    {
        DIO_SelectDirectionForPin(
            GroupName,
            PinNo,
            DIO_Input
        );

        DIO_WriteValueForPin(
            GroupName,
            PinNo,
            DIO_Low
        );
    }
}
