/*
 * DIO_Program.c
 *
 *  Created on: Sep 7, 2026
 *      Author: zbook g8
 */
#include "../AtMega128Registers.h"
#include "DIO_Private.h"
#include "../../Common/BitMath.h"
void DIO_SelectDirectionForPin(uint8_t GroupName, uint8_t PinNo,uint8_t Direction) {
	volatile uint8_t *ptr = 0;

	switch (GroupName) {
	case DIO_GroupA:
		if (PinNo <= DIO_pin7)
			ptr = &DDRA_Reg;
		break;

	case DIO_GroupB:
		if (PinNo <= DIO_pin7)
			ptr = &DDRB_Reg;
		break;

	case DIO_GroupC:
		if (PinNo <= DIO_pin7)
			ptr = &DDRC_Reg;
		break;

	case DIO_GroupD:
		if (PinNo <= DIO_pin7)
			ptr = &DDRD_Reg;
		break;

	case DIO_GroupE:
		if (PinNo <= DIO_pin7)
			ptr = &DDRE_Reg;
		break;

	case DIO_GroupF:
		if (PinNo <= DIO_pin7)
			ptr = &DDRF_Reg;
		break;

	case DIO_GroupG:
		if (PinNo <= DIO_pin4)
			ptr = &DDRG_Reg;
		break;

	default:
		return;
	}

	if (ptr == 0)
		return;

	if (Direction == DIO_Input) {
		clear(*ptr, PinNo);
	} else if (Direction == DIO_Output) {
		set(*ptr, PinNo);
	} else {
		return;
	}
}
void DIO_SelectDirectionForAll(uint8_t GroupName, uint8_t Direction){

	switch(GroupName)
					{
						case DIO_GroupA: DDRA_Reg=Direction; break;
						case DIO_GroupB: DDRB_Reg=Direction; break;
						case DIO_GroupC: DDRC_Reg=Direction; break;
						case DIO_GroupD: DDRD_Reg=Direction; break;
						case DIO_GroupE: DDRE_Reg=Direction; break;
						case DIO_GroupF: DDRF_Reg=Direction; break;
						case DIO_GroupG: DDRG_Reg=Direction; break;
						default: return;/*error code*/
					}
}

void DIO_WriteValueForPin(uint8_t GroupName,
                          uint8_t PinNo,
                          uint8_t OutputValue)
{
    volatile uint8_t *ptr = 0;

    switch (GroupName)
    {
        case DIO_GroupA:
            if (PinNo <= DIO_pin7)
                ptr = &PORTA_Reg;
            break;

        case DIO_GroupB:
            if (PinNo <= DIO_pin7)
                ptr = &PORTB_Reg;
            break;

        case DIO_GroupC:
            if (PinNo <= DIO_pin7)
                ptr = &PORTC_Reg;
            break;

        case DIO_GroupD:
            if (PinNo <= DIO_pin7)
                ptr = &PORTD_Reg;
            break;

        case DIO_GroupE:
            if (PinNo <= DIO_pin7)
                ptr = &PORTE_Reg;
            break;

        case DIO_GroupF:
            if (PinNo <= DIO_pin7)
                ptr = &PORTF_Reg;
            break;

        case DIO_GroupG:
            if (PinNo <= DIO_pin4)
                ptr = &PORTG_Reg;
            break;

        default:
            return;
    }

    if (ptr == 0)
        return;

    if (OutputValue == DIO_High)
    {
        set(*ptr, PinNo);
    }
    else if (OutputValue == DIO_Low)
    {
        clear(*ptr, PinNo);
    }
    else
    {
        return;
    }
}
void DIO_WriteValueForAll(uint8_t GroupName, uint8_t OutputValue){
	switch(GroupName)
						{
							case DIO_GroupA: PORTA_Reg=OutputValue; break;
							case DIO_GroupB: PORTB_Reg=OutputValue; break;
							case DIO_GroupC: PORTC_Reg=OutputValue; break;
							case DIO_GroupD: PORTD_Reg=OutputValue; break;
							case DIO_GroupE: PORTE_Reg=OutputValue; break;
							case DIO_GroupF: PORTF_Reg=OutputValue; break;
							case DIO_GroupG: PORTG_Reg=OutputValue; break;

							default: return;/*error code*/
						}
}

