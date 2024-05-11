
/*
 *_*
 * ultrasonicSensor.h
 *
 *  Created on: 28 April 2024
 *      Author: Maab-Sayed 
 */



#ifndef HAL_ULTRASONICSENSOR_ULTRASONICSENSOR_H_
#define HAL_ULTRASONICSENSOR_ULTRASONICSENSOR_H_
#include<avr/io.h>
#include<util/delay.h>
#include"dio_int.h"
#include"TIMER_interface.h"
/*
-------------- this This header file defines the basic
 interface for an ultrasonic sensor driver.
 It provides functions to initialize
 the sensor and read the distance to an object --------*/


#define ULTRASONIC_PORT DIO_PORTD


#define ECHO_PIN DIO_PIN6
#define TRIG_PIN DIO_PIN1


u16 UltrasonicReadDistance(); /* defined unsigned int as u16 it should read the distance of ultrasonic  */


#endif 
