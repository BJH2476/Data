/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : pwm.c
 */
#include "Board.h"

PWM_Params params;
PWM_Status status;
PWM_Handle pwm1 = NULL;                             // PWM Handler channel 1
PWM_Handle pwm2 = NULL;                             // PWM Handler channel 2
PWM_Handle pwm3 = NULL;                             // PWM Handler channel 3
PWM_Handle pwm4 = NULL;                             // PWM Handler channel 4
PWM_Handle pwm5 = NULL;                             // PWM Handler channel 5
PWM_Handle pwm6 = NULL;                             // PWM Handler channel 6
PWM_Handle pwm7 = NULL;                             // PWM Handler channel 7
PWM_Handle pwm8 = NULL;                             // PWM Handler channel 8

void PWM_Params_Set(Motor_Choice select, uint32_t pwmPeriod, uint32_t dutyvalue)
{
    if(select == DC_Motor)
    {
        PWM_Params_init(&params);
        params.idleLevel  = PWM_IDLE_HIGH;
        params.dutyUnits = PWM_DUTY_US;
        params.dutyValue = dutyvalue;
        params.periodUnits = PWM_PERIOD_HZ;
        params.periodValue = pwmPeriod;
    }
    else if(select == Servo_Motor)
    {
        PWM_Params_init(&params);
        params.idleLevel  = PWM_IDLE_LOW;
        params.dutyUnits = PWM_DUTY_US;
        params.dutyValue = dutyvalue;
        params.periodUnits = PWM_PERIOD_HZ;
        params.periodValue = pwmPeriod;
    }
}

void PWM_Config_init(Motor_Choice select, uint32_t pwmPeriod, uint32_t dutyvalue)
{
    PWM_init();
    PWM_Params_Set(select, pwmPeriod, dutyvalue);
}

PWM_Status PWM_Handler_Open(uint8_t pwmch)
{
    switch(pwmch)
    {
        case PWM_CH1 :
                       pwm1 = PWM_open(Board_PWM0, &params);
                       if(pwm1 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm1); break;
        case PWM_CH2 :
                       pwm2 = PWM_open(Board_PWM1, &params);
                       if(pwm2 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm2); break;
        case PWM_CH3 :
                       pwm3 = PWM_open(Board_PWM2, &params);
                       if(pwm3 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm3); break;
        case PWM_CH4 :
                       pwm4 = PWM_open(Board_PWM3, &params);
                       if(pwm4 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm4); break;
        case PWM_CH5 :
                       pwm5 = PWM_open(Board_PWM4, &params);
                       if(pwm5 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm5); break;
        case PWM_CH6 :
                       pwm6 = PWM_open(Board_PWM5, &params);
                       if(pwm6 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm6); break;
        case PWM_CH7 :
                       pwm7 = PWM_open(Board_PWM6, &params);
                       if(pwm7 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm7); break;
        case PWM_CH8 :
                       pwm8 = PWM_open(Board_PWM7, &params);
                       if(pwm8 == NULL) status = PWM_Handle_NULL;
                       PWM_start(pwm8); break;
    }

    return status;
}

void PWM_PeriodSet(uint8_t pwmch, uint32_t period)
{
    switch(pwmch)
    {
        case PWM_CH1 : PWM_setPeriod(pwm1, period); break;
        case PWM_CH2 : PWM_setPeriod(pwm2, period); break;
        case PWM_CH3 : PWM_setPeriod(pwm3, period); break;
        case PWM_CH4 : PWM_setPeriod(pwm4, period); break;
        case PWM_CH5 : PWM_setPeriod(pwm5, period); break;
        case PWM_CH6 : PWM_setPeriod(pwm6, period); break;
        case PWM_CH7 : PWM_setPeriod(pwm7, period); break;
        case PWM_CH8 : PWM_setPeriod(pwm8, period); break;
    }
}

