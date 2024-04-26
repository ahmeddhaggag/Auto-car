/*
 *

dio_int.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Ahmed D. Haggag
 */

#include<util/delay.h>
#include"STD_TYPES.H"
#include"bitmath.h"
#include"DIO_priv.h"
#include"dio_int.h"

// Alt + shift + A
// Toggle port and pin functions.
// 7 segment counter function
// 8 LEDs, all of them blink at the same time, switch two leds on , then switch the next two and turn the first two off and so on
// incremental leds

void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 CopyDirection){
	if(Copy_u8PinID >  7 || Copy_u8PinID < 0){



	} else {

		switch(Copy_u8PortID)
		{
		case DIO_PORTA:
		{
			switch(CopyDirection)
			{
			case DIO_OUTPUT:
			{
				SET_BIT(DDRA_REG, Copy_u8PinID);
				break;
			}
			case DIO_INPUT:
			{
				CLR_BIT(DDRA_REG, Copy_u8PinID);
				break;
			}
			default:
			{

				//#warning " "
				break;
			}

			break;
			}

			break;
		}
		case DIO_PORTB:
		{
			switch(CopyDirection)
			{
			case DIO_OUTPUT:
			{
				SET_BIT(DDRB_REG, Copy_u8PinID);
				break;
			}
			case DIO_INPUT:
			{
				CLR_BIT(DDRB_REG, Copy_u8PinID);
				break;
			}
			default:
			{

				//#warning " "
				break;
			}

			break;
			}


		}
		break;
		case DIO_PORTC:
		{
			switch(CopyDirection)
			{
			case DIO_OUTPUT:
			{
				SET_BIT(DDRC_REG, Copy_u8PinID);
				break;
			}
			case DIO_INPUT:
			{
				CLR_BIT(DDRC_REG, Copy_u8PinID);
				break;
			}
			default:
			{

				//#warning " "
				break;
			}

			break;
			}


		} break;
		case DIO_PORTD:
		{
			switch(CopyDirection)
			{
			case DIO_OUTPUT:
			{
				SET_BIT(DDRD_REG, Copy_u8PinID);
				break;
			}
			case DIO_INPUT:
			{
				CLR_BIT(DDRD_REG, Copy_u8PinID);
				break;
			}
			default:
			{

				//#warning " "
				break;
			}

			break;
			}


		}
		}
	}

}


void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value){
	if(Copy_u8PinID >  7 || Copy_u8PinID < 0){



		} else {

			switch(Copy_u8PortID)
			{
			case DIO_PORTA:
			{
				switch(Copy_u8Value)
				{
				case DIO_HIGH:
				{
					SET_BIT(PORTA_REG, Copy_u8PinID);
					break;
				}
				case DIO_LOW:
				{
					CLR_BIT(PORTA_REG, Copy_u8PinID);
					break;
				}
				default:
				{

					//#warning " "
					break;
				}

				break;
				}


			} break;
			case DIO_PORTB:
			{
				switch(Copy_u8Value)
				{
				case DIO_HIGH:
				{
					SET_BIT(PORTB_REG, Copy_u8PinID);
					break;
				}
				case DIO_LOW:
				{
					CLR_BIT(PORTB_REG, Copy_u8PinID);
					break;
				}
				default:
				{

					//#warning " "
					break;
				}

				break;
				}


			}break;
			case DIO_PORTC:
			{
				switch(Copy_u8Value)
				{
				case DIO_HIGH:
				{
					SET_BIT(PORTC_REG, Copy_u8PinID);
					break;
				}
				case DIO_LOW:
				{
					CLR_BIT(PORTC_REG, Copy_u8PinID);
					break;
				}
				default:
				{

					//#warning " "
					break;
				}

				break;
				}


			}break;
			case DIO_PORTD:
			{
				switch(Copy_u8Value)
				{
				case DIO_HIGH:
				{
					SET_BIT(PORTD_REG, Copy_u8PinID);
					break;
				}
				case DIO_LOW:
				{
					CLR_BIT(PORTD_REG, Copy_u8PinID);
					break;
				}
				default:
				{

					//#warning " "
					break;
				}

				break;
				}


			}
			}
		}

	}



u8 DIO_u8GetPinValue( u8 Copy_u8PortID, u8 Copy_u8PinID){
	u8 Local_Data = -1;

	if(Copy_u8PinID >= 0 && Copy_u8PinID){
		switch(Copy_u8PortID){
		case DIO_PORTA:
			Local_Data = GET_BIT(PINA_REG , Copy_u8PinID); break;
		case DIO_PORTB:
					Local_Data = GET_BIT(PINB_REG , Copy_u8PinID); break;
		case DIO_PORTC:
					Local_Data = GET_BIT(PINC_REG , Copy_u8PinID); break;
		case DIO_PORTD:
					Local_Data = GET_BIT(PIND_REG , Copy_u8PinID); break;

		}

	}else{

	}
	return Local_Data;

}


void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Direction){

		switch(Copy_u8PortID){
				case DIO_PORTA:
				DDRA_REG =  Direction;     break;
				case DIO_PORTB:
					DDRB_REG = Direction;   break;
				case DIO_PORTC:
					DDRC_REG = Direction; break;
				case DIO_PORTD:
					DDRD_REG = Direction; break;


	}


}

void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value){

	switch(Copy_u8PortID){
					case DIO_PORTA:
						PORTA_REG =   Copy_u8Value;     break;
					case DIO_PORTB:
						PORTB_REG = Copy_u8Value;   break;
					case DIO_PORTC:
						PORTC_REG = Copy_u8Value; break;
					case DIO_PORTD:
						PORTD_REG = Copy_u8Value; break;


		}

}

u8 DIO_u8GetPortValue(u8 Copy_u8PortID){
	switch(Copy_u8PortID){
						case DIO_PORTA:
							return PORTA_REG;     break;
						case DIO_PORTB:
							return PORTB_REG ;   break;
						case DIO_PORTC:
							return PORTC_REG ; break;
						case DIO_PORTD:
							return PORTD_REG ; break;


			}
		return -1; //Error: invalid input




}

void DIO_voidTogglePinValue(u8 Copy_u8PortID, u8 Copy_u8PinID){

	switch(Copy_u8PortID){
	case DIO_PORTA:
		TOGGLE_BIT(PORTA_REG, Copy_u8PinID);
		break;
	case DIO_PORTB:
			TOGGLE_BIT(PORTB_REG, Copy_u8PinID);
			break;
	case DIO_PORTC:
			TOGGLE_BIT(PORTC_REG, Copy_u8PinID);
			break;
	case DIO_PORTD:
			TOGGLE_BIT(PORTD_REG, Copy_u8PinID);
			break;

	}
}

void DIO_voidTogglePortValue(u8 Copy_u8PortID){

	switch(Copy_u8PortID){
	case DIO_PORTA:
		PORTA_REG= ~PORTA_REG;
		break;
	case DIO_PORTB:
		PORTB_REG= ~PORTB_REG;
			break;
	case DIO_PORTC:
		PORTC_REG= ~PORTC_REG;
			break;
	case DIO_PORTD:
		PORTD_REG= ~PORTD_REG;
			break;

	}
}

void DIO_voidPinEnablePullUp(u8 Copy_u8PortID, u8 Copy_u8PinID){
	DIO_voidSetPinValue(Copy_u8PortID, Copy_u8PinID, DIO_HIGH);
}
void DIO_voidPortEnablePullUp(u8 Copy_u8PortID){
	DIO_voidSetPortValue(Copy_u8PortID, DIO_HIGH);
}












