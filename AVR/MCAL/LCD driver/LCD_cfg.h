/*
 * LCD_cfg.h
 *
 *  Created on: Jul 25, 2025
 *      Author: Administrator
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
#include "../../MCAL/DIO/DIO_int.h"

#define HLCD_DATA_PORT	   MDIO_PORTA

#define HLCD_CONTROL_PORT  MDIO_PORTB
#define HLCD_RS_PIN		   MDIO_PIN0
#define HLCD_RW_PIN		   MDIO_PIN1
#define HLCD_EN_PIN		   MDIO_PIN2


#define LCD_MAX_COLS 16
#define LCD_MAX_ROWS 2



#endif /* HAL_LCD_LCD_CFG_H_ */
