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
    clear(DDRC_Reg, 0);
    set(PORTC_Reg, 0);

    clear(DDRC_Reg, 1);
    set(PORTC_Reg, 1);

    clear(DDRC_Reg, 2);
    set(PORTC_Reg, 2);

    set(DDRC_Reg, 3);
    set(DDRC_Reg, 4);

    DDRD_Reg = 0xFF;

    uint8_t State = notPressed;
    uint8_t oldState = notPressed;
    uint8_t counter = 0;
    uint8_t State2 = notPressed;
    uint8_t State3 = notPressed;

    while (1)
    {
        State = read(PINC_Reg, 0);
        State2 = read(PINC_Reg, 1);
        State3 = read(PINC_Reg,2);

        if (oldState == notPressed && State == Pressed)
        {
            switch (counter)
            {
                case 0:
                    PORTD_Reg = AnodeZero;
                    break;

                case 1:
                    PORTD_Reg = AnodeOne;
                    break;

                case 2:
                    PORTD_Reg = AnodeTwo;
                    break;

                case 3:
                    PORTD_Reg = AnodeThree;
                    break;

                case 4:
                    PORTD_Reg = AnodeFour;
                    break;

                case 5:
                    PORTD_Reg = AnodeFive;
                    break;

                case 6:
                    PORTD_Reg = AnodeSix;
                    break;

                case 7:
                    PORTD_Reg = AnodeSeven;
                    break;

                case 8:
                    PORTD_Reg = AnodeEight;
                    break;

                case 9:
                    PORTD_Reg = AnodeNine;
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
            set(PORTC_Reg, 3);
        }
        else if (State2 == notPressed)
        {
            clear(PORTC_Reg, 3);
        }

        if(State3==Pressed){
        	toggle(PORTC_Reg,4);
        	_delay_ms(100);
        }
        else if(State3==notPressed){
        	clear(PORTC_Reg,4);
        }
    }
}
