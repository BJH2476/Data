/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : i2c.c
 */

#include "Board.h"

I2C_Handle      i2c;
I2C_Params      i2cParams;
I2C_Transaction i2cTransaction;

void I2C_Config_init(I2C_BitRate bitRate)
{
    I2C_init();

    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = bitRate;
    i2c = I2C_open(Board_I2C0, &i2cParams);
}

void I2C_Command(uint_least8_t slaveAddress, void *txBuffer, size_t txCnt, void *rxBuffer, size_t rxCnt)
{
    i2cTransaction.slaveAddress = slaveAddress;
    i2cTransaction.writeBuf   = txBuffer;
    i2cTransaction.writeCount = txCnt;
    i2cTransaction.readBuf    = rxBuffer;
    i2cTransaction.readCount  = rxCnt;

    I2C_transfer(i2c, &i2cTransaction);
}
