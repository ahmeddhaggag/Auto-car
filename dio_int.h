/*
 * dio_int.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Ahmed D. Haggag
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include"STD_TYPES.H"


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 0xff

#define DIO_HIGH 0xff
#define DIO_LOW 0


void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 CopyDirection);
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 CopyPinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Direction);
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8PortID);
void DIO_voidTogglePinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidTogglePortValue(u8 Copy_u8PortID);
void DIO_voidPinEnablePullUp(u8 Copy_u8PortID, u8 Copy_u8PinID);
void DIO_voidPortEnablePullUp(u8 Copy_u8PortID);


#endif /* DIO_INT_H_ */
