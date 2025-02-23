/**
 * \file
 *
 * \brief Example to illustrate the Sleepwalking feature with the ACIFB module
 *        in AT32UC3L series
 *
 * Copyright (C) 2011-2014 Atmel Corporation. All rights reserved.
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

/* Include Files */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <stdint.h>
#include "compiler.h"
#include "board.h"
#include "conf_example.h"
/* Include ASF drivers */
#include "acifb.h"
#include "gpio.h"
#include "ast.h"
#include "pm_uc3l.h"
#include "scif_uc3l.h"
#if defined(__GNUC__)
#include "intc.h"
#endif
/* Include ASF services */
#include "sysclk.h"
#include "sleepmgr.h"
#include "delay.h"
#include "status_codes.h"

/*! \name Example Configuration */
/*!@{ */

/**
 * \def CONFIG_SYSCLK_SOURCE
 * \brief DFLL using internal RCSYS as source. Clock source used by
 *        sysclk_init() to initialize system clock.\n
 *        Defined in conf_clock.h
 */

/**
 * \def STATUS_LED
 * \brief LED1_GPIO is used as status LED.
 */

/**
 * \def ERROR_LED
 * \brief LED0_GPIO is used as error status LED.
 */

/**
 * \def LED_DELAY
 * \brief Delay in ms for LED blinking.
 */

/**
 * \def POWER_SUPPLY_MODE_1_8V
 * \brief Enable when operated in 1.8V VDDIN
 */

/**
 * \def AST_CLOCK_SOURCE
 * \brief 32KHz external oscillator is used as AST source
 */

/**
 * \def AST_PRESCALER
 * \brief Prescaler is set to AST_PSEL_32KHZ_1HZ to run at 1Hz
 */

/**
 * \def AST_TRIGGER_PRESCALER
 * \brief Periodic interrupt prescaler is set to 12 for trigger in every 250ms
 */

/**
 * \def AC
 * \brief ACIFB Module is used
 */

/**
 * \def AC_INTERRUPT_PRIORITY
 * \brief ACIFB interrupt priority is set to 1
 */

/**
 * \def AC_GCLK_ID
 * \brief ACIFB Generic Clock - GCLK4
 */

/**
 * \def AC_GCLK_SRC
 * \brief ACIFB Generic Clock Source - PBA
 */

/**
 * \def AC_GCLK_FREQUENCY
 * \brief ACIFB Generic Clock Frequency - 1 MHz
 */

/**
 * \def AC_STARTUP_CYCLES
 * \brief ACIFB startup cycle  - 6 cycles
 */

/**
 * \def EXAMPLE_ACIFBN_CHANNEL
 * \brief ACIFB channel used - 6
 */

/**
 * \def EXAMPLE_ACIFBP_PIN
 * \brief ACIFB Positive input pin
 */

/**
 * \def EXAMPLE_ACIFBP_FUNCTION
 * \brief Pin Functionality for ACIFB input
 */

/**
 * \def EXAMPLE_ACIFBN_PIN
 * \brief ACIFB Negative input pin
 */

/**
 * \def EXAMPLE_ACIFBP_FUNCTION
 * \brief Pin Functionality for ACIFB input
 */

/**
 * \def DEBUG_MESSAGES
 * \brief Enable Trace messages through USART terminal
 */
/*!@} */

/*! \name APPLICATION SPECIFIC CONFIGURATION */
/*!@{ */
/* Enable DEBUG Trace Message */
#define DEBUG_MESSAGES DISABLE
#if DEBUG_MESSAGES
#  include "print_funcs.h"
#endif

/* ACIFB comparison Status is displayed by this LED. */
#define STATUS_LED LED1_GPIO
/* Error Status is displayed by this LED. */
#define ERROR_LED  LED0_GPIO
/* LED blink delay in ms */
#define LED_DELAY  10

/*
 * Power Supply Mode -> 1.8V or 3.3V operation
 * Note: Internal voltage regulator cannot be disabled in 3.3V operation
 * and the application will hang when trying to do so. Hence, this should
 * not be set to true when in 3.3V operation.
 */
