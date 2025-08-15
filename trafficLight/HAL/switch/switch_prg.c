#include "switch_int.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

static u8 prevUpState = 1;
static u8 prevDownState = 1;

void Hswitch_vInit(void) {
    MDIO_voidSetPinDir(HSwitchPort, upCounterButtonPin, MDIO_INPUT);
    MDIO_voidSetPinDir(HSwitchPort, downCounterButtonPin, MDIO_INPUT);
    MDIO_voidSetPinVal(HSwitchPort, upCounterButtonPin, MDIO_HIGH);
    MDIO_voidSetPinVal(HSwitchPort, downCounterButtonPin, MDIO_HIGH);
}

u8 Hswitch_u8GetPress(void) {
    u8 currentUpState = MDIO_u8GetPinVal(HSwitchPort, upCounterButtonPin);
    u8 currentDownState = MDIO_u8GetPinVal(HSwitchPort, downCounterButtonPin);
    u8 result = NO_PRESS;

    _delay_ms(20);

    if((prevUpState == 1) && (currentUpState == 0)) {
        result = UP_PRESS;
    }

    if((prevDownState == 1) && (currentDownState == 0)) {
        result = DOWN_PRESS;
    }

    prevUpState = currentUpState;
    prevDownState = currentDownState;

    return result;
}
