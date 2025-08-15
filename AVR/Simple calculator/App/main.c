#define F_CPU 8000000
#include <avr/delay.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/KeyPad/KEYPAD_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "Calculator/calculator.h"

int main(void) {
    KEYPAD_vInit();
    HLCD_vinit();
    calculator();

    while (1) {
    }
}