#define POWER_SUPPLY_MODE_1_8V  false

/* ACIFB Configuration */
/* ACIFB Address */
#define AC                      &AVR32_ACIFB
/* ACIFB Interrupt Priority - 0 to 3 */
#define AC_INTERRUPT_PRIORITY   1
/* ACIFB GCLK ID */
#define AC_GCLK_ID              AVR32_SCIF_GCLK_ACIFB
/* ACIFB GCLK Source */
#define AC_GCLK_SRC             SCIF_GCCTRL_PBACLOCK
/* ACIFB GCLK Frequency */
#define AC_GCLK_FREQUENCY       250000
/* ACIFB startup time */
#define AC_STARTUP_CYCLES       6
/* ACIFB Number of channels */
#define AC_NB_CHANNELS          1

/* AST Configuration */
/* Configure the AST Clock Source */
#define AST_CLOCK_SOURCE        AST_OSC_32KHZ
/* Configure AST to run at 1Hz frequency */
#define AST_PRESCALER           AST_PSEL_32KHZ_1HZ

/*
 * Configure AST to generate periodic trigger for ACIFB module every 500ms
 * 1000* (2 ^ (prescaler + 1)) / 32768 = 500 -> prescaler = 13
 */
#define AST_TRIGGER_PRESCALER   13

/*
 * Number of used GPIO pins
 * ACIFB Input pins       -   2
 * Oscillator Input pins  -   2
 * LEDS used              -   2
 */
#define NB_GPIO_USED_PINS       6
/*!@} */

/* FUNCTION PROTOTYPES */
/*! \brief Initializes the ACIFB module with trigger */
static status_code_t ac_init(void);

/**
 * \brief Initialize Asynchronous Timer to trigger ACIFB module at regular
 *        intervals.
 */
static status_code_t ast_init(void);

/*! \brief Initializes the power saving measures to reduce power consumption */
static void power_save_measures_init(void);

/* GLOBAL VARIABLES DECLARATION */
/*! \brief Global variable to Store the ACIFB module address */
volatile avr32_acifb_t *acifb = AC;

/*! \brief Array to hold the used GPIO pins */
uint32_t gpio_used_pins[NB_GPIO_USED_PINS] = {
	EXAMPLE_ACIFBP_PIN,
	EXAMPLE_ACIFBN_PIN,
	STATUS_LED,
	ERROR_LED,
#if BOARD_OSC32_PINSEL
	AVR32_SCIF_XIN32_2_0_PIN,
	AVR32_SCIF_XOUT32_2_0_PIN,
#else
	AVR32_SCIF_XIN32_0_PIN,
	AVR32_SCIF_XOUT32_0_PIN
#endif
};

/* FUNCTION DEFINITIONS */

/**
 * \brief ACIFB ISR Routine
 */
ISR(ACIFB_interrupt_handler, AVR32_ACIFB_IRQ_GROUP, AC_INTERRUPT_PRIORITY)
{
	/* Clear the ACIFB interrupt */
	acifb_clear_comparison_interrupt_flag(acifb, EXAMPLE_ACIFB_CHANNEL);
} /* End of ISR routine */

/**
 * \brief Main Application Routine
 *  - Initialize the system clocks
 *  - Initialize the sleep manager
 *  - Initialize the power save measures
 *  - Initialize the ACIFB module
 *  - Initialize the AST to trigger ACIFB at regular intervals
 *  - Go to STATIC sleep mode and wake up on a touch status change
 */
