/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : pwm.h
 * ���� : pwm�� ���� ����
 */

#ifndef INCLUDE_PWM_H_
#define INCLUDE_PWM_H_

#define PWM_CH1                     1               // PWM ä�� 1 ����
#define PWM_CH2                     2               // PWM ä�� 2 ����
#define PWM_CH3                     3               // PWM ä�� 3 ����
#define PWM_CH4                     4               // PWM ä�� 4 ����
#define PWM_CH5                     5               // PWM ä�� 5 ����
#define PWM_CH6                     6               // PWM ä�� 6 ����
#define PWM_CH7                     7               // PWM ä�� 7 ����
#define PWM_CH8                     8               // PWM ä�� 8 ����

//PWM �ʱ�ȭ ���� Ȯ��
typedef enum
{
    PWM_Handle_NULL             = 0, //!< Handler_Null
    PWM_Status_Success          = 1, //!< Success
    PWM_Status_Fail             = 2, //!< Fail

}PWM_Status;

//PWM �ڵ鷯 ���� ���� Ȯ��
typedef enum
{
    PWM_Handler_CH1_Start       = 1, //!< Channel 1 Start
    PWM_Handler_CH2_Start       = 2, //!< Channel 2 Start
    PWM_Handler_CH3_Start       = 3, //!< Channel 3 Start
    PWM_Handler_CH4_Start       = 4, //!< Channel 4 Start
    PWM_Handler_CH5_Start       = 5, //!< Channel 5 Start
    PWM_Handler_CH6_Start       = 6, //!< Channel 6 Start
    PWM_Handler_CH7_Start       = 7, //!< Channel 7 Start
    PWM_Handler_CH8_Start       = 8, //!< Channel 8 Start

}PWM_Start_status;

//PWM �ڵ鷯 ���� ���� Ȯ��
typedef enum
{
    PWM_Handler_CH1_Stop       = 1, //!< Channel 1 Stop
    PWM_Handler_CH2_Stop       = 2, //!< Channel 2 Stop
    PWM_Handler_CH3_Stop       = 3, //!< Channel 3 Stop
    PWM_Handler_CH4_Stop       = 4, //!< Channel 4 Stop
    PWM_Handler_CH5_Stop       = 5, //!< Channel 5 Stop
    PWM_Handler_CH6_Stop       = 6, //!< Channel 6 Stop
    PWM_Handler_CH7_Stop       = 7, //!< Channel 7 Stop
    PWM_Handler_CH8_Stop       = 8, //!< Channel 8 Stop

}PWM_Stop_status;

//PWM �ڵ鷯 ���� ���� Ȯ��
typedef enum
{
    PWM_Handler_CH1_Close       = 1, //!< Channel 1 Close
    PWM_Handler_CH2_Close       = 2, //!< Channel 2 Close
    PWM_Handler_CH3_Close       = 3, //!< Channel 3 Close
    PWM_Handler_CH4_Close       = 4, //!< Channel 4 Close
    PWM_Handler_CH5_Close       = 5, //!< Channel 5 Close
    PWM_Handler_CH6_Close       = 6, //!< Channel 6 Close
    PWM_Handler_CH7_Close       = 7, //!< Channel 7 Close
    PWM_Handler_CH8_Close       = 8, //!< Channel 8 Close

}PWM_Close_status;

//PWM �ʱ�ȭ ���� Ȯ��
typedef enum
{
    Servo_Motor             = 0, //!< Servo Motor
    DC_Motor                = 1, //!< DC Motor

}Motor_Choice;

void PWM_Config_init(Motor_Choice select, uint32_t pwmPeriod, uint32_t dutyvalue);          // PWM �ʱ�ȭ
void PWM_DutySet(uint8_t pwmch, uint16_t duty);                                             // PWM ��Ƽ ����
void PWM_PeriodSet(uint8_t pwmch, uint32_t period);                                         // PWM �ֱ� ����
PWM_Status PWM_Handler_Open(uint8_t pwmch);                                                 // PWM �ڵ鷯 ����
PWM_Start_status PWM_Handler_Start(uint8_t pwmch);                                          // PWM �ڵ鷯 ����
PWM_Stop_status PWM_Handler_Stop(uint8_t pwmch);                                            // PWM �ڵ鷯 ����
PWM_Close_status PWM_Handler_Close(uint8_t pwmch);                                          // PWM �ڵ鷯 ����

#endif /* INCLUDE_PWM_H_ */
