/**
 * \file
 *
 * \brief Unit tests for AFEC driver.
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
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <board.h>
#include <sysclk.h>
#include <delay.h>
#include "afec.h"
#include "pmc.h"
#include "tc.h"
#include "ioport.h"
#include <string.h>
#include <unit_test/suite.h>
#include <stdio_serial.h>
#include <conf_test.h>
#include <conf_board.h>

/**
 * \mainpage
 *
 * \section intro Introduction
 * This is the unit test application for the AFEC driver.
 * It consists of test cases for the following functionality:
 * - TC trigger test
 * - Comparison window test
 *
 * \section files Main Files
 * - \ref unit_tests.c
 * - \ref conf_test.h
 * - \ref conf_board.h
 * - \ref conf_clock.h
 * - \ref conf_uart_serial.h
 * - \ref conf_sleepmgr.h
 *
 * \section device_info Device Info
 * The SAM4E devices can be used.
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for ARM. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */

/** Conversion data is ready flag */
volatile bool is_data_ready = false;

/** Enter comparison window flag */
volatile bool is_comp_event_flag = false;

/**
 * \brief Callback function for AFEC conversion data is ready interrupt.
 */
static void afec_set_data_ready_flag(void)
{
	is_data_ready = true;
	afec_disable_interrupt(AFEC0, AFEC_INTERRUPT_DATA_READY);
	tc_stop(TC0, 0);
}

/**
 * \brief Callback function for AFEC enter compasion window interrupt.
 */
static void afec_set_comp_flag(void)
{
	is_comp_event_flag = true;
	afec_disable_interrupt(AFEC0, AFEC_INTERRUPT_COMP_ERROR);

}

/**
 * \brief Configure to trigger AFEC by TIOA output of timer.
 */
static void configure_tc_trigger(void)
{
	uint32_t ul_div = 0;
	uint32_t ul_tc_clks = 0;
	uint32_t ul_sysclk = sysclk_get_cpu_hz();

	/* Enable peripheral clock. */
	pmc_enable_periph_clk(ID_TC0);

	/* TIOA configuration */
	ioport_set_pin_mode(PIN_TC0_TIOA0, PIN_TC0_TIOA0_FLAGS);
	ioport_disable_pin(PIN_TC0_TIOA0);

	/* Configure TC for a 10Hz frequency and trigger on RC compare. */
	tc_find_mck_divisor(10, ul_sysclk, &ul_div, &ul_tc_clks, ul_sysclk);
	tc_init(TC0, 0, ul_tc_clks | TC_CMR_CPCTRG | TC_CMR_WAVE |
			TC_CMR_ACPA_CLEAR | TC_CMR_ACPC_SET);
	TC0->TC_CHANNEL[0].TC_RA = (ul_sysclk / ul_div) / 2;
	TC0->TC_CHANNEL[0].TC_RC = (ul_sysclk / ul_div) / 1;

	/* Start the Timer. */
	tc_start(TC0, 0);

	afec_set_trigger(AFEC0, AFEC_TRIG_TIO_CH_0);
}

/**
 * \brief Test AFEC in TC trigger mode,
 *        which also tests interrupt driven conversions.
 *
 * \param test Current test case.
 */
static void run_afec_tc_trig_test(const struct test_case *test)
{
	configure_tc_trigger();

	afec_set_callback(AFEC0, AFEC_INTERRUPT_DATA_READY,
			afec_set_data_ready_flag, 1);
	delay_ms(2000);

	test_assert_true(test, is_data_ready == true,
			"AFEC using TC trigger test failed");
}

/**
 * \brief Test AFEC in comparsion window mode.
 *
 * \param test Current test case.
 */
static void run_afec_comp_test(const struct test_case *test)
{
	afec_set_trigger(AFEC0, AFEC_TRIG_SW);
	afec_set_comparison_mode(AFEC0, AFEC_CMP_MODE_2, AFEC_CHANNEL_1, 0);
	afec_set_comparison_window(AFEC0, 0, 0xFFF);
	afec_set_callback(AFEC0, AFEC_INTERRUPT_COMP_ERROR,
			afec_set_comp_flag, 1);
	afec_start_software_conversion(AFEC0);
	delay_ms(100);

	test_assert_true(test, is_comp_event_flag == true,
			"AFEC Comparsion Window test failed");
}

/**
 * \brief Run AFEC driver unit tests.
 */
int main(void)
{
	const usart_serial_options_t usart_serial_options = {
		.baudrate   = CONF_TEST_BAUDRATE,
		.paritytype = CONF_TEST_PARITY
	};

	/* Initialize the system clock and board */
	sysclk_init();
	board_init();

	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_TEST_USART, &usart_serial_options);

	afec_enable(AFEC0);

	struct afec_config afec_cfg;

	afec_get_config_defaults(&afec_cfg);
	afec_init(AFEC0, &afec_cfg);

	/*
	 * Because the internal ADC offset is 0x800, it should cancel it and shift
	 * down to 0.
	 */
	afec_channel_set_analog_offset(AFEC0, AFEC_CHANNEL_1, 0x800);

	afec_channel_enable(AFEC0, AFEC_CHANNEL_1);

#if defined(__GNUC__)
	setbuf(stdout, NULL);
#endif

	/* Define all the test cases */
	DEFINE_TEST_CASE(afec_tc_trig_test, NULL, run_afec_tc_trig_test, NULL,
			"AFEC TC Trig test");
	DEFINE_TEST_CASE(afec_comp_test, NULL, run_afec_comp_test,
			NULL, "AFEC Comparison Window test");

	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(afec_tests) = {
		&afec_tc_trig_test,
		&afec_comp_test,
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(afec_suite, afec_tests,
			"SAM AFEC driver test suite");

	/* Run all tests in the test suite */
	test_suite_run(&afec_suite);

	while (1) {
		/* Busy-wait forever. */
	}
}