int main(void)
{
	/* Switch on the STATUS LED */
	gpio_clr_gpio_pin(STATUS_LED);
	/* Switch off the error LED. */
	gpio_set_gpio_pin(ERROR_LED);

	/*
	 * Initialize the system clock.
	 * Note: Clock settings are specified in conf_clock.h
	 */
	sysclk_init();

	/*
	 * Initialize the sleep manager.
	 * Note: CONFIG_SLEEPMGR_ENABLE should have been defined in conf_sleepmgr.h
	 */
	sleepmgr_init();
	/* Lock required sleep mode. */
	sleepmgr_lock_mode(SLEEPMGR_STATIC);

	/* Initialize the delay routines */
	delay_init(sysclk_get_cpu_hz());

	/* Initialize the power saving features */
	power_save_measures_init();

	/* Switch off the error LED. */
	gpio_set_gpio_pin(ERROR_LED);

#if DEBUG_MESSAGES
	/* Enable the clock to USART interface */
	sysclk_enable_peripheral_clock(DBG_USART);
	/* Initialize the USART interface to print trace messages */
	init_dbg_rs232(sysclk_get_pba_hz());

	print_dbg("\r Sleepwalking with ACIFB Module in UC3L \n");
	print_dbg("\r Initializing ACIFB Module..... \n");
#endif

	/* Initialize the Analog Comparator peripheral */
	if (ac_init() != STATUS_OK) {
#if DEBUG_MESSAGES
		/* Error initializing the ACIFB peripheral */
		print_dbg("\r Error initializing Analog Comparator module \n");
#endif
		while (1) {
			delay_ms(LED_DELAY);
			gpio_tgl_gpio_pin(ERROR_LED);
		}
	}

#if DEBUG_MESSAGES
	print_dbg("\r ACIFB Module initialized. \n");
	print_dbg("\r Initializing AST Module..... \n");
#endif

	/* Initialize the AST peripheral */
	if (ast_init() != STATUS_OK) {
#if DEBUG_MESSAGES
		print_dbg("\r Error initializing AST module \n");
#endif
		/* Error initializing the AST peripheral */
		while (1) {
			delay_ms(LED_DELAY);
			gpio_tgl_gpio_pin(ERROR_LED);
		}
	}

#if DEBUG_MESSAGES
	print_dbg("\r AST Module initialized. \n");
#endif

	/* Application routine */
	while (1) {
		/* Enable Asynchronous wake-up for ACIFB */
		pm_asyn_wake_up_enable(AVR32_PM_AWEN_ACIFBWEN_MASK);

#if DEBUG_MESSAGES
		print_dbg("\r Going to STATIC sleep mode \n");
		print_dbg(
				"\r Wake up only when input is higher than threshold \n");
#endif

		/* Switch off the status LED */
		gpio_set_gpio_pin(STATUS_LED);
		/* Disable GPIO clock before entering sleep mode */
		sysclk_disable_pba_module(SYSCLK_GPIO);
		AVR32_INTC.ipr[0];
		/* Enter STATIC sleep mode */
		sleepmgr_enter_sleep();
		/* Enable GPIO clock after waking from sleep mode */
		sysclk_enable_pba_module(SYSCLK_GPIO);
		/* Switch on the status LED */
		gpio_clr_gpio_pin(STATUS_LED);

#if DEBUG_MESSAGES
		print_dbg("\r Output higher than threshold \n");
		print_dbg("\n");
#else
		/* LED on for few ms */
		delay_ms(LED_DELAY);
#endif

		/* Clear the wake up & enable it to enter sleep mode again */
		pm_asyn_wake_up_disable(AVR32_PM_AWEN_ACIFBWEN_MASK);
		/* Clear All AST Interrupt request and clear SR */
		ast_clear_all_status_flags(&AVR32_AST);
	}

	return 0;
} /* End of main() */

/**
 * \brief Initializes the ACIFB module with trigger
 * - Start the GCLK for ACIFB
 * - Initialize the trigger mode & compare interrupts for ACIFB
 *
 * \retval STATUS_OK   Configuration OK
 * \retval ERR_TIMEOUT Timeout on configuring ACIFB module
 * \retval ERR_BUSY    ACIFB module unable to configure the trigger
 */
