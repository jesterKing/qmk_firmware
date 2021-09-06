/*
Copyright 2019 Thomas Baart <thomas@splitkb.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFAB0
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    jesterKing
#define PRODUCT         jesterTeensy41

/* key matrix size */
/* Rows are doubled up */
// note actual kyria 8x8
#define MATRIX_ROWS  4
#define MATRIX_COLS  2

// wiring
/*#define MATRIX_ROW_PINS \
    { B4, E6, D7, D4 }
#define MATRIX_COL_PINS \
    { B6, B2, B3, B1, F7, F6, F5, F4 }
    */
#define MATRIX_ROW_PINS \
    { LINE_PIN2, LINE_PIN3 }
#define MATRIX_COL_PINS \
    { LINE_PIN4, LINE_PIN5 }
#define UNUSED_PINS

#define ENCODERS_PAD_A \
    { LINE_PIN9 }
#define ENCODERS_PAD_B \
    { LINE_PIN10 }
#define ENCODERS_PAD_A_RIGHT \
    { LINE_PIN10 }
#define ENCODERS_PAD_B_RIGHT \
    { LINE_PIN9 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE        5

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
// RX2
#define SOFT_SERIAL_PIN LINE_PIN8


// TX2
#define RGB_DI_PIN      LINE_PIN8
#define RGBLED_SPLIT \
    { 10, 10 }
#define RGBLED_NUM 20

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define SPLIT_OLED_ENABLE
#endif

/* RGB matrix support */
#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define DRIVER_LED_TOTAL RGBLED_NUM // Number of LEDs
#    define RGB_MATRIX_SPLIT { 10, 10 }
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 170
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

#define NOP_FUDGE   0.4

#define SERIAL_USART_CONFIG { (SERIAL_USART_SPEED), } // Only field is speed
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
//#define SERIAL_USART_TX_PIN LINE_PIN1     // USART TX pin / uses SOFT_SERIAL_PIN
#define SERIAL_USART_RX_PIN LINE_PIN0     // USART RX pin
//#define USART1_REMAP             // Remap USART TX and RX pins on STM32F103 MCUs, see table below.
//#define SERIAL_USART_PIN_SWAP    // Swap TX and RX pins if keyboard is master halve.
                                   // Check if this feature is necessary with your keyboard design and available on the mcu.
#define SELECT_SOFT_SERIAL_SPEED 0 // or 0, 2, 3, 4, 5
                                   //  0: 460800 baud
                                   //  1: 230400 baud (default)
                                   //  2: 115200 baud
                                   //  3: 57600 baud
                                   //  4: 38400 baud
                                   //  5: 19200 baud
#define SERIAL_USART_DRIVER SD2    // USART driver of TX and RX pin. default: SD1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 20    // USART driver timeout. default 20
