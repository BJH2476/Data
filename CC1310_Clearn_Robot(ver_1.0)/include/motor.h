/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : motor.h
 * 내용 : 모터 동작에 대한 정의
 */

#ifndef INCLUDE_MOTOR_H_
#define INCLUDE_MOTOR_H_

#define Motor_Handler_Open(pwmch)             PWM_Handler_Open(pwmch)           // 모터동작을 위한 PWM 채널 오픈
#define Motor_Handler_Start(pwmch)            PWM_Handler_Start(pwmch)          // 모터동작을 위한 PWM 채널 시작
#define Motor_Handler_Stop(pwmch)             PWM_Handler_Stop(pwmch)           // 모터동작을 위한 PWM 채널 정지

// 모터 동작 상태 표시
typedef enum
{
    Move_Forward        = 0,            //!< 전진 상태 표시
    Back_UP             = 1,            //!< 후진 상태 표시
    Forward_Left        = 2,            //!< 전진 좌회전 상태 표시
    Forward_Right       = 3,            //!< 전진 우회전 상태 표시
    Back_Left           = 4,            //!< 후진 좌회전 상태 표시
    Back_Right          = 5,            //!< 후진 우회전 상태 표시

}Motor_Status;

// 모터 명령 시간 제한을 위한 구조체
struct Motor_timer
{
    uint8_t motor_flag;
    uint8_t motor_cnt;

}__attribute__((aligned(1), packed));
typedef struct Motor_timer Motor_T;

Motor_T Timer_Motor;

void Motor_Config_init(void);                       // 모터 초기화
Motor_Status Move_forward_Motor(void);              // 모터 전진
Motor_Status Back_UP_Motor(void);                   // 모터 후진
Motor_Status Move_forward_Left_Motor(void);         // 모터 좌측 방향 전환
Motor_Status Move_forward_Right_Motor(void);        // 모터 우측 방향 전환
void DC_Motor_Manger(void);                         // 전제척인 모터 제어 관리
void Motor_Control_Timer(uint16_t time);            // 2가지 이상의 명령을 사용해야되는경우 사용하는 타이머

#endif /* INCLUDE_MOTOR_H_ */
