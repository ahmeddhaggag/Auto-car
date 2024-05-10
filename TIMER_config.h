/*******************************************************************/
/*******************************************************************/
/*****************   Author:  Ahmed D. Haggag	********************/
/*****************   Layer:	  MCAL				********************/
/*****************   SWC:     TIMER				********************/
/*****************	 Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Choose your prescaler division factor
 * Options:   1- DIVIDE_BY_1
 * 			  2- DIVIDE_BY_8
 * 			  3- DIVIDE_BY_64
 * 			  4- DIVIDE_BY_256
 * 			  5- DIVIDE_BY_1024
 * */

#define DIVIDE_BY_1        1
#define DIVIDE_BY_8        2
#define DIVIDE_BY_64       3
#define DIVIDE_BY_256      4
#define DIVIDE_BY_1024     5


#define MAX 255
#define TIMER0_u8_PRESCALER			DIVIDE_BY_8
#define TIMER1_u8_PRESCALER			DIVIDE_BY_256
#define TIMER2_u8_PRESCALER			DIVIDE_BY_8


#define EIGHT_BIT 256
#define NINE_BIT 512
#define TEN_BIT 1024

#define TIMER1_BIT_MODE  NINE_BIT


/*Choose the preload value*/
#define TIMER0_u8_PRELOAD			0
#define FAST_PWM 0
#define PHASE_PWM 1

#define WGM_MODE FAST_PWM

#endif
