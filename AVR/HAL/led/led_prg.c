/*
 * led_prg.c
 *
 *  Created on: Aug 7, 2025
 *      Author: Hana Elhady
 */

#ifndef HAL_LED_LED_PRG_C_
#define HAL_LED_LED_PRG_C_
#include "led_int.h"
#include "../../MCAL/Timer/TIMER_int.h"

#include <avr/delay.h>

void Hled_vInit(void){
	MDIO_voidSetPinDir(ledPort,red_led_pin,MDIO_OUTPUT);
	MDIO_voidSetPinDir(ledPort,yellow_led_pin,MDIO_OUTPUT);
	MDIO_voidSetPinDir(ledPort,green_led_pin,MDIO_OUTPUT);
}


void Hled_vRedLedOn(void) {
	MDIO_voidSetPinVal(ledPort,red_led_pin,MDIO_HIGH);
}

void Hled_vRedLedOff(void) {
	MDIO_voidSetPinVal(ledPort,red_led_pin,MDIO_LOW);
}

void Hled_vGreenLedOn(void) {
	MDIO_voidSetPinVal(ledPort,green_led_pin,MDIO_HIGH);
}

void Hled_vGreenLedOff(void) {
	MDIO_voidSetPinVal(ledPort,green_led_pin,MDIO_LOW);
}

#endif /* HAL_LED_LED_PRG_C_ */
