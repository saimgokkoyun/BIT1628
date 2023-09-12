#ifndef __I2C_H
#define __I2C_H

#include "stm32f10x.h"
#include "BIT1632A.H"

#define NOACK  0x01
#define ACK    0x00

#define I2C_IO_ADDR_1			0b00000010
#define I2C_Speed               50000
#define VP_MAD                  0xC0       // VP IF MAD

#define BITEK_TxBurst(wREG, wCNT, pbDATA)   \
    I2C_TxBurst((0xC0) | (((wREG) >> 7) & 0x1E), (wREG), (wCNT), (pbDATA))

#define BITEK_TxByte(wREG, bDATA)           \
    I2C_TxByte((VP_MAD) | (((wREG) >> 7) & 0x1E), (wREG), (bDATA))


#define BITEK_TxRepeat(wREG, wCNT, bDATA)   \
    I2C_TxRepeat((VP_MAD) | (((wREG) >> 7) & 0x1E), (wREG), (wCNT), (bDATA))

#define BITEK_RxByte(wREG)                  \
    I2C_RxByte((VP_MAD) | (((wREG) >> 7) & 0x1E), (wREG))


extern void I2CInit(void);
extern void I2CWriteCommand (uint8_t addr, uint8_t data);
extern uint8_t I2CReadCommand(uint8_t addr);
extern void I2CReadButton(uint8_t addr,uint8_t * i2c_buffer, uint8_t bufferSize);

#endif /* __I2C_H */
