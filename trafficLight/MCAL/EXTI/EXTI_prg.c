/*
 * EXTI_prg.c
 *
 *  Created on: Jul 23, 2025
 *      Author: bahgt
 */
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

// Array of pointers to callback functions
static void (*EXTI_pvCallBackFunc[3])(void) = {NULL, NULL, NULL};

void MEXTI_vInit(void)
{
#if EXTI_INT0 == ENABLE
    MDIO_voidSetPinDir(MDIO_PORTD, MDIO_PIN2, MDIO_INPUT);
    MDIO_voidSetPinVal(MDIO_PORTD, MDIO_PIN2, MDIO_HIGH);
    CLR_BIT(MCUCR, ISC00);
    SET_BIT(MCUCR, ISC01);
    SET_BIT(GICR, INT0);
#endif

#if EXTI_INT1 == ENABLE
    MDIO_voidSetPinDir(DIO_PORTD, DIO_PIN3, DIO_INPUT);
    MDIO_voidSetPinVal(DIO_PORTD, DIO_PIN3, DIO_HIGH);
    CLR_BIT(MCUCR, ISC10);
    SET_BIT(MCUCR, ISC11);
    SET_BIT(GICR, INT1);
#endif

#if EXTI_INT2 == ENABLE
    MDIO_voidSetPinDir(DIO_PORTB, DIO_PIN2, DIO_INPUT);
    MDIO_voidSetPinVal(DIO_PORTB, DIO_PIN2, DIO_HIGH);
    CLR_BIT(MCUCSR, ISC2);
    SET_BIT(GICR, INT2);
#endif
}

void MEXTI_voidSetSenseCtrl(u8 Copy_u8IntId, u8 Copy_u8SenseMode)
{
    switch(Copy_u8IntId)
    {
        case MEXTI_INT0:
            if(Copy_u8SenseMode == LOW_LEVEL)       { CLR_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); }
            else if(Copy_u8SenseMode == ANY_CHANGE) { SET_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); }
            else if(Copy_u8SenseMode == FALLING_EDGE){ CLR_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); }
            else if(Copy_u8SenseMode == RISING_EDGE) { SET_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); }
            break;

        case MEXTI_INT1:
            if(Copy_u8SenseMode == LOW_LEVEL)       { CLR_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); }
            else if(Copy_u8SenseMode == ANY_CHANGE) { SET_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); }
            else if(Copy_u8SenseMode == FALLING_EDGE){ CLR_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); }
            else if(Copy_u8SenseMode == RISING_EDGE) { SET_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); }
            break;

        case MEXTI_INT2:
            if(Copy_u8SenseMode == FALLING_EDGE) { CLR_BIT(MCUCSR, ISC2); }
            else if(Copy_u8SenseMode == RISING_EDGE) { SET_BIT(MCUCSR, ISC2); }
            break;
    }
}

void MEXTI_voidEnableInt(u8 Copy_u8IntId)
{
    SET_BIT(GICR, Copy_u8IntId);
}

void MEXTI_voidDisableInt(u8 Copy_u8IntId)
{
    CLR_BIT(GICR, Copy_u8IntId);
}

void MEXTI_voidSetCallBack(u8 Copy_u8IntId, void (*Copy_pvCallBack)(void))
{
    if(Copy_pvCallBack != NULL)
    {
        EXTI_pvCallBackFunc[Copy_u8IntId] = Copy_pvCallBack;
    }
}

// ISR definitions
void __vector_1(void) __attribute__((signal));
void __vector_1(void) { if(EXTI_pvCallBackFunc[0] != NULL) EXTI_pvCallBackFunc[0](); }

void __vector_2(void) __attribute__((signal));
void __vector_2(void) { if(EXTI_pvCallBackFunc[1] != NULL) EXTI_pvCallBackFunc[1](); }

void __vector_3(void) __attribute__((signal));
void __vector_3(void) { if(EXTI_pvCallBackFunc[2] != NULL) EXTI_pvCallBackFunc[2](); }
