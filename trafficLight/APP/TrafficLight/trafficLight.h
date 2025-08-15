/*
 * trafficLight.h
 *
 *  Created on: Aug 8, 2025
 *      Author: Hana Elhady
 */
#ifndef APP_TRAFFICLIGHT_TRAFFICLIGHT_H_
#define APP_TRAFFICLIGHT_TRAFFICLIGHT_H_

#include "../../HAL/led/led_int.h"
#include "../../HAL/switch/switch_int.h"
#include "../../MCAL/DIO/DIO_int.h"

void TrafficLight(void);
void HandleSwitchPress(void);
void BlinkIfLast3Seconds(u8 secondsLeft);

#define DEFAULT_START 20
#define START_BLINK   3


#endif /* APP_TRAFFICLIGHT_TRAFFICLIGHT_H_ */
