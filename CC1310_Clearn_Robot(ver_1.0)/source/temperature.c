/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : temperature.c
 */
#include "Board.h"

void Temperature_Manager(void)
{
    I2C_Command(TEMPERATURE_ADD, Data_Temp.txData, 0, Data_Temp.rxData, 2);

    Data_Temp.totalData = (Data_Temp.rxData[0] << 3) + (Data_Temp.rxData[1] >> 5);

    Data_Temp.totalData = Data_Temp.totalData * 0.125;
}
