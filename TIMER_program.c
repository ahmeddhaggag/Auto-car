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
#if WGM_MODE == FAST_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
#endif
#if TIMER0_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#endif
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	OCR0 = (u8)floorf(Copy_u8DutyCycle*256/100) - 1;

}


void Timer1_voidGeneratePWM(u8 Copy_u8Pin, u8 Copy_u8DutyCycle){
#if WGM_MODE == FAST_PWM
	SET_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1A, TCCR1B_WGM12);
#endif
#if TIMER0_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
#endif
    if(Copy_u8Pin == OC1A_PIN ){
	SET_BIT(TCCR1A, TCCR1A_COMA0);
	SET_BIT(TCCR1A, TCCR1A_COMA1);
	OCR1AL = (u8)floorf(Copy_u8DutyCycle*255/100);
    } else if(Copy_u8Pin == OC1B_PIN){
    	SET_BIT(TCCR1A, TCCR1A_COMB0);
    	SET_BIT(TCCR1A, TCCR1A_COMB1);
	OCR1BL = (u8)floorf(Copy_u8DutyCycle*256/100) - 1;

    }
}


void Timer1_voidInputCapture(u8 Copy_u8Edge){
	TCCR1A =0;
	TCCR1B =0;
#if TIMER0_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
#endif

	if(Copy_u8Edge%2 == 0){
		SET_BIT(TCCR1B, TCCR1B_ICES1);
	}else{
		CLR_BIT(TCCR1B, TCCR1B_ICES1);
	}
//	SET_BIT(TIMSK, 5);

}


u16 Timer1_u16MeasurePulseDuration(){
	u8 edge =0;
	u16 high =0, low =0;
		Timer1_voidInputCapture(edge++);
			while((TIFR & (1<<ICF1)) == 0);
			high = ICR1L;
			high += (ICR1H<<8);
			TIFR =  (1<<ICF1);
			Timer1_voidInputCapture(edge++);
			while((TIFR & (1<<ICF1)) == 0);
			low = ICR1L;
			low += (ICR1H<<8);
			TIFR =  (1<<ICF1);
			if(low < high){
				low+= 65536;
			}

			return high - low;
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
	CLR_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	OCR2 = (u8)floorf(Copy_u8DutyCycle*256/100) - 1;

}


//void _vector_7(void)__attribute__((signal));
//void _vector_7(void){
//
//
//}
