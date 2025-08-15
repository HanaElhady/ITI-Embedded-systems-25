/*
 * DIO_prg.c
 *
 *  Created on: Jul 17, 2025
 *      Author: Hana Elhady
 */

#include "DIO_int.h"
#include "DIO_prv.h"
#include "../../LIB/BIT_MATH.h"


void MDIO_voidSetPinDir(u8 A_u8PortNum, u8 A_u8PinNum, u8 A_u8PinDir) {
    switch (A_u8PortNum) {
        case MDIO_PORTA:
            if (A_u8PinDir == MDIO_OUTPUT)
                SET_BIT(DDRA, A_u8PinNum);
            else
                CLR_BIT(DDRA, A_u8PinNum);
        break;

        case MDIO_PORTB:
            if (A_u8PinDir == MDIO_OUTPUT)
                SET_BIT(DDRB, A_u8PinNum);
            else
                CLR_BIT(DDRB, A_u8PinNum);
            break;

        case MDIO_PORTC:
            if (A_u8PinDir == MDIO_OUTPUT)
                SET_BIT(DDRC, A_u8PinNum);
            else
                CLR_BIT(DDRC, A_u8PinNum);
            break;

        case MDIO_PORTD:
            if (A_u8PinDir == MDIO_OUTPUT)
                SET_BIT(DDRD, A_u8PinNum);
            else
                CLR_BIT(DDRD, A_u8PinNum);
            break;

        default:
            break;
    }
}

void MDIO_voidSetPinVal(u8 A_u8PortNum, u8 A_u8PinNum, u8 A_u8PinVal) {
    switch (A_u8PortNum) {
        case MDIO_PORTA:
            if (A_u8PinVal == MDIO_HIGH)
                SET_BIT(PORTA, A_u8PinNum);
            else
                CLR_BIT(PORTA, A_u8PinNum);
            break;

        case MDIO_PORTB:
            if (A_u8PinVal == MDIO_HIGH)
                SET_BIT(PORTB, A_u8PinNum);
            else
                CLR_BIT(PORTB, A_u8PinNum);
            break;

        case MDIO_PORTC:
            if (A_u8PinVal == MDIO_HIGH)
                SET_BIT(PORTC, A_u8PinNum);
            else
                CLR_BIT(PORTC, A_u8PinNum);
            break;

        case MDIO_PORTD:
            if (A_u8PinVal == MDIO_HIGH)
                SET_BIT(PORTD, A_u8PinNum);
            else
                CLR_BIT(PORTD, A_u8PinNum);
            break;

        default:
            break;
    }
}

void MDIO_voidSetPortDir(u8 A_u8PortNum, u8 A_u8PortDir) {
    switch (A_u8PortNum) {
        case MDIO_PORTA:
            DDRA = A_u8PortDir;
            break;
        case MDIO_PORTB:
            DDRB = A_u8PortDir;
            break;
        case MDIO_PORTC:
            DDRC = A_u8PortDir;
            break;
        case MDIO_PORTD:
            DDRD = A_u8PortDir;
            break;
        default:
            break;
    }
}

void MDIO_voidSetPortVal(u8 A_u8PortNum, u8 A_u8PortVal) {
    switch (A_u8PortNum) {
        case MDIO_PORTA:
            PORTA = A_u8PortVal;
            break;
        case MDIO_PORTB:
            PORTB = A_u8PortVal;
            break;
        case MDIO_PORTC:
            PORTC = A_u8PortVal;
            break;
        case MDIO_PORTD:
            PORTD = A_u8PortVal;
            break;
        default:
            break;
    }
}

s8 MDIO_u8GetPinVal(s8 A_u8PortNum, u8 A_u8PinNum) {
    s8 L_s8ReturnVal = -1;

    switch (A_u8PortNum) {
        case MDIO_PORTA:
            L_s8ReturnVal = GET_BIT(PINA, A_u8PinNum);
            break;
        case MDIO_PORTB:
            L_s8ReturnVal = GET_BIT(PINB, A_u8PinNum);
            break;
        case MDIO_PORTC:
            L_s8ReturnVal = GET_BIT(PINC, A_u8PinNum);
            break;
        case MDIO_PORTD:
            L_s8ReturnVal = GET_BIT(PIND, A_u8PinNum);
            break;
        default:
            break;
    }

    return L_s8ReturnVal;
}

s8 MDIO_u8GetPortVal(s8 A_u8PortNum) {
    s8 L_s8ReturnVal = -1;

    switch (A_u8PortNum) {
        case MDIO_PORTA:
            L_s8ReturnVal = PINA;
            break;
        case MDIO_PORTB:
            L_s8ReturnVal = PINB;
            break;
        case MDIO_PORTC:
            L_s8ReturnVal = PINC;
            break;
        case MDIO_PORTD:
            L_s8ReturnVal = PIND;
            break;
        default:
            break;
    }

    return L_s8ReturnVal;
}

