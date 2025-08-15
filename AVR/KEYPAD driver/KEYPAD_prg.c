/*
 * KEYPAD_prg.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Administrator
 */

#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_cfg.h"
#include <util/delay.h>


u8 Arr[4][4] = {
    {'7', '4', '1', 'C'},
    {'8', '5', '2', '0'},
    {'9', '6', '3', '='},
    {'/', '*', '-', '+'}
};


void KEYPAD_vInit(void) {

	MDIO_voidSetPortDir(KEYPAD_PORT,KEYPAD_PORT_OUTPUT);
	MDIO_voidSetPortVal(KEYPAD_PORT,KEYPAD_PORT_VALUE);
}

u8 KEYPAD_u8GetKeyPad() {
	u8 return_Val = KEYPAD_NO_PRESSED_KEY;
	MDIO_voidSetPortVal(KEYPAD_PORT, KEYPAD_PORT_VALUE); // Reset port state

	for(u8 i = 0; i < 4; i++) {   // columns
		MDIO_voidSetPinVal(KEYPAD_PORT, COL_START + i, MDIO_Low);  // Drive column low

		for(u8 j = 0; j < 4; j++) {   // rows
			if(MDIO_u8GetPinVal(KEYPAD_PORT, ROW_START + j) == 0) {
				_delay_ms(20);  // Debounce
				if(MDIO_u8GetPinVal(KEYPAD_PORT, ROW_START + j) == 0) { // Check again
					return_Val = Arr[j][i];
					while(MDIO_u8GetPinVal(KEYPAD_PORT, ROW_START + j) == 0); // Wait for release
					MDIO_voidSetPinVal(KEYPAD_PORT, COL_START + i, MDIO_High);  // Reset column
					return return_Val;
				}
			}
		}

		MDIO_voidSetPinVal(KEYPAD_PORT, COL_START + i, MDIO_High);  // Reset column
	}

	return return_Val;
}

