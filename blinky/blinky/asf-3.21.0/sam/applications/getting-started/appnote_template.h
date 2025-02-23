锘**
 * \file
 *
 * \brief Getting Started with CHIP_NAME
 *
 * Copyright (C) 2014 Atmel Corporation. All rights reserved.
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
\mainpage Getting Started with CHIP_NAME
\copydetails appdoc_preface
*/
/**
\page appdoc_preface Introduction

<b>Features</b>

- Getting started with CHIP_NAME device and tools
- Getting started with BOARD_NAME in Atmel Studio, IAR Embedded Workbench庐 for
  ARM庐 and SAM-BA庐
- Getting started example in Atmel Software Framework (ASF)

<b>Description</b>

This applaiction note aims at helpling the readers to get start with the Atmel
ARM Cortex庐-M4 based CHIP_NAME microcontroller. It will provide information on
how to get datasheet, tools and software, and give a step-by-step instruction
on how to load and buildup a single example project to BOARD_NAME.
*/
/**
\page appdoc_chap_00_title1 Get the Device Datasheet

Web page: http://www.atmel.com/CHIP_NAME

Documents: CHIP_NAME Series Datasheet (Summary, Complete) (.pdf) 
- Select the required device (ie. ATCHIP_NAMEx) or and get the latest datasheet
  (.pdf file). There are two versions: 
- Complete version (Full datasheet)
- Summary version (short version includes product features, package, pinout and
  order information)

*/

/**
\page appdoc_chap_01_title2 Get the CHIP_NAME Evaluation Kit

Web page: http://www.atmel.com/tools/BOARD_NAME.aspx

Get the kit: http://store.atmel.com

Document/file:
- BOARD_NAME production files: schematics (.pdf), gerber, BOM,  test software 
- BOARD_NAME User Guide (.pdf)

\copydoc BOARD_FEATURE

The BOARD_NAME User Guide introduces the BOARD_NAME and describes its
development and debugging capabilities.
*/

/**
\page appdoc_chap_02_title3 Get the Tools

The following tools are necessary for CHIP_NAME development:
\copydoc DEV_TOOLS
*/

/**
\page appdoc_chap_03_title4 Get Started with Atmel Studio 6
\section appdoc_chap_03_section1 Requirements
\copydoc AS6_USAGE
\section appdoc_chap_03_section2 Load the Example
- Launch Atmel Studio
- Open the example selection menu in ASF from Atmel Studio:
  <i>File->New->Example Project from ASF...</i>
- Select the 鈥淜it鈥view and select BOARD_NAME in the latest ASF
- Pick a project in the list and then press OK
- Accept the license agreement and press \a Finish. Then the Atmel Studio will
  open the example
- Build the project: <i>Build->Build Solution</i>
- Load the code in CHIP_NAME and start debugging: <i>Debug->Start Debugging and
  Break</i>

Now the application has been programmed and the debugger stops at the beginning
of <i>main()</i>. To execute it, click on <i>Debug->Continue</i>.
*/

/**
\page appdoc_chap_04_title5 Get Started with IAR EWARM
\section appdoc_chap_04_section1 Requirements
\copydoc IAR_USAGE
\section appdoc_chap_04_section2 Load the Example
- Open the an example project file for BOARD_NAME
- Build the project: <i>Project->Make</i>
- Load the code in CHIP_NAME and start debugging: <i>Project->Download and
Debug</i>

Now the application has been programmed and the debugger stops at the beginning
of <i>main()</i>. To execute it, click on <i>Debug->Go</i>.
*/

/**
\page appdoc_chap_05_title6 Get Started with SAM-BA
\section appdoc_chap_05_section1 Requirements
\copydoc SAM-BA_REQ
\section appdoc_chap_05_section2 Build the Binary File
- Open the Atmel Studio command line: <i>Start->All Programs->Atmel->Atmel
  Studio 6.1 Command Prompt</i>
- Change the directory where the a BOARD_NAME example makefile is
- Type 鈥渕ake鈥and enter. Then the binary file (<i>getting-started_flash.bin</i>)
  will be generated in the directory
- The binary file generated by IAR can be programmed by SAM-BA as well. About
  how to generate binary files by IAR, please refer to IAR C/C++ Development
  Guide for ARM provided by IAR Embedded Workbench for ARM.
\section appdoc_chap_05_section3 Load the Example
\copydoc SAM-BA_LOAD

Now the application has been programmed. To execute it, reset the board.

Besides J-Link, UART and USB can be used for the communication between SAM-BA
and CHIP_NAME, please refer to the chapter 鈥淪AM-BA Boot Program for CHIP_NAME
Microcontrollers鈥in CHIP_NAME datasheet for the details.
*/

