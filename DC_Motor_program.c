/*

 * DC_Motor_program.c
 *
 *  Created on: May 3, 2024
 *      Author: Ahmed D. Haggag
 */
#include<util/delay.h>
#include"dio_int.h"
#include"TIMER_interface.h"
#include"DC_Motor_int.h"



void Forward(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);
 //Headstart
	Timer0_voidGeneratePWM(85);      //speedR
	Timer2_voidGeneratePWM(85);       //speedL
	_delay_ms(20);
	Timer0_voidGeneratePWM(75);      //speedR
	Timer2_voidGeneratePWM(75);       //speedL
}


void Backward(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_HIGH);
	//Headstart
	Timer0_voidGeneratePWM(80);      //speedR
	Timer2_voidGeneratePWM(80);       //speedL
	_delay_ms(20);
	Timer0_voidGeneratePWM(70);      //speedR
	Timer2_voidGeneratePWM(70);       //speedL
}

void Right(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);
	//Headstart
	Timer0_voidGeneratePWM(40);      //speedR
	Timer2_voidGeneratePWM(85);       //speedL
	_delay_ms(20);
	Timer0_voidGeneratePWM(40);      //speedR
	Timer2_voidGeneratePWM(75);       //speedL
}

void Left(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_HIGH);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);
	//Headstart
	Timer0_voidGeneratePWM(85);      //speedR
	Timer2_voidGeneratePWM(40);       //speedL
	_delay_ms(20);
	Timer0_voidGeneratePWM(75);      //speedR
	Timer2_voidGeneratePWM(40);       //speedL
}

void Stop(){
	DIO_voidSetPinValue(in_PORT, in1_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in2_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in3_PIN, DIO_LOW);
	DIO_voidSetPinValue(in_PORT, in4_PIN, DIO_LOW);

	Timer0_voidGeneratePWM(0);      //speedR
	Timer2_voidGeneratePWM(0);       //speedL
}




