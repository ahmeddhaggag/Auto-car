/*****************************************************
 * servo.c********************************************
 *****************************************************
 * Created: 5/8/2024 2:24:50 PM***********************
 *  Author: MOSTFA AHMED *****************************
 *****************************************************
 */ 
#include <util/delay.h>
#include"servo.h"
#include"TIMER_interface.h"

void servo_init()
{
	DIO_voidSetPinDirection(servo_port,servo_pin,DIO_OUTPUT);
	
}


void SRV_MOVE_TO_0()
{
	Timer1_voidGeneratePWM(OC1A_PIN,4);
	
	_delay_ms(1000);
}
void SRV_MOVE_TO_90()
{
	Timer1_voidGeneratePWM(OC1A_PIN,9);

	
	_delay_ms(1000);
}
void SRV_MOVE_TO_180()
{
	Timer1_voidGeneratePWM(OC1A_PIN,15);
	
	_delay_ms(1000);
}
