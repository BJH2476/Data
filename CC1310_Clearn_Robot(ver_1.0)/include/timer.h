/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : timer.h
 * ���� : Ÿ�̸� ���� ����
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

// Ÿ�̸� ī���͸� ������ ����ü
struct Timer
{
    uint32_t timer0Count[2];
    uint8_t tempCount[2];

}__attribute__((aligned(1), packed));
typedef struct Timer Timer_Data;

GPTimerCC26XX_Handle Timer1;                        // Ÿ�̸� �ڵ鷯 ����
GPTimerCC26XX_Value rxTimeoutVal;                   // SysCtrlClockGet�� 1ms ���� �߻��Ǵ� ���  rxTimeoutVal�� �Է�

Timer_Data  timerData;

void Timer_Config_init(void);                                           //Timer Init & Param
uint32_t getCalcTimer0( uint32_t startTime );                           //Timer Counter
uint32_t getCalcTimer1( uint32_t startTime );                           //Timer Counter

#endif /* INCLUDE_TIMER_H_ */
