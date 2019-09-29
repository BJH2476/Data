#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/cc13x0/driverlib/ioc.h>
#include <ti/devices/cc13x0/driverlib/udma.h>
#include <ti/devices/cc13x0/inc/hw_ints.h>
#include <ti/devices/cc13x0/inc/hw_memmap.h>

#include "CC1310_LAUNCHXL.h"

/*
 *  =============================== ADC ===============================
 */
#include <ti/drivers/ADC.h>
#include <ti/drivers/adc/ADCCC26XX.h>

ADCCC26XX_Object adcCC26xxObjects[CC1310_LAUNCHXL_ADCCOUNT];


const ADCCC26XX_HWAttrs adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADCCOUNT] = {
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO7,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO6,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO5,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO4,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO3,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO2,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO1,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO0,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_10P9_MS,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_DCOUPL,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_VSS,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_VDDS,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    }
};

const ADC_Config ADC_config[CC1310_LAUNCHXL_ADCCOUNT] = {
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC0], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC0]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC1], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC1]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC2], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC2]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC3], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC3]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC4], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC4]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC5], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC5]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC6], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC6]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADC7], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADC7]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADCDCOUPL], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADCDCOUPL]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADCVSS], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADCVSS]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1310_LAUNCHXL_ADCVDDS], &adcCC26xxHWAttrs[CC1310_LAUNCHXL_ADCVDDS]},
};

const uint_least8_t ADC_count = CC1310_LAUNCHXL_ADCCOUNT;

/*
 *  =============================== GPTimer ===============================
 *  Remove unused entries to reduce flash usage both in Board.c and Board.h
 */
#include <ti/drivers/timer/GPTimerCC26XX.h>

GPTimerCC26XX_Object gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMERCOUNT];

const GPTimerCC26XX_HWAttrs gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMERPARTSCOUNT] = {
    { .baseAddr = GPT0_BASE, .intNum = INT_GPT0A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT0, .pinMux = GPT_PIN_0A, },
    { .baseAddr = GPT0_BASE, .intNum = INT_GPT0B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT0, .pinMux = GPT_PIN_0B, },
    { .baseAddr = GPT1_BASE, .intNum = INT_GPT1A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT1, .pinMux = GPT_PIN_1A, },
    { .baseAddr = GPT1_BASE, .intNum = INT_GPT1B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT1, .pinMux = GPT_PIN_1B, },
    { .baseAddr = GPT2_BASE, .intNum = INT_GPT2A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT2, .pinMux = GPT_PIN_2A, },
    { .baseAddr = GPT2_BASE, .intNum = INT_GPT2B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT2, .pinMux = GPT_PIN_2B, },
    { .baseAddr = GPT3_BASE, .intNum = INT_GPT3A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT3, .pinMux = GPT_PIN_3A, },
    { .baseAddr = GPT3_BASE, .intNum = INT_GPT3B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT3, .pinMux = GPT_PIN_3B, },
};

const GPTimerCC26XX_Config GPTimerCC26XX_config[CC1310_LAUNCHXL_GPTIMERPARTSCOUNT] = {
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER0], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER0A], GPT_A },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER0], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER0B], GPT_B },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER1], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER1A], GPT_A },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER1], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER1B], GPT_B },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER2], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER2A], GPT_A },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER2], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER2B], GPT_B },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER3], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER3A], GPT_A },
    { &gptimerCC26XXObjects[CC1310_LAUNCHXL_GPTIMER3], &gptimerCC26xxHWAttrs[CC1310_LAUNCHXL_GPTIMER3B], GPT_B },
};

/*
 *  =============================== I2C ===============================
*/
#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CCC26XX.h>

I2CCC26XX_Object i2cCC26xxObjects[CC1310_LAUNCHXL_I2CCOUNT];

