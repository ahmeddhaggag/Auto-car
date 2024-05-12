/*

 * DC_Motor_program.c
 *
 *  Created on: May 3, 2024
 *      Author: Ahmed D. Haggag
 */
#include"dio_int.h"
#include"TIMER_interface.h"
#include"DC_Motor_int.h"



void Forward(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);

	Timer0_voidGeneratePWM(70);      //speedR
	Timer2_voidGeneratePWM(70);       //speedL
}


void Backward(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_HIGH);

	Timer0_voidGeneratePWM(70);      //speedR
	Timer2_voidGeneratePWM(70);       //speedL
}

void Right(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);

	Timer0_voidGeneratePWM(50);      //speedR
	Timer2_voidGeneratePWM(80);       //speedL
}

void Left(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);

	Timer0_voidGeneratePWM(80);      //speedR
	Timer2_voidGeneratePWM(50);       //speedL
}

void Stop(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);

	Timer0_voidGeneratePWM(0);      //speedR
	Timer2_voidGeneratePWM(0);       //speedL
}





