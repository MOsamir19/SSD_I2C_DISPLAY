/*
 * TWI_private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TWI_TWI_PRIVATE_H_
#define TWI_TWI_PRIVATE_H_



/********************************************************************************************/
/********************************************************************************************/
#define TWI_START_COND_ACK                 0x08
#define TWI_REPEATED_START_COND_ACK        0x10
#define TWI_SEND_SLAVE_ADD_WRITE_ACK       0x18
#define TWI_SEND_SLAVE_ADD_READ_ACK        0x40
#define TWI_SEND_BYTE_ACK                  0x28
#define TWI_READ_BYTE_ACK                  0x50

/********************************************************************************************/
/********************************************************************************************/

#define TWI_MASTER_MODE     1
#define TWI_SLAVE_MODE      2

/********************************************************************************************/

/*TWI (Slave) Address Register*/
#define TWAR_REG   *((volatile u8 *)0x22)

/********************************************************************************************/

/*TWI Data Register*/
#define TWDR_REG   *((volatile u8 *)0x23)

/********************************************************************************************/
/*TWI Bit Rate Register */
#define TWBR_REG   *((volatile u8 *)0x20)

/********************************************************************************************/
/*TWI Status Register –*/
#define TWSR_REG   *((volatile u8 *)0x21)
#define TWSR_TWPS0   0
#define TWSR_TWPS1   1

/********************************************************************************************/
/* TWI Control Register */
#define TWCR_REG   *((volatile u8 *)0x56)
#define TWCR_TWIE        0
#define TWCR_TWEN        2
#define TWCR_TWSTO       4
#define TWCR_TWSTA       5
#define TWCR_TWEA        6
#define TWCR_TWINT       7

/********************************************************************************************/



#endif /* TWI_TWI_PRIVATE_H_ */
