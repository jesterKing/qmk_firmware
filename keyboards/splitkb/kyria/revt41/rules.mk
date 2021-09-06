OLED_ENABLE = no
OLED_DRIVER = SSD1306        # Enables the use of OLED displays
ENCODER_ENABLE = no          # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no         # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no       # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
RGB_MATRIX_DRIVER = WS2812   # RGB matrix driver support

RGB_MATRIX_SUPPORTED = no

# MCU name
MCU_FAMILY = MIMXRT1062
MCU_SERIES = MIMXRT1062
MCU_LDSCRIPT = MIMXRT1062
MCU_STARTUP = MIMXRT1062
BOARD = IC_TEENSY_4_1
MCU  = cortex-m4
ARMV = 7

SERIAL_DRIVER = usart

# Bootloader selection
BOOTLOADER = halfkay
