/*
 * DIO_int.h
 *
 *  Created on: Jul 17, 2025
 *      Author: Hana Elhady
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#include "../../LIB/STD_TYPES.h"


#define MDIO_OUTPUT 1
#define MDIO_INPUT  0

#define MDIO_PIN0   0
#define MDIO_PIN1   1
#define MDIO_PIN2 	2
#define MDIO_PIN3 	3
#define MDIO_PIN4 	4
#define MDIO_PIN5 	5
#define MDIO_PIN6 	6
#define MDIO_PIN7 	7

#define MDIO_HIGH 	1
#define MDIO_LOW 	0

#define MDIO_PORTA  0
#define MDIO_PORTB  1
#define MDIO_PORTC  2
#define MDIO_PORTD  3



void MDIO_voidSetPinDir(u8 A_u8PortNum,u8 A_u8PinNum , u8 A_u8PinDir);
void MDIO_voidSetPinVal(u8 A_u8PortNum,u8 A_u8PinNum , u8 A_u8PinVal);
void MDIO_voidSetPortDir(u8 A_u8PortNum,u8 A_u8PortDir );
void MDIO_voidSetPortVal(u8 A_u8PortNum,u8 A_u8PortVal);

s8 MDIO_u8GetPinVal(s8 A_u8PortNum,u8 A_u8PinNum);
s8 MDIO_u8GetPortVal(s8 A_u8PortNum);


#endif /* MCAL_DIO_DIO_INT_H_ */
