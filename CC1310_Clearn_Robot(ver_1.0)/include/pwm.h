/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : pwm.h
 * 내용 : pwm에 대한 정의
 */

#ifndef INCLUDE_PWM_H_
#define INCLUDE_PWM_H_

#define PWM_CH1                     1               // PWM 채널 1 정의
#define PWM_CH2                     2               // PWM 채널 2 정의
#define PWM_CH3                     3               // PWM 채널 3 정의
#define PWM_CH4                     4               // PWM 채널 4 정의
#define PWM_CH5                     5               // PWM 채널 5 정의
#define PWM_CH6                     6               // PWM 채널 6 정의
#define PWM_CH7                     7               // PWM 채널 7 정의
#define PWM_CH8                     8               // PWM 채널 8 정의

//PWM 초기화 상태 확인
typedef enum
{
    PWM_Handle_NULL             = 0, //!< Handler_Null
    PWM_Status_Success          = 1, //!< Success
    PWM_Status_Fail             = 2, //!< Fail

}PWM_Status;

//PWM 핸들러 시작 상태 확인
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

//PWM 핸들러 정지 상태 확인
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

//PWM 핸들러 닫힘 상태 확인
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

//PWM 초기화 상태 확인
typedef enum
{
    Servo_Motor             = 0, //!< Servo Motor
    DC_Motor                = 1, //!< DC Motor

}Motor_Choice;

void PWM_Config_init(Motor_Choice select, uint32_t pwmPeriod, uint32_t dutyvalue);          // PWM 초기화
void PWM_DutySet(uint8_t pwmch, uint16_t duty);                                             // PWM 듀티 설정
void PWM_PeriodSet(uint8_t pwmch, uint32_t period);                                         // PWM 주기 설정
PWM_Status PWM_Handler_Open(uint8_t pwmch);                                                 // PWM 핸들러 오픈
PWM_Start_status PWM_Handler_Start(uint8_t pwmch);                                          // PWM 핸들러 시작
PWM_Stop_status PWM_Handler_Stop(uint8_t pwmch);                                            // PWM 핸들러 정지
PWM_Close_status PWM_Handler_Close(uint8_t pwmch);                                          // PWM 핸들러 닫힘

#endif /* INCLUDE_PWM_H_ */
