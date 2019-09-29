/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : i2c.h
 * ���� : i2c�� ���� ����
 */

#ifndef INCLUDE_I2C_H_
#define INCLUDE_I2C_H_

typedef enum
{
    I2C_Handle_NULL            = 0, //!< Handler_Null
    I2C_Status_Success         = 1, //!< Success
    I2C_Status_Fail            = 2, //!< Fail
}I2C_Status;

//I2C_100kHz  !< I2C Standard-mode. Up to 100 kbit/s.
//I2C_400kHz  !< I2C Fast-mode. Up to 400 kbit/s.
//I2C_1000kHz !< I2C Fast-mode Plus. Up to 1Mbit/s.
//I2C_3330kHz !< I2C High-speed mode. Up to 3.4Mbit/s.
//I2C_3400kHz !< I2C High-speed mode. Up to 3.4Mbit/s.

void I2C_Config_init(I2C_BitRate bitRate);                                                                      // i2c �ʱ�ȭ
void I2C_Command(uint_least8_t slaveAddress, void *txBuffer, size_t txCnt, void *rxBuffer, size_t rxCnt);       // i2c Command

#endif /* INCLUDE_I2C_H_ */