static status_code_t ac_init()
{
	/* struct genclk_config gcfg; */
	uint32_t div = sysclk_get_pba_hz() / AC_GCLK_FREQUENCY;

	scif_gc_setup(AC_GCLK_ID, AC_GCLK_SRC, AVR32_GC_DIV_CLOCK, div);

	/* Now enable the generic clock */
	scif_gc_enable(AC_GCLK_ID);

	/* GPIO pin/acifb - function map. */
	static const gpio_map_t ACIFB_GPIO_MAP = {
		{EXAMPLE_ACIFBP_PIN, EXAMPLE_ACIFBP_FUNCTION},
		{EXAMPLE_ACIFBN_PIN, EXAMPLE_ACIFBN_FUNCTION},
	};

	/* ACIFB Configuration */
	const acifb_t acifb_opt = {
		.sut = 6, /* Resolution mode */
		.actest = TESTMODE_OFF,
		.eventen = true
	};
	/* ACIFB Channel Configuration */
	const acifb_channel_t acifb_channel_opt = {
		/* Filter length */
		.filter_len = 0,
		/* Hysteresis value */
		.hysteresis_value = 0,
		/* Output event when ACOUT is zero? */
		.event_negative = false,
		/* Output event when ACOUT is one? */
		.event_positive = false,
		/* Set the positive input */
		.positive_input = PI_ACP,
		/* Set the negative input */
		.negative_input = NI_ACN,
		/* Set the comparator mode */
		.mode = MODE_EVENT_TRIGGERED,
		/* Interrupt settings */
		.interrupt_settings = IS_VINP_LT_VINN,
		/* Analog comparator channel number */
		.ac_n = EXAMPLE_ACIFB_CHANNEL
	};

	/* Enable Analog Comparator clock */
	sysclk_enable_pba_module(SYSCLK_ACIFB);
	/* Disable pullup on ACIFB channel input pins */
	gpio_disable_pin_pull_up(EXAMPLE_ACIFBP_PIN);
	gpio_disable_pin_pull_up(EXAMPLE_ACIFBN_PIN);
	/* Enable the ACIFB pins */
	gpio_enable_module(ACIFB_GPIO_MAP,
			sizeof(ACIFB_GPIO_MAP) / sizeof(ACIFB_GPIO_MAP[0]));
	/* Configure the ACIFB peripheral */
	acifb_setup_and_enable(acifb, &acifb_opt);
	/* Configure the ACIFB channel with interrupt & trigger */
	acifb_channels_setup(acifb, &acifb_channel_opt, AC_NB_CHANNELS);

	/* Disable global interrupts */
	cpu_irq_disable();

	/*
	 * Initialize the interrupt vectors
	 * Note: This function adds nothing for IAR as the interrupts are
	 * handled by the IAR compiler itself. It provides an abstraction
	 * between GCC & IAR compiler to use interrupts.
	 * Refer function implementation in interrupt_avr32.h
	 */
	irq_initialize_vectors();

	/*
	 * Register the ACIFB interrupt handler
	 * Note: This function adds nothing for IAR as the interrupts are
	 * handled by the IAR compiler itself. It provides an abstraction
	 * between GCC & IAR compiler to use interrupts.
	 * Refer function implementation in interrupt_avr32.h
	 */
	irq_register_handler(&ACIFB_interrupt_handler, AVR32_ACIFB_IRQ,
			AC_INTERRUPT_PRIORITY);
	/* Enable Analog Comparator Channel interrupt */
	acifb_enable_comparison_interrupt(acifb, EXAMPLE_ACIFB_CHANNEL);
	/* Enable global interrupts */
	cpu_irq_enable();

	return STATUS_OK;
} /* End of ac_init() */

/**
 * \brief  Asynchronous Timer Initialization
 * - Start the 32KHz Oscillator
 * - Initializes the AST module with periodic trigger events
 *
 * \retval STATUS_OK   Configuration OK
 * \retval ERR_BUSY    Error in configuring the AST module
 */
