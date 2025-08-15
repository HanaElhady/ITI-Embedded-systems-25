/*
 * EXTI_int.h
 *
 *  Created on: Jul 23, 2025
 *      Author: bahgt
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "../../LIB/STD_TYPES.h"

// Interrupt IDs
#define MEXTI_INT0   0
#define MEXTI_INT1   1
#define MEXTI_INT2   2

// Sense control modes
#define LOW_LEVEL      0
#define ANY_CHANGE     1
#define FALLING_EDGE   2
#define RISING_EDGE    3

// Function prototypes
void MEXTI_vInit(void);
void MEXTI_voidSetSenseCtrl(u8 Copy_u8IntId, u8 Copy_u8SenseMode);
void MEXTI_voidEnableInt(u8 Copy_u8IntId);
void MEXTI_voidDisableInt(u8 Copy_u8IntId);
void MEXTI_voidSetCallBack(u8 Copy_u8IntId, void (*Copy_pvCallBack)(void));


#endif /* MCAL_EXTI_EXTI_INT_H_ */
