/*
 * main.c
 *
 *  Created on: Jul 27, 2025
 *      Author: Administrator
 */

#include "../MCAL/UART/UART_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../LIB/BIT_MATH.h"

int main(void) {
    MUART_vInit();

    MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
    MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);

    while (1) {
        char received = MUART_u16Recieve();

        if (received == 'A') {
            SET_BIT(PORTA, DIO_PIN0);
        } else {
            CLR_BIT(PORTA, DIO_PIN0);
        }

        MUART_vTransmit(received);
    }
    return 0;
}
