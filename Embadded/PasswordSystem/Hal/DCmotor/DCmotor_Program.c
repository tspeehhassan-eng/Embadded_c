/*
 * DCmotor_Program.c
 *
 *  Created on: Sep 5, 2026
 *      Author: zbook g8
 */
#include "DCmotor_Private.h"
#include "DCmotor_Interface.h"
//#include "../../Mcal/DIO/DIO_Interface.h"
//#include "../../Mcal/DIO/DIO_Private.h"
void DC_Init(DC_Config *DC_Config) {
	if (DC_Config->Dc_Connection == Dc_WithHBridge) {
		DIO_SelectDirectionForPin(DC_Config->M1Group, DC_Config->M1Pin,
				DIO_Output);
		DIO_SelectDirectionForPin(DC_Config->M2Group, DC_Config->M2Pin,
				DIO_Output);

	} else if (DC_Config->Dc_Connection == Dc_WithoutHBridge) {
		DIO_SelectDirectionForPin(DC_Config->M1Group, DC_Config->M1Pin,
				DIO_Output);

	} else {

	}
}
void DC_On(DC_Config *DC_Config) {
	if (DC_Config->Dc_Connection == Dc_WithoutHBridge) {
		DIO_WriteValueForPin(DC_Config->M1Group, DC_Config->M1Pin ,DIO_High);

	}
	else {

	}
}
void DC_OFF(DC_Config *DC_Config) {
	if (DC_Config->Dc_Connection == Dc_WithoutHBridge) {
		DIO_WriteValueForPin(DC_Config->M1Group, DC_Config->M1Pin ,DIO_Low);

	}
	else if (DC_Config->Dc_Connection == Dc_WithHBridge) {
		DIO_WriteValueForPin(DC_Config->M1Group, DC_Config->M1Pin ,DIO_Low);
		DIO_WriteValueForPin(DC_Config->M2Group, DC_Config->M2Pin ,DIO_Low);

	} else {

	}
}
///////////
void DC_OnCW(DC_Config *DC_Config){
	if (DC_Config->Dc_Connection == Dc_WithHBridge) {
		DIO_WriteValueForPin(DC_Config->M1Group, DC_Config->M1Pin ,DIO_High);
		DIO_WriteValueForPin(DC_Config->M2Group, DC_Config->M2Pin ,DIO_Low);
	}
	else{

	}
}
void DC_OnCCW(DC_Config *DC_Config){
	if (DC_Config->Dc_Connection == Dc_WithHBridge) {
		DIO_WriteValueForPin(DC_Config->M1Group, DC_Config->M1Pin ,DIO_Low);
		DIO_WriteValueForPin(DC_Config->M2Group, DC_Config->M2Pin ,DIO_High);
	}
	else{

	}
}

