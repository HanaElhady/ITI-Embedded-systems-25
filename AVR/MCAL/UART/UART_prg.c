/*
 * UART_prg.c
 *
 *  Created on: Jul 29, 2025
 *      Author: Administrator
 */

#include "UART_cfg.h"
#include "UART_int.h"
#include "UART_prv.h"
#include "../../LIB/BIT_MATH.h"
void MUART_vInit(void) {
	UCSRB = 0X18;
	UCSRC = 0X86;

	//	UBRRH =0b0 if UCSRC 0b1

	// 9600  // UBRR = (F_CPU / (16*BAUD))-1)
	UBRRL = 51;
	// LOW NOT HIGH BECAUSE 51 NOT EXCEED 255 CHAR SIZE

}

void MUART_vTransmit(u16 A_u16Data){
	/* Wait for empty transmit buffer */
	while(GET_BIT(UCSRA,UDRE) != 1); 		// == while ( !( UCSRA & (1<<UDRE)) )

	/* Put data into buffer, sends the data */
	UDR = A_u16Data;

}

u16 MUART_u16Recieve(void){
	/* Wait for data to be received */
	while(GET_BIT(UCSRA,RXC) != 1); 		// == while ( !(UCSRA & (1<<RXC)) );

	/* Get and return received data from buffer */
	return UDR;
}
