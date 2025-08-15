/*
 * ssd_prg.c
 *
 *  Created on: Aug 7, 2025
 *      Author: Hana Elhady
 */


#include "ssd_int.h"
#include "../../MCAL/DIO/DIO_int.h"

u8 GR_u8SsdNum[HSSD_MAX_ARR_LENGTH] ={
		0x3F,
		0x06,
		0x5B,
		0x4f,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F
};

void SSD_vInit(void){
	MDIO_voidSetPortDir(HSSD_FIRST_PORT, 0xFF);
	MDIO_voidSetPortDir(HSSD_SECOND_PORT, 0xFF);

}

//void SSD_vCountUp(void){
//	if(G_u8Count == HSSD_MAX_ARR_LENGTH )
//		G_u8Count = 0;
//	MDIO_voidSetPortVal(HSSD_PORT,GR_u8SsdNum[G_u8Count++]);
//}
//
//void SSD_vCountDown(void){
//	if(G_u8Count == 0 )
//		G_u8Count = HSSD_MAX_ARR_LENGTH;
//	MDIO_voidSetPortVal(HSSD_PORT,GR_u8SsdNum[--G_u8Count]);
//}

void SSD_vDisplayNumber(u16 A_u16Counter) {


	u16 L_u16tenthNumber =(int) A_u16Counter / 10;
	u16 L_u16UnitNumber = A_u16Counter % 10;

	MDIO_voidSetPortVal(HSSD_FIRST_PORT,GR_u8SsdNum[L_u16tenthNumber]);
	MDIO_voidSetPortVal(HSSD_SECOND_PORT,GR_u8SsdNum[L_u16UnitNumber]);


}


