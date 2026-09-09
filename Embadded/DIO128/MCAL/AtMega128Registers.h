/*
 * AtMega128Registers.h
 *
 *  Created on: Sep 9, 2026
 *      Author: zbook g8
 */

#ifndef MCAL_ATMEGA128REGISTERS_H_
#define MCAL_ATMEGA128REGISTERS_H_


#include <stdint.h>

/* PORT A */
#define PORTA_Reg   *((volatile uint8_t*)0x3B)
#define DDRA_Reg    *((volatile uint8_t*)0x3A)
#define PINA_Reg    *((volatile uint8_t*)0x39)

/* PORT B */
#define PORTB_Reg   *((volatile uint8_t*)0x38)
#define DDRB_Reg    *((volatile uint8_t*)0x37)
#define PINB_Reg    *((volatile uint8_t*)0x36)

/* PORT C */
#define PORTC_Reg   *((volatile uint8_t*)0x35)
#define DDRC_Reg    *((volatile uint8_t*)0x34)
#define PINC_Reg    *((volatile uint8_t*)0x33)

/* PORT D */
#define PORTD_Reg   *((volatile uint8_t*)0x32)
#define DDRD_Reg    *((volatile uint8_t*)0x31)
#define PIND_Reg    *((volatile uint8_t*)0x30)

/* PORT E */
#define PORTE_Reg   *((volatile uint8_t*)0x22)
#define DDRE_Reg    *((volatile uint8_t*)0x21)
#define PINE_Reg    *((volatile uint8_t*)0x20)

/* PORT F */
#define PORTF_Reg   *((volatile uint8_t*)0x32)
#define DDRF_Reg    *((volatile uint8_t*)0x31)
#define PINF_Reg    *((volatile uint8_t*)0x30)

/* PORT G */
#define PORTG_Reg   *((volatile uint8_t*)0x34)
#define DDRG_Reg    *((volatile uint8_t*)0x33)
#define PING_Reg    *((volatile uint8_t*)0x32)



#endif /* MCAL_ATMEGA128REGISTERS_H_ */
