/*
 * led_int.h
 *
 *  Created on: Aug 7, 2025
 *      Author: Hana Elhady
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#include "led_cfg.h"

void Hled_vInit(void);

void Hled_vBlink(void);

void Hled_vRedLedOn(void);
void Hled_vRedLedOff(void);

void Hled_vGreenLedOn(void);
void Hled_vGreenLedOff(void);


#endif /* HAL_LED_LED_INT_H_ */

