/**************************************************************
 * servo.h*****************************************************
 **************************************************************
 * Created: 5/8/2024 2:25:46 PM********************************
 *  Author: mostafa ahmed**************************************
 **************************************************************
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "STD_TYPES.H"
#include "dio_int.h"s

#define servo_port DIO_PORTD
#define servo_pin  DIO_PIN5



void servo_init();
void SRV_MOVE_TO_0();
void SRV_MOVE_TO_90();
void SRV_MOVE_TO_180();


#endif /* SERVO_H_ */