void PWM_DutySet(uint8_t pwmch, uint16_t duty)
{
    switch(pwmch)
    {
        case PWM_CH1 : PWM_setDuty(pwm1, duty); break;
        case PWM_CH2 : PWM_setDuty(pwm2, duty); break;
        case PWM_CH3 : PWM_setDuty(pwm3, duty); break;
        case PWM_CH4 : PWM_setDuty(pwm4, duty); break;
        case PWM_CH5 : PWM_setDuty(pwm5, duty); break;
        case PWM_CH6 : PWM_setDuty(pwm6, duty); break;
        case PWM_CH7 : PWM_setDuty(pwm7, duty); break;
        case PWM_CH8 : PWM_setDuty(pwm8, duty); break;
    }
}

PWM_Stop_status PWM_Handler_Stop(uint8_t pwmch)
{
    PWM_Stop_status status;

    switch(pwmch)
    {
        case PWM_CH1 : PWM_stop(pwm1);
                       status = PWM_Handler_CH1_Stop;
                       break;
        case PWM_CH2 : PWM_stop(pwm2);
                       status = PWM_Handler_CH2_Stop;
                       break;
        case PWM_CH3 : PWM_stop(pwm3);
                       status = PWM_Handler_CH3_Stop;
                       break;
        case PWM_CH4 : PWM_stop(pwm4);
                       status = PWM_Handler_CH4_Stop;
                       break;
        case PWM_CH5 : PWM_stop(pwm5);
                       status = PWM_Handler_CH5_Stop;
                       break;
        case PWM_CH6 : PWM_stop(pwm6);
                       status = PWM_Handler_CH6_Stop;
                       break;
        case PWM_CH7 : PWM_stop(pwm7);
                       status = PWM_Handler_CH7_Stop;
                       break;
        case PWM_CH8 : PWM_stop(pwm8);
                       status = PWM_Handler_CH8_Stop;
                       break;
    }

    return status;
}

PWM_Start_status PWM_Handler_Start(uint8_t pwmch)
{
    PWM_Start_status status;

    switch(pwmch)
    {
        case PWM_CH1 : PWM_start(pwm1);
                       status = PWM_Handler_CH1_Start;
                       break;
        case PWM_CH2 : PWM_start(pwm2);
                       status = PWM_Handler_CH2_Start;
                       break;
        case PWM_CH3 : PWM_start(pwm3);
                       status = PWM_Handler_CH3_Start;
                       break;
        case PWM_CH4 : PWM_start(pwm4);
                       status = PWM_Handler_CH4_Start;
                       break;
        case PWM_CH5 : PWM_start(pwm5);
                       status = PWM_Handler_CH5_Start;
                       break;
        case PWM_CH6 : PWM_start(pwm6);
                       status = PWM_Handler_CH6_Start;
                       break;
        case PWM_CH7 : PWM_start(pwm7);
                       status = PWM_Handler_CH7_Start;
                       break;
        case PWM_CH8 : PWM_start(pwm8);
                       status = PWM_Handler_CH8_Start;
                       break;
    }

    return status;
}

PWM_Close_status PWM_Handler_Close(uint8_t pwmch)
{
    PWM_Close_status status;

    switch(pwmch)
    {
        case PWM_CH1 : PWM_close(pwm1);
                       status = PWM_Handler_CH1_Close;
                       break;
        case PWM_CH2 : PWM_close(pwm2);
                       status = PWM_Handler_CH2_Close;
                       break;
        case PWM_CH3 : PWM_close(pwm3);
                       status = PWM_Handler_CH3_Close;
                       break;
        case PWM_CH4 : PWM_close(pwm4);
                       status = PWM_Handler_CH4_Close;
                       break;
        case PWM_CH5 : PWM_close(pwm5);
                       status = PWM_Handler_CH5_Close;
                       break;
        case PWM_CH6 : PWM_close(pwm6);
                       status = PWM_Handler_CH6_Close;
                       break;
        case PWM_CH7 : PWM_close(pwm7);
                       status = PWM_Handler_CH7_Close;
                       break;
        case PWM_CH8 : PWM_close(pwm8);
                       status = PWM_Handler_CH8_Close;
                       break;
    }

    return status;
}
