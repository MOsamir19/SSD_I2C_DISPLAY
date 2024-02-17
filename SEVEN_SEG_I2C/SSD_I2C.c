/*****************************************************************************
 *==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "TWI_int.h"

void SEVEN_SEG_I2C_INIT(void)
{
	M_TWI_void_Init();
}
void SEVEN_SEG_I2C_DISPLAY(u8 *arr)
{
	M_TWI_u8_StartCondition();
	M_TWI_u8_SendSlaveAddressWrite( 0b0100000 );/*0100 A2 A1 A0 R/W ---> 8 Bit address */

	/*****************************************************************************************
	 * 1110 0000 ->> 0 in MSB thats means selct one ssd
	 *
	 * for 	ex  0000 0111 | 1110 0000 =1110 0111  thats means display num 7 on the first ssd
	 ****************************************************************************************/
	M_TWI_u8_SendByte(arr[3]|0b11100000);
	_delay_ms(2);
	M_TWI_u8_SendByte(arr[2]|0b11010000);
	_delay_ms(2);
	M_TWI_u8_SendByte(arr[1]|0b10110000);
	_delay_ms(2);
	M_TWI_u8_SendByte(arr[0]|0b01110000);
	_delay_ms(2);
	/**********************************************************************************/

	M_TWI_void_StopCondition();
	_delay_ms(2);
}

void CLEAR_Array(u8*arr)
{
	arr[0]=0 ;
	arr[1]=0 ;
	arr[2]=0 ;
	arr[3]=0 ;
}
