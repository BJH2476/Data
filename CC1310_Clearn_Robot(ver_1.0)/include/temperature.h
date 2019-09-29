/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : Temperature.h
 * 내용 : LM75A 온도센서 동작 정의
 */

#ifndef INCLUDE_TEMPERATURE_H_
#define INCLUDE_TEMPERATURE_H_

#define TEMPERATURE_ADD                 0x48            // 온도센서 주소
#define I2C_DATA_SIZE                   100             // 데이터 버퍼 사이즈

typedef struct
{
    uint8_t txData[I2C_DATA_SIZE];                      // Tx 버퍼 데이터
    uint8_t rxData[I2C_DATA_SIZE];                      // Rx 버퍼 데이터
    uint8_t totalData;                                  // 온도센서 데이터 2Byte 데이터를 가공한 데이터

}Temp_Data;

Temp_Data Data_Temp;

void Temperature_Manager(void);                         // 온도센서를 관리

#endif /* INCLUDE_TEMPERATURE_H_ */
