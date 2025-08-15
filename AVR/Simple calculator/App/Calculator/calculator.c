#include "../../HAL/KeyPad/KEYPAD_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "calculator.h"

int calculator(void) {
    u8 key;
    u8 L_u8op;
    u32 L_u32FirstOperand = 0;
    u32 L_u32SecondOperand = 0;
    u32 L_u32Result = 0;

    // Read first operand
    while (1) {
        key = KEYPAD_u8GetKeyPad();
        if (key == KEYPAD_NO_PRESSED_KEY)
            continue;  // wait for a key

        if (key >= '0' && key <= '9') {
            HLCD_vSendChar(key);
            L_u32FirstOperand = L_u32FirstOperand * 10 + (key - '0');
        } else {
            break;  // an operator was pressed
        }
    }

    // If clear key pressed
    if (key == 'C') {
        HLCD_vClearScreen();
        return 0;
    }

    // Save operator and display it
    L_u8op = key;
    HLCD_vSendChar(L_u8op);

    // Read second operand
    while (1) {
        key = KEYPAD_u8GetKeyPad();
        if (key == KEYPAD_NO_PRESSED_KEY)
            continue;

        if (key >= '0' && key <= '9') {
            HLCD_vSendChar(key);
            L_u32SecondOperand = L_u32SecondOperand * 10 + (key - '0');
        } else {
            break;  // likely '='
        }
    }

    // Perform calculation when '=' is pressed
    if (key == '=') {
        switch (L_u8op) {
            case '+':
                L_u32Result = L_u32FirstOperand + L_u32SecondOperand;
                break;
            case '-':
                L_u32Result = L_u32FirstOperand - L_u32SecondOperand;
                break;
            case '*':
                L_u32Result = L_u32FirstOperand * L_u32SecondOperand;
                break;
            case '/':
                if (L_u32SecondOperand != 0)
                    L_u32Result = L_u32FirstOperand / L_u32SecondOperand;
                else {
                    HLCD_vClearScreen();
                	HLCD_vPrintStr("Math Error");
                    return 0;
                }
                break;
            default:
                break;
        }

        HLCD_vClearScreen();
        HLCD_vPrintNumber(L_u32Result);
    }

    return 0;
}
