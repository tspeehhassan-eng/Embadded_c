/*
 * LCD_Interface.h
 *
 *  Created on: Aug 29, 2026
 *      Author: zbook g8
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include <stdint.h>

void LCD_Init();
void LCD_SendInstruction(uint8_t Instruction);
void LCD_PrintData(uint8_t Character);
void LCD_WriteString(uint8_t *Word);
void LCD_CursorGoTo(uint8_t Row, uint8_t Column);
void LCD_Clear();
void LCD_CreateSpecialChar(uint8_t *SpecialChar,uint8_t location );
void LCD_Enable();
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
