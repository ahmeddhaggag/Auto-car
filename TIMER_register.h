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

#define TCCR0_REG			*((volatile u8*)0x53)		/*Timer/counter 0 control register*/
#define TCCR0_WGM00		6							/*Waveform generation mode bit 0*/
#define TCCR0_WGM01		3                           /*Waveform generation mode bit 1*/
#define TCCR0_CS00        0
#define TCCR0_CS01        1
#define TCCR0_CS02        2
#define TCCR0_COM00       4
#define TCCR0_COM01       5
#define TCCR0_FOC         7



#define TCCR1A_REG        *((volatile u8*)0x4f)
#define TCCR1A_WGM10           0
#define TCCR1A_WGM11           1
#define TCCR1A_FOC1B           2
#define TCCR1A_FOC1A           3
#define TCCR1A_COMB0            4
#define TCCR1A_COMB1            5
#define TCCR1A_COMA0            6
#define TCCR1A_COMA1            7



#define TCCR1B_REG         *((volatile u8*)0x4e)
#define TCCR1B_CS10           0
#define TCCR1B_CS11           1
#define TCCR1B_CS12           2
#define TCCR1B_WGM12           3
#define TCCR1B_WGM13            4
// reserved
#define TCCR1B_ICES1            6
#define TCCR1B_ICNC1            7







#define TCCR2_REG			*((volatile u8*)0x45)		/*Timer/counter 0 control register*/
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
