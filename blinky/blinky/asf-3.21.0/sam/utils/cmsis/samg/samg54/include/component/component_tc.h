/**
 * \file
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

#ifndef _SAMG54_TC_COMPONENT_
#define _SAMG54_TC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Timer Counter */
/* ============================================================================= */
/** \addtogroup SAMG54_TC Timer Counter */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TcChannel hardware registers */
typedef struct {
  __O  uint32_t TC_CCR;       /**< \brief (TcChannel Offset: 0x0) Channel Control Register */
  __IO uint32_t TC_CMR;       /**< \brief (TcChannel Offset: 0x4) Channel Mode Register */
  __IO uint32_t TC_SMMR;      /**< \brief (TcChannel Offset: 0x8) Stepper Motor Mode Register */
  __I  uint32_t Reserved1[1];
  __I  uint32_t TC_CV;        /**< \brief (TcChannel Offset: 0x10) Counter Value */
  __IO uint32_t TC_RA;        /**< \brief (TcChannel Offset: 0x14) Register A */
  __IO uint32_t TC_RB;        /**< \brief (TcChannel Offset: 0x18) Register B */
  __IO uint32_t TC_RC;        /**< \brief (TcChannel Offset: 0x1C) Register C */
  __I  uint32_t TC_SR;        /**< \brief (TcChannel Offset: 0x20) Status Register */
  __O  uint32_t TC_IER;       /**< \brief (TcChannel Offset: 0x24) Interrupt Enable Register */
  __O  uint32_t TC_IDR;       /**< \brief (TcChannel Offset: 0x28) Interrupt Disable Register */
  __I  uint32_t TC_IMR;       /**< \brief (TcChannel Offset: 0x2C) Interrupt Mask Register */
  __I  uint32_t Reserved2[4];
} TcChannel;
/** \brief Tc hardware registers */
#define TCCHANNEL_NUMBER 3
typedef struct {
       TcChannel TC_CHANNEL[TCCHANNEL_NUMBER]; /**< \brief (Tc Offset: 0x0) channel = 0 .. 2 */
  __O  uint32_t  TC_BCR;                       /**< \brief (Tc Offset: 0xC0) Block Control Register */
  __IO uint32_t  TC_BMR;                       /**< \brief (Tc Offset: 0xC4) Block Mode Register */
  __I  uint32_t  Reserved1[7];
  __IO uint32_t  TC_WPMR;                      /**< \brief (Tc Offset: 0xE4) Write Protection Mode Register */
  __I  uint32_t  Reserved2[6];
  __IO uint32_t  TC_RPR0;                      /**< \brief (Tc Offset: 0x100) Receive Pointer Register (pdc = 0) */
  __IO uint32_t  TC_RCR0;                      /**< \brief (Tc Offset: 0x104) Receive Counter Register (pdc = 0) */
  __I  uint32_t  Reserved3[2];
  __IO uint32_t  TC_RNPR0;                     /**< \brief (Tc Offset: 0x110) Receive Next Pointer Register (pdc = 0) */
  __IO uint32_t  TC_RNCR0;                     /**< \brief (Tc Offset: 0x114) Receive Next Counter Register (pdc = 0) */
  __I  uint32_t  Reserved4[2];
  __O  uint32_t  TC_PTCR0;                     /**< \brief (Tc Offset: 0x120) Transfer Control Register (pdc = 0) */
  __I  uint32_t  TC_PTSR0;                     /**< \brief (Tc Offset: 0x124) Transfer Status Register (pdc = 0) */
} Tc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- TC_CCR : (TC Offset: N/A) Channel Control Register -------- */
#define TC_CCR_CLKEN (0x1u << 0) /**< \brief (TC_CCR) Counter Clock Enable Command */
#define TC_CCR_CLKDIS (0x1u << 1) /**< \brief (TC_CCR) Counter Clock Disable Command */
#define TC_CCR_SWTRG (0x1u << 2) /**< \brief (TC_CCR) Software Trigger Command */
/* -------- TC_CMR : (TC Offset: N/A) Channel Mode Register -------- */
#define TC_CMR_TCCLKS_Pos 0
#define TC_CMR_TCCLKS_Msk (0x7u << TC_CMR_TCCLKS_Pos) /**< \brief (TC_CMR) Clock Selection */
#define   TC_CMR_TCCLKS_TIMER_CLOCK1 (0x0u << 0) /**< \brief (TC_CMR) Clock selected: internal TIMER_CLOCK1 clock signal (from PMC) */
#define   TC_CMR_TCCLKS_TIMER_CLOCK2 (0x1u << 0) /**< \brief (TC_CMR) Clock selected: internal TIMER_CLOCK2 clock signal (from PMC) */
#define   TC_CMR_TCCLKS_TIMER_CLOCK3 (0x2u << 0) /**< \brief (TC_CMR) Clock selected: internal TIMER_CLOCK3 clock signal (from PMC) */
#define   TC_CMR_TCCLKS_TIMER_CLOCK4 (0x3u << 0) /**< \brief (TC_CMR) Clock selected: internal TIMER_CLOCK4 clock signal (from PMC) */
#define   TC_CMR_TCCLKS_TIMER_CLOCK5 (0x4u << 0) /**< \brief (TC_CMR) Clock selected: internal TIMER_CLOCK5 clock signal (from PMC) */
#define   TC_CMR_TCCLKS_XC0 (0x5u << 0) /**< \brief (TC_CMR) Clock selected: XC0 */
#define   TC_CMR_TCCLKS_XC1 (0x6u << 0) /**< \brief (TC_CMR) Clock selected: XC1 */
#define   TC_CMR_TCCLKS_XC2 (0x7u << 0) /**< \brief (TC_CMR) Clock selected: XC2 */
#define TC_CMR_CLKI (0x1u << 3) /**< \brief (TC_CMR) Clock Invert */
#define TC_CMR_BURST_Pos 4
#define TC_CMR_BURST_Msk (0x3u << TC_CMR_BURST_Pos) /**< \brief (TC_CMR) Burst Signal Selection */
#define   TC_CMR_BURST_NONE (0x0u << 4) /**< \brief (TC_CMR) The clock is not gated by an external signal. */
#define   TC_CMR_BURST_XC0 (0x1u << 4) /**< \brief (TC_CMR) XC0 is ANDed with the selected clock. */
#define   TC_CMR_BURST_XC1 (0x2u << 4) /**< \brief (TC_CMR) XC1 is ANDed with the selected clock. */
#define   TC_CMR_BURST_XC2 (0x3u << 4) /**< \brief (TC_CMR) XC2 is ANDed with the selected clock. */
#define TC_CMR_LDBSTOP (0x1u << 6) /**< \brief (TC_CMR) Counter Clock Stopped with RB Loading */
#define TC_CMR_LDBDIS (0x1u << 7) /**< \brief (TC_CMR) Counter Clock Disable with RB Loading */
#define TC_CMR_ETRGEDG_Pos 8
#define TC_CMR_ETRGEDG_Msk (0x3u << TC_CMR_ETRGEDG_Pos) /**< \brief (TC_CMR) External Trigger Edge Selection */
#define   TC_CMR_ETRGEDG_NONE (0x0u << 8) /**< \brief (TC_CMR) The clock is not gated by an external signal. */
#define   TC_CMR_ETRGEDG_RISING (0x1u << 8) /**< \brief (TC_CMR) Rising edge */
#define   TC_CMR_ETRGEDG_FALLING (0x2u << 8) /**< \brief (TC_CMR) Falling edge */
#define   TC_CMR_ETRGEDG_EDGE (0x3u << 8) /**< \brief (TC_CMR) Each edge */
#define TC_CMR_ABETRG (0x1u << 10) /**< \brief (TC_CMR) TIOA or TIOB External Trigger Selection */
#define TC_CMR_CPCTRG (0x1u << 14) /**< \brief (TC_CMR) RC Compare Trigger Enable */
#define TC_CMR_WAVE (0x1u << 15) /**< \brief (TC_CMR) Waveform Mode */
#define TC_CMR_LDRA_Pos 16
#define TC_CMR_LDRA_Msk (0x3u << TC_CMR_LDRA_Pos) /**< \brief (TC_CMR) RA Loading Edge Selection */
#define   TC_CMR_LDRA_NONE (0x0u << 16) /**< \brief (TC_CMR) None */
#define   TC_CMR_LDRA_RISING (0x1u << 16) /**< \brief (TC_CMR) Rising edge of TIOA */
#define   TC_CMR_LDRA_FALLING (0x2u << 16) /**< \brief (TC_CMR) Falling edge of TIOA */
#define   TC_CMR_LDRA_EDGE (0x3u << 16) /**< \brief (TC_CMR) Each edge of TIOA */
#define TC_CMR_LDRB_Pos 18
#define TC_CMR_LDRB_Msk (0x3u << TC_CMR_LDRB_Pos) /**< \brief (TC_CMR) RB Loading Edge Selection */
#define   TC_CMR_LDRB_NONE (0x0u << 18) /**< \brief (TC_CMR) None */
#define   TC_CMR_LDRB_RISING (0x1u << 18) /**< \brief (TC_CMR) Rising edge of TIOA */
#define   TC_CMR_LDRB_FALLING (0x2u << 18) /**< \brief (TC_CMR) Falling edge of TIOA */
#define   TC_CMR_LDRB_EDGE (0x3u << 18) /**< \brief (TC_CMR) Each edge of TIOA */
#define TC_CMR_CPCSTOP (0x1u << 6) /**< \brief (TC_CMR) Counter Clock Stopped with RC Compare */
#define TC_CMR_CPCDIS (0x1u << 7) /**< \brief (TC_CMR) Counter Clock Disable with RC Compare */
#define TC_CMR_EEVTEDG_Pos 8
#define TC_CMR_EEVTEDG_Msk (0x3u << TC_CMR_EEVTEDG_Pos) /**< \brief (TC_CMR) External Event Edge Selection */
#define   TC_CMR_EEVTEDG_NONE (0x0u << 8) /**< \brief (TC_CMR) None */
#define   TC_CMR_EEVTEDG_RISING (0x1u << 8) /**< \brief (TC_CMR) Rising edge */
#define   TC_CMR_EEVTEDG_FALLING (0x2u << 8) /**< \brief (TC_CMR) Falling edge */
#define   TC_CMR_EEVTEDG_EDGE (0x3u << 8) /**< \brief (TC_CMR) Each edge */
#define TC_CMR_EEVT_Pos 10
#define TC_CMR_EEVT_Msk (0x3u << TC_CMR_EEVT_Pos) /**< \brief (TC_CMR) External Event Selection */
#define   TC_CMR_EEVT_TIOB (0x0u << 10) /**< \brief (TC_CMR) TIOB */
#define   TC_CMR_EEVT_XC0 (0x1u << 10) /**< \brief (TC_CMR) XC0 */
#define   TC_CMR_EEVT_XC1 (0x2u << 10) /**< \brief (TC_CMR) XC1 */
#define   TC_CMR_EEVT_XC2 (0x3u << 10) /**< \brief (TC_CMR) XC2 */
#define TC_CMR_ENETRG (0x1u << 12) /**< \brief (TC_CMR) External Event Trigger Enable */
#define TC_CMR_WAVSEL_Pos 13
#define TC_CMR_WAVSEL_Msk (0x3u << TC_CMR_WAVSEL_Pos) /**< \brief (TC_CMR) Waveform Selection */
#define   TC_CMR_WAVSEL_UP (0x0u << 13) /**< \brief (TC_CMR) UP mode without automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UPDOWN (0x1u << 13) /**< \brief (TC_CMR) UPDOWN mode without automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UP_RC (0x2u << 13) /**< \brief (TC_CMR) UP mode with automatic trigger on RC Compare */
#define   TC_CMR_WAVSEL_UPDOWN_RC (0x3u << 13) /**< \brief (TC_CMR) UPDOWN mode with automatic trigger on RC Compare */
#define TC_CMR_ACPA_Pos 16
#define TC_CMR_ACPA_Msk (0x3u << TC_CMR_ACPA_Pos) /**< \brief (TC_CMR) RA Compare Effect on TIOA */
#define   TC_CMR_ACPA_NONE (0x0u << 16) /**< \brief (TC_CMR) None */
#define   TC_CMR_ACPA_SET (0x1u << 16) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ACPA_CLEAR (0x2u << 16) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ACPA_TOGGLE (0x3u << 16) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_ACPC_Pos 18
#define TC_CMR_ACPC_Msk (0x3u << TC_CMR_ACPC_Pos) /**< \brief (TC_CMR) RC Compare Effect on TIOA */
#define   TC_CMR_ACPC_NONE (0x0u << 18) /**< \brief (TC_CMR) None */
#define   TC_CMR_ACPC_SET (0x1u << 18) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ACPC_CLEAR (0x2u << 18) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ACPC_TOGGLE (0x3u << 18) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_AEEVT_Pos 20
#define TC_CMR_AEEVT_Msk (0x3u << TC_CMR_AEEVT_Pos) /**< \brief (TC_CMR) External Event Effect on TIOA */
#define   TC_CMR_AEEVT_NONE (0x0u << 20) /**< \brief (TC_CMR) None */
#define   TC_CMR_AEEVT_SET (0x1u << 20) /**< \brief (TC_CMR) Set */
#define   TC_CMR_AEEVT_CLEAR (0x2u << 20) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_AEEVT_TOGGLE (0x3u << 20) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_ASWTRG_Pos 22
#define TC_CMR_ASWTRG_Msk (0x3u << TC_CMR_ASWTRG_Pos) /**< \brief (TC_CMR) Software Trigger Effect on TIOA */
#define   TC_CMR_ASWTRG_NONE (0x0u << 22) /**< \brief (TC_CMR) None */
#define   TC_CMR_ASWTRG_SET (0x1u << 22) /**< \brief (TC_CMR) Set */
#define   TC_CMR_ASWTRG_CLEAR (0x2u << 22) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_ASWTRG_TOGGLE (0x3u << 22) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BCPB_Pos 24
#define TC_CMR_BCPB_Msk (0x3u << TC_CMR_BCPB_Pos) /**< \brief (TC_CMR) RB Compare Effect on TIOB */
#define   TC_CMR_BCPB_NONE (0x0u << 24) /**< \brief (TC_CMR) None */
#define   TC_CMR_BCPB_SET (0x1u << 24) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BCPB_CLEAR (0x2u << 24) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BCPB_TOGGLE (0x3u << 24) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BCPC_Pos 26
#define TC_CMR_BCPC_Msk (0x3u << TC_CMR_BCPC_Pos) /**< \brief (TC_CMR) RC Compare Effect on TIOB */
#define   TC_CMR_BCPC_NONE (0x0u << 26) /**< \brief (TC_CMR) None */
#define   TC_CMR_BCPC_SET (0x1u << 26) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BCPC_CLEAR (0x2u << 26) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BCPC_TOGGLE (0x3u << 26) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BEEVT_Pos 28
#define TC_CMR_BEEVT_Msk (0x3u << TC_CMR_BEEVT_Pos) /**< \brief (TC_CMR) External Event Effect on TIOB */
#define   TC_CMR_BEEVT_NONE (0x0u << 28) /**< \brief (TC_CMR) None */
#define   TC_CMR_BEEVT_SET (0x1u << 28) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BEEVT_CLEAR (0x2u << 28) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BEEVT_TOGGLE (0x3u << 28) /**< \brief (TC_CMR) Toggle */
#define TC_CMR_BSWTRG_Pos 30
#define TC_CMR_BSWTRG_Msk (0x3u << TC_CMR_BSWTRG_Pos) /**< \brief (TC_CMR) Software Trigger Effect on TIOB */
#define   TC_CMR_BSWTRG_NONE (0x0u << 30) /**< \brief (TC_CMR) None */
#define   TC_CMR_BSWTRG_SET (0x1u << 30) /**< \brief (TC_CMR) Set */
#define   TC_CMR_BSWTRG_CLEAR (0x2u << 30) /**< \brief (TC_CMR) Clear */
#define   TC_CMR_BSWTRG_TOGGLE (0x3u << 30) /**< \brief (TC_CMR) Toggle */
/* -------- TC_SMMR : (TC Offset: N/A) Stepper Motor Mode Register -------- */
#define TC_SMMR_GCEN (0x1u << 0) /**< \brief (TC_SMMR) Gray Count Enable */
#define TC_SMMR_DOWN (0x1u << 1) /**< \brief (TC_SMMR) DOWN Count */
/* -------- TC_CV : (TC Offset: N/A) Counter Value -------- */
#define TC_CV_CV_Pos 0
#define TC_CV_CV_Msk (0xffffffffu << TC_CV_CV_Pos) /**< \brief (TC_CV) Counter Value */
/* -------- TC_RA : (TC Offset: N/A) Register A -------- */
#define TC_RA_RA_Pos 0
#define TC_RA_RA_Msk (0xffffffffu << TC_RA_RA_Pos) /**< \brief (TC_RA) Register A */
#define TC_RA_RA(value) ((TC_RA_RA_Msk & ((value) << TC_RA_RA_Pos)))
/* -------- TC_RB : (TC Offset: N/A) Register B -------- */
#define TC_RB_RB_Pos 0
#define TC_RB_RB_Msk (0xffffffffu << TC_RB_RB_Pos) /**< \brief (TC_RB) Register B */
#define TC_RB_RB(value) ((TC_RB_RB_Msk & ((value) << TC_RB_RB_Pos)))
/* -------- TC_RC : (TC Offset: N/A) Register C -------- */
#define TC_RC_RC_Pos 0
#define TC_RC_RC_Msk (0xffffffffu << TC_RC_RC_Pos) /**< \brief (TC_RC) Register C */
#define TC_RC_RC(value) ((TC_RC_RC_Msk & ((value) << TC_RC_RC_Pos)))
/* -------- TC_SR : (TC Offset: N/A) Status Register -------- */
#define TC_SR_COVFS (0x1u << 0) /**< \brief (TC_SR) Counter Overflow Status */
#define TC_SR_LOVRS (0x1u << 1) /**< \brief (TC_SR) Load Overrun Status */
#define TC_SR_CPAS (0x1u << 2) /**< \brief (TC_SR) RA Compare Status */
#define TC_SR_CPBS (0x1u << 3) /**< \brief (TC_SR) RB Compare Status */
#define TC_SR_CPCS (0x1u << 4) /**< \brief (TC_SR) RC Compare Status */
#define TC_SR_LDRAS (0x1u << 5) /**< \brief (TC_SR) RA Loading Status */
#define TC_SR_LDRBS (0x1u << 6) /**< \brief (TC_SR) RB Loading Status */
#define TC_SR_ETRGS (0x1u << 7) /**< \brief (TC_SR) External Trigger Status */
#define TC_SR_ENDRX (0x1u << 8) /**< \brief (TC_SR) End of Receiver Transfer */
#define TC_SR_RXBUFF (0x1u << 9) /**< \brief (TC_SR) Reception Buffer Full */
#define TC_SR_CLKSTA (0x1u << 16) /**< \brief (TC_SR) Clock Enabling Status */
#define TC_SR_MTIOA (0x1u << 17) /**< \brief (TC_SR) TIOA Mirror */
#define TC_SR_MTIOB (0x1u << 18) /**< \brief (TC_SR) TIOB Mirror */
/* -------- TC_IER : (TC Offset: N/A) Interrupt Enable Register -------- */
#define TC_IER_COVFS (0x1u << 0) /**< \brief (TC_IER) Counter Overflow */
#define TC_IER_LOVRS (0x1u << 1) /**< \brief (TC_IER) Load Overrun */
#define TC_IER_CPAS (0x1u << 2) /**< \brief (TC_IER) RA Compare */
#define TC_IER_CPBS (0x1u << 3) /**< \brief (TC_IER) RB Compare */
#define TC_IER_CPCS (0x1u << 4) /**< \brief (TC_IER) RC Compare */
#define TC_IER_LDRAS (0x1u << 5) /**< \brief (TC_IER) RA Loading */
#define TC_IER_LDRBS (0x1u << 6) /**< \brief (TC_IER) RB Loading */
#define TC_IER_ETRGS (0x1u << 7) /**< \brief (TC_IER) External Trigger */
#define TC_IER_ENDRX (0x1u << 8) /**< \brief (TC_IER) End of Receiver Transfer */
#define TC_IER_RXBUFF (0x1u << 9) /**< \brief (TC_IER) Reception Buffer Full */
/* -------- TC_IDR : (TC Offset: N/A) Interrupt Disable Register -------- */
#define TC_IDR_COVFS (0x1u << 0) /**< \brief (TC_IDR) Counter Overflow */
#define TC_IDR_LOVRS (0x1u << 1) /**< \brief (TC_IDR) Load Overrun */
#define TC_IDR_CPAS (0x1u << 2) /**< \brief (TC_IDR) RA Compare */
#define TC_IDR_CPBS (0x1u << 3) /**< \brief (TC_IDR) RB Compare */
#define TC_IDR_CPCS (0x1u << 4) /**< \brief (TC_IDR) RC Compare */
#define TC_IDR_LDRAS (0x1u << 5) /**< \brief (TC_IDR) RA Loading */
#define TC_IDR_LDRBS (0x1u << 6) /**< \brief (TC_IDR) RB Loading */
#define TC_IDR_ETRGS (0x1u << 7) /**< \brief (TC_IDR) External Trigger */
#define TC_IDR_ENDRX (0x1u << 8) /**< \brief (TC_IDR) End of Receiver Transfer */
#define TC_IDR_RXBUFF (0x1u << 9) /**< \brief (TC_IDR) Reception Buffer Full */
/* -------- TC_IMR : (TC Offset: N/A) Interrupt Mask Register -------- */
#define TC_IMR_COVFS (0x1u << 0) /**< \brief (TC_IMR) Counter Overflow */
#define TC_IMR_LOVRS (0x1u << 1) /**< \brief (TC_IMR) Load Overrun */
#define TC_IMR_CPAS (0x1u << 2) /**< \brief (TC_IMR) RA Compare */
#define TC_IMR_CPBS (0x1u << 3) /**< \brief (TC_IMR) RB Compare */
#define TC_IMR_CPCS (0x1u << 4) /**< \brief (TC_IMR) RC Compare */
#define TC_IMR_LDRAS (0x1u << 5) /**< \brief (TC_IMR) RA Loading */
#define TC_IMR_LDRBS (0x1u << 6) /**< \brief (TC_IMR) RB Loading */
#define TC_IMR_ETRGS (0x1u << 7) /**< \brief (TC_IMR) External Trigger */
#define TC_IMR_ENDRX (0x1u << 8) /**< \brief (TC_IMR) End of Receiver Transfer */
#define TC_IMR_RXBUFF (0x1u << 9) /**< \brief (TC_IMR) Reception Buffer Full */
/* -------- TC_BCR : (TC Offset: 0xC0) Block Control Register -------- */
#define TC_BCR_SYNC (0x1u << 0) /**< \brief (TC_BCR) Synchro Command */
/* -------- TC_BMR : (TC Offset: 0xC4) Block Mode Register -------- */
#define TC_BMR_TC0XC0S_Pos 0
#define TC_BMR_TC0XC0S_Msk (0x3u << TC_BMR_TC0XC0S_Pos) /**< \brief (TC_BMR) External Clock Signal 0 Selection */
#define   TC_BMR_TC0XC0S_TCLK0 (0x0u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TCLK0 */
#define   TC_BMR_TC0XC0S_TIOA1 (0x2u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TIOA1 */
#define   TC_BMR_TC0XC0S_TIOA2 (0x3u << 0) /**< \brief (TC_BMR) Signal connected to XC0: TIOA2 */
#define TC_BMR_TC1XC1S_Pos 2
#define TC_BMR_TC1XC1S_Msk (0x3u << TC_BMR_TC1XC1S_Pos) /**< \brief (TC_BMR) External Clock Signal 1 Selection */
#define   TC_BMR_TC1XC1S_TCLK1 (0x0u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TCLK1 */
#define   TC_BMR_TC1XC1S_TIOA0 (0x2u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TIOA0 */
#define   TC_BMR_TC1XC1S_TIOA2 (0x3u << 2) /**< \brief (TC_BMR) Signal connected to XC1: TIOA2 */
#define TC_BMR_TC2XC2S_Pos 4
#define TC_BMR_TC2XC2S_Msk (0x3u << TC_BMR_TC2XC2S_Pos) /**< \brief (TC_BMR) External Clock Signal 2 Selection */
#define   TC_BMR_TC2XC2S_TCLK2 (0x0u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TCLK2 */
#define   TC_BMR_TC2XC2S_TIOA0 (0x2u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TIOA0 */
#define   TC_BMR_TC2XC2S_TIOA1 (0x3u << 4) /**< \brief (TC_BMR) Signal connected to XC2: TIOA1 */
/* -------- TC_WPMR : (TC Offset: 0xE4) Write Protection Mode Register -------- */
#define TC_WPMR_WPEN (0x1u << 0) /**< \brief (TC_WPMR) Write Protect Enable */
#define TC_WPMR_WPKEY_Pos 8
#define TC_WPMR_WPKEY_Msk (0xffffffu << TC_WPMR_WPKEY_Pos) /**< \brief (TC_WPMR) Write Protect KEY */
#define   TC_WPMR_WPKEY_PASSWD (0x54494Du << 8) /**< \brief (TC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. */
/* -------- TC_RPR0 : (TC Offset: 0x100) Receive Pointer Register (pdc = 0) -------- */
#define TC_RPR0_RXPTR_Pos 0
#define TC_RPR0_RXPTR_Msk (0xffffffffu << TC_RPR0_RXPTR_Pos) /**< \brief (TC_RPR0) Receive Pointer Register */
#define TC_RPR0_RXPTR(value) ((TC_RPR0_RXPTR_Msk & ((value) << TC_RPR0_RXPTR_Pos)))
/* -------- TC_RCR0 : (TC Offset: 0x104) Receive Counter Register (pdc = 0) -------- */
#define TC_RCR0_RXCTR_Pos 0
#define TC_RCR0_RXCTR_Msk (0xffffu << TC_RCR0_RXCTR_Pos) /**< \brief (TC_RCR0) Receive Counter Register */
#define TC_RCR0_RXCTR(value) ((TC_RCR0_RXCTR_Msk & ((value) << TC_RCR0_RXCTR_Pos)))
/* -------- TC_RNPR0 : (TC Offset: 0x110) Receive Next Pointer Register (pdc = 0) -------- */
#define TC_RNPR0_RXNPTR_Pos 0
#define TC_RNPR0_RXNPTR_Msk (0xffffffffu << TC_RNPR0_RXNPTR_Pos) /**< \brief (TC_RNPR0) Receive Next Pointer */
#define TC_RNPR0_RXNPTR(value) ((TC_RNPR0_RXNPTR_Msk & ((value) << TC_RNPR0_RXNPTR_Pos)))
/* -------- TC_RNCR0 : (TC Offset: 0x114) Receive Next Counter Register (pdc = 0) -------- */
#define TC_RNCR0_RXNCTR_Pos 0
#define TC_RNCR0_RXNCTR_Msk (0xffffu << TC_RNCR0_RXNCTR_Pos) /**< \brief (TC_RNCR0) Receive Next Counter */
#define TC_RNCR0_RXNCTR(value) ((TC_RNCR0_RXNCTR_Msk & ((value) << TC_RNCR0_RXNCTR_Pos)))
/* -------- TC_PTCR0 : (TC Offset: 0x120) Transfer Control Register (pdc = 0) -------- */
#define TC_PTCR0_RXTEN (0x1u << 0) /**< \brief (TC_PTCR0) Receiver Transfer Enable */
#define TC_PTCR0_RXTDIS (0x1u << 1) /**< \brief (TC_PTCR0) Receiver Transfer Disable */
#define TC_PTCR0_TXTEN (0x1u << 8) /**< \brief (TC_PTCR0) Transmitter Transfer Enable */
#define TC_PTCR0_TXTDIS (0x1u << 9) /**< \brief (TC_PTCR0) Transmitter Transfer Disable */
#define TC_PTCR0_RXCBEN (0x1u << 16) /**< \brief (TC_PTCR0) Receiver Circular Buffer Enable */
#define TC_PTCR0_RXCBDIS (0x1u << 17) /**< \brief (TC_PTCR0) Receiver Circular Buffer Disable */
#define TC_PTCR0_TXCBEN (0x1u << 18) /**< \brief (TC_PTCR0) Transmitter Circular Buffer Enable */
#define TC_PTCR0_TXCBDIS (0x1u << 19) /**< \brief (TC_PTCR0) Transmitter Circular Buffer Disable */
#define TC_PTCR0_ERRCLR (0x1u << 24) /**< \brief (TC_PTCR0) Transfer Bus Error Clear */
/* -------- TC_PTSR0 : (TC Offset: 0x124) Transfer Status Register (pdc = 0) -------- */
#define TC_PTSR0_RXTEN (0x1u << 0) /**< \brief (TC_PTSR0) Receiver Transfer Enable */
#define TC_PTSR0_TXTEN (0x1u << 8) /**< \brief (TC_PTSR0) Transmitter Transfer Enable */
#define TC_PTSR0_RXCBEN (0x1u << 16) /**< \brief (TC_PTSR0) Receiver Transfer Enable */
#define TC_PTSR0_TXCBEN (0x1u << 18) /**< \brief (TC_PTSR0) Transmitter Transfer Enable */
#define TC_PTSR0_ERR (0x1u << 24) /**< \brief (TC_PTSR0) Transfer Bus Error */

/*@}*/


#endif /* _SAMG54_TC_COMPONENT_ */
