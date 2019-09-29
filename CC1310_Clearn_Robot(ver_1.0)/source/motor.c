/*
 * 작성자    : 변진혁
 * 작성일    : 2019.09.19
 * 파일명    : motor.c
 * 채널 구성 : PWM_CH5 : 왼쪽 모터 후진 역할 채널
 *          PWM_CH6 : 왼쪽 모터 전진 역할 채널
 *          PWM_CH7 : 오른쪽 모터 전진 역할 채널
 *          PWM_CH8 : 오른쪽 모터 후진 역할 채널
 */

#include "Board.h"

static uint8_t same_cmd_cnt = 0;                // 같은 명령이 반복 되는걸 방지하기 위한 변수.
static uint8_t same_flag_cmd = 0;               // 같은 명령이 반복 되는경우 시간 플래그를 활성화.
static uint8_t same_timer = 0;                  // 같은 명령이 반복 되지 않는 경우 해당 설정 시간이 되면 same_cmd_cnt 초기화.

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Motor_Control_Timer
 * 내   용: 모터 제어 명령 전환 대기를 위한 Timer
 */
void Motor_Control_Timer(uint16_t time)
{
    static uint32_t chkTimer=0;

    if( getCalcTimer1(chkTimer) > time)
    {
        chkTimer = timerData.timer0Count[1];

        if(Timer_Motor.motor_flag == 1) Timer_Motor.motor_cnt++;        // 모터 제어 명령 동작 시간 카운터.
        if(same_flag_cmd == 1)
        {
            same_timer++;                                               // 같은 명령 방지 시간 카운터.
            if(same_timer == 10)
            {
                same_flag_cmd = 0;
                same_cmd_cnt = 0;
                same_timer = 0;
            }
        }
    }
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Motor_Config_init
 * 내   용: 모터 파라미터 및 초기화 설정 함수
 */
void Motor_Config_init(void)
{
    PWM_Config_init(DC_Motor, 50, 0);               // Period(HZ) : 50HZ
                                                    // Duty(US)   : 0US
    Motor_Handler_Open(PWM_CH5);
    Motor_Handler_Open(PWM_CH6);
    Motor_Handler_Open(PWM_CH7);
    Motor_Handler_Open(PWM_CH8);
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Move_forward_Motor
 * 내   용: 모터 전진 설정에 대한 함수
 */
Motor_Status Move_forward_Motor(void)
{
    Motor_Handler_Stop(PWM_CH5);
    Motor_Handler_Stop(PWM_CH8);
    usleep(50000);
    Motor_Handler_Start(PWM_CH6);
    Motor_Handler_Start(PWM_CH7);

    return Move_Forward;
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Back_UP_Motor
 * 내   용: 모터 후진 설정에 대한 함수
 */
Motor_Status Back_UP_Motor(void)
{
    Motor_Handler_Stop(PWM_CH6);
    Motor_Handler_Stop(PWM_CH7);
    usleep(50000);
    Motor_Handler_Start(PWM_CH5);
    Motor_Handler_Start(PWM_CH8);

    return Back_UP;
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Move_forward_Left_Motor
 * 내   용: 모터 전진 좌회전 설정에 대한 함수
 */
Motor_Status Move_forward_Left_Motor(void)
{
    Motor_Handler_Start(PWM_CH7);
    Motor_Handler_Start(PWM_CH5);
    usleep(50000);
    Motor_Handler_Stop(PWM_CH6);
    Motor_Handler_Stop(PWM_CH8);

    return Forward_Left;
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : Move_forward_Right_Motor
 * 내   용: 모터 전진 우회전 설정에 대한 함수
 */
Motor_Status Move_forward_Right_Motor(void)
{
    Motor_Handler_Start(PWM_CH6);
    Motor_Handler_Start(PWM_CH8);
    usleep(50000);
    Motor_Handler_Stop(PWM_CH5);
    Motor_Handler_Stop(PWM_CH7);

    return Forward_Right;
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.19
 * 함수명 : DC_Motor_Manger
 * 내   용: 모터 제어에 대한 전체적으로 관리하는 함수.
 * 제어명령 :
 *          0x00 : 전체 센서가 OFF인 없는 경우.
 *          0x01 : 좌측 센서가 ON인 경우.
 *          0x02 : 우측 센서가 ON인 경우.
 *          0x04 : 하단 좌측 센서가 ON인 경우.
 *          0x08 : 하단 우측 센서가 ON인 경우.
 *          0x10 : 상단 좌측 센서가 ON인 경우.
 *          0x20 : 상단 우측 센서가 ON인 경우.
 *          --------------------------
 *          0x30 : 상단 좌우측 센서가 ON인 경우.
 *          0x11 : 상단 좌측 & 좌측 센서가 ON인 경우.
 *          0x22 : 상단 우측 & 우측 센서가 ON인 경우.
 *
 */
void DC_Motor_Manger(void)
{
    switch(cmd_motor.motor_command)
    {
        case 0x00 : // 전체 센서 OFF    (전진 명령)
                    Move_forward_Motor(); break;

        case 0x01 : // 좌측 센서 ON     (우측 방향 전환 명령)
                    Timer_Motor.motor_flag = 1;
                    Move_forward_Left_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x00;
                    } break;

        case 0x02 : // 우측 센서 ON     (좌측 방향 전환 명령)
                    Timer_Motor.motor_flag = 1;
                    Move_forward_Right_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x00;
                    } break;

        //case 0x04 : // 하단 좌측 센서 ON  (후진 명령 후 우측 방향 전환)
        //case 0x08 : // 하단 우측 센서 ON  (후진 명령 후 좌측 방향 전환)

        case 0x10 : // 상단 좌측 센서 ON  (후진 명령)
        case 0x20 : // 상단 우측 센서 ON  (후진 명령)
        case 0x30 : // 상단 좌우측 센서 ON  (후진 명령)
                    Timer_Motor.motor_flag = 1;
                    same_flag_cmd = 1;

                    Back_UP_Motor();

                    if(Timer_Motor.motor_cnt == 2)  // 2초 동안 후진 동작 이후 전진명령
                    {
                        same_cmd_cnt++;
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        if(same_cmd_cnt != 3) cmd_motor.motor_command = 0x00;
                    }

                    // 후진 명령 3회 및 최종적인 센서 명령을 판단하여 우측 방량으로 동작
                    if(same_cmd_cnt == 3 && cmd_motor.motor_command == 0x20)
                    {
                        cmd_motor.motor_command = 0x02;
                        same_cmd_cnt = 0;
                    }
                    else if(same_cmd_cnt == 3 && cmd_motor.motor_command != 0x20)
                    {
                        cmd_motor.motor_command = 0x01;
                        same_cmd_cnt = 0;
                    }break;

        case 0x11 : // 상단 좌측 & 좌측 센서가 ON (후진 명령 -> 우측 방향 전환 명령)
                    Timer_Motor.motor_flag = 1;
                    Back_UP_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x01;
                    } break;

        case 0x22 : // 상단 우측 & 우측 센서가 ON (후진 명령 -> 좌측 방향 전환 명령)
                    Timer_Motor.motor_flag = 1;
                    Back_UP_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x02;
                    } break;

        default :   // 정의 되지 않는 나머지 명령 제어는 전진 명령으로 정의한다.
                    cmd_motor.motor_command = 0x00; break;
    }
}
