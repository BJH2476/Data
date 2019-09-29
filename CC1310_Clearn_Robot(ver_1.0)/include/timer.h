/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : timer.h
 * 내용 : 타이머 동작 정의
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

// 타이머 카운터를 정의한 구조체
struct Timer
{
    uint32_t timer0Count[2];
    uint8_t tempCount[2];

}__attribute__((aligned(1), packed));
typedef struct Timer Timer_Data;

GPTimerCC26XX_Handle Timer1;                        // 타이머 핸들러 정의
GPTimerCC26XX_Value rxTimeoutVal;                   // SysCtrlClockGet이 1ms 마다 발생되는 경우  rxTimeoutVal에 입력

Timer_Data  timerData;

void Timer_Config_init(void);                                           //Timer Init & Param
uint32_t getCalcTimer0( uint32_t startTime );                           //Timer Counter
uint32_t getCalcTimer1( uint32_t startTime );                           //Timer Counter

#endif /* INCLUDE_TIMER_H_ */
