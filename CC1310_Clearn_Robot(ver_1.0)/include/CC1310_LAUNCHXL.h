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

// DIO 입출력 포트 정의
#define RUN_LED_PORT                          IOID_10               // RUN LED 포트
#define SENSOR_LEFT                           IOID_21               // 좌측 센서 입력 포트
#define SENSOR_LIGHT                          IOID_22               // 우측 센서 입력 포트
#define SENSOR_UNDER_LEFT                     IOID_23               // 하단 좌측 센서 입력 포트
#define SENSOR_UNDER_RIGHT                    IOID_24               // 하단 우측 센서 입력 포트
#define SENSOR_TOP_LEFT                       IOID_25               // 상단 좌측 센서 입력 포트
#define SENSOR_TOP_RIGHT                      IOID_26               // 상단 우측 센서 입력 포트

// I2C (SCL & SDA) 포트 정의
#define CC1310_LAUNCHXL_I2C0_SCL0             PIN_UNASSIGNED        // I2C 클럭 입력 포트
#define CC1310_LAUNCHXL_I2C0_SDA0             PIN_UNASSIGNED        // I2C 데이터 입력 포트

// PWM 출력 포트 정의
#define CC1310_LAUNCHXL_PWMPIN0               PIN_UNASSIGNED        // Timer 채널 사용중이므로 사용 금지.
#define CC1310_LAUNCHXL_PWMPIN1               PIN_UNASSIGNED        // PWM 1채널 포트
#define CC1310_LAUNCHXL_PWMPIN2               PIN_UNASSIGNED        // PWM 2채널 포트
#define CC1310_LAUNCHXL_PWMPIN3               PIN_UNASSIGNED        // PWM 3채널 포트
#define CC1310_LAUNCHXL_PWMPIN4               IOID_9                // PWM 4채널 포트 (DC 모터 사용중)
#define CC1310_LAUNCHXL_PWMPIN5               IOID_7                // PWM 5채널 포트 (DC 모터 사용중)
#define CC1310_LAUNCHXL_PWMPIN6               IOID_11               // PWM 6채널 포트 (DC 모터 사용중)
#define CC1310_LAUNCHXL_PWMPIN7               IOID_6                // PWM 7채널 포트 (DC 모터 사용중)

// UART (Tx & Rx) 입출력 포트 정의
#define CC1310_LAUNCHXL_UART_RX               IOID_3                // UART Rx 포트 정의
#define CC1310_LAUNCHXL_UART_TX               IOID_1                // UART Tx 포트 정의
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
