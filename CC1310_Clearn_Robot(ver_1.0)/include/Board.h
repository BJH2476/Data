/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : Board.h
 * 내용 : 전체적인 헤더 파일 및 주변장치 채널명 정의
 */

#ifndef __BOARD_H
#define __BOARD_H

#define Board_CC1310_LAUNCHXL

#ifdef __cplusplus
extern "C" {
#endif

// Standard C Header File
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// NoRTOS Command Header
#include <NoRTOS.h>

// Ti CC1310 Peripheral Driver
#include <ti/drivers/Board.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/drivers/Power.h>
#include <ti/drivers/rf/RF.h>
#include <ti/drivers/PWM.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/timer/GPTimerCC26XX.h>
#include <ti/devices/DeviceFamily.h>
#include <ti/devices/cc13x0/driverlib/vims.h>
#include <ti/devices/cc13x0/driverlib/flash.h>
#include <ti/devices/cc13x0/driverlib/aon_batmon.h>

// Basic Radio Frequency information Setting
#include "smartrf_settings/smartrf_settings.h"

// Driverlib APIs
#include DeviceFamily_constructPath(driverlib/sys_ctrl.h)

// EasyLink API Header files
#include "easylink/EasyLink.h"
#include "CC1310_LAUNCHXL.h"

// User Make Header files
#include "timer.h"
#include "flash.h"
#include "pwm.h"
#include "easyRF.h"
#include "uart.h"
#include "i2c.h"
#include "temperature.h"
#include "motor.h"
#include "sensor.h"
#include "crc.h"


#define Board_initGeneral()     Board_init()                        // CC1310 파워 및 초기화 정의

#define Board_ADC0              CC1310_LAUNCHXL_ADC0                // ADC 채널 0
#define Board_ADC1              CC1310_LAUNCHXL_ADC1                // ADC 채널 1

#define Board_GPTIMER0A         CC1310_LAUNCHXL_GPTIMER0A           // Timer 채널 0A (Timer 사용중)
#define Board_GPTIMER0B         CC1310_LAUNCHXL_GPTIMER0B           // Timer 채널 0B
#define Board_GPTIMER1A         CC1310_LAUNCHXL_GPTIMER1A           // Timer 채널 1A
#define Board_GPTIMER1B         CC1310_LAUNCHXL_GPTIMER1B           // Timer 채널 1B
#define Board_GPTIMER2A         CC1310_LAUNCHXL_GPTIMER2A           // Timer 채널 2A (DC Motor 사용중)
#define Board_GPTIMER2B         CC1310_LAUNCHXL_GPTIMER2B           // Timer 채널 2B (DC Motor 사용중)
#define Board_GPTIMER3A         CC1310_LAUNCHXL_GPTIMER3A           // Timer 채널 3A (DC Motor 사용중)
#define Board_GPTIMER3B         CC1310_LAUNCHXL_GPTIMER3B           // Timer 채널 3B (DC Motor 사용중)

#define Board_I2C0              CC1310_LAUNCHXL_I2C0                // I2C 채널 0 (LM75 온도센서 사용중)

#define Board_PWM0              CC1310_LAUNCHXL_PWM0                // PWM 채널 0
#define Board_PWM1              CC1310_LAUNCHXL_PWM1                // PWM 채널 1
#define Board_PWM2              CC1310_LAUNCHXL_PWM2                // PWM 채널 2
#define Board_PWM3              CC1310_LAUNCHXL_PWM3                // PWM 채널 3
#define Board_PWM4              CC1310_LAUNCHXL_PWM4                // PWM 채널 4 (DC Motor 사용중)
#define Board_PWM5              CC1310_LAUNCHXL_PWM5                // PWM 채널 5 (DC Motor 사용중)
#define Board_PWM6              CC1310_LAUNCHXL_PWM6                // PWM 채널 6 (DC Motor 사용중)
#define Board_PWM7              CC1310_LAUNCHXL_PWM7                // PWM 채널 7 (DC Motor 사용중)

#define Board_UART0             CC1310_LAUNCHXL_UART0               // UART 채널 0 (Debug 포트 사용중)

#define Board_WATCHDOG0         CC1310_LAUNCHXL_WATCHDOG0           // WatchDog 채널 0

PIN_Handle  pinHandle;
PIN_Id      pinId;

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
