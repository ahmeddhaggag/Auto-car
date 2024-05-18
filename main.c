/*

 * main.c

 *
 *  Created on: Apr 25, 2024
 *      Author: Ahmed D. Haggag
 */


#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"STD_TYPES.H"
#include"bitmath.h"
#include"dio_int.h"
#include"TIMER_interface.h"
#include"DC_Motor_int.h"
#include"ultrasonic_int.h"
#include"servo_int.h"

#define OBSTACLE_THRESHOLD  50
#define CRASH_THRESHOLD     25


int main(){
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_OUTPUT);
	DIO_voidSetPortDirection(DIO_PORTB, DIO_OUTPUT);
    sei();
    TIMSK = (1<<TICIE1) | (1<<TOIE1);
    u16 distance = 0;
	while(1){
		SRV_MOVE_TO_90();
		  distance = UltrasonicReadDistance();

		        if (distance >= OBSTACLE_THRESHOLD) {
		            Forward();

		        } else if (distance <= CRASH_THRESHOLD) {

		            Stop();
		            Backward();
		            _delay_ms(1000);
		            Stop();
		            // Change direction
		            SRV_MOVE_TO_0();
		            distance = UltrasonicReadDistance();
		            if (distance > OBSTACLE_THRESHOLD) {
		                Right();
		                _delay_ms(200);
		            } else {
		            	SRV_MOVE_TO_180();
		            	distance = UltrasonicReadDistance();
		            	if(distance > OBSTACLE_THRESHOLD){
		                Left();
		                _delay_ms(200);
		            	}else{
		            		Right();
		            		_delay_ms(550);
		            	}
		            }
		            _delay_ms(500);
		        } else {
		            // Obstacle detected but not too close for a crash
		            Stop();
		            // Change direction
		            SRV_MOVE_TO_0();
		            distance = UltrasonicReadDistance();
		            if (distance > OBSTACLE_THRESHOLD) {
		            	Backward();
		            	 _delay_ms(200);
		               Right();
		               _delay_ms(200);
		            } else {
		          		 SRV_MOVE_TO_180();
		          		distance = UltrasonicReadDistance();
		          		 if(distance > OBSTACLE_THRESHOLD){
		          			 Backward();
		          			 _delay_ms(200);
		          		    Left();
		          		  _delay_ms(200);
		          		    }else{
		          		      	Right(); //Rotate
		          		 	_delay_ms(550);
		            	}
		        }
		    }
	}
	return 0;
}
