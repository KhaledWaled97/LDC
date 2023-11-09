/*
 * ADC_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Khaled Waled
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "STD_TYPES.h"
typedef enum
{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
}ADC_Channel_t;

void ADC_voidInit(void);
void ADC_voidStartConversion(ADC_Channel_t ADC_Channel);
u16 ADC_voidGetResoult(void);
void ADC_EnableInt0(void);
void ADC_DesableInt0(void);
void ADC_SetCallback(void (*CopyFuncPtr)(void));



#endif /* ADC_INTERFACE_H_ */
