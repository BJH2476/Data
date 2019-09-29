/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : sensor.c
 */
#include "Board.h"

const uint8_t cbits[8]    = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

void Sensor_Manager(void)
{
    if( !PIN_getInputValue(SENSOR_LEFT) )                   cmd_motor.motor_command |= cbits[0];
    if( !PIN_getInputValue(SENSOR_LIGHT) )                  cmd_motor.motor_command |= cbits[1];
    //if( !PIN_getInputValue(SENSOR_UNDER_LEFT) )              cmd_motor.motor_command |= cbits[2];
    //if( !PIN_getInputValue(SENSOR_UNDER_RIGHT) )             cmd_motor.motor_command |= cbits[3];
    if( !PIN_getInputValue(SENSOR_TOP_LEFT) )               cmd_motor.motor_command |= cbits[4];
    if( !PIN_getInputValue(SENSOR_TOP_RIGHT) )              cmd_motor.motor_command |= cbits[5];

}


