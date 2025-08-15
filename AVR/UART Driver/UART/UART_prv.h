/*
 * UART_prv.h
 *
 *  Created on: Jul 29, 2025
 *      Author: Administrator
 */

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_
#include "../../LIB/STD_TYPES.h"

#define  UDRE 	5
#define  RXC  	7
#define  UDR 	*((volatile u8*)(0x2C))
#define  UCSRA 	*((volatile u8*)(0x2B))
#define  UCSRB 	*((volatile u8*)(0x2A))
#define  UCSRC 	*((volatile u8*)(0x40))
#define  UBRRH 	*((volatile u8*)(0x40))
#define  UBRRL 	*((volatile u8*)(0x29))

#endif /* MCAL_UART_UART_PRV_H_ */
