/*
 * main.c
 *
 *  Created on: Oct 4, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interfac.h"
#include "ADC_interface.h"
#include "util/delay.h"

int main()
{

	//RES & LDR
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID, PIN7, PIN_HIGH);
	//LCD
//	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTB_ID, PIN1, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTB_ID, PIN2, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_OUTPUT);
//	DIO_voidSetPinDirection(PORTA_ID, PIN3, PIN_OUTPUT);
	//button
	DIO_voidSetPinDirection(PORTD_ID, PIN7, PIN_INPUT);
//	DIO_voidSetPinDirection(PORTD_ID, PIN6, PIN_INPUT);
//	DIO_voidSetPinDirection(PORTD_ID, PIN5, PIN_INPUT);
//	DIO_voidSetPinDirection(PORTD_ID, PIN3, PIN_INPUT);
	//LED
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT);//red
	DIO_voidSetPinDirection(PORTA_ID, PIN4, PIN_OUTPUT);//green
	DIO_voidSetPinDirection(PORTA_ID, PIN5, PIN_OUTPUT);//blue
	DIO_voidSetPinDirection(PORTA_ID, PIN6, PIN_OUTPUT);//yellow

	HLCD_voidLcdIntiate();
	ADC_voidInit();
	ADC_EnableInt0();
	volatile u16 ret = 0;
	//u8 Str_Val[8];
	u8 Current = PIN_LOW ;
	u8 Previous = PIN_LOW ;

while(1)
{
	Current = DIO_u8GetPinValue(PORTD_ID, PIN7);
		ADC_voidStartConversion(ADC_Channel_0);
		ret = ADC_voidGetResoult();

	if(Current == PIN_HIGH && Previous == PIN_LOW)
	{
		//itoa(ret, Str_Val, 10);
		HLCD_voidLcdWriteIntiger(ret, 1, 9);

		if(ret < 1023 && ret > 768)
		{
			//red
			DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_HIGH);
			DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN5, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN6, PIN_LOW);
		}
		else if(ret < 768 && ret > 513)
		{
			//green
			DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_HIGH);
			DIO_voidSetPinValue(PORTA_ID, PIN5, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN6, PIN_LOW);
		}
		else if(ret < 513 && ret > 258)
		{
			//blue
			DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN5, PIN_HIGH);
			DIO_voidSetPinValue(PORTA_ID, PIN6, PIN_LOW);
		}
		else if(ret < 258 && ret > 0)
		{
			//yellow
			DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN5, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN6, PIN_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN4, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN5, PIN_LOW);
			DIO_voidSetPinValue(PORTA_ID, PIN6, PIN_LOW);
		}
	}
	else if(Current == PIN_LOW && Previous == PIN_HIGH)
	{
		HLCD_voidLcdClear();
	}


}

	return 0;
}

