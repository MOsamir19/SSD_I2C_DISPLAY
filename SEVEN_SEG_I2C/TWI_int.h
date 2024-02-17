/*
 * TWI_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_

/********************************************************************************************/
typedef enum
{
	NO_ERROR=1,
	START_ERROR,
	REPEATED_STSRT_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	SEND_BYTE_ERROR,
	READ_BYTE_ERROR

}TWI_ERROR_STATUS;

/********************************************************************************************/

void M_TWI_void_Init(void);
void M_TWI_void_StopCondition(void);

TWI_ERROR_STATUS M_TWI_u8_StartCondition(void);
TWI_ERROR_STATUS M_TWI_u8_RepeatedStart(void);
TWI_ERROR_STATUS M_TWI_u8_SendSlaveAddressWrite(u8);
TWI_ERROR_STATUS M_TWI_u8_SendSlaveAddressRead(u8);
TWI_ERROR_STATUS M_TWI_u8_SendByte(u8);
TWI_ERROR_STATUS M_TWI_u8_ReadByte(u8 *TWI_DATA);

/********************************************************************************************/

#endif /* TWI_TWI_INT_H_ */
