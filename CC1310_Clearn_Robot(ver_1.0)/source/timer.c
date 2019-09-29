/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : timer.c
 */

#include "Board.h"

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : rxTimeoutCb
 * ��   ��: Ÿ�̸� ���ͷ�Ʈ �ڵ鷯 (1ms�� �ѹ��� �ڵ鷯 ȣ��)
 */
void Timer_Interrupt_Handler1(GPTimerCC26XX_Handle handle, GPTimerCC26XX_IntMask interruptMask)
{
    if(++timerData.tempCount[0] >= 1)
    {
        timerData.tempCount[0] = 0;
        timerData.timer0Count[0]++;
    }

    if(++timerData.tempCount[1] >= 1)
    {
        timerData.tempCount[1] = 0;
        timerData.timer0Count[1]++;
    }
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : getCalcTimer0
 * ��   ��: �ð������� ���� �Լ�
 */
uint32_t getCalcTimer0( uint32_t startTime )
{
    if(timerData.timer0Count[0] >= startTime)  return(timerData.timer0Count[0]  - startTime);
    else                                    return( (0xFFFFFFFF - startTime) + timerData.timer0Count[0] );
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : getCalcTimer0
 * ��   ��: �ð������� ���� �Լ�
 */
uint32_t getCalcTimer1( uint32_t startTime )
{
    if(timerData.timer0Count[1] >= startTime)  return(timerData.timer0Count[1]  - startTime);
    else                                    return( (0xFFFFFFFF - startTime) + timerData.timer0Count[1] );
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : Timer_Config_init
 * ��   ��: Ÿ�̸� �ʱ�ȭ �� �Ķ���� ����
 */
void Timer_Config_init(void)
{
    GPTimerCC26XX_Params params;
    params.width          = GPT_CONFIG_32BIT;
    params.mode           = GPT_MODE_PERIODIC_UP;
    params.debugStallMode = GPTimerCC26XX_DEBUG_STALL_OFF;

    Timer1 = GPTimerCC26XX_open(Board_GPTIMER0A, &params);
    if(Timer1 == NULL)
    {
        while(1);
    }

    /* Set Timeout value to 1ms */
    rxTimeoutVal = (SysCtrlClockGet()*1UL)/1000UL - 1UL;

    GPTimerCC26XX_setLoadValue(Timer1, rxTimeoutVal);
    GPTimerCC26XX_registerInterrupt(Timer1, Timer_Interrupt_Handler1, GPT_INT_TIMEOUT);
    GPTimerCC26XX_start(Timer1);
}

