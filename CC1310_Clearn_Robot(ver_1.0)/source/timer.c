/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : timer.c
 */

#include "Board.h"

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : rxTimeoutCb
 * 내   용: 타이머 인터럽트 핸들러 (1ms에 한번씩 핸들러 호출)
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
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : getCalcTimer0
 * 내   용: 시간설정을 위함 함수
 */
uint32_t getCalcTimer0( uint32_t startTime )
{
    if(timerData.timer0Count[0] >= startTime)  return(timerData.timer0Count[0]  - startTime);
    else                                    return( (0xFFFFFFFF - startTime) + timerData.timer0Count[0] );
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : getCalcTimer0
 * 내   용: 시간설정을 위함 함수
 */
uint32_t getCalcTimer1( uint32_t startTime )
{
    if(timerData.timer0Count[1] >= startTime)  return(timerData.timer0Count[1]  - startTime);
    else                                    return( (0xFFFFFFFF - startTime) + timerData.timer0Count[1] );
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : Timer_Config_init
 * 내   용: 타이머 초기화 및 파라미터 세팅
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

