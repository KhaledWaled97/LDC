/*
 * ADC_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Khaled Waled
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
// ADC Special FunctionIO Register
#define SFIOR      (*(volatile u8*)(0x50))
#define ADMUX      (*(volatile u8*)(0x27))//(Voltage Reference Selection pin7 , pin6) & (MUX pin1 => pin4) & pin5
// ADC Prescaler Selections
#define ADCSRA     (*(volatile u8*)(0x26)) // ADPS pin0 => pin2
#define ADCSR     *((volatile u8 *)0x28)
// ADCL and ADCH
#define ADCH       (*(volatile u8*)(0x25))
#define ADCL       (*(volatile u8*)(0x24))
#define ADCLH       (*(volatile u16*)(0x24))


#define ADC_VOLTAGE_REF_CLR_MSK 0b00111111
#define ADC_VOLTAGE_REF_AVCC	0b01000000
#define ADC_VOLTAGE_REF_AREF	0b00000000
#define ADC_VOLTAGE_REF_2_56V	0b11000000
// ADC SELECT MODE
#define ADC_MODE_AUTO_TRIGGER 		1
#define ADC_MODE_SINGLE_CONVERION 	0
// ADC SELECT ADJUSTED
#define ADC_LEFT_ADJUSTED 			1
#define ADC_RIGHT_ADJUSTED 			0

#define ADC_PRESCALER_CLR_MSK		0b11111000
#define ADC_PRESCALER_2_MSK			0b00000000
#define ADC_PRESCALER_4_MSK			0b00000010
#define ADC_PRESCALER_8_MSK			0b00000011
#define ADC_PRESCALER_16_MSK		0b00000100
#define ADC_PRESCALER_32_MSK		0b00000101
#define ADC_PRESCALER_64_MSK		0b00000110
#define ADC_PRESCALER_128_MSK		0b00000111

// AUTO TRIGGER SELECT
#define ADC_AUTO_TRIG_SRC_CLR_MSK 			0b00011111
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_MSK 	0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_MSK 	0b00100000
#define ADC_AUTO_TRIG_SRC_EXTI0_MSK 		0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_MSK 	0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_MSK 	0b10000000
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_MSK 	0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_MSK 	0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_MSK 	0b11100000

// ADC MASK TO CLR Channel
#define ADC_CHANNEL_SELECTOR_clr_msk		0b11100000

#endif /* ADC_PRIVATE_H_ */
