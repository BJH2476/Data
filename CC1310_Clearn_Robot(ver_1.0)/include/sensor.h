/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : sensor.h
 * 내용 : 센서 동작에 대한 정의
 */

#ifndef INCLUDE_SENSOR_H_
#define INCLUDE_SENSOR_H_

// 센서 명령에 대한 구조체
struct Sensor_Command
{
    uint8_t motor_command;          // 모터 제어 명령 변수

}__attribute__((aligned(1), packed));
typedef struct Sensor_Command command_motor;

command_motor   cmd_motor;

void Sensor_Manager(void);          // 전체 센서 입력을 관리

#endif /* INCLUDE_SENSOR_H_ */
