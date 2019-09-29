/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : Temperature.h
 * ���� : LM75A �µ����� ���� ����
 */

#ifndef INCLUDE_TEMPERATURE_H_
#define INCLUDE_TEMPERATURE_H_

#define TEMPERATURE_ADD                 0x48            // �µ����� �ּ�
#define I2C_DATA_SIZE                   100             // ������ ���� ������

typedef struct
{
    uint8_t txData[I2C_DATA_SIZE];                      // Tx ���� ������
    uint8_t rxData[I2C_DATA_SIZE];                      // Rx ���� ������
    uint8_t totalData;                                  // �µ����� ������ 2Byte �����͸� ������ ������

}Temp_Data;

Temp_Data Data_Temp;

void Temperature_Manager(void);                         // �µ������� ����

#endif /* INCLUDE_TEMPERATURE_H_ */
