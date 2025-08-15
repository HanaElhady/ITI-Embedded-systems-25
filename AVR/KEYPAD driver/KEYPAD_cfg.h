/*
 * KEYPAD_cfg.h
 *
 *  Created on: Jul 26, 2025
 *      Author: Administrator
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_
#include "../../MCAL/DIO/DIO_int.h"



	//KEYPAD PORT A
	// row PA4 ->PA7 INPUT PULL UP
	// COL PA0 ->PA3 output

#define KEYPAD_PORT MDIO_PORTC
#define KEYPAD_PORT_OUTPUT 0b00001111      //ROW INPUT COL OUTPUT
#define KEYPAD_PORT_VALUE 0xFF			  // PULLUP SO INPUTS HAS HIGH OUTPUT NEED INITAILY TO BE WITH 1
#define KEYPAD_NO_PRESSED_KEY 0xFF


#define ROW_START 4    // Rows on PC0–PC3
#define COL_START 0    // Columns on PC4–PC7




#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
