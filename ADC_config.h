/*
 * ADC_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Khaled Waled
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    	ADC_VOLTAGE_REF_AREF 				*/
/*							ADC_VOLTAGE_REF_AVCC 				*/
/*				    		ADC_VOLTAGE_REF_2_56V				*/
/****************************************************************/

#define VOLTAGE_REFERENCE			ADC_VOLTAGE_REF_AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    				ADC_RIGHT_ADJUSTED		*/
/*							    		ADC_LEFT_ADJUSTED		*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*			is ADC_LEFT_ADJUSTED and for a 10 bits Resolution	*/
/*			is ADC_RIGHT_ADJUSTED								*/
/****************************************************************/

#define ADJUSTMENT				ADC_RIGHT_ADJUSTED


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*	    					ADC_MODE_AUTO_TRIGGER 				*/
/*	    				ADC_MODE_SINGLE_CONVERION 				*/
/*							    								*/
/****************************************************************/

#define ADC_MODE_SELECTOR		ADC_MODE_SINGLE_CONVERION

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					  		ADC_PRESCALER_CLR_MSK				*/
/*							ADC_PRESCALER_2_MSK					*/
/*							ADC_PRESCALER_4_MSK					*/
/*                   		ADC_PRESCALER_8_MSK					*/
/*                    		ADC_PRESCALER_16_MSK				*/
/*                    		ADC_PRESCALER_32_MSK				*/
/*                   		ADC_PRESCALER_64_MSK				*/
/*                    		ADC_PRESCALER_128_MSK				*/
/* 																*/
/****************************************************************/

#define ADC_PRESCALLER				ADC_PRESCALER_128_MSK

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*	    				ADC_AUTO_TRIG_SRC_CLR_MSK 				*/
/*	    				ADC_AUTO_TRIG_SRC_FREE_RUNNING_MSK		*/
/*						ADC_AUTO_TRIG_SRC_ANALOG_COMP_MSK 		*/
/*                      ADC_AUTO_TRIG_SRC_EXTI0_MSK 			*/
/*                      ADC_AUTO_TRIG_SRC_TIMER0_COMP_MSK 		*/
/*                      ADC_AUTO_TRIG_SRC_TIMER0_OVF_MSK 		*/
/*                      ADC_AUTO_TRIG_SRC_TIMER1_COMP_MSK 		*/
/*                      ADC_AUTO_TRIG_SRC_TIMER1_OVF_MSK 		*/
/*                      ADC_AUTO_TRIG_SRC_TIMER1_CAPT_MSK 		*/
/*																*/
/****************************************************************/

#define ADC_AUTO_TRIG_SRCE_SELECTOR		ADC_AUTO_TRIG_SRC_FREE_RUNNING_MSK

#define ADC_VOLTAGE_REF_mv			5000
#define ADC_MAX_NUMBER_OF_STEPS		1024



#endif /* ADC_CONFIG_H_ */