static status_code_t ast_init()
{
	/* Initial Count value to write in AST */
	unsigned long ast_counter = 0;
	/* Set the prescaler to set a periodic trigger from AST */
	avr32_ast_pir0_t pir = {
		.insel = AST_TRIGGER_PRESCALER
	};

	/* Set the OSC32 parameters */
	scif_osc32_opt_t osc32_opt = {
		.mode = SCIF_OSC_MODE_2PIN_CRYSTAL_HICUR,
		.startup = OSC32_STARTUP_8192,
		.pinsel = BOARD_OSC32_PINSEL,
		.en1k = false,
		.en32k = true
	};

	/* Enable the 32KHz Oscillator */
	scif_start_osc32(&osc32_opt, true);
	/* Enable the Peripheral Event System Clock */
	sysclk_enable_hsb_module(SYSCLK_EVENT);
	/* Enable PBA clock for AST clock to switch its source */
	sysclk_enable_pba_module(SYSCLK_AST);
	/* Initialize the AST in counter mode */
	if (!ast_init_counter(&AVR32_AST, AST_CLOCK_SOURCE, AST_PRESCALER,
			ast_counter)) {
		return ERR_BUSY;
	}

	/* Initialize the periodic value register with the prescaler */
	ast_set_periodic0_value(&AVR32_AST, pir);
	/* Enable the AST periodic event */
	ast_enable_periodic0(&AVR32_AST);

	/* Clear All AST Interrupt request and clear SR */
	ast_clear_all_status_flags(&AVR32_AST);

	/* Enable the AST */
	ast_enable(&AVR32_AST);
	
	/* Disable PBA clock for AST after switching its source to OSC32 */
	sysclk_disable_pba_module(SYSCLK_AST);

	return STATUS_OK;
} /* End of ast_init() */

/**
 * \brief  Low Power Configuration
 * Initializes the power saving measures to reduce power consumption
 * - Enable pull-ups on GPIO pins
 * - Disable the clocks to unwanted modules
 * - Disable internal voltage regulator when in 1.8V supply mode
 */
static void power_save_measures_init()
{
	uint8_t i;
	uint32_t gpio_mask[AVR32_GPIO_PORT_LENGTH] = {0};

	/*
	 * Enable internal pull-ups on all unused GPIO pins
	 * Note: Pull-ups on Oscillator or JTAG pins can be enabled only if they
	 * are not used as an oscillator or JTAG pin respectively.
	 */
	for (i = 0; i < (sizeof(gpio_used_pins) / sizeof(uint32_t)); i++) {
		gpio_mask[gpio_used_pins[i] >>
		5] |= 1 << (gpio_used_pins[i] & 0x1F);
	}
	for (i = 0; i < AVR32_GPIO_PORT_LENGTH; i++) {
		gpio_configure_group(i, ~(gpio_mask[i]),
				GPIO_PULL_UP | GPIO_DIR_INPUT);
	}
	/* Disable OCD clock which is not disabled by sysclk service */
	sysclk_disable_cpu_module(SYSCLK_OCD);
#if POWER_SUPPLY_MODE_1_8V

	/*
	 * When using 1.8V Single supply mode, the Voltage Regulator can be
	 * shut-down using the code below, in-order to save power.
	 * See Voltage Regulator Calibration Register in datasheet for more
	 *info.
	 * CAUTION: When using 3.3V Single supply mode, the Voltage Regulator
	 * cannot be shut-down and the application will hang in this loop.
	 */
	uint32_t tmp = (AVR32_SCIF.vregcr);
	tmp &= (~(1 << 5 | 1 << 18));
	AVR32_SCIF.unlock = 0xAA000000 | AVR32_SCIF_VREGCR;
	AVR32_SCIF.vregcr = tmp;
	/* Wait until internal voltage regulator is disabled. */
	while ((AVR32_SCIF.vregcr & 0x00040020)) {
	}
#endif
} /* End of power_save_measures_init() */

/* Application Documentation */

