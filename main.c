/*

 * main.c
 *
 *  Created on: Apr 25, 2024
 *      Author: Ahmed D. Haggag
 */


#include"avr/io.h"
#include"util/delay.h"
#include"STD_TYPES.H"
#include"bitmath.h"
#include"dio_int.h"
#include"TIMER_interface.h"



int main(){
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
	while(1){
		Timer0_voidGeneratePWM(70);


	}

	return 0;
}

