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
#include<avr/interrupt.h>
#include "STD_TYPES.h"
#include "bitmath.h"

#include "TIMER_private.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"


u8 ovf_count = 0;
u16 highEdge =0, lowEdge = 0;
u8 flag = 0;

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
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	OCR0 = (u8)floorf(Copy_u8DutyCycle*256/100) - 1;

}


void Timer1_voidGeneratePWM(u8 Copy_u8Pin, u8 Copy_u8DutyCycle){
	u16 CompareValue;
#if WGM_MODE == FAST_PWM
#if TIMER1_BIT_MODE == EIGHT_BIT
	SET_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1A, TCCR1B_WGM12);
#endif
#if TIMER1_BIT_MODE == NINE_BIT
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1A, TCCR1B_WGM12);
#endif
#if TIMER1_BIT_MODE == TEN_BIT
	SET_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1A, TCCR1B_WGM12);
#endif
#endif
#if TIMER1_u8_PRESCALER == DIVIDE_BY_256
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	CLR_BIT(TCCR1B, TCCR1B_CS11);
	SET_BIT(TCCR1B, TCCR1B_CS12);
#endif
    if(Copy_u8Pin == OC1A_PIN ){
	CLR_BIT(TCCR1A, TCCR1A_COMA0);
	SET_BIT(TCCR1A, TCCR1A_COMA1);
	CompareValue = (u16)floorf(Copy_u8DutyCycle*(TIMER1_BIT_MODE)/100) - 1;
	OCR1AL = CompareValue;
	OCR1AH = CompareValue>>8;
    } else if(Copy_u8Pin == OC1B_PIN){
    	CLR_BIT(TCCR1A, TCCR1A_COMB0);
    	SET_BIT(TCCR1A, TCCR1A_COMB1);
//	OCR1BL = (u8)floorf(Copy_u8DutyCycle*512/100) - 1;
	CompareValue = (u16)floorf(Copy_u8DutyCycle*(TIMER1_BIT_MODE)/100) - 1;
		OCR1BL = CompareValue;
		OCR1BH = CompareValue>>8;
    }

}


void Timer1_voidInputCapture(u8 Copy_u8Edge){
	TCCR1A =0;
	TCCR1B =0;
 //prescaler 8, tick time : 1 us
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);


	if(Copy_u8Edge%2 == 0){
		SET_BIT(TCCR1B, TCCR1B_ICES1);
	}else{
		CLR_BIT(TCCR1B, TCCR1B_ICES1);
	}


}

void __vector_9(void) __attribute__((signal));  //Timer1 overflow interrupt
void __vector_9(void){

	ovf_count++;

}

void __vector_6(void) __attribute__((signal));   //Timer1 Capture Interrupt
void __vector_6(void){
	if(flag == 0){
		highEdge = ICR1L;
		highEdge+= (ICR1H<<8);
		flag++;
		Timer1_voidInputCapture(1);
	}else{
		lowEdge = ICR1L;
	    lowEdge+= (ICR1H<<8);
		flag++;
	}


}



u32 Timer1_u32MeasurePulseDuration(){
	ovf_count = 0;
	flag = 0;
	Timer1_voidInputCapture(0);
	while(flag < 2);
	return ovf_count*65535 + lowEdge - highEdge;


}

//u16 Timer1_u16MeasurePulseDuration(){
//	u8 edge =0;
//	//u16 high =0, low =0;
//		Timer1_voidInputCapture(edge++);
//			while((TIFR & (1<<ICF1)) == 0);
//			high = ICR1L;
//			high += (ICR1H<<8);
//			TIFR =  (1<<ICF1);
//			Timer1_voidInputCapture(edge++);
//			while((TIFR & (1<<ICF1)) == 0);
//			low = ICR1L;
//			low += (ICR1H<<8);
//			TIFR =  (1<<ICF1);
//			if(lowEdge < highEdge){
////				high+= 65536;
//				return 65536 - highEdge + lowEdge;
//			}
//
//			return lowEdge - highEdge;
//}

void Timer2_voidGeneratePWM(u8 Copy_u8DutyCycle){
	TCCR2 = 0;
#if WGM_MODE == FAST_PWM
	SET_BIT(TCCR2, TCCR0_WGM00);
	SET_BIT(TCCR2, TCCR0_WGM01);
#endif
#if TIMER2_u8_PRESCALER == DIVIDE_BY_8
	CLR_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);
#endif
	CLR_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	OCR2 = (u8)floorf(Copy_u8DutyCycle*256/100) - 1;

}



