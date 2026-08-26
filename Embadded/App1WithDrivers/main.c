/*
 * main.c

 *
 *  Created on: Aug 26, 2026
 *      Author: zbook g8
 */
#include "Mcal/DIO/DIO_Interface.h"
#include "Mcal/DIO/DIO_Private.h"

#include "Common/BitMath.h"
#include <util/delay.h>
#include "Mcal/AtMega32Registers.h"
#include <stdint.h>

#define notPressed 1
#define Pressed    0

#define AnodeZero   0xC0
#define AnodeOne    0xF9
#define AnodeTwo    0xA4
#define AnodeThree  0xB0
#define AnodeFour   0x99
#define AnodeFive   0x92
#define AnodeSix    0x82
#define AnodeSeven  0xF8
#define AnodeEight  0x80
#define AnodeNine   0x90

int main(void)
{

    DIO_EnableInternalPullUp(DIO_GroupC,DIO_pin0);

    DIO_EnableInternalPullUp(DIO_GroupC,DIO_pin1);

    DIO_EnableInternalPullUp(DIO_GroupC,DIO_pin2);

    //set(DDRC_Reg, 3);
    DIO_SelectDirectionForPin(DIO_GroupC,DIO_pin3,DIO_Output);

    //set(DDRC_Reg, 4);
    DIO_SelectDirectionForPin(DIO_GroupC,DIO_pin4,DIO_Output);

   // DDRD_Reg = 0xFF;
    DIO_SelectDirectionForAll(DIO_GroupD,DIO_AllOutput);



    uint8_t State = notPressed;
    uint8_t oldState = notPressed;
    uint8_t counter = 0;
    uint8_t State2 = notPressed;
    uint8_t State3 = notPressed;

    while (1)
    {
    	DIO_ReadValueForPin(DIO_GroupC,DIO_pin0,&State);
        //State = read(PINC_Reg, 0);
        //State2 = read(PINC_Reg, 1);
    	DIO_ReadValueForPin(DIO_GroupC,DIO_pin1,&State2);
        //State3 = read(PINC_Reg,2);
    	DIO_ReadValueForPin(DIO_GroupC,DIO_pin2,&State3);

        if (oldState == notPressed && State == Pressed)
        {
            switch (counter)
            {
                case 0:
                    //PORTD_Reg = AnodeZero;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeZero);
                    break;

                case 1:
                    //PORTD_Reg = AnodeOne;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeOne);

                    break;

                case 2:
                    //PORTD_Reg = AnodeTwo;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeTwo);

                    break;

                case 3:
                    //PORTD_Reg = AnodeThree;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeThree);

                    break;

                case 4:
                    //PORTD_Reg = AnodeFour;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeFour);

                    break;

                case 5:
                    //PORTD_Reg = AnodeFive;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeFive);

                    break;

                case 6:
                    //PORTD_Reg = AnodeSix;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeSix);

                    break;

                case 7:
                    //PORTD_Reg = AnodeSeven;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeSeven);

                    break;

                case 8:
                    //PORTD_Reg = AnodeEight;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeEight);

                    break;

                case 9:
                   // PORTD_Reg = AnodeNine;
                    DIO_WriteValueForAll(DIO_GroupD,AnodeNine);

                    break;
            }

            counter++;

            if (counter > 9)
            {
                counter = 0;
            }
        }

        oldState = State;

        if (State2 == Pressed)
        {
            //set(PORTC_Reg, 3);
            DIO_WriteValueForPin(DIO_GroupC,DIO_pin3,DIO_High);
        }
        else if (State2 == notPressed)
        {            //clear(PORTC_Reg, 3);

            DIO_WriteValueForPin(DIO_GroupC,DIO_pin3,DIO_Low);
        }

        if(State3==Pressed){
        	//toggle(PORTC_Reg,4);
        	DIO_ToggleAtPin(DIO_GroupC,DIO_pin4);
        	_delay_ms(100);
        }
        else if(State3==notPressed){
        	//clear(PORTC_Reg,4);
            DIO_WriteValueForPin(DIO_GroupC,DIO_pin4,DIO_Low);

        }
    }
}

