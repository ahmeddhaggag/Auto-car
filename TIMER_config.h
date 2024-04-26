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



#define MAX 255
#define TIMER0_u8_PRESCALER			DIVIDE_BY_8

/*Choose the preload value*/
#define TIMER0_u8_PRELOAD			0
#define FAST_PWM 0
#define PHASE_PWM 1

#define WGM_MODE FAST_PWM

#endif
