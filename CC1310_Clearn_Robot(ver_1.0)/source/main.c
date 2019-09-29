/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : main.c
 */
#include "Board.h"

static float VoltageValue = 0;
static uint32_t temperatureValue = 0;

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : RunningLED
 * ��   ��: RUN LED �Լ�(500ms�� �ѹ��� RUN LED Toggle )
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
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : Peripheral_init
 * ��   ��: RUN LED �Լ�(500ms�� �ѹ��� RUN LED Toggle )
 */
void Peripheral_init(void)
{
    Uart_Config_init(115200);                               // UART init & Params Setting
    Timer_Config_init();                                    // Timer init & Params Setting
    Motor_Config_init();                                    // Motor init & Params Setting
    RF_Config_init();                                       // RF init & Params Setting
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : main
 */
int main(void)
{
    Board_initGeneral();
    NoRTOS_start();
    Peripheral_init();

    while (1)
    {
        VoltageValue = AONBatMonBatteryVoltageGet();            // CPU ���� ���͸�����
        VoltageValue = VoltageValue/255;                        // 2^8���� ������.
        temperatureValue = AONBatMonTemperatureGetDegC();       // CPU ���� �µ�������

        Motor_Control_Timer(1000);
        RunningLED(500);
        Sensor_Manager();
        DC_Motor_Manger();
        RF_Send_Manager(temperatureValue, VoltageValue);
    }
}