const I2CCC26XX_HWAttrsV1 i2cCC26xxHWAttrs[CC1310_LAUNCHXL_I2CCOUNT] = {
    {
        .baseAddr    = I2C0_BASE,
        .powerMngrId = PowerCC26XX_PERIPH_I2C0,
        .intNum      = INT_I2C_IRQ,
        .intPriority = ~0,
        .swiPriority = 0,
        .sdaPin      = CC1310_LAUNCHXL_I2C0_SDA0,
        .sclPin      = CC1310_LAUNCHXL_I2C0_SCL0,
    }
};

const I2C_Config I2C_config[CC1310_LAUNCHXL_I2CCOUNT] = {
    {
        .fxnTablePtr = &I2CCC26XX_fxnTable,
        .object      = &i2cCC26xxObjects[CC1310_LAUNCHXL_I2C0],
        .hwAttrs     = &i2cCC26xxHWAttrs[CC1310_LAUNCHXL_I2C0]
    }
};

const uint_least8_t I2C_count = CC1310_LAUNCHXL_I2CCOUNT;

/*
 *  =============================== PIN ===============================
 */
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

const PIN_Config BoardGpioInitTable[] = {

    CC1310_LAUNCHXL_UART_RX | PIN_INPUT_EN | PIN_PULLDOWN,                                                      /* UART RX via debugger back channel */
    CC1310_LAUNCHXL_UART_TX | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL,                                 /* UART TX via debugger back channel */
    SENSOR_LEFT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                                 // 좌측 센서 입력 핀 설정
    SENSOR_LIGHT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                                // 우측 센서 입력 핀 설정
    SENSOR_UNDER_LEFT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                           // 하단 좌측 센서 입력 핀 설정
    SENSOR_UNDER_RIGHT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                          // 하단 우측 센서 입력 핀 설정
    SENSOR_TOP_LEFT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                             // 상단 좌측 센서 입력 핀 설정
    SENSOR_TOP_RIGHT  | PIN_INPUT_EN | PIN_PULLUP | PIN_IRQ_NEGEDGE,                                            // 상단 우측 센서 입력 핀 설정
    RUN_LED_PORT | PIN_GPIO_OUTPUT_EN | PIN_GPIO_HIGH | PIN_PUSHPULL | PIN_DRVSTR_MAX,                          // RUN LED 출력 핀 설정

    PIN_TERMINATE
};

const PINCC26XX_HWAttrs PINCC26XX_hwAttrs = {
    .intPriority = ~0,
    .swiPriority = 0
};

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26XX.h>

const PowerCC26XX_Config PowerCC26XX_config = {
    .policyInitFxn      = NULL,
    .policyFxn          = &PowerCC26XX_standbyPolicy,
    .calibrateFxn       = &PowerCC26XX_calibrate,
    .enablePolicy       = true,
    .calibrateRCOSC_LF  = true,
    .calibrateRCOSC_HF  = true,
};

/*
 *  =============================== PWM ===============================
 *  Remove unused entries to reduce flash usage both in Board.c and Board.h
 */
#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerCC26XX.h>

PWMTimerCC26XX_Object pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWMCOUNT];

const PWMTimerCC26XX_HwAttrs pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWMCOUNT] = {
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN0, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER0A },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN1, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER0B },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN2, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER1A },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN3, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER1B },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN4, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER2A },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN5, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER2B },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN6, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER3A },
    { .pwmPin = CC1310_LAUNCHXL_PWMPIN7, .gpTimerUnit = CC1310_LAUNCHXL_GPTIMER3B },
};

const PWM_Config PWM_config[CC1310_LAUNCHXL_PWMCOUNT] = {
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM0], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM0] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM1], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM1] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM2], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM2] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM3], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM3] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM4], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM4] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM5], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM5] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM6], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM6] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1310_LAUNCHXL_PWM7], &pwmtimerCC26xxHWAttrs[CC1310_LAUNCHXL_PWM7] },
};

