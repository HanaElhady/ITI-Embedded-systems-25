#include "../../MCAL/Timer/TIMER_int.h"
#include "../../HAL/led/led_int.h"
#include "../../HAL/ssd/ssd_int.h"
#include "../../HAL/switch/switch_int.h"
#include "../../LIB/BIT_MATH.h"
#include "trafficLight.h"
#include <util/delay.h>

volatile u8 G_u8LightTime = DEFAULT_START;
volatile u8 G_u8NextTime = DEFAULT_START;

void BlinkIfLast3Seconds(u8 secondsLeft) {
    if (secondsLeft <= 3 && secondsLeft > 0) {
        MDIO_voidSetPinVal(ledPort, yellow_led_pin, MDIO_HIGH);
        _delay_ms(250);
        MDIO_voidSetPinVal(ledPort, yellow_led_pin, MDIO_LOW);

        for(u8 j = 0; j < 2; j++) {
            HandleSwitchPress();
            _delay_ms(125);
        }
    }
}

void HandleSwitchPress(void) {
    u8 switchState = Hswitch_u8GetPress();

    if(switchState == UP_PRESS) {
        if(G_u8NextTime < MAX_TIME) G_u8NextTime++;
    }
    else if(switchState == DOWN_PRESS) {
        if(G_u8NextTime > MIN_TIME) G_u8NextTime--;
    }
}

void TrafficLight(void) {
    Hswitch_vInit();

    while(1) {
        HandleSwitchPress();

        // -------- GREEN LIGHT --------
        Hled_vGreenLedOn();
        for(s8 i = G_u8LightTime; i > 0; i--) {
            SSD_vDisplayNumber(i);

            if(i > 3) {
                for(u8 j = 0; j < 10; j++) {
                    HandleSwitchPress();
                    _delay_ms(13);
                }
            }
            else {
                BlinkIfLast3Seconds(i);
            }
        }
        Hled_vGreenLedOff();
        G_u8LightTime = G_u8NextTime;

        // -------- RED LIGHT --------
        Hled_vRedLedOn();
        for(s8 i = G_u8LightTime; i > 0; i--) {
            SSD_vDisplayNumber(i);

            if(i > 3) {
                for(u8 j = 0; j < 10; j++) {
                    HandleSwitchPress();
                    _delay_ms(13);
                }
            }
            else {
                BlinkIfLast3Seconds(i);
            }
        }
        Hled_vRedLedOff();
        G_u8LightTime = G_u8NextTime;
    }
}
