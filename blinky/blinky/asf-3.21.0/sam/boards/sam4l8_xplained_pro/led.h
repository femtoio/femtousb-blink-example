/**
 * \file
 *
 * \brief SAM4L8 Xplained Pro board LEDs support package.
 *
 * This file contains definitions and services related to the LED features of
 * the SAM4L8 Xplained Pro board.
 *
 * To use this board, define BOARD=SAM4L8_XPLAINED_PRO.
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "compiler.h"
#include "ioport.h"

/**
 * \brief Turns off the specified LEDs.
 *
 * \param led LED to turn off (LEDx).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Off(led)     ioport_set_pin_level(led, IOPORT_PIN_LEVEL_HIGH)

/**
 * \brief Turns on the specified LEDs.
 *
 * \param led LED to turn on (LEDx).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_On(led)      ioport_set_pin_level(led, IOPORT_PIN_LEVEL_LOW)

/**
 * \brief Toggles the specified LEDs.
 *
 * \param led LED to toggle (LEDx).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Toggle(led)  ioport_toggle_pin_level(led)


#endif  /* LED_H_INCLUDED */
