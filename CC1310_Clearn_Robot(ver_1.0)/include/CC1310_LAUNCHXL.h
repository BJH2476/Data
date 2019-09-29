/** ============================================================================
 *  @file       CC1310_LAUNCHXL.h
 *
 *  @brief      CC1310 LaunchPad Board Specific header file.
 *
 *  The CC1310_LAUNCHXL header file should be included in an application as
 *  follows:
 *  @code
 *  #include "CC1310_LAUNCHXL.h"
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __CC1310_LAUNCHXL_BOARD_H__
#define __CC1310_LAUNCHXL_BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include <ti/drivers/PIN.h>
#include <ti/devices/cc13x0/driverlib/ioc.h>

/* Externs */
extern const PIN_Config BoardGpioInitTable[];

/* Defines */
#define CC1310_LAUNCHXL

/* Mapping of pins to board signals using general board aliases
 *      <board signal alias>                  <pin mapping>   <comments>
 */

// DIO ����� ��Ʈ ����
#define RUN_LED_PORT                          IOID_10               // RUN LED ��Ʈ
#define SENSOR_LEFT                           IOID_21               // ���� ���� �Է� ��Ʈ
#define SENSOR_LIGHT                          IOID_22               // ���� ���� �Է� ��Ʈ
#define SENSOR_UNDER_LEFT                     IOID_23               // �ϴ� ���� ���� �Է� ��Ʈ
#define SENSOR_UNDER_RIGHT                    IOID_24               // �ϴ� ���� ���� �Է� ��Ʈ
#define SENSOR_TOP_LEFT                       IOID_25               // ��� ���� ���� �Է� ��Ʈ
#define SENSOR_TOP_RIGHT                      IOID_26               // ��� ���� ���� �Է� ��Ʈ

// I2C (SCL & SDA) ��Ʈ ����
#define CC1310_LAUNCHXL_I2C0_SCL0             PIN_UNASSIGNED        // I2C Ŭ�� �Է� ��Ʈ
#define CC1310_LAUNCHXL_I2C0_SDA0             PIN_UNASSIGNED        // I2C ������ �Է� ��Ʈ

// PWM ��� ��Ʈ ����
#define CC1310_LAUNCHXL_PWMPIN0               PIN_UNASSIGNED        // Timer ä�� ������̹Ƿ� ��� ����.
#define CC1310_LAUNCHXL_PWMPIN1               PIN_UNASSIGNED        // PWM 1ä�� ��Ʈ
#define CC1310_LAUNCHXL_PWMPIN2               PIN_UNASSIGNED        // PWM 2ä�� ��Ʈ
#define CC1310_LAUNCHXL_PWMPIN3               PIN_UNASSIGNED        // PWM 3ä�� ��Ʈ
#define CC1310_LAUNCHXL_PWMPIN4               IOID_9                // PWM 4ä�� ��Ʈ (DC ���� �����)
#define CC1310_LAUNCHXL_PWMPIN5               IOID_7                // PWM 5ä�� ��Ʈ (DC ���� �����)
#define CC1310_LAUNCHXL_PWMPIN6               IOID_11               // PWM 6ä�� ��Ʈ (DC ���� �����)
#define CC1310_LAUNCHXL_PWMPIN7               IOID_6                // PWM 7ä�� ��Ʈ (DC ���� �����)

// UART (Tx & Rx) ����� ��Ʈ ����
#define CC1310_LAUNCHXL_UART_RX               IOID_3                // UART Rx ��Ʈ ����
#define CC1310_LAUNCHXL_UART_TX               IOID_1                // UART Tx ��Ʈ ����
#define CC1310_LAUNCHXL_UART_CTS              PIN_UNASSIGNED        /* CTS */
#define CC1310_LAUNCHXL_UART_RTS              PIN_UNASSIGNED        /* RTS */

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
void CC1310_LAUNCHXL_initGeneral(void);

/*!
 *  @def    CC1310_LAUNCHXL_ADCName
 *  @brief  Enum of ADCs
 */
