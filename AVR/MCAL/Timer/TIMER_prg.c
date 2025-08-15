#include "../../LIB/BIT_MATH.h"
#include "TIMER_cfg.h"
#include "TIMER_int.h"
#include "TIMER_prv.h"
#include "../DIO/DIO_int.h"

u32 G_u32Counter = 0;

void(*G_fsetCallBack) (void) = ((void*)(0));

void MTIMER_vInit(void){
    TCCR0 = TIMER0_MODE_CTC;

    SET_BIT(TIMSK, OCIE0);
}

void MTIMER_vStart(void) {
    TCCR0 = (TCCR0 & 0b11111000) | (PRESCALER_TIMER & 0b00000111);
}

void MTIMER_vStop(void) {
    TCCR0 = (TCCR0 & 0b11111000) | (0b000);
}

void MTIMER_vSetIntervalVal(u32 A_u32NumOfTick) {
    G_u32Counter = A_u32NumOfTick;
}

void MTIMER_vSetCallBackAddress(void (*A_fptr) (void)) {
    G_fsetCallBack = A_fptr;
}

void MTIMER_vSetCompareMatch(u8 A_u8CompareValue) {
    OCR0 = A_u8CompareValue;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    static u32 count = 0;
    count++;

    if (count >= G_u32Counter) {
        count = 0;
        if (G_fsetCallBack != NULL) {
            G_fsetCallBack();
        }
    }
}