void DIO_ReadValueForPin(uint8_t GroupName,
                            uint8_t PinNo,
                            uint8_t *InputValue)
{
    volatile uint8_t *ptr = 0;

    switch (GroupName)
    {
        case DIO_GroupA:
            if (PinNo <= DIO_pin7)
                ptr = &PINA_Reg;
            break;

        case DIO_GroupB:
            if (PinNo <= DIO_pin7)
                ptr = &PINB_Reg;
            break;

        case DIO_GroupC:
            if (PinNo <= DIO_pin7)
                ptr = &PINC_Reg;
            break;

        case DIO_GroupD:
            if (PinNo <= DIO_pin7)
                ptr = &PIND_Reg;
            break;

        case DIO_GroupE:
            if (PinNo <= DIO_pin7)
                ptr = &PINE_Reg;
            break;

        case DIO_GroupF:
            if (PinNo <= DIO_pin7)
                ptr = &PINF_Reg;
            break;

        case DIO_GroupG:
            if (PinNo <= DIO_pin4)
                ptr = &PING_Reg;
            break;

        default:
            return;
    }

    if (ptr == 0){return;}


    *InputValue = read(*ptr, PinNo);
}
void DIO_ReadValueForAll(uint8_t GroupName, uint8_t *Inputvalue)
{
    switch(GroupName)
    {
        case DIO_GroupA:
            *Inputvalue = PINA_Reg;
            break;

        case DIO_GroupB:
            *Inputvalue = PINB_Reg;
            break;

        case DIO_GroupC:
            *Inputvalue = PINC_Reg;
            break;

        case DIO_GroupD:
            *Inputvalue = PIND_Reg;
            break;

        case DIO_GroupE:
            *Inputvalue = PINE_Reg;
            break;

        case DIO_GroupF:
            *Inputvalue = PINF_Reg;
            break;

        case DIO_GroupG:
            *Inputvalue = PING_Reg;
            break;

        default:
            return;
    }
}

void DIO_ToggleAtPin(uint8_t GroupName, uint8_t PinNo)
{
    volatile uint8_t *ptr = 0;

    switch(GroupName)
    {
        case DIO_GroupA:
            if (PinNo <= DIO_pin7)
                ptr = &PORTA_Reg;
            break;

        case DIO_GroupB:
            if (PinNo <= DIO_pin7)
                ptr = &PORTB_Reg;
            break;

        case DIO_GroupC:
            if (PinNo <= DIO_pin7)
                ptr = &PORTC_Reg;
            break;

        case DIO_GroupD:
            if (PinNo <= DIO_pin7)
                ptr = &PORTD_Reg;
            break;

        case DIO_GroupE:
            if (PinNo <= DIO_pin7)
                ptr = &PORTE_Reg;
            break;

        case DIO_GroupF:
            if (PinNo <= DIO_pin7)
                ptr = &PORTF_Reg;
            break;

        case DIO_GroupG:
            if (PinNo <= DIO_pin4)
                ptr = &PORTG_Reg;
            break;

        default:
            return;
    }

    if (ptr == 0)
        return;

    toggle(*ptr, PinNo);
}
void DIO_ToggleAtAll(uint8_t GroupName)
{
    switch(GroupName)
    {
        case DIO_GroupA:
            PORTA_Reg ^= 0xFF;
            break;

        case DIO_GroupB:
            PORTB_Reg ^= 0xFF;
            break;

        case DIO_GroupC:
            PORTC_Reg ^= 0xFF;
            break;

        case DIO_GroupD:
            PORTD_Reg ^= 0xFF;
            break;

        case DIO_GroupE:
            PORTE_Reg ^= 0xFF;
            break;

        case DIO_GroupF:
            PORTF_Reg ^= 0xFF;
            break;

        case DIO_GroupG:
            PORTG_Reg ^= 0x1F;
            break;

        default:
            return;
    }
}
void DIO_EnableInternalPullUp(uint8_t GroupName, uint8_t PinNo)
{
    DIO_SelectDirectionForPin(GroupName, PinNo, DIO_Input);

    DIO_WriteValueForPin(GroupName, PinNo, DIO_High);
}
void DIO_DisableInternalPullUp(uint8_t GroupName, uint8_t PinNo)
{
    DIO_SelectDirectionForPin(GroupName, PinNo, DIO_Input);

    DIO_WriteValueForPin(GroupName, PinNo, DIO_Low);
}
