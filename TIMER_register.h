/*******************************************************************/
/*******************************************************************/
/*****************   Author: Ahmed D. Haggag 	********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)		/*Timer/counter 0 control register*/
#define TCCR0_WGM00		6							/*Waveform generation mode bit 0*/
#define TCCR0_WGM01		3                           /*Waveform generation mode bit 1*/
#define TCCR0_CS00        0
#define TCCR0_CS01        1
#define TCCR0_CS02        2
#define TCCR0_COM00       4
#define TCCR0_COM01       5
#define TCCR0_FOC         7


#define TCCR2			*((volatile u8*)0x45)		/*Timer/counter 0 control register*/
#define TCCR0_WGM20		6							/*Waveform generation mode bit 0*/
#define TCCR0_WGM21		3                           /*Waveform generation mode bit 1*/
#define TCCR0_CS20        0
#define TCCR0_CS21        1
#define TCCR0_CS22        2
#define TCCR0_COM20       4
#define TCCR0_COM21       5
#define TCCR0_FOC         7

#define TCNT0			*((volatile u8*)0x52)		/*Timer/counter 0 register*/

#define TIMSK			*((volatile u8*)0x59)		/*Timer mask register*/
#define TIMSK_TOIE0		0							/*Timer0 overflow interrupt enable*/

#define TIMER2_OCR2     *((volatile u8*)0x43)

#endif
