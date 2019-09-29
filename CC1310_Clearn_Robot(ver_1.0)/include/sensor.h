/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : sensor.h
 * ���� : ���� ���ۿ� ���� ����
 */

#ifndef INCLUDE_SENSOR_H_
#define INCLUDE_SENSOR_H_

// ���� ��ɿ� ���� ����ü
struct Sensor_Command
{
    uint8_t motor_command;          // ���� ���� ��� ����

}__attribute__((aligned(1), packed));
typedef struct Sensor_Command command_motor;

command_motor   cmd_motor;

void Sensor_Manager(void);          // ��ü ���� �Է��� ����

#endif /* INCLUDE_SENSOR_H_ */
