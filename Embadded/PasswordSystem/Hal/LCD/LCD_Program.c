/*
 * LCD_Program.c
 *
 *  Created on: Aug 29, 2026
 *      Author: zbook g8
 */
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "../../Common/BitMath.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include <util/delay.h>
void LCD_Enable(void){
    DIO_WriteValueForPin(EN_Group, EN_Pin, DIO_High);
    _delay_us(50);
    DIO_WriteValueForPin(EN_Group, EN_Pin, DIO_Low);
    _delay_us(50);
}
void LCD_SendInstruction(uint8_t Instruction){
	DIO_WriteValueForPin(RS_Group, RS_Pin, DIO_Low);
	DIO_WriteValueForPin(RW_Group, RW_Pin, DIO_Low);
	//commend
	DIO_WriteValueForAll(LCD_DataPins_Group,Instruction);
	LCD_Enable();
}
void LCD_PrintData(uint8_t Character){
	DIO_WriteValueForPin(RS_Group, RS_Pin, DIO_High);
	DIO_WriteValueForPin(RW_Group, RW_Pin, DIO_Low);
	DIO_WriteValueForAll(LCD_DataPins_Group,Character);
	LCD_Enable();
}
void LCD_Init(){
#if Mode_8Bit==1
		DIO_SelectDirectionForAll(LCD_DataPins_Group,DIO_Output);
	    DIO_SelectDirectionForPin(RS_Group, RS_Pin, DIO_Output);
	    DIO_SelectDirectionForPin(RW_Group, RW_Pin, DIO_Output);
	    DIO_SelectDirectionForPin(EN_Group, EN_Pin, DIO_Output);

	 _delay_ms(30);


	 DIO_WriteValueForPin(RW_Group, RW_Pin, DIO_Low);
	 LCD_SendInstruction(Function_Set);
	 _delay_ms(1);
	 LCD_SendInstruction(Function_DisplayOnOff);
	 _delay_ms(1);
	 LCD_SendInstruction(Function_DisplayClear);
	 _delay_ms(2);
	 LCD_SendInstruction(Function_EntryMode);
#endif
}

void LCD_CreateSpecialChar(uint8_t *SpecialChar, uint8_t location)
{
    if (location < 8)
    {
        uint8_t Address = 0x40 | (location * 8);
        LCD_SendInstruction(Address);
        for (uint8_t i = 0; i < 8; i++)
        {
            LCD_PrintData(SpecialChar[i]);
        }
        LCD_CursorGoTo(0, 0);
    }
}




void LCD_WriteString(uint8_t *Word)
{
    while (*Word != '\0')
    {
        LCD_PrintData(*Word);
        Word++;
    }
}


void LCD_Clear()
{
    LCD_SendInstruction(Function_DisplayClear);
    _delay_ms(2);
}
void LCD_CursorGoTo(uint8_t Row, uint8_t Column)
{
    uint8_t Address;

    if (Row == 0)
    {
        Address = 0x00 + Column;
    }
    else
    {
        Address = 0x40 + Column;
    }

    Address |= 0x80;

    LCD_SendInstruction(Address);
}
