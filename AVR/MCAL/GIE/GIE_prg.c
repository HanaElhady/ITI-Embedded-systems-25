/*
 * GIE_prg.c
 *
 *  Created on: Jul 23, 2025
 *      Author: Hana Elhady
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GIE_prv.h"
#include "GIE_int.h"
/* Function of EXTI */

void MGIE_vEnable(void)
{
	SET_BIT(SREG,7);
}
void MGIE_vDisable(void)
{
	CLR_BIT(SREG,7);
}

