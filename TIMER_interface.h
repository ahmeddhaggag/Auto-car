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

void Timer0_voidInit(void);

u8 Timer0_u8OvSetCallBack(void (*Copy_pvCallBackFunc)(void));

void Timer0_voidGeneratePWM(u8 Copy_u8DutyCycle);

void Timer2_voidGeneratePWM(u8 Copy_u8DutyCycle);

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue);



#endif
