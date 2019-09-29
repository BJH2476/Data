/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : Board.h
 * ���� : ��ü���� ��� ���� �� �ֺ���ġ ä�θ� ����
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


#define Board_initGeneral()     Board_init()                        // CC1310 �Ŀ� �� �ʱ�ȭ ����

#define Board_ADC0              CC1310_LAUNCHXL_ADC0                // ADC ä�� 0
#define Board_ADC1              CC1310_LAUNCHXL_ADC1                // ADC ä�� 1

#define Board_GPTIMER0A         CC1310_LAUNCHXL_GPTIMER0A           // Timer ä�� 0A (Timer �����)
#define Board_GPTIMER0B         CC1310_LAUNCHXL_GPTIMER0B           // Timer ä�� 0B
#define Board_GPTIMER1A         CC1310_LAUNCHXL_GPTIMER1A           // Timer ä�� 1A
#define Board_GPTIMER1B         CC1310_LAUNCHXL_GPTIMER1B           // Timer ä�� 1B
#define Board_GPTIMER2A         CC1310_LAUNCHXL_GPTIMER2A           // Timer ä�� 2A (DC Motor �����)
#define Board_GPTIMER2B         CC1310_LAUNCHXL_GPTIMER2B           // Timer ä�� 2B (DC Motor �����)
#define Board_GPTIMER3A         CC1310_LAUNCHXL_GPTIMER3A           // Timer ä�� 3A (DC Motor �����)
#define Board_GPTIMER3B         CC1310_LAUNCHXL_GPTIMER3B           // Timer ä�� 3B (DC Motor �����)

#define Board_I2C0              CC1310_LAUNCHXL_I2C0                // I2C ä�� 0 (LM75 �µ����� �����)

#define Board_PWM0              CC1310_LAUNCHXL_PWM0                // PWM ä�� 0
#define Board_PWM1              CC1310_LAUNCHXL_PWM1                // PWM ä�� 1
#define Board_PWM2              CC1310_LAUNCHXL_PWM2                // PWM ä�� 2
#define Board_PWM3              CC1310_LAUNCHXL_PWM3                // PWM ä�� 3
#define Board_PWM4              CC1310_LAUNCHXL_PWM4                // PWM ä�� 4 (DC Motor �����)
#define Board_PWM5              CC1310_LAUNCHXL_PWM5                // PWM ä�� 5 (DC Motor �����)
#define Board_PWM6              CC1310_LAUNCHXL_PWM6                // PWM ä�� 6 (DC Motor �����)
#define Board_PWM7              CC1310_LAUNCHXL_PWM7                // PWM ä�� 7 (DC Motor �����)

#define Board_UART0             CC1310_LAUNCHXL_UART0               // UART ä�� 0 (Debug ��Ʈ �����)

#define Board_WATCHDOG0         CC1310_LAUNCHXL_WATCHDOG0           // WatchDog ä�� 0

PIN_Handle  pinHandle;
PIN_Id      pinId;

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
