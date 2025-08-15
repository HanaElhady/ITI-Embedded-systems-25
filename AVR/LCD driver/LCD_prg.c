/*
 * LCD_prg.c
 *
 *  Created on: Jul 25, 2025
 *      Author: Administrator
 */

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../LIB/STD_TYPES.h"
#include "LCD_cfg.h"
#include "LCD_prv.h"
#include "LCD_int.h"
#include <avr/delay.h>



u8 G_u8Row = 0;
u8 G_u8Col = 0;
void HLCD_vinit(void){
	MDIO_voidSetPortDir(HLCD_DATA_PORT,MDIO_output);
	MDIO_voidSetPinDir(HLCD_CONTROL_PORT,HLCD_RS_PIN,MDIO_output);
	MDIO_voidSetPinDir(HLCD_CONTROL_PORT,HLCD_RW_PIN,MDIO_output);
	MDIO_voidSetPinDir(HLCD_CONTROL_PORT,HLCD_EN_PIN,MDIO_output);

	// LCD INIT
	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);

	_delay_ms(1);
	HLCD_vSendCommand(0b00001110);


	_delay_ms(1);
	HLCD_vSendCommand(HLCD_CLR_COMMAND);


	_delay_ms(2);
	// I/D --> increment mode SH --> SHIFT
	HLCD_vSendCommand(0b00000110);


}


void HLCD_vSetCursor(u8 A_u8Row, u8 A_u8Col) {
	if(A_u8Col >= 0 && A_u8Col<= 15) {
		switch(A_u8Row){
		case 1:
			HLCD_vSendCommand(0b10000000  + A_u8Col);
			break;
		case 2:
			HLCD_vSendCommand(0b10000000  + A_u8Col + 0x40 );
			break;

		}
	}
}

void HLCD_vTracker(void) {
    G_u8Col++;
	if (G_u8Col >= LCD_MAX_COLS) {
	        G_u8Col = 0;
	        G_u8Row++;
	        if (G_u8Row >= LCD_MAX_ROWS) {
	            G_u8Row = 0;
	        }
	    }
}
// send command
void HLCD_vSendCommand(u8 A_u8Command) {
	MDIO_voidSetPinVal(HLCD_CONTROL_PORT,HLCD_RS_PIN,MDIO_Low);
	MDIO_voidSetPinVal(HLCD_CONTROL_PORT,HLCD_RW_PIN,MDIO_Low);
	MDIO_voidSetPortVal(HLCD_DATA_PORT,A_u8Command);
	MDIO_voidSetPinVal(HLCD_CONTROL_PORT,HLCD_EN_PIN,MDIO_High);
	_delay_ms(1);
	MDIO_voidSetPinVal(HLCD_CONTROL_PORT,HLCD_EN_PIN,MDIO_Low);
	_delay_ms(1);

}


void HLCD_vSendChar(u8 A_u8Data) {
    HLCD_vSetCursor(G_u8Row + 1, G_u8Col);

    // Send the character
    MDIO_voidSetPinVal(HLCD_CONTROL_PORT, HLCD_RS_PIN, MDIO_High);
    MDIO_voidSetPinVal(HLCD_CONTROL_PORT, HLCD_RW_PIN, MDIO_Low);
    MDIO_voidSetPortVal(HLCD_DATA_PORT, A_u8Data);
    MDIO_voidSetPinVal(HLCD_CONTROL_PORT, HLCD_EN_PIN, MDIO_High);
    _delay_ms(1);
    MDIO_voidSetPinVal(HLCD_CONTROL_PORT, HLCD_EN_PIN, MDIO_Low);
    _delay_ms(1);

    HLCD_vTracker();

}

//print
void HLCD_vPrintStr(u8 arr[]) {
	for (u8 L_u8I = 0 ; arr[L_u8I] ; L_u8I++) {
		HLCD_vSendChar(arr[L_u8I]);
	}
}
void HLCD_vPrintNumber(u32 A_u32Data) {

}


// clear screen
void HLCD_vClearScreen(void) {
		HLCD_vSendCommand(HLCD_CLR_COMMAND);
		G_u8Row = 0;
		G_u8Col = 0;
		_delay_ms(2);
}

