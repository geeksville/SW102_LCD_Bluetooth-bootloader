
#ifndef CUSTOM_H
#define CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif

#define LEDS_NUMBER    0
#define BUTTONS_NUMBER 0

#define SYSTEM_POWER_HOLD__PIN    9

#define LCD_RES__PIN              5
#define LCD_COMMAND_DATA__PIN     30
#define LCD_CHIP_SELECT__PIN      4
#define LCD_CLOCK__PIN            6
#define LCD_DATA__PIN             7

#define BUTTON_UP__PIN            2
#define BUTTON_PWR__PIN           10
#define BUTTON_DOWN__PIN          19
#define BUTTON_M__PIN             14

#define UART_TX__PIN              12
#define UART_RX__PIN              11

#define TEST__PIN                 28

#define BOOTLOADER_BUTTON         BUTTON_M__PIN /**< Button for entering DFU mode. */

// Low frequency clock source to be used by the SoftDevice
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_RC,  \
                                 .rc_ctiv       = 16, /* Check temperature every 4 seconds */ \
                                 .rc_temp_ctiv  = 2,  /* Calibrate at least every 8 seconds even if the temperature hasn't changed */ \
                                 .xtal_accuracy = 0   /* For the NRF_CLOCK_LF_SRC_RC clock source this parameter is ignored. */}

#ifdef __cplusplus
}
#endif

#endif
