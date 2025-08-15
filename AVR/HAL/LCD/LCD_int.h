/*
 * LCD_int.h
 *
 *  Created on: Jul 25, 2025
 *      Author: Administrator
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "../../LIB/STD_TYPES.h"


// initialization
void HLCD_vinit(void);

// send command
void HLCD_vSendCommand(u8 A_u8Command);

// send data
void HLCD_vSendChar(u8 A_u8Data);

//print
void HLCD_vPrintStr(u8 arr[]);
void HLCD_vPrintNumber(u32 A_u32Data);


void HLCD_vSetCursor(u8 A_u8Row, u8 A_u8Col);


// clear screen
void HLCD_vClearScreen(void);


#endif /* HAL_LCD_LCD_INT_H_ */
