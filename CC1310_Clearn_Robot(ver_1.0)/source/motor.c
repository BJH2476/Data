/*
 * �ۼ���    : ������
 * �ۼ���    : 2019.09.19
 * ���ϸ�    : motor.c
 * ä�� ���� : PWM_CH5 : ���� ���� ���� ���� ä��
 *          PWM_CH6 : ���� ���� ���� ���� ä��
 *          PWM_CH7 : ������ ���� ���� ���� ä��
 *          PWM_CH8 : ������ ���� ���� ���� ä��
 */

#include "Board.h"

static uint8_t same_cmd_cnt = 0;                // ���� ����� �ݺ� �Ǵ°� �����ϱ� ���� ����.
static uint8_t same_flag_cmd = 0;               // ���� ����� �ݺ� �Ǵ°�� �ð� �÷��׸� Ȱ��ȭ.
static uint8_t same_timer = 0;                  // ���� ����� �ݺ� ���� �ʴ� ��� �ش� ���� �ð��� �Ǹ� same_cmd_cnt �ʱ�ȭ.

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Motor_Control_Timer
 * ��   ��: ���� ���� ��� ��ȯ ��⸦ ���� Timer
 */
void Motor_Control_Timer(uint16_t time)
{
    static uint32_t chkTimer=0;

    if( getCalcTimer1(chkTimer) > time)
    {
        chkTimer = timerData.timer0Count[1];

        if(Timer_Motor.motor_flag == 1) Timer_Motor.motor_cnt++;        // ���� ���� ��� ���� �ð� ī����.
        if(same_flag_cmd == 1)
        {
            same_timer++;                                               // ���� ��� ���� �ð� ī����.
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Motor_Config_init
 * ��   ��: ���� �Ķ���� �� �ʱ�ȭ ���� �Լ�
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Move_forward_Motor
 * ��   ��: ���� ���� ������ ���� �Լ�
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Back_UP_Motor
 * ��   ��: ���� ���� ������ ���� �Լ�
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Move_forward_Left_Motor
 * ��   ��: ���� ���� ��ȸ�� ������ ���� �Լ�
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : Move_forward_Right_Motor
 * ��   ��: ���� ���� ��ȸ�� ������ ���� �Լ�
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.19
 * �Լ��� : DC_Motor_Manger
 * ��   ��: ���� ��� ���� ��ü������ �����ϴ� �Լ�.
 * ������ :
 *          0x00 : ��ü ������ OFF�� ���� ���.
 *          0x01 : ���� ������ ON�� ���.
 *          0x02 : ���� ������ ON�� ���.
 *          0x04 : �ϴ� ���� ������ ON�� ���.
 *          0x08 : �ϴ� ���� ������ ON�� ���.
 *          0x10 : ��� ���� ������ ON�� ���.
 *          0x20 : ��� ���� ������ ON�� ���.
 *          --------------------------
 *          0x30 : ��� �¿��� ������ ON�� ���.
 *          0x11 : ��� ���� & ���� ������ ON�� ���.
 *          0x22 : ��� ���� & ���� ������ ON�� ���.
 *
 */
void DC_Motor_Manger(void)
{
    switch(cmd_motor.motor_command)
    {
        case 0x00 : // ��ü ���� OFF    (���� ���)
                    Move_forward_Motor(); break;

        case 0x01 : // ���� ���� ON     (���� ���� ��ȯ ���)
                    Timer_Motor.motor_flag = 1;
                    Move_forward_Left_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x00;
                    } break;

        case 0x02 : // ���� ���� ON     (���� ���� ��ȯ ���)
                    Timer_Motor.motor_flag = 1;
                    Move_forward_Right_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x00;
                    } break;

        //case 0x04 : // �ϴ� ���� ���� ON  (���� ��� �� ���� ���� ��ȯ)
        //case 0x08 : // �ϴ� ���� ���� ON  (���� ��� �� ���� ���� ��ȯ)

        case 0x10 : // ��� ���� ���� ON  (���� ���)
        case 0x20 : // ��� ���� ���� ON  (���� ���)
        case 0x30 : // ��� �¿��� ���� ON  (���� ���)
                    Timer_Motor.motor_flag = 1;
                    same_flag_cmd = 1;

                    Back_UP_Motor();

                    if(Timer_Motor.motor_cnt == 2)  // 2�� ���� ���� ���� ���� �������
                    {
                        same_cmd_cnt++;
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        if(same_cmd_cnt != 3) cmd_motor.motor_command = 0x00;
                    }

                    // ���� ��� 3ȸ �� �������� ���� ����� �Ǵ��Ͽ� ���� �淮���� ����
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

        case 0x11 : // ��� ���� & ���� ������ ON (���� ��� -> ���� ���� ��ȯ ���)
                    Timer_Motor.motor_flag = 1;
                    Back_UP_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x01;
                    } break;

        case 0x22 : // ��� ���� & ���� ������ ON (���� ��� -> ���� ���� ��ȯ ���)
                    Timer_Motor.motor_flag = 1;
                    Back_UP_Motor();
                    if(Timer_Motor.motor_cnt == 2)
                    {
                        Timer_Motor.motor_cnt = 0;
                        Timer_Motor.motor_flag = 0;
                        cmd_motor.motor_command = 0x02;
                    } break;

        default :   // ���� ���� �ʴ� ������ ��� ����� ���� ������� �����Ѵ�.
                    cmd_motor.motor_command = 0x00; break;
    }
}
