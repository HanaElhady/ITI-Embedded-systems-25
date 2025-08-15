/*
 * UART_int.h
 *
 *  Created on: Jul 29, 2025
 *      Author: Administrator
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_
#include "../../LIB/STD_TYPES.h"

void MUART_vInit(void);
void MUART_vTransmit(u16 A_u16Data); // it can be 9bit
u16 MUART_u16Recieve(void);


#endif /* MCAL_UART_UART_INT_H_ */
