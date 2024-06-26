/*******************************************************************/
/*******************************************************************/
/*****************   Author: Ahmed D. Haggag	********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define OC1A_PIN 0       //PORTD PIN5
#define OC1B_PIN 1       //PORTD PIN4

#define RISING_EDGE 0
#define FALLING_EDGE 1

void Timer0_voidInit(void);

u8 Timer0_u8OvSetCallBack(void (*Copy_pvCallBackFunc)(void));

void Timer0_voidGeneratePWM(u8 Copy_u8DutyCycle);

void Timer1_voidGeneratePWM(u8 Copy_u8Pin, u8 Copy_u8DutyCycle);

void Timer1_voidInputCapture(u8 Copy_u8Edge);

u32 Timer1_u32MeasurePulseDuration();

void Timer2_voidGeneratePWM(u8 Copy_u8DutyCycle);

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue);



#endif