const uint_least8_t PWM_count = CC1310_LAUNCHXL_PWMCOUNT;

/*
 *  =============================== RF Driver ===============================
 */
#include <ti/drivers/rf/RF.h>

const RFCC26XX_HWAttrsV2 RFCC26XX_hwAttrs = {
    .hwiPriority        = ~0,       /* Lowest HWI priority */
    .swiPriority        = 0,        /* Lowest SWI priority */
    .xoscHfAlwaysNeeded = true,     /* Keep XOSC dependency while in standby */
    .globalCallback     = NULL,     /* No board specific callback */
    .globalEventMask    = 0         /* No events subscribed to */
};

/*
 *  =============================== UART ===============================
 */
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>

UARTCC26XX_Object uartCC26XXObjects[CC1310_LAUNCHXL_UARTCOUNT];

uint8_t uartCC26XXRingBuffer[CC1310_LAUNCHXL_UARTCOUNT][32];

const UARTCC26XX_HWAttrsV2 uartCC26XXHWAttrs[CC1310_LAUNCHXL_UARTCOUNT] = {
    {
        .baseAddr       = UART0_BASE,
        .powerMngrId    = PowerCC26XX_PERIPH_UART0,
        .intNum         = INT_UART0_COMB,
        .intPriority    = ~0,
        .swiPriority    = 0,
        .txPin          = CC1310_LAUNCHXL_UART_TX,
        .rxPin          = CC1310_LAUNCHXL_UART_RX,
        .ctsPin         = PIN_UNASSIGNED,
        .rtsPin         = PIN_UNASSIGNED,
        .ringBufPtr     = uartCC26XXRingBuffer[CC1310_LAUNCHXL_UART0],
        .ringBufSize    = sizeof(uartCC26XXRingBuffer[CC1310_LAUNCHXL_UART0]),
        .txIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_1_8,
        .rxIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_4_8,
        .errorFxn       = NULL
    }
};

const UART_Config UART_config[CC1310_LAUNCHXL_UARTCOUNT] = {
    {
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object      = &uartCC26XXObjects[CC1310_LAUNCHXL_UART0],
        .hwAttrs     = &uartCC26XXHWAttrs[CC1310_LAUNCHXL_UART0]
    },
};

const uint_least8_t UART_count = CC1310_LAUNCHXL_UARTCOUNT;

/*
 *  =============================== Watchdog ===============================
 */
#include <ti/drivers/Watchdog.h>
#include <ti/drivers/watchdog/WatchdogCC26XX.h>

WatchdogCC26XX_Object watchdogCC26XXObjects[CC1310_LAUNCHXL_WATCHDOGCOUNT];

const WatchdogCC26XX_HWAttrs watchdogCC26XXHWAttrs[CC1310_LAUNCHXL_WATCHDOGCOUNT] = {
    {
        .baseAddr    = WDT_BASE,
        .reloadValue = 1000 /* Reload value in milliseconds */
    },
};

const Watchdog_Config Watchdog_config[CC1310_LAUNCHXL_WATCHDOGCOUNT] = {
    {
        .fxnTablePtr = &WatchdogCC26XX_fxnTable,
        .object      = &watchdogCC26XXObjects[CC1310_LAUNCHXL_WATCHDOG0],
        .hwAttrs     = &watchdogCC26XXHWAttrs[CC1310_LAUNCHXL_WATCHDOG0]
    },
};

const uint_least8_t Watchdog_count = CC1310_LAUNCHXL_WATCHDOGCOUNT;

/*
 *  ======== CC1310_LAUNCHXL_initGeneral ========
 */
void CC1310_LAUNCHXL_initGeneral(void)
{
    Power_init();

    if (PIN_init(BoardGpioInitTable) != PIN_SUCCESS) {
        /* Error with PIN_init */
        while (1);
    }
}

/*
 *  ======== Board_init ========
 */
void Board_init(void)
{
    CC1310_LAUNCHXL_initGeneral();
}
