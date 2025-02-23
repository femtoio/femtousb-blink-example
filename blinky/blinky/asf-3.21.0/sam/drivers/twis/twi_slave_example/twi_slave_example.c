/**
 * \file
 *
 * \brief TWI SLAVE Example for SAM.
 *
 * Copyright (c) 2013-2014 Atmel Corporation. All rights reserved.
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
 * \mainpage TWI SLAVE Example
 *
 * \section intro Introduction
 *
 * The application demonstrates how to use use the SAM TWIS peripheral.
 *
 * \section Requirements
 *
 * This package can be used with SAM4L boards.
 *
 * In addition, another device will be needed to act as the TWI master. The
 * twim_example can be used for that, in which case a second kit
 * supported by that project is needed.
 * -# Connect TWD (SDA) for the 2 boards.
 * -# Connect TWCK (SCL) for the 2 boards.
 * -# Connect GND for the 2 boards.
 * -# Add a pull up resistor on TWD and TWCK
 *
 * \section files Main files:
 *  - twis.c SAM Two-Wire Slave Interface driver implementation.
 *  - twis.h SAM Two-Wire Slave Interface driver definitions.
 *  - twi_slave_example.c Example application.
 *
 * \section exampledescription Description of the Example
 * After launching the program, the device will act as a simple TWI-enabled
 * serial memory containing 50 bytes. This enables this project to be used
 * with the twim_example project as the master.
 *
 * To write in the memory, the TWI master must address the device first, then
 * send two bytes containing the memory address to access. Additional bytes are
 * treated as the data to write.
 *
 * Reading is done in the same fashion, except that after receiving the memory
 * address, the device will start outputting data until a STOP condition is
 * sent by the master.
 * The default address for the TWI slave is fixed to 0x50. If the board has a TWI
 * component with this address, you can change the define TARGET_ADDRESS in
 * conf_example.h of twim_example project, and the define SLAVE_ADDRESS
 * in twi_slave_example.c of twi_slave_exmaple project.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR EWARM.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 *
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "asf.h"
#include "conf_example.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define STRING_EOL    "\r"
#define STRING_HEADER "--TWI SLAVE Example --\r\n" \
		"-- "BOARD_NAME" --\r\n" \
		"-- Compiled: "__DATE__" "__TIME__" --"STRING_EOL

/**
 * \brief Information about TWIS Module
 * @{
 */
#define SLAVE_ADDRESS          0x50      /** Target's TWI address */
#define SLAVE_ADDR_LGT         2         /** Address length of virtual mem */
#define VIRTUALMEM_ADDR_START  0         /** Address of virtual mem */
/* @} */

/**
 * \brief Defines to manage a virtual TWI memory
 * @{
 */
#define TWI_MEM_SIZE    50    /** The size of the virtual mem */
#define TWI_MEM_IDLE    0     /** Idle state */
#define TWI_MEM_ADDR    1     /** Address state */
#define TWI_MEM_DATA    2     /** Data state */
/* @} */

/** State variable */
uint8_t status_cmd = TWI_MEM_IDLE;
/** Offset in the address value */
uint8_t addr_pos;
/** The current address in the virtual mem */
uint32_t addr;
/** Content of the Virtual mem*/
uint8_t memory[TWI_MEM_SIZE];

struct twis_dev_inst twis_device;

/**
 * \brief Manage the received data on TWI
 *
 * \remarks User defined operations after reception
 */
static void twis_slave_rx(uint8_t value)
{
	switch( status_cmd ) {
		case TWI_MEM_IDLE:
			/* Init before receiving the target address. */
			addr_pos = SLAVE_ADDR_LGT;
			addr = 0;
			/* No break to continue on next case */

		case TWI_MEM_ADDR:
			addr_pos--;
			/* Receiving the Nth Byte that makes the address (MSB first). */
			addr += ((uint32_t)value << (addr_pos * 8));
			if (0 == addr_pos) {
				/* the address is completely received => switch to data mode. */
				status_cmd = TWI_MEM_DATA;
			} else {
				status_cmd = TWI_MEM_ADDR;
			}
			break;

		case TWI_MEM_DATA:
			/* Check that we're still in the range of the virtual mem */
			if (TWI_MEM_SIZE > (addr - VIRTUALMEM_ADDR_START)) {
				memory[addr - VIRTUALMEM_ADDR_START] = value;
			} else {
				addr = VIRTUALMEM_ADDR_START;
			}
			/* Update to next position */
			addr++;
			break;
	}
}

/**
 * \brief Transmit a data on TWIS
 *
 * \remarks User defined operations during transmission
 */
static uint8_t twis_slave_tx(void)
{
	uint8_t value;
	/*
	 * This callback is called after a read request from the TWI master, for
	 * each byte to transmit.
	 */
	status_cmd = TWI_MEM_IDLE;
	/* Check that we're still in the range of the virtual mem */
	if (TWI_MEM_SIZE > (addr - VIRTUALMEM_ADDR_START)) {
		value = memory[addr - VIRTUALMEM_ADDR_START];
	} else {
		value = 0xFF;
	}
	/* Update to next position */
	addr++;
	return value;
}

/**
 * \brief Manage stop transfer reception on TWIS
 *
 * \remarks User defined operations on Stop condition
*/
static void twis_slave_stop(void)
{
	status_cmd = TWI_MEM_IDLE;
}

/**
 * \brief Manage Error on TWIS
 *
 * \remarks User defined operations on Error condition
*/
static void twis_slave_error(void)
{
	puts("I2C bus error\r\n");
}

/**
 * \brief Configure serial console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
#ifdef CONF_UART_CHAR_LENGTH
		.charlength = CONF_UART_CHAR_LENGTH,
#endif
		.paritytype = CONF_UART_PARITY,
#ifdef CONF_UART_STOP_BITS
		.stopbits = CONF_UART_STOP_BITS,
#endif
	};

	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/**
 * \brief Application entry point for TWI Slave example.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	twis_callback_t slave_callbacks;

	/* Initialize the SAM system */
	sysclk_init();

	/* Initialize the board */
	board_init();

	/* Initialize the console UART */
	configure_console();

	/* Output example information */
	puts(STRING_HEADER);

	/* Configure TWI as slave */
	struct twis_config config;
	twis_get_config_defaults(&config);
	config.chip = SLAVE_ADDRESS;
	if (twis_init(&twis_device, BOARD_BASE_TWI_SLAVE, &config) == STATUS_OK) {
		/* Set pointer to user specific application routines */
		slave_callbacks.rx = &twis_slave_rx;
		slave_callbacks.tx = &twis_slave_tx;
		slave_callbacks.stop = &twis_slave_stop;
		slave_callbacks.error = &twis_slave_error;
		twis_set_callback(&twis_device, TWIS_INTERRUPT_SLAVEADR_MATCH,
			slave_callbacks, 1);
		/* Enable the TWIS module */
		twis_enable(&twis_device);

	} else {
		puts("-E- Initialization failed!\r\n");
	}

	while (1) {
	}
}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