/**
 * \mainpage Sleepwalking example with the ACIFB module on AVR UC3 L devices
 * \section intro Introduction
 *  The Example projects demonstrates:\n
 *  - Sleepwalking Feature in AT32UC3L devices:\n
 *    SleepWalking feature allows to reduce the power consumption of the
 *    peripherals in sleep modes. It allows the UC3L Event System to handle
 *    asynchronous events in various sleep modes by requesting a module local
 *    clock for the duration of the Event processing. When the event processing
 *    ends, the clock request is dis-asserted and the module goes back to sleep.\n
 *
 *  - Sleepwalking with ACIFB Module in AT32UC3L devices:\n
 *    The given example demonstrates the use of Analog Comparator using
 *    SleepWalking feature. The ACIFB interface once configured remains in the
 *    sleep mode. The AST (Asynchronous Timer) is configured to run at 32KHz
 *    oscillator and periodically generates an event which will be used by
 *    ACIFB. Upon receiving the event, ACIFB module clock will be enabled and
 *    analog value on the selected channels will be sampled. The input signals
 *    from positive and negative inputs will be compared. If positive is less
 *    than negative input, an interrupt will be generated by ACIFB. This will
 *    wake up the CPU as well as rest of the system. The ISR will clear the
 *    interrupt and system will toggle the status LED before going back to
 *    sleep. In case the positive input is greater than negative input, then
 *    ACIFB will go back to sleep mode without waking the entire system. \n \n
 *
 * \section files Main Files
 * - conf_example.h               : Example Configuration
 * - conf_clock.h                 : Clock Configuration
 * - conf_sleepmgr.h              : Sleep Manager configuration
 * - acifb_sleepwalking_example.c : Sleepwalking with ACIFB Example
 *
 *
 * \section referenceinfo References
 *  - Refer Application Note AVR32849: Sleepwalking with AT32UC3L
 *  - Refer Application Note AVR4029: ASF Getting Started Guide
 *  - Refer Application Note AVR 4030: ASF Reference Manual
 *
 * \section compinfo Compiler Support
 * The example application supports:
 *  - IAR EWAVR32
 *  - GNU GCC for AVR32
 *
 * \section deviceinfo Device Support
 *  - AT32UC3L0 Series
 *
 * \section testinfo Test Information
 * This example has been tested with the following :
 *  - AVR Studio 5.0
 *  - IAR32 Embedded Workbench
 *  - STK600 development board, UC3-L0-XPLAINED & UC3L-EK evaluation kits
 *  - 1.8V and 3.3V Supply mode
 *
 * \section setupinfo Setup Information
 *  - CPU Clock Source  : DFLL(96MHz) with internal RCSYS as its source
 *  - AST Clock Source  : 32KHz external oscillator
 *  - CPU Speed         : 12MHz
 *  - PBA Speed         : 6MHz
 *  - PBB Speed         : 6MHz
 *  - AST Trigger Period: Every 250ms
 *  - UC3L-EK: ACIFB Channel 2 \n
 *    ----------------------------------------------------------- \n
 *    ACIFB Input Pin name - UC3L-EK board Port\n
 *    ----------------------------------------------------------- \n
 *    ACIFB ACAP[1]    -   PA10  Pin 6 on J14 Header \n
 *    ACIFB ACAN[1]    -   PA12  Pin 10 on J14 Header  \n
 *    ----------------------------------------------------------- \n
 *
 *  - UC3-L0-XPLAINED: ACIFB Channel 6 \n
 *    ----------------------------------------------------------- \n
 *    ACIFB Input Pin name - UC3-L0-XPLAINED board Port\n
 *    ----------------------------------------------------------- \n
 *    ACIFB ACAP[3]    -   PB07  Pin 5 on J2 Header \n
 *    ACIFB ACAN[3]    -   PB06  Pin 7 on J2 Header \n
 *    ----------------------------------------------------------- \n
 *
 * \section contactinfo Contact Information
 * For further information, visit :
 * <A href="http://www.atmel.com/products/AVR32/"> Atmel AVR32 </A>.\n
 * Technical support & faq, visit :
 * <A href="http://www.atmel.com/design-support/"> Support and FAQ </A>.
 *
 * \author
 * Atmel Corporation : http://www.atmel.com \n
 */
