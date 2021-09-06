/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

#if defined(KEYBOARD_splitkb_kyria_revt41)

#define MIMXRT1062_MCUCONF
#define MIMXRT1062_SERIAL_USE_UART1             TRUE
#define STM32_SERIAL_USE_USART1                 TRUE

#define KINETIS_PLLCLK_FREQUENCY                660000000UL  // 600 MHz (RUN)
#define KINETIS_SYSCLK_FREQUENCY                KINETIS_PLLCLK_FREQUENCY
#define STM32_SYSCLK                            KINETIS_SYSCLK_FREQUENCY

#define GPIO_INPUT_PIN_DELAY     0

#endif
