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
#define TIMER1_PRESCALLER     TIMER1_8_PRESCALER


#define TIMER1_DISABLE               0X00
#define TIMER1_1_PRESCALER           0X01
#define TIMER1_8_PRESCALER           0X02
#define TIMER1_64_PRESCALER          0X03
#define TIMER1_256_PRESCALER         0X04
#define TIMER1_1024_PRESCALER        0X05

#define TIMER1_EXITRNAL_RISING       0X07
#define TIMER1_EXITRNAL_FALLING      0X06
#define WGM_MODE FAST_PWM

#endif
