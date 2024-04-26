/*******************************************************************/
/*******************************************************************/
/*****************   Author: Ahmed D. Haggag	********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include<math.h>
#include<avr/io.h>
#include "STD_TYPES.h"
#include "bitmath.h"

#include "TIMER_private.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"



void Timer0_voidGeneratePWM(u8 Copy_u8DutyCycle){
	TCCR0 = 0;
#if WGM_MODE == FAST_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
#endif
#if TIMER0_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#endif
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	OCR0 = (u8)floorf(Copy_u8DutyCycle*255/100);

}


void Timer2_voidGeneratePWM(u8 Copy_u8DutyCycle){
	TCCR2 = 0;
#if WGM_MODE == FAST_PWM
	SET_BIT(TCCR2, TCCR0_WGM00);
	SET_BIT(TCCR2, TCCR0_WGM01);
#endif
#if TIMER0_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);
#endif
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	OCR2 = (u8)floorf(Copy_u8DutyCycle*255/100);

}
