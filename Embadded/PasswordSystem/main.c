#include <stdint.h>
#include <util/delay.h>

#include "Mcal/DIO/DIO_Interface.h"
#include "Mcal/DIO/DIO_Private.h"

#include "Hal/LED/LED_Interface.h"
#include "Hal/LED/LED_Private.h"

#include "Hal/BUZZER/Buzzer_Interface.h"
#include "Hal/BUZZER/Buzzer_Private.h"

#include "Hal/KPD/KPD_Interface.h"

Buzzer_Config_t Buzzer = {
		.GroupName = DIO_GroupC,
		.PinNo = DIO_pin0
};
int main(void)
{
	uint8_t passLength=3;
	uint8_t PressedKey = 0xFF;
	uint8_t password[3] = { '2', '5', '5' };
	uint8_t Enterpassword[10] = { 0 };
	uint8_t PasswordIndex = 0;
	uint8_t threetimes = 3;


	/* Initialize Keypad */
	KPD_Init();

	Buzzer_Init(&Buzzer);

	/* Initialize LEDs */
	LED_Init(LED1, DIO_GroupA, DIO_pin0);
	LED_Init(LED2, DIO_GroupA, DIO_pin1);
	LED_Init(LED3, DIO_GroupA, DIO_pin2);
	LED_Init(LED4, DIO_GroupA, DIO_pin3);
	LED_Init(LED5, DIO_GroupA, DIO_pin4);
	LED_Init(LED6, DIO_GroupA, DIO_pin5);
	LED_Init(LED7, DIO_GroupA, DIO_pin6);
	LED_Init(LED8, DIO_GroupA, DIO_pin7);

	while (1)
	{
		KPD_GetKPDValue(&PressedKey);

		if (PressedKey != 0xFF)
		{
			switch (PressedKey)
			{
				case 'C':

					for (uint8_t i = 0; i < passLength; i++)
					{
						if (password[i] != Enterpassword[i] || PasswordIndex!=passLength)
						{
							threetimes--;

							PasswordIndex = 0;

							LED_ON(LED1, LED_SOURCE);
							LED_ON(LED5, LED_SOURCE);
							LED_ON(LED8, LED_SOURCE);

							_delay_ms(1000);

							LED_OFF(LED1, LED_SOURCE);
							LED_OFF(LED5, LED_SOURCE);
							LED_OFF(LED8, LED_SOURCE);

							if (threetimes == 0)
							{
								while(1){
								LED_Toggle(LED1);
								LED_Toggle(LED5);
								LED_Toggle(LED8);
								Buzzer_Toggle();
								_delay_ms(1000);
								}
							}
							else
							{

							 if (threetimes == 2)
								{
									LED_ON(LED1, LED_SOURCE);
									LED_ON(LED2, LED_SOURCE);

									_delay_ms(3000);

									LED_OFF(LED1, LED_SOURCE);
									LED_OFF(LED2, LED_SOURCE);
								}
								else if (threetimes == 1)
								{
									LED_ON(LED1, LED_SOURCE);

									_delay_ms(3000);

									LED_OFF(LED1, LED_SOURCE);
								}
							}

							break;
						}
						else if (i == passLength-1 && password[i] == Enterpassword[i] && PasswordIndex==passLength)
						{
							LED_ON(LED3, LED_SOURCE);
							LED_ON(LED6, LED_SOURCE);

							_delay_ms(5000);

							LED_OFF(LED3, LED_SOURCE);
							LED_OFF(LED6, LED_SOURCE);

							LED_ON(LED1, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED1, LED_SOURCE);
							LED_ON(LED2, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED2, LED_SOURCE);
							LED_ON(LED3, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED3, LED_SOURCE);
							LED_ON(LED4, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED4, LED_SOURCE);
							LED_ON(LED5, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED5, LED_SOURCE);
							LED_ON(LED6, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED6, LED_SOURCE);
							LED_ON(LED7, LED_SOURCE);
							_delay_ms(1000);
							LED_OFF(LED7, LED_SOURCE);
							LED_ON(LED8, LED_SOURCE);
							_delay_ms(1000);

							LED_OFF(LED8, LED_SOURCE);



							return 0;
						}
					}

					break;

				default:
					Enterpassword[PasswordIndex] = PressedKey;
					PasswordIndex++;

					break;
			}

			PressedKey = 0xFF;
		}
	}
}
