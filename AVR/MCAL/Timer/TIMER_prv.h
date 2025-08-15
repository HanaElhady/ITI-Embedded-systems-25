/*
 * TIMER1_prv.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Hana Elhady
 */

#ifndef MCAL_TIMER_TIMER0_CTC_TIMER_PRV_H_
#define MCAL_TIMER_TIMER0_CTC_TIMER_PRV_H_

#define MCAL_TIMER_TIMER_PRV_H_


// register names needed

#define TCCR0 *((volatile u8*)(0x53))
#define TCNT0 *((volatile u8*)(0x52))
#define TIMSK *((volatile u8*)(0x59))
#define TIFR  *((volatile u8*)(0x58))
#define OCR0  *((volatile u8*)(0x5C))


//pin names needed

// TIMSK
//#define  0
//#define 1
//#define 2
#define WGM01 3
//#define 4
//#define 5
#define WGM00 6
//#define 7

// Interrupt
#define TOIE0 0
#define OCIE0 1


//flag
#define TOV0 0
#define OCF0 1

#define TIMER0_MODE_NORMAL   0
#define TIMER0_MODE_CTC      (1 << WGM01)
#define TIMER0_MODE_FASTPWM  ((1 << WGM01) | (1 << WGM00))

#endif /* MCAL_TIMER_TIMER0_CTC_TIMER_PRV_H_ */
