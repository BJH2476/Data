/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : motor.h
 * ���� : ���� ���ۿ� ���� ����
 */

#ifndef INCLUDE_MOTOR_H_
#define INCLUDE_MOTOR_H_

#define Motor_Handler_Open(pwmch)             PWM_Handler_Open(pwmch)           // ���͵����� ���� PWM ä�� ����
#define Motor_Handler_Start(pwmch)            PWM_Handler_Start(pwmch)          // ���͵����� ���� PWM ä�� ����
#define Motor_Handler_Stop(pwmch)             PWM_Handler_Stop(pwmch)           // ���͵����� ���� PWM ä�� ����

// ���� ���� ���� ǥ��
typedef enum
{
    Move_Forward        = 0,            //!< ���� ���� ǥ��
    Back_UP             = 1,            //!< ���� ���� ǥ��
    Forward_Left        = 2,            //!< ���� ��ȸ�� ���� ǥ��
    Forward_Right       = 3,            //!< ���� ��ȸ�� ���� ǥ��
    Back_Left           = 4,            //!< ���� ��ȸ�� ���� ǥ��
    Back_Right          = 5,            //!< ���� ��ȸ�� ���� ǥ��

}Motor_Status;

// ���� ��� �ð� ������ ���� ����ü
struct Motor_timer
{
    uint8_t motor_flag;
    uint8_t motor_cnt;

}__attribute__((aligned(1), packed));
typedef struct Motor_timer Motor_T;

Motor_T Timer_Motor;

void Motor_Config_init(void);                       // ���� �ʱ�ȭ
Motor_Status Move_forward_Motor(void);              // ���� ����
Motor_Status Back_UP_Motor(void);                   // ���� ����
Motor_Status Move_forward_Left_Motor(void);         // ���� ���� ���� ��ȯ
Motor_Status Move_forward_Right_Motor(void);        // ���� ���� ���� ��ȯ
void DC_Motor_Manger(void);                         // ����ô�� ���� ���� ����
void Motor_Control_Timer(uint16_t time);            // 2���� �̻��� ����� ����ؾߵǴ°�� ����ϴ� Ÿ�̸�

#endif /* INCLUDE_MOTOR_H_ */