typedef enum CC1310_LAUNCHXL_ADCName {
    CC1310_LAUNCHXL_ADC0 = 0,
    CC1310_LAUNCHXL_ADC1,
    CC1310_LAUNCHXL_ADC2,
    CC1310_LAUNCHXL_ADC3,
    CC1310_LAUNCHXL_ADC4,
    CC1310_LAUNCHXL_ADC5,
    CC1310_LAUNCHXL_ADC6,
    CC1310_LAUNCHXL_ADC7,
    CC1310_LAUNCHXL_ADCDCOUPL,
    CC1310_LAUNCHXL_ADCVSS,
    CC1310_LAUNCHXL_ADCVDDS,

    CC1310_LAUNCHXL_ADCCOUNT
} CC1310_LAUNCHXL_ADCName;

/*!
 *  @def    CC1310_LAUNCHXL_GPTimerName
 *  @brief  Enum of GPTimer parts
 */
typedef enum CC1310_LAUNCHXL_GPTimerName {
    CC1310_LAUNCHXL_GPTIMER0A = 0,
    CC1310_LAUNCHXL_GPTIMER0B,
    CC1310_LAUNCHXL_GPTIMER1A,
    CC1310_LAUNCHXL_GPTIMER1B,
    CC1310_LAUNCHXL_GPTIMER2A,
    CC1310_LAUNCHXL_GPTIMER2B,
    CC1310_LAUNCHXL_GPTIMER3A,
    CC1310_LAUNCHXL_GPTIMER3B,

    CC1310_LAUNCHXL_GPTIMERPARTSCOUNT
} CC1310_LAUNCHXL_GPTimerName;

/*!
 *  @def    CC1310_LAUNCHXL_GPTimers
 *  @brief  Enum of GPTimers
 */
typedef enum CC1310_LAUNCHXL_GPTimers {
    CC1310_LAUNCHXL_GPTIMER0 = 0,
    CC1310_LAUNCHXL_GPTIMER1,
    CC1310_LAUNCHXL_GPTIMER2,
    CC1310_LAUNCHXL_GPTIMER3,

    CC1310_LAUNCHXL_GPTIMERCOUNT
} CC1310_LAUNCHXL_GPTimers;

/*!
 *  @def    CC1310_LAUNCHXL_I2CName
 *  @brief  Enum of I2C names
 */
typedef enum CC1310_LAUNCHXL_I2CName {
    CC1310_LAUNCHXL_I2C0 = 0,

    CC1310_LAUNCHXL_I2CCOUNT
} CC1310_LAUNCHXL_I2CName;

/*!
 *  @def    CC1310_LAUNCHXL_PWM
 *  @brief  Enum of PWM outputs
 */
typedef enum CC1310_LAUNCHXL_PWMName {
    CC1310_LAUNCHXL_PWM0 = 0,
    CC1310_LAUNCHXL_PWM1,
    CC1310_LAUNCHXL_PWM2,
    CC1310_LAUNCHXL_PWM3,
    CC1310_LAUNCHXL_PWM4,
    CC1310_LAUNCHXL_PWM5,
    CC1310_LAUNCHXL_PWM6,
    CC1310_LAUNCHXL_PWM7,

    CC1310_LAUNCHXL_PWMCOUNT
} CC1310_LAUNCHXL_PWMName;

/*!
 *  @def    CC1310_LAUNCHXL_UARTName
 *  @brief  Enum of UARTs
 */
typedef enum CC1310_LAUNCHXL_UARTName {
    CC1310_LAUNCHXL_UART0 = 0,

    CC1310_LAUNCHXL_UARTCOUNT
} CC1310_LAUNCHXL_UARTName;

/*!
 *  @def    CC1310_LAUNCHXL_WatchdogName
 *  @brief  Enum of Watchdogs
 */
typedef enum CC1310_LAUNCHXL_WatchdogName {
    CC1310_LAUNCHXL_WATCHDOG0 = 0,

    CC1310_LAUNCHXL_WATCHDOGCOUNT
} CC1310_LAUNCHXL_WatchdogName;


#ifdef __cplusplus
}
#endif

#endif /* __CC1310_LAUNCHXL_BOARD_H__ */
