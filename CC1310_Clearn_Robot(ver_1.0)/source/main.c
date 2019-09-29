/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : main.c
 */
#include "Board.h"

static float VoltageValue = 0;
static uint32_t temperatureValue = 0;

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : RunningLED
 * 내   용: RUN LED 함수(500ms에 한번씩 RUN LED Toggle )
 */
void RunningLED(uint16_t time)
{
    static uint32_t chkTimer=0;

    if( getCalcTimer0(chkTimer) > time)
    {
        chkTimer = timerData.timer0Count[0];
        PIN_setOutputValue(pinHandle, RUN_LED_PORT,!PIN_getOutputValue(RUN_LED_PORT));
    }
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : Peripheral_init
 * 내   용: RUN LED 함수(500ms에 한번씩 RUN LED Toggle )
 */
void Peripheral_init(void)
{
    Uart_Config_init(115200);                               // UART init & Params Setting
    Timer_Config_init();                                    // Timer init & Params Setting
    Motor_Config_init();                                    // Motor init & Params Setting
    RF_Config_init();                                       // RF init & Params Setting
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : main
 */
int main(void)
{
    Board_initGeneral();
    NoRTOS_start();
    Peripheral_init();

    while (1)
    {
        VoltageValue = AONBatMonBatteryVoltageGet();            // CPU 내부 배터리감시
        VoltageValue = VoltageValue/255;                        // 2^8으로 나눈다.
        temperatureValue = AONBatMonTemperatureGetDegC();       // CPU 내부 온도데이터

        Motor_Control_Timer(1000);
        RunningLED(500);
        Sensor_Manager();
        DC_Motor_Manger();
        RF_Send_Manager(temperatureValue, VoltageValue);
    }
}
