/*

 * main.c
 *
 *  Created on: Apr 25, 2024
 *      Author: Ahmed D. Haggag
 
 */

#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"
#include "TIMER_interface.h"
#include "DIO_int.h"
#include"TIMER_interface.h"
#include "UltrasonicSensor.h"
#include"servo.h"
#include"DC_Motor_int.h"

u8 distance;
u8 distance_right=0;
u8 distance_left=0;

#define STOP_DISTANCE
#define CRASH_DISTANCE
#define OBSTACLE_DISTANCE
int main(){
	sei();
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
	Ultrasonic_init();
	
	while(1){
		Timer0_voidGeneratePWM(70);
		distance=UltrasonicReadDistance();

		if(distance > STOP_DISTANCE)
		{

			Forward();
		}
		else if (distance<STOP_DISTANCE)
		{
			Stop();
			Servo_angle(0);
			_delay_ms(1000);
			distance_right=UltrasonicReadDistance();
			_delay_ms(300);
			// move forward
			_delay_ms(1000);
			distance_left=UltrasonicReadDistance();
			_delay_ms(300);
		
			if(distance_right>distance_left)
			{
				//servo rotate right
			}
			else if(distance_right<distance_left)
			{
			// servo rotate left
			}

		}

	}

}
	}

	return 0;
}

