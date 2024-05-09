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
#include "STD_TYPES.h"

#define OC1A_PIN 0       //PORTD PIN5
#define OC1B_PIN 1       //PORTD PIN4

#define TIMER1_SET_OCR1A_CHAN_MODE(_MODE)        (TCCR1A = TCCR1A | (_MODE))
#define TIMER1_SET_OCR1B_CHAN_MODE(_MODE)        (TCCR1B = TCCR1B | (_MODE))


#define TMR1_SET_MODE(_MODE)             (TCCR1A = TCCR1A+( _MODE&0x03),\ TCCR1B = TCCR1B + ((_MODE &0x0c)<<1))


#define TMR1_SET_u8_PRESCALLER(_PRE)        (TCCR1B = TCCR1B + (_PRE))


typedef enum{
	TIMER1_NORMAL_MODE=0,
	TIMER1_PWM_PHASE_CORRECT_8BIT_MODE, /*  Pulse Width Modulation (PWM) modes with varying resolutions (8-bit, 9-bit, 10-bit) */
	TIMER1_PWM_PHASE_CORRECT_9BIT_MODE,
	TIMER1_PWM_PHASE_CORRECT_10BIT_MODE,
	TIMER1_CTC_OCR1A_MODE,
	TIMER1_PWM_FAST_MODE_8BIT,
	TIMER1_PWM_FAST_MODE_9BIT,
	TIMER1_PWM_FAST_MODE_10BIT,
	TIMER1_PWM_PHASE_FRQ_ICR1_MODE,
	TIMER1_PWM_PHASE_FRQ_OCR1A_MODE,
	TIMER1_PWM_PHASE_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TIMER1_CTC_ICR1_MODE,
	REVERSED,
	TIMER1_PWM_FAST_MODE_ICR1,
	TIMER1_PWM_FAST_MODE_OCR1A
}TIMER1_mode;
typedef enum{
	OCRA1_DISCONNECTED = 0,
	OCRA1_TOGGLE= 0X40,
	OCRA1_NON_INVERTING = 0X80,
	OCRA1_INVERTING = 0XC0
}OCRA_Phase_fast_pwm;
typedef enum{
	OCRB1_DISCONNECTED=0,
	OCRB1_TOGGLE=0X10,
	OCRB1_NON_INVERTING=0X20,
	OCRB1_INVERTING=0X30
}OCRB_Phase_fast_pwm;

typedef enum{
	FALLING_EDGE,
	RISING_EDGE
}Edge_t;




void Timer0_voidInit(void);

u8 Timer0_u8OvSetCallBack(void (*Copy_pvCallBackFunc)(void));
void Timer0_voidGeneratePWM(u8 Copy_u8DutyCycle);
void Timer1_Init(u8 mode ,OCRA_Phase_fast_pwm outputa,OCRB_Phase_fast_pwm outputb);
void Timer1_Interrupt_Enable();
void Timer1_Interrupt_Disable();
void Timer1_Set_u8_CallBack(void (*tmr1_ptf)(void));
void TIMER1_Set_OCR1A(u16 Copy_u16Value);
void TIMER1_Set_OCR1B(u16 Copy_u16Value);
void TIMER1_Set_ICR1(u16 Copy_u16Value);
void TIMER1_Set_TCNT1(u16 Copy_u16Value);
void Timer1_ICU_InterruptEnable();
void Timer1_ICU_InterruptDisnable();
void Timer1_voidGeneratePWM(u8 Copy_u8Pin, u8 Copy_u8DutyCycle);
void Timer1_voidInputCapture(Edge_t _edge));
void Timer1_SetCallBack_COMPA(void (*tmr1_ptf)(void));
u16 Timer1_u16MeasurePulseDuration();
void PWM_measure(u32 *pfeq,u8 * pduty);
void Timer2_voidGeneratePWM(u8 Copy_u8DutyCycle);

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue);



#endif
