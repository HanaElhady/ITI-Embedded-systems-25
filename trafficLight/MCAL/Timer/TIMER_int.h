/*
 * TIMER1_int.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Hana Elhady
 */

#ifndef MCAL_TIMER_TIMER1_INT_H_
#define MCAL_TIMER_TIMER1_INT_H_


#include "../../LIB/STD_TYPES.h"

void MTIMER_vInit(void);
void MTIMER_vCalculations(u32 A_u32Trequired);
void MTIMER_vSetPreload(u32 A_u32Preload);

void MTIMER_vStart(void);
void MTIMER_vStop(void);
void MTIMER_vSetIntervalVal(u32 A_u32NumOfTick);
void MTIMER_vSetCallBackAddress(void (*A_fptr) (void));
void MTIMER_vSetCompareMatch(u8 A_u8CompareValue);

// PMW TIMER1A
void MTIMER0_vInit_PMW(void);

void MTIMER_vSetDutyCycle(u8 A_u8Duty);


#endif /* MCAL_TIMER_TIMER1_INT_H_ */
