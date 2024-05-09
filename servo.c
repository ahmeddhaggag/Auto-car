/*****************************************************
 * servo.c********************************************
 *****************************************************
 * Created: 5/8/2024 2:24:50 PM***********************
 *  Author: MOSTFA AHMED *****************************
 *****************************************************
 */ 
#include "servo.h"
#include <util/delay.h>
#include "TIMER_interface.h"

void servo_init()
{
	DIO_voidSetPinDirection(servo_port,servo_pin,DIO_OUTPUT);
	
}


void srv_MOVE_TO_0()
{
	
	Timer1_voidGeneratePWM()
	
	OCR1A = 1000 ;
	
	_delay_ms(1000);
}
void srv_MOVE_TO_90()
{
	Timer1_voidGeneratePWM()
	
	OCR1A = 1500 ;
	_delay_ms(1000);
}
void srv_MOVE_TO_180()
{
	Timer1_voidGeneratePWM()
	
	OCR1A = 2000 ;
	_delay_ms(1000);
}
