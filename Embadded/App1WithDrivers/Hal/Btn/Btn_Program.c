#include "Btn_Config.h"
#include "Btn_Private.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include <stdint.h>

static Button_Type Button1_Type;

static Button_Type Button2_Type;

static Button_Type Button3_Type;

void Btn_Init(uint8_t ConnectionState, uint8_t BtnNo) {
	switch (BtnNo) {
	case Btn1:
		Button1_Type = ConnectionState;

		if (ConnectionState == BUTTON_SINK) {
			DIO_EnableInternalPullUp( BUTTON0_Group, BUTTON0_Pin);
		} else if (ConnectionState == BUTTON_SOURCE) {
			DIO_DisableInternalPullUp( BUTTON0_Group, BUTTON0_Pin);
		}

		break;

	case Btn2:

		Button2_Type = ConnectionState;

		if (ConnectionState == BUTTON_SINK) {
			DIO_EnableInternalPullUp(BUTTON1_Group, BUTTON1_Pin);
		} else if (ConnectionState == BUTTON_SOURCE) {
			DIO_DisableInternalPullUp( BUTTON1_Group, BUTTON1_Pin);

		}

		break;

	case Btn3:

		Button3_Type = ConnectionState;

		if (ConnectionState == BUTTON_SINK) {
			DIO_EnableInternalPullUp(
			BUTTON2_Group,
			BUTTON2_Pin);
		} else if (ConnectionState == BUTTON_SOURCE) {
			DIO_DisableInternalPullUp( BUTTON2_Group, BUTTON2_Pin);
		}

		break;

	default:
		break;
	}
}

uint8_t Btn_GetState(uint8_t BtnNo, uint8_t ConnectionState) {
	uint8_t InputValue;

	switch (BtnNo) {
	case Btn1:
		DIO_ReadValueForPin(BUTTON0_Group, BUTTON0_Pin, &InputValue);

		if (ConnectionState == BUTTON_SINK) {
			if (InputValue == SinkNotPressed) {
				return SinkNotPressed;
			} else {
				return SinkPressed;
			}
		} else if (ConnectionState == BUTTON_SOURCE) {
			if (InputValue == SourceNotPressed) {
				return SourceNotPressed;
			} else {
				return SourcePressed;
			}
		} else {
			return 0;
			//error code
		}

		break;

	case Btn2:
		DIO_ReadValueForPin(BUTTON1_Group, BUTTON1_Pin, &InputValue);

		if (ConnectionState == BUTTON_SINK) {
			if (InputValue == SinkNotPressed) {
				return SinkNotPressed;
			} else {
				return SinkPressed;
			}
		} else if (ConnectionState == BUTTON_SOURCE) {
			if (InputValue == SourceNotPressed) {
				return SourceNotPressed;
			} else {
				return SourcePressed;
			}
		} else {
			return 0;

			//error code
		}
		break;
	case Btn3:
		DIO_ReadValueForPin(BUTTON2_Group, BUTTON2_Pin, &InputValue);

		if (ConnectionState == BUTTON_SINK) {
			if (InputValue == SinkNotPressed) {
				return SinkNotPressed;
			} else {
				return SinkPressed;
			}
		} else if (ConnectionState == BUTTON_SOURCE) {
			if (InputValue == SourceNotPressed) {
				return SourceNotPressed;
			} else {
				return SourcePressed;
			}
		} else {
			return 0;
			//error code
		}
		break;
	default:
		return 0;
	}

}
