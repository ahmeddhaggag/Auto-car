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


static void (*(TMR1_InterruptOveFlow)) (void);
static void (*(TMR1_InterruptComA)) (void);
static void (*(TMR1_InterruptComB)) (void);
static void (*(TMR1_InterrupICU)) (void);
static void Func_ICU();
u8 flag=0;
volatile u16 t1,t2,t3;

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
void Timer1_Init(u8 mode ,OCRA_Phase_fast_pwm outputa,OCRB_Phase_fast_pwm outputb){
	TIMER1_SET_MODE(mode);
	TIMER1_SET_PRESCALLER(TIMER1_PRESCALLER);
	TIMER1_OCR1A_SET_CHAN_MODE(outputa);
	TIMER1_OCR1A_SET_CHAN_MODE(outputb);
	if(outputa !=OCRA1_DISCONNECTED)
	{
		SET_BIT(DDRD,5);
	}
	if(outputa !=OCRB1_DISCONNECTED)
	{
		SET_BIT(DDRD,4);
	}
}

void Timer1_Interrupt_Enable()
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_Interrupt_Disable()
{
	CLEAR_BIT(TIMSK,TOIE1);
}

void Timer1_Set_u8_CallBack(void (*tmr1_ptf)(void))
{
	TMR1_InterriptOveFlow = tmr1_ptf;
}

void TIMER1_Set_OCR1A(u16 _value)
{
	OCR1A=_value;
}
void TIMER1_Set_OCR1B(u16 _value)
{
	OCR1B=_value;
}
void TIMER1_Set_ICR1(u16 _value)
{
	ICR1=_value;
}
void TIMER1_Set_TCNT1(u16 _value)
{
	TCNT1=_value;
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


void Timer1_InputCaptureEdge(Edge_t _edge)
{
	if(FALLING_EDGE ==_edge)
	{
		CLEAR_BIT(TCCR1B,ICES1);
	}
	else if(RISING_EDGE ==_edge)
	{
		SET_BIT(TCCR1B,ICES1);
	}
}

void Timer1_ICU_InterruptEnable()
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisnable()
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_SetCallBack(void (*(TMR1_ICU)) (void))
{

		TMR1_InterrupICU=TMR1_ICU;

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
void PWM_measure(u32 *pfeq,u8 * pduty)
{
	u16 Ton,Toff;
	TCNT1=0;
	Timer1_ICU_SetCallBack(Func_ICU);
	Timer1_InputCpetureEdge(RISING_EDGE);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);
	Ton=t2-t1;
	Toff=t3-t2;
	*pduty = ((u32)Ton*100)/((u32)Ton+Toff);
	*pfeq =(u32)1000000/((u32)Ton+Toff);


static void Func_ICU()
{
	if(flag==0)
	{
		t1=ICR1;
		Timer1_InputCpetureEdge(FALLING_EDGE);
		flag=1;

	}
	else if(flag==1)
	{
		t2=ICR1;
		Timer1_InputCpetureEdge(RISING_EDGE);
		flag=2;
	}
	else if(flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisnable();
		flag=3;
	}
}
ISR(TIMER1_OVF_vect)
{
	if(TMR1_InterriptOveFlow)
		TMR1_InterruptOveFlow();
}
void Timer1_SetCallBack_COMPA(void (*tmr1_ptf)(void))
{
	TMR1_InterriptComA=tmr1_ptf;
}
void TMR1_Interrupt_COMPA_Disable(){
	CLEAR_BIT(TIMSK,OCIE1A);
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
