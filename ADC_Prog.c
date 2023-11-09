/*
 * ADC_prog.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Khaled Waled
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "DIO_interface.h"

static void (*ADC_Callback)(void) = NULL ;

void __vector_16(void) __attribute__ ((signal,used, externally_visible)); //to avoid optimization

void ADC_voidInit(void)
{
	/* **************** Select Voltage Reference **************** */
	ADMUX &= ADC_VOLTAGE_REF_CLR_MSK ;
	ADMUX |= VOLTAGE_REFERENCE ;
	/* **************** Select ADC MODE ************************* */
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	SET_BIT(ADCSRA, 5);
	SFIOR &= ADC_AUTO_TRIG_SRC_CLR_MSK ;
	SFIOR |= ADC_AUTO_TRIG_SRCE_SELECTOR;
#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERION
	 CLR_BIT(ADCSRA, 5);
#endif
	/* **************** Select ADJUSTMENT *********************** */
#if ADJUSTMENT == ADC_RIGHT_ADJUSTED
	CLR_BIT(ADMUX, 5);

#elif ADJUSTMENT == ADC_LEFT_ADJUSTED
	SET_BIT(ADMUX, 5);
#endif
	/* **************** Select Clear Interrupt Flag ************* */
	SET_BIT(ADCSRA, 4);
	/* **************** Enable ADC ****************************** */
	SET_BIT(ADCSRA, 7);
}
void ADC_voidStartConversion(ADC_Channel_t ADC_Channel)
{
	/* **************** Select ADC Channel ****************************** */
	ADMUX &= ADC_CHANNEL_SELECTOR_clr_msk ;
	ADMUX |= ADC_Channel ;
	/* **************** ADC Start Conversion ****************************** */
	SET_BIT(ADCSRA, 6);
}
u16 ADC_voidGetResoult(void)
{
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	return ADCLH;
#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERION
	while((GET_BIT(ADCSRA, 6))); // while(!ADCSRA)
	return ADCLH;
#endif

}

void ADC_EnableInt0(void)
{
	SET_BIT(ADCSRA, 3);
}
void ADC_DesableInt0(void)
{
	CLR_BIT(ADCSRA, 3);
}
void ADC_SetCallback(void (*CopyFuncPtr)(void))
{
	ADC_Callback = CopyFuncPtr ;
}

void __vector_16(void)
{
	if(ADC_Callback)
	{
		ADC_Callback();

	}
}
