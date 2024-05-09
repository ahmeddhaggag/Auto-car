
/*
 *_*
 * ultrasonicSensor.h
 *
 *  Created on: 28 April 2024
 *      Author: Maab-Sayed 
 */



#ifndef HAL_ULTRASONICSENSOR_ULTRASONICSENSOR_H_
#define HAL_ULTRASONICSENSOR_ULTRASONICSENSOR_H_
#include "STD_TYPES.h"
#include "bitmath.h"
#include "Dio_int.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
/*
-------------- this This header file defines the basic
 interface for an ultrasonic sensor driver.
 It provides functions to initialize
 the sensor and read the distance to an object --------*/

typedef struct{
	channel_t Echo;
	channel_t Trigger;
}Ultrasonic_t; /*it represents the digital pin connected to the echo signal of the ultrasonic sensor */

void Ultrasonic_init();  /* This function initializes the ultrasonic sensor */

u8 UltrasonicReadDistance(Ultrasonic_t *ultra); /* defined unsigned int as u8 it should read the distance of ultrasonic  */


#endif 
