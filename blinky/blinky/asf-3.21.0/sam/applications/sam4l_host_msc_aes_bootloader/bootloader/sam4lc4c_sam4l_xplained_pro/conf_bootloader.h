/**
 * \file
 *
 * \brief Bootloader configuration.
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

//! Configuration of the bootloader

#ifndef CONF_BOOTLOADER_H_
#define CONF_BOOTLOADER_H_

//! Enable/disable the AES Decryption
#define FIRMWARE_AES_ENABLED         ENABLE
//! Enable/disable the Console message output
#define CONSOLE_OUTPUT_ENABLED       ENABLE
//! Enable/disable the verification of memory after programming
#define VERIFY_PROGRAMMING_ENABLED   ENABLE
//! Enable/disable the Security bit after firmware upgrade
#define SECURITY_BIT_ENABLED         DISABLE

/** 
 * GP Fuse bit to force bootloader mode after reset. Bits 31-16 are usable
 * (15-0 used for flash region locking)
 */
#define BOOT_GP_FUSE_BIT             16
//!* Firmware file input name
#define FIRMWARE_IN_FILE_NAME        "0:firmware.bin"
//! GPIO pin used to activate the bootloader mode
#define BOOT_LOAD_PIN                GPIO_PUSH_BUTTON_0
//! Active state of GPIO pin used to activate the bootloader mode
#define BOOT_LOAD_PIN_ACTIVE_LVL     SW0_ACTIVE
//! UI displaying the bootloader status
#define BOOT_LED                     LED0_PIN
//! ON level for the BOOT_LED
#define BOOT_LED_ON_LVL              0
//! ON level for the BOOT_LED
#define BOOT_LED_OFF_LVL             1

//! Application starting offset - Verify with bootloader footprint*/
#define APP_START_OFFSET             0x8000
//! Application starting address in Flash
#define APP_START_ADDRESS            (FLASH_ADDR + APP_START_OFFSET)
//! Maximum possible size of the Application
#define APP_MAX_SIZE                 (FLASH_ADDR + FLASH_SIZE  \
										- APP_START_ADDRESS)
//! Buffer size to be used for programming
#define FLASH_BUFFER_SIZE            (FLASH_PAGE_SIZE)

//! Offset for the firmware in the input application binary - 16 bytes
#define APP_BINARY_OFFSET            (APP_CRC_SIZE + APP_SIGNATURE_SIZE)
//! CRCCU Polynomial Selection
#define APP_CRC_POLYNOMIAL_TYPE      CRCCU_MR_PTYPE_CCITT8023 //32-bit CRC
//! Application Signature
#define APP_SIGNATURE                "ATMEL SAM4L "
//! Size of signature in bytes
#define APP_SIGNATURE_SIZE           12
//! Size of CRC32 in bytes
#define APP_CRC_SIZE                 4


//! AES Configuration
#if FIRMWARE_AES_ENABLED

//! AES Key Size
#define  FIRMWARE_AES_KEY_SIZE       128

//! Initialization vector AES
#define  FIRMWARE_AES_INITVECT_WORD0 0x03020100
#define  FIRMWARE_AES_INITVECT_WORD1 0x07060504
#define  FIRMWARE_AES_INITVECT_WORD2 0x0b0a0908
#define  FIRMWARE_AES_INITVECT_WORD3 0x0f0e0d0c

//! AES Encryption Key 128
#define  FIRMWARE_AES_KEY_WORD0      0x603deb10
#define  FIRMWARE_AES_KEY_WORD1      0x15ca71be
#define  FIRMWARE_AES_KEY_WORD2      0x2b73aef0
#define  FIRMWARE_AES_KEY_WORD3      0x857d7781
//! AES Encryption Key Size 192
#  define  FIRMWARE_AES_KEY_WORD4    0x1f352c07
#  define  FIRMWARE_AES_KEY_WORD5    0x3b6108d7
//! AES Encryption Key Size 256
#  define  FIRMWARE_AES_KEY_WORD6    0x2d9810a3
#  define  FIRMWARE_AES_KEY_WORD7    0x0914dff4

#endif

//! Console configurations
#if CONSOLE_OUTPUT_ENABLED
//! Console USART Parameters
#define CONSOLE_UART                 COM_PORT_USART
#define CONSOLE_UART_ID              COM_PORT_USART_ID
#define CONSOLE_UART_BAUDRATE        115200
#define CONSOLE_UART_PARITY          US_MR_PAR_NO
#define CONSOLE_UART_STOPBITS        US_MR_NBSTOP_1_BIT
#define CONSOLE_UART_CHAR_LENGTH     US_MR_CHRL_8_BIT
//! Console debug output
#define CONSOLE_PUTS(str)            usart_write_line(CONSOLE_UART, str)
#define CONSOLE_PUTC(c)              usart_putchar(CONSOLE_UART, c)
//! Console Strings
#define APP_HEADER                   \
					"\n\rATMEL SAM4L Firmware Generator for USB MSC BOOTLOADER"
#define TASK_PASSED                  "\n\rPASS"
#define TASK_FAILED                  "\n\rFAIL"
#endif

#endif /* CONF_BOOTLOADER_H_ */
