/**
 * \file
 *
 * \brief Unit tests for PDCA driver.
 *
 * Copyright (c) 2012 - 2014 Atmel Corporation. All rights reserved.
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

#include <board.h>
#include <sysclk.h>
#include "pdca.h"
#include "usart.h"
#include <string.h>
#include <unit_test/suite.h>
#include <stdio_serial.h>
#include <conf_test.h>
#include <conf_board.h>

/**
 * \mainpage
 *
 * \section intro Introduction
 * This is the unit test application for the PDCA driver.
 * It consists of test cases for the following functionality:
 * - Transfer data by loopback mode
 *
 *
 * \section files Main Files
 * - \ref unit_tests.c
 * - \ref conf_test.h
 * - \ref conf_board.h
 * - \ref conf_clock.h
 * - \ref conf_usart_serial.h
 *
 * \section device_info Device Info
 * The SAM4L devices can be used.
 * This example has been tested with the following setup:
 * - sam4lc4c_sam4l_ek
 * - sam4lc4c_sam4l_xplained_pro
 * - sam4lc8c_sam4l8_xplained_pro
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for ARM. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */

//! \name Unit test configuration
//@{
/**
 * \def CONF_TEST_PDCA
 * \brief Test the functions provided by the PDCA driver.
 */
//@}

/** Size of the receive buffer used by the PDC, in bytes. */
#define BUFFER_SIZE         100

#define PDCA_RX_CHANNEL  0
#define PDCA_TX_CHANNEL  1

/** PDCA channel peripheral setting. */
#define PDCA_PID_USART0_RX    0
#define PDCA_PID_USART0_TX    18

/** All interrupt mask. */
#define ALL_INTERRUPT_MASK  0xffffffff

/** Receive buffer. */
static uint8_t gs_rev_buffer[BUFFER_SIZE];

/** Transmit buffer. */
static uint8_t gs_tran_buffer[BUFFER_SIZE];

volatile uint8_t rxbuff_flag = 0;

/** PDC channel options. */
pdca_channel_config_t pdca_rx_options = {
	.addr = (void *)gs_rev_buffer,     /* memory address */
	.pid = PDCA_PID_USART0_RX,         /* select peripheral - USART0 RX line.*/
	.size = BUFFER_SIZE,               /* transfer counter */
	.r_addr = (void *)gs_rev_buffer,   /* next memory address */
	.r_size = BUFFER_SIZE,             /* next transfer counter */
	.transfer_size = PDCA_MR_SIZE_BYTE,/* select size of the transfer */
	.etrig  = false,                   /* disable the transfer upon event
										* trigger */
};

pdca_channel_config_t pdca_tx_options = {
	.addr = (void *)gs_tran_buffer,    /* memory address */
	.pid = PDCA_PID_USART0_TX,         /* select peripheral - USART0 TX line.*/
	.size = BUFFER_SIZE,               /* transfer counter */
	.r_addr = (void *)gs_tran_buffer,  /* next memory address */
	.r_size = BUFFER_SIZE,             /* next transfer counter */
	.transfer_size = PDCA_MR_SIZE_BYTE,/* select size of the transfer */
	.etrig  = false,                   /* disable the transfer upon event
										* trigger */
};

/**
 * \brief Interrupt handler for USART.
 */
void USART_Handler(void)
{
	uint32_t ul_status;

	/* Read USART Status. */
	ul_status = usart_get_status(BOARD_USART);

	/* Receive buffer is full. */
	if (ul_status & US_CSR_RXBUFF) {
		rxbuff_flag = 1;
		usart_disable_interrupt(BOARD_USART, US_IER_RXBUFF);
	}
}

/**
 * \brief Configure USART in normal (serial rs232) mode, asynchronous,
 * 8 bits, 1 stop bit, no parity, 115200 bauds and enable its transmitter
 * and receiver.
 */
static void configure_usart(void)
{
	const sam_usart_opt_t usart_console_settings = {
		BOARD_USART_BAUDRATE,
		US_MR_CHRL_8_BIT,
		US_MR_PAR_NO,
		US_MR_NBSTOP_1_BIT,
		US_MR_CHMODE_NORMAL,
		/* This field is only used in IrDA mode. */
		0
	};

	/* Enable the peripheral clock in the PMC. */
	sysclk_enable_peripheral_clock(BOARD_USART);

	/* Configure USART in serial mode. */
	usart_init_rs232(BOARD_USART, &usart_console_settings,
			sysclk_get_peripheral_bus_hz(BOARD_USART));

	/* Configure USART in loopback mode. */
	BOARD_USART->US_MR |= US_MR_CHMODE_LOCAL_LOOP;

	/* Disable all the interrupts. */
	usart_disable_interrupt(BOARD_USART, ALL_INTERRUPT_MASK);

	/* Enable the receiver and transmitter. */
	usart_enable_tx(BOARD_USART);
	usart_enable_rx(BOARD_USART);

	/* Configure and enable interrupt of USART. */
	NVIC_EnableIRQ(USART_IRQn);
}

/**
 * \brief Test PDCA transfer in loopback mode.
 *
 * \param test Current test case.
 */
static void run_pdca_loopback_test(const struct test_case *test)
{
	uint32_t i;

	for (i = 0; i < BUFFER_SIZE; i++) {
		gs_tran_buffer[i] = i;
	}

	/* Configure USART. */
	configure_usart();

	/* Enable PDCA module clock */
	pdca_enable(PDCA);
	/* Init PDCA channel with the pdca_options.*/
	pdca_channel_set_config(PDCA_RX_CHANNEL, &pdca_rx_options);
	pdca_channel_set_config(PDCA_TX_CHANNEL, &pdca_tx_options);
	/* Enable PDCA channel, start receiving data. */
	pdca_channel_enable(PDCA_RX_CHANNEL);
	pdca_channel_enable(PDCA_TX_CHANNEL);

	/* Enable USART RXBUFF interrupt */
	usart_enable_interrupt(BOARD_USART, US_IER_RXBUFF);

	while(!rxbuff_flag);

	for (i = 0; i < BUFFER_SIZE; i++) {
		test_assert_true(test,
				gs_rev_buffer[i] == gs_tran_buffer[i],
				"PDCA loopback test failed");
	}

}

/**
 * \brief Run PDCA driver unit tests.
 */
int main(void)
{
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_TEST_BAUDRATE,
		.charlength = CONF_TEST_CHARLENGTH,
		.paritytype = CONF_TEST_PARITY,
		.stopbits   = CONF_TEST_STOPBITS
	};

	/* Initialize the system clock and board */
	sysclk_init();
	board_init();

	/* Enable the debug uart */
	stdio_serial_init(CONF_TEST_USART, &usart_serial_options);

#if defined(__GNUC__)
	setbuf(stdout, NULL);
#endif

	/* Define all the test cases */
	DEFINE_TEST_CASE(pdca_test, NULL, run_pdca_loopback_test, NULL,
			"PDCA loopback transfer test");

	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(pdca_tests) = {
		&pdca_test
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(pdca_suite, pdca_tests,
			"SAM PDCA driver test suite");

	/* Run all tests in the test suite */
	test_suite_run(&pdca_suite);

	while (1) {
		/* Busy-wait forever. */
	}
}