/**
\page appdoc_chap_06_title7 The Getting-started Example
This section describes a simple example project that uses several important
features present on CHIP_NAME device.

There are four main parts in this section:
- The specification of the getting-started example
- The introduction about relevant on-chip peripherals
- The introduction about relevant on-board components
- The implementation of the example

\section appdoc_chap_06_section1 Specification
\copydoc GS_SPEC

\section appdoc_chap_06_section2 On-chip Peripherals
In order to perform the operations described previously, the getting-started
example uses the following set of peripherals:
- Parallel Input/Output (PIO) controller
- Timer Counter (TC)
- System Tick Timer (SysTick)
- Nested Vectored Interrupt Controller (NVIC)
- Universal asynchronous Receiver Transmitter (UART)
- Power Management Controller (PMC)

LEDs and buttons on the board are connected to standard input/output pins on the
chip. The pins are managed by a PIO controller. In addition, it is possible to
have the controller generate an interrupt when the status of one of its pins
changes; buttons are configured to have this behavior.

The TC and SysTick are used to generate two timebases, in order to obtain the
LED blinking rates. They are both used in interrupt mode: 
- The TC triggers an interrupt at a fixed rate, each time toggling the LED state
  (on/off). 
- The SysTick triggers an interrupt every millisecond, incrementing a variable
  by one tick. 

The Wait function monitors this variable to provide a precise delay for toggling
the second LED state.

Using the NVIC is required to manage interrupts. It allows the configuration of
a separate interrupt handler for each source. Three different functions are used
to handle PIO, TC and SysTick interrupts.

Finally, an additional peripheral is used to output debug traces on a serial
line: the UART. Having the firmware send debug traces at key points of the code
can greatly help the debugging process.

\section appdoc_chap_06_section3 On-board Components
\subsection appdoc_chap_06_section3_sub1 Buttons
\copydoc BUTTONS

\subsection appdoc_chap_06_section3_sub2 LEDs
\copydoc LEDS

\subsection appdoc_chap_06_section3_sub3 COM Port (UART)
\copydoc COM

\section appdoc_chap_06_section4 Implementation
\subsection appdoc_chap_06_section4_sub1 Startup
Most of the code in this program is written in C, which makes it easier to
understand, more portable and modular. The C-startup code must:
- Provide vector table
- Initialize critical peripherals
- Initialize stacks
- Initialize memory segments
- Locate Vector Table Offset
These steps are described in the following paragraphs.

Note that there are two versions of c-startup code in Atmel Software Framework.
One is for the IAR Embedded Workbench for ARM compiler and the other is for GNU
GCC compiler. This application note will focus on the details of the GCC one.

\subsubsection appdoc_chap_06_section4_sub1_subsub1 Vector Table
The vector table contains the initialization value for the stack pointer (see
鈥淚nitializing Stacks鈥in \ref table_vector_table_format) on reset, and the entry
point addressed for all exception handlers. The exception numbers (see
\ref table_exception_numbers) define the order of entries in the vector table
associated with the exception handler entries
(see \ref table_vector_table_format).

\anchor table_exception_numbers
<table>
 <caption>Exception Numbers</caption>
 <tr>
      <th>Exception Number</th>
      <th>Exception</th>
 </tr>
 <tr>
      <td>1</td>
      <td>Reset</td>
 </tr>
 <tr>
      <td>2</td>
      <td>Non-maskable Interrupt</td>
 </tr>
 <tr>
      <td>3</td>
      <td>Hard Fault</td>
 </tr>
 <tr>
      <td>4</td>
      <td>Memory Management</td>
 </tr>
 <tr>
      <td>5</td>
      <td>Bus Fault</td>
 </tr>
 <tr>
      <td>6</td>
      <td>Usage Fault</td>
 </tr>
 <tr>
      <td>7-10</td>
      <td>Reserved</td>
 </tr>
 <tr>
      <td>11</td>
      <td>SVCall</td>
 </tr>
 <tr>
      <td>12</td>
      <td>Debug Monitor</td>
 </tr>
 <tr>
      <td>13</td>
      <td>Reserved</td>
 </tr>
 <tr>
      <td>14</td>
      <td>PendSV</td>
 </tr>
 <tr>
      <td>15</td>
      <td>SysTick</td>
 </tr>
 <tr>
      <td>16</td>
      <td>External Interrupt 0</td>
 </tr>
 <tr>
      <td>...</td>
      <td>...</td>
 </tr>
 <tr>
      <td>16 + N</td>
      <td>External Interrupt N</td>
 </tr>
</table>

\anchor table_vector_table_format
<table>
 <caption>Vector Table Format</caption>
 <tr>
      <th>Word Offset</th>
      <th>Description</th>
 </tr>
 <tr>
      <td>0</td>
      <td>Initial Stack Pointer</td>
 </tr>
 <tr>
      <td>Exception Number</td>
      <td>Exception using that Exception Number</td>
 </tr>
</table>

On reset, the vector table is located at CODE partition. The table鈥檚 current
location can be determined or relocated in the CODE or SRAM partitions of the
memory map using the Vector Table Offset Register (VTOR). Details on the
register can be found in the "Cortex鈩M4 Technical Reference Manual".

In the getting-started example, a full vector table looks like this:

\anchor code_startup_vector_table
<b>Code: The Full Vector Table in the getting-started example</b>
\snippet startup_CHIP_NAME.c startup_vector_table

\subsubsection appdoc_chap_06_section4_sub1_subsub2 Reset Exception
The handler of reset exception is responsible for starting up the application
by performing the following actions:
\anchor table_reset_exception_actions
<table>
 <caption>Reset Exception Actions</caption>
 <tr>
      <th>Action</th>
      <th>Description</th>
 </tr>
 <tr>
      <td>Initialize variables</td>
      <td>Any global/static variables must be setup. This includes
          initializing the BSS variable to 0, and copying initial values from
          ROM to RAM for non-constant variables.</td>
 </tr>
 <tr>
      <td>Set vector table</td>
      <td>Optionally change vector table from Code area, value 0, to a
          location in SRAM. This is normally done to enable dynamic changes.
          </td>
 </tr>
 <tr>
      <td>Branch to main</td>
      <td>Branch to the <i>main()</i> application.</td>
 </tr>
</table>

\subsection appdoc_chap_06_section4_sub2 System Clock Initialization
At the very beginning of the getting-started example <i>main()</i>,
<i>sysclk_init()</i> is called to initialized the system clock of CHIP_NAME. In
this function, Power Management Controller (PMC) is set according to the clock
configuration file, <i>conf_clock.h</i>.

\copydoc CONF_CLOCK

\anchor code_clock_configuration
<b>Code: Clock Configuration</b>
\snippet conf_clock.h conf_clock_sysclk_settings
\snippet conf_clock.h conf_clock_pll0_settings

\copydoc SYS_CLOCK

So after calling <i>sysclk_init()</i> with this configuration, the system clock
frequency (SYSCLK) is

\par
\copydoc CLOCK_FORMULA

Note that on the BOARD_NAME, 12MHz crystal oscillator is connected to XIN and
XOUT pins.

\subsection appdoc_chap_06_section4_sub3 Board Initialization
To contol the on-board components, buttons, LEDs and COM port in the case of the
getting-started example, <i>board_init()</i> is called in the <i>main()</i>.
With the <i>conf_board.h</i>, the corresponding pins are configured in the
appropriate mode.

\anchor code_com_enable
<b>Code: Board Configuration</b>
\snippet conf_board.h conf_board_uart_enable

In <i>board_init()</i>, the pins connected to buttons are configured as input
ports and the pins connected to LEDs are configured as output ports.

In the getting-started example, \c CONF_BOARD_UART_CONSOLE is predefined as
above, which enables the COM port by configuring PB4 and PB5 as URXD0 and UTXD0
respectively.

\subsection appdoc_chap_06_section4_sub4 Peripherals Configuration and Usage
\subsubsection appdoc_chap_06_section4_sub4_subsub1 UART
UART outputs the debug information via the USB-to-COM port in the
getting-started example. To display characters on PC terminal software
correctly, several parameters must be configured before calling <i>puts()</i>
and <i>printf()</i>.

In CHIP_NAME, the UART peripheral operates in asynchronous mode only and
supports only 8-bit character handling (with no parity) and 1 stop bit. No flow
control is supported. So there are the baudrate and parity left to be
configured.

\anchor code_com_parameters
<b>Code: UART Parameters</b>
\snippet conf_uart_serial.h conf_uart_serial_settings

In <i>conf_uart_serial.h</i>, the baudrate is set as 115200bps and no parity is
used.

\anchor code_com_configuration
<b>Code: UART Configuration</b>
\snippet main.c main_console_configure

In the above code, the peripheral clock for \c UART0 is enabled by calling
<i>sysclk_enable_peripheral_clock()</i>. Then <i>stdio_serial_init()</i>
configures the baudrate and the parity type.

\subsubsection appdoc_chap_06_section4_sub4_subsub2 SysTick
SysTick can be easily configured by calling <i>SysTick_Config()</i>. To generate
1ms period, the only parameter of this function should be <i>system clock
frequency</i> / 1000.

\anchor code_systick_configuration
<b>Code: SysTick Configuration</b>
\snippet main.c main_step_systick_init

<i>sysclk_get_cpu_hz()</i> returns the current system clock frequency in Hz.
Then the SysTick interrupt will be triggered every 1ms. In the getting-started
example, the SysTick interrupt handler <i>SysTick_Handler()</i> simply increases
a global counter by 1 every time, which is used by the wait function to generate
a specified period delay.

\anchor code_systick_handler
<b>Code: SysTick Interrupt Handler</b>
\snippet main.c main_var_ticks
\snippet main.c main_systick_handler

\anchor code_delay_fun
<b>Code: Wait Function</b>
\snippet main.c main_ms_delay

Note that the global counter, \a ticks_in_ms, is declared as a volatile
variable. It prevents the compiler from optimizing the code casuing that the
wait function does not work.

\subsubsection appdoc_chap_06_section4_sub4_subsub3 TC
CHIP_NAME provides six 32-bit TC channels, which could be used to measure
frequency, count event, generate PWM wave and so on.

In the getting-started example, the TC channel 0 is configured to generate an
interrupt per a quarter of a second.

\anchor code_tc_configuration
<b>Code: Timer Counter Configuration</b>
\snippet main.c main_tc_configure

Before any configuration, TC peripheral clock is enabled. 2 necessary
parameters, the TC divider, the tick value for the compare register (RC is used
in the example), must be calculated to initialize the TC and the compare
register. Then the program enables the TC channel 0 interrupt and the compare
interrupt. In the end, it starts TC channel 0 and the counter starts ticking.

In the TC channel 0 interrupt handler, the LED status is toggled every time.

\anchor code_tc_handler
<b>Code: Interrupt Handler for TC Channel 0</b>
\snippet main.c main_tc0_handler

\subsubsection appdoc_chap_06_section4_sub4_subsub4 PIO
Besides toggling LEDs, in the getting-started example, PIO retrieves the button
input. When a button is pressed, the level of the corresponding pin is changed.
PIO detects the change and triggers an interrupt.

\anchor code_pio_configuration
<b>Code: PIO Configuration for one button (one pin)</b>
\snippet main.c main_button1_configure

The PIO peripheral clock is enabled at first so that the configuration below can
take effect.

Usually in an application with the button inputs, there are some glitches on the
input lines of the buttons. In PIO of CHIP_NAME, the debouncing filter can be
set to reject these unwanted pulses. In the getting-started example, if the
period of a glitch is less than 10 slow clock cycles (slow clock frequency is
32768Hz in this case), the glitch will be ignored by PIO.

Pressing different button leads to different action, so there should be a
specified handler for a specified button pressing. Before enabling the PIO
interrupt and any pin interrupt, a handler, \a _button0_handler, is set by
calling <i>pio_handler_set()</i>. Also the condition to trigger a pin interrupt
is chosen here.

\copydoc HOW_IT_WORKS

\anchor code_button_press_process
<b>Code: Button Pressing Process</b>
\snippet main.c main_button1_evnt_process
\snippet main.c main_button1_handler
\snippet main.c main_button2_evnt_process
\snippet main.c main_button2_handler
*/

/**
\page appdoc_chap_99_revsision_history Revision History
<table>
<tr>
<th>Doc. Rev.</td>
<th>Date</td>
<th>Comments</td>
</tr>
<tr>
<td>A</td>
<td>08/2013</td>
<td>Initial release</td>
</tr>
</table>
*/ /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
