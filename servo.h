/**************************************************************
 * servo.h*****************************************************
 **************************************************************
 * Created: 5/8/2024 2:25:46 PM********************************
 *  Author: mostafa ahmed**************************************
 **************************************************************
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "STD_TYPES (1).H"
#include "dio_int (1).h"

#define servo_port DIO_PORTD
#define servo_pin  DIO_PIN5



void servo_init();
void srv_MOVE_TO_0();
void srv_MOVE_TO_90();
void srv_MOVE_TO_180();


#endif /* SERVO_H_ */