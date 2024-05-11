/*
 *_*
 * ultrasonicSensor.c
 *
 *  Created on: 28 April 2024
 *      Author: Maab-Sayed 
  version ; 1.1
 */

 #include "ultrasonic_int.h"


u16 UltrasonicReadDistance(){
    u16 distance = 0;
    u32 time = 0;

    TCNT1 = 0; /* Clear Timer1 counter */
    DIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN , DIO_HIGH);  /* Trigger high pulse */
    _delay_us(10);             /* Trigger pulse duration */
    DIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN , DIO_LOW);   /* Trigger low pulse */
    time = Timer1_u32MeasurePulseDuration(); //each unit time is 1 us, prescaler 8

    distance = (u16)((0.0346*time)/(2*1.5));
    return distance;

}

