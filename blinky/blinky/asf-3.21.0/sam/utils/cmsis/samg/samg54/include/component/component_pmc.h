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

#ifndef _SAMG54_PMC_COMPONENT_
#define _SAMG54_PMC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Power Management Controller */
/* ============================================================================= */
/** \addtogroup SAMG54_PMC Power Management Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Pmc hardware registers */
typedef struct {
  __O  uint32_t PMC_SCER;       /**< \brief (Pmc Offset: 0x0000) System Clock Enable Register */
  __O  uint32_t PMC_SCDR;       /**< \brief (Pmc Offset: 0x0004) System Clock Disable Register */
  __I  uint32_t PMC_SCSR;       /**< \brief (Pmc Offset: 0x0008) System Clock Status Register */
  __I  uint32_t Reserved1[1];
  __O  uint32_t PMC_PCER0;      /**< \brief (Pmc Offset: 0x0010) Peripheral Clock Enable Register 0 */
  __O  uint32_t PMC_PCDR0;      /**< \brief (Pmc Offset: 0x0014) Peripheral Clock Disable Register 0 */
  __I  uint32_t PMC_PCSR0;      /**< \brief (Pmc Offset: 0x0018) Peripheral Clock Status Register 0 */
  __I  uint32_t Reserved2[1];
  __IO uint32_t CKGR_MOR;       /**< \brief (Pmc Offset: 0x0020) Main Oscillator Register */
  __IO uint32_t CKGR_MCFR;      /**< \brief (Pmc Offset: 0x0024) Main Clock Frequency Register */
  __IO uint32_t CKGR_PLLAR;     /**< \brief (Pmc Offset: 0x0028) PLLA Register */
  __I  uint32_t Reserved3[1];
  __IO uint32_t PMC_MCKR;       /**< \brief (Pmc Offset: 0x0030) Master Clock Register */
  __I  uint32_t Reserved4[3];
  __IO uint32_t PMC_PCK[3];     /**< \brief (Pmc Offset: 0x0040) Programmable Clock 0 Register */
  __I  uint32_t Reserved5[5];
  __O  uint32_t PMC_IER;        /**< \brief (Pmc Offset: 0x0060) Interrupt Enable Register */
  __O  uint32_t PMC_IDR;        /**< \brief (Pmc Offset: 0x0064) Interrupt Disable Register */
  __I  uint32_t PMC_SR;         /**< \brief (Pmc Offset: 0x0068) Status Register */
  __I  uint32_t PMC_IMR;        /**< \brief (Pmc Offset: 0x006C) Interrupt Mask Register */
  __IO uint32_t PMC_FSMR;       /**< \brief (Pmc Offset: 0x0070) Fast Startup Mode Register */
  __IO uint32_t PMC_FSPR;       /**< \brief (Pmc Offset: 0x0074) Fast Startup Polarity Register */
  __O  uint32_t PMC_FOCR;       /**< \brief (Pmc Offset: 0x0078) Fault Output Clear Register */
  __I  uint32_t Reserved6[26];
  __IO uint32_t PMC_WPMR;       /**< \brief (Pmc Offset: 0x00E4) Write Protection Mode Register */
  __I  uint32_t PMC_WPSR;       /**< \brief (Pmc Offset: 0x00E8) Write Protection Status Register */
  __I  uint32_t Reserved7[9];
  __IO uint32_t PMC_OCR;        /**< \brief (Pmc Offset: 0x0110) Oscillator Calibration Register */
  __O  uint32_t PMC_SLPWK_ER0;  /**< \brief (Pmc Offset: 0x114) SleepWalking Enable Register 0 */
  __O  uint32_t PMC_SLPWK_DR0;  /**< \brief (Pmc Offset: 0x118) SleepWalking Disable Register 0 */
  __I  uint32_t PMC_SLPWK_SR0;  /**< \brief (Pmc Offset: 0x11C) SleepWalking Status Register 0 */
  __I  uint32_t PMC_SLPWK_ASR0; /**< \brief (Pmc Offset: 0x120) SleepWalking Activity Status Register 0 */
  __I  uint32_t Reserved8[3];
  __IO uint32_t PMC_PMMR;       /**< \brief (Pmc Offset: 0x130) PLL Maximum Multiplier Value Register */
} Pmc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PMC_SCER : (PMC Offset: 0x0000) System Clock Enable Register -------- */
#define PMC_SCER_PCK0 (0x1u << 8) /**< \brief (PMC_SCER) Programmable Clock 0 Output Enable */
#define PMC_SCER_PCK1 (0x1u << 9) /**< \brief (PMC_SCER) Programmable Clock 1 Output Enable */
#define PMC_SCER_PCK2 (0x1u << 10) /**< \brief (PMC_SCER) Programmable Clock 2 Output Enable */
/* -------- PMC_SCDR : (PMC Offset: 0x0004) System Clock Disable Register -------- */
#define PMC_SCDR_PCK0 (0x1u << 8) /**< \brief (PMC_SCDR) Programmable Clock 0 Output Disable */
#define PMC_SCDR_PCK1 (0x1u << 9) /**< \brief (PMC_SCDR) Programmable Clock 1 Output Disable */
#define PMC_SCDR_PCK2 (0x1u << 10) /**< \brief (PMC_SCDR) Programmable Clock 2 Output Disable */
/* -------- PMC_SCSR : (PMC Offset: 0x0008) System Clock Status Register -------- */
#define PMC_SCSR_PCK0 (0x1u << 8) /**< \brief (PMC_SCSR) Programmable Clock 0 Output Status */
#define PMC_SCSR_PCK1 (0x1u << 9) /**< \brief (PMC_SCSR) Programmable Clock 1 Output Status */
#define PMC_SCSR_PCK2 (0x1u << 10) /**< \brief (PMC_SCSR) Programmable Clock 2 Output Status */
/* -------- PMC_PCER0 : (PMC Offset: 0x0010) Peripheral Clock Enable Register 0 -------- */
#define PMC_PCER0_PID8 (0x1u << 8) /**< \brief (PMC_PCER0) Peripheral Clock 8 Enable */
#define PMC_PCER0_PID9 (0x1u << 9) /**< \brief (PMC_PCER0) Peripheral Clock 9 Enable */
#define PMC_PCER0_PID10 (0x1u << 10) /**< \brief (PMC_PCER0) Peripheral Clock 10 Enable */
#define PMC_PCER0_PID11 (0x1u << 11) /**< \brief (PMC_PCER0) Peripheral Clock 11 Enable */
#define PMC_PCER0_PID12 (0x1u << 12) /**< \brief (PMC_PCER0) Peripheral Clock 12 Enable */
#define PMC_PCER0_PID13 (0x1u << 13) /**< \brief (PMC_PCER0) Peripheral Clock 13 Enable */
#define PMC_PCER0_PID14 (0x1u << 14) /**< \brief (PMC_PCER0) Peripheral Clock 14 Enable */
#define PMC_PCER0_PID15 (0x1u << 15) /**< \brief (PMC_PCER0) Peripheral Clock 15 Enable */
#define PMC_PCER0_PID16 (0x1u << 16) /**< \brief (PMC_PCER0) Peripheral Clock 16 Enable */
#define PMC_PCER0_PID17 (0x1u << 17) /**< \brief (PMC_PCER0) Peripheral Clock 17 Enable */
#define PMC_PCER0_PID18 (0x1u << 18) /**< \brief (PMC_PCER0) Peripheral Clock 18 Enable */
#define PMC_PCER0_PID19 (0x1u << 19) /**< \brief (PMC_PCER0) Peripheral Clock 19 Enable */
#define PMC_PCER0_PID20 (0x1u << 20) /**< \brief (PMC_PCER0) Peripheral Clock 20 Enable */
#define PMC_PCER0_PID21 (0x1u << 21) /**< \brief (PMC_PCER0) Peripheral Clock 21 Enable */
#define PMC_PCER0_PID22 (0x1u << 22) /**< \brief (PMC_PCER0) Peripheral Clock 22 Enable */
#define PMC_PCER0_PID23 (0x1u << 23) /**< \brief (PMC_PCER0) Peripheral Clock 23 Enable */
#define PMC_PCER0_PID24 (0x1u << 24) /**< \brief (PMC_PCER0) Peripheral Clock 24 Enable */
#define PMC_PCER0_PID25 (0x1u << 25) /**< \brief (PMC_PCER0) Peripheral Clock 25 Enable */
#define PMC_PCER0_PID26 (0x1u << 26) /**< \brief (PMC_PCER0) Peripheral Clock 26 Enable */
#define PMC_PCER0_PID27 (0x1u << 27) /**< \brief (PMC_PCER0) Peripheral Clock 27 Enable */
#define PMC_PCER0_PID28 (0x1u << 28) /**< \brief (PMC_PCER0) Peripheral Clock 28 Enable */
#define PMC_PCER0_PID29 (0x1u << 29) /**< \brief (PMC_PCER0) Peripheral Clock 29 Enable */
/* -------- PMC_PCDR0 : (PMC Offset: 0x0014) Peripheral Clock Disable Register 0 -------- */
#define PMC_PCDR0_PID8 (0x1u << 8) /**< \brief (PMC_PCDR0) Peripheral Clock 8 Disable */
#define PMC_PCDR0_PID9 (0x1u << 9) /**< \brief (PMC_PCDR0) Peripheral Clock 9 Disable */
#define PMC_PCDR0_PID10 (0x1u << 10) /**< \brief (PMC_PCDR0) Peripheral Clock 10 Disable */
#define PMC_PCDR0_PID11 (0x1u << 11) /**< \brief (PMC_PCDR0) Peripheral Clock 11 Disable */
#define PMC_PCDR0_PID12 (0x1u << 12) /**< \brief (PMC_PCDR0) Peripheral Clock 12 Disable */
#define PMC_PCDR0_PID13 (0x1u << 13) /**< \brief (PMC_PCDR0) Peripheral Clock 13 Disable */
#define PMC_PCDR0_PID14 (0x1u << 14) /**< \brief (PMC_PCDR0) Peripheral Clock 14 Disable */
#define PMC_PCDR0_PID15 (0x1u << 15) /**< \brief (PMC_PCDR0) Peripheral Clock 15 Disable */
#define PMC_PCDR0_PID16 (0x1u << 16) /**< \brief (PMC_PCDR0) Peripheral Clock 16 Disable */
#define PMC_PCDR0_PID17 (0x1u << 17) /**< \brief (PMC_PCDR0) Peripheral Clock 17 Disable */
#define PMC_PCDR0_PID18 (0x1u << 18) /**< \brief (PMC_PCDR0) Peripheral Clock 18 Disable */
#define PMC_PCDR0_PID19 (0x1u << 19) /**< \brief (PMC_PCDR0) Peripheral Clock 19 Disable */
#define PMC_PCDR0_PID20 (0x1u << 20) /**< \brief (PMC_PCDR0) Peripheral Clock 20 Disable */
#define PMC_PCDR0_PID21 (0x1u << 21) /**< \brief (PMC_PCDR0) Peripheral Clock 21 Disable */
#define PMC_PCDR0_PID22 (0x1u << 22) /**< \brief (PMC_PCDR0) Peripheral Clock 22 Disable */
#define PMC_PCDR0_PID23 (0x1u << 23) /**< \brief (PMC_PCDR0) Peripheral Clock 23 Disable */
#define PMC_PCDR0_PID24 (0x1u << 24) /**< \brief (PMC_PCDR0) Peripheral Clock 24 Disable */
#define PMC_PCDR0_PID25 (0x1u << 25) /**< \brief (PMC_PCDR0) Peripheral Clock 25 Disable */
#define PMC_PCDR0_PID26 (0x1u << 26) /**< \brief (PMC_PCDR0) Peripheral Clock 26 Disable */
#define PMC_PCDR0_PID27 (0x1u << 27) /**< \brief (PMC_PCDR0) Peripheral Clock 27 Disable */
#define PMC_PCDR0_PID28 (0x1u << 28) /**< \brief (PMC_PCDR0) Peripheral Clock 28 Disable */
#define PMC_PCDR0_PID29 (0x1u << 29) /**< \brief (PMC_PCDR0) Peripheral Clock 29 Disable */
/* -------- PMC_PCSR0 : (PMC Offset: 0x0018) Peripheral Clock Status Register 0 -------- */
#define PMC_PCSR0_PID8 (0x1u << 8) /**< \brief (PMC_PCSR0) Peripheral Clock 8 Status */
#define PMC_PCSR0_PID9 (0x1u << 9) /**< \brief (PMC_PCSR0) Peripheral Clock 9 Status */
#define PMC_PCSR0_PID10 (0x1u << 10) /**< \brief (PMC_PCSR0) Peripheral Clock 10 Status */
#define PMC_PCSR0_PID11 (0x1u << 11) /**< \brief (PMC_PCSR0) Peripheral Clock 11 Status */
#define PMC_PCSR0_PID12 (0x1u << 12) /**< \brief (PMC_PCSR0) Peripheral Clock 12 Status */
#define PMC_PCSR0_PID13 (0x1u << 13) /**< \brief (PMC_PCSR0) Peripheral Clock 13 Status */
#define PMC_PCSR0_PID14 (0x1u << 14) /**< \brief (PMC_PCSR0) Peripheral Clock 14 Status */
#define PMC_PCSR0_PID15 (0x1u << 15) /**< \brief (PMC_PCSR0) Peripheral Clock 15 Status */
#define PMC_PCSR0_PID16 (0x1u << 16) /**< \brief (PMC_PCSR0) Peripheral Clock 16 Status */
#define PMC_PCSR0_PID17 (0x1u << 17) /**< \brief (PMC_PCSR0) Peripheral Clock 17 Status */
#define PMC_PCSR0_PID18 (0x1u << 18) /**< \brief (PMC_PCSR0) Peripheral Clock 18 Status */
#define PMC_PCSR0_PID19 (0x1u << 19) /**< \brief (PMC_PCSR0) Peripheral Clock 19 Status */
#define PMC_PCSR0_PID20 (0x1u << 20) /**< \brief (PMC_PCSR0) Peripheral Clock 20 Status */
#define PMC_PCSR0_PID21 (0x1u << 21) /**< \brief (PMC_PCSR0) Peripheral Clock 21 Status */
#define PMC_PCSR0_PID22 (0x1u << 22) /**< \brief (PMC_PCSR0) Peripheral Clock 22 Status */
#define PMC_PCSR0_PID23 (0x1u << 23) /**< \brief (PMC_PCSR0) Peripheral Clock 23 Status */
#define PMC_PCSR0_PID24 (0x1u << 24) /**< \brief (PMC_PCSR0) Peripheral Clock 24 Status */
#define PMC_PCSR0_PID25 (0x1u << 25) /**< \brief (PMC_PCSR0) Peripheral Clock 25 Status */
#define PMC_PCSR0_PID26 (0x1u << 26) /**< \brief (PMC_PCSR0) Peripheral Clock 26 Status */
#define PMC_PCSR0_PID27 (0x1u << 27) /**< \brief (PMC_PCSR0) Peripheral Clock 27 Status */
#define PMC_PCSR0_PID28 (0x1u << 28) /**< \brief (PMC_PCSR0) Peripheral Clock 28 Status */
#define PMC_PCSR0_PID29 (0x1u << 29) /**< \brief (PMC_PCSR0) Peripheral Clock 29 Status */
/* -------- CKGR_MOR : (PMC Offset: 0x0020) Main Oscillator Register -------- */
#define CKGR_MOR_MOSCXTEN (0x1u << 0) /**< \brief (CKGR_MOR) Main Crystal Oscillator Enable */
#define CKGR_MOR_MOSCXTBY (0x1u << 1) /**< \brief (CKGR_MOR) Main Crystal Oscillator Bypass */
#define CKGR_MOR_WAITMODE (0x1u << 2) /**< \brief (CKGR_MOR) Wait Mode Command */
#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Enable */
#define CKGR_MOR_MOSCRCF_Pos 4
#define CKGR_MOR_MOSCRCF_Msk (0x7u << CKGR_MOR_MOSCRCF_Pos) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Frequency Selection */
#define   CKGR_MOR_MOSCRCF_8_MHz (0x0u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 8 MHz (default) */
#define   CKGR_MOR_MOSCRCF_16_MHz (0x1u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 16 MHz */
#define   CKGR_MOR_MOSCRCF_24_MHz (0x2u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 24 MHz */
#define CKGR_MOR_MOSCXTST_Pos 8
#define CKGR_MOR_MOSCXTST_Msk (0xffu << CKGR_MOR_MOSCXTST_Pos) /**< \brief (CKGR_MOR) Main Crystal Oscillator Start-up Time */
#define CKGR_MOR_MOSCXTST(value) ((CKGR_MOR_MOSCXTST_Msk & ((value) << CKGR_MOR_MOSCXTST_Pos)))
#define CKGR_MOR_KEY_Pos 16
#define CKGR_MOR_KEY_Msk (0xffu << CKGR_MOR_KEY_Pos) /**< \brief (CKGR_MOR) Write Access Password */
#define   CKGR_MOR_KEY_PASSWD (0x37u << 16) /**< \brief (CKGR_MOR) Writing any other value in this field aborts the write operation.Always reads as 0. */
#define CKGR_MOR_MOSCSEL (0x1u << 24) /**< \brief (CKGR_MOR) Main Oscillator Selection */
#define CKGR_MOR_CFDEN (0x1u << 25) /**< \brief (CKGR_MOR) Clock Failure Detector Enable */
/* -------- CKGR_MCFR : (PMC Offset: 0x0024) Main Clock Frequency Register -------- */
#define CKGR_MCFR_MAINF_Pos 0
#define CKGR_MCFR_MAINF_Msk (0xffffu << CKGR_MCFR_MAINF_Pos) /**< \brief (CKGR_MCFR) Main Clock Frequency */
#define CKGR_MCFR_MAINF(value) ((CKGR_MCFR_MAINF_Msk & ((value) << CKGR_MCFR_MAINF_Pos)))
#define CKGR_MCFR_MAINFRDY (0x1u << 16) /**< \brief (CKGR_MCFR) Main Clock Ready */
#define CKGR_MCFR_RCMEAS (0x1u << 20) /**< \brief (CKGR_MCFR) RC Oscillator Frequency Measure (write-only) */
/* -------- CKGR_PLLAR : (PMC Offset: 0x0028) PLLA Register -------- */
#define CKGR_PLLAR_PLLAEN_Pos 0
#define CKGR_PLLAR_PLLAEN_Msk (0xffu << CKGR_PLLAR_PLLAEN_Pos) /**< \brief (CKGR_PLLAR) PLLA Control */
#define CKGR_PLLAR_PLLAEN(value) ((CKGR_PLLAR_PLLAEN_Msk & ((value) << CKGR_PLLAR_PLLAEN_Pos)))
#define CKGR_PLLAR_PLLACOUNT_Pos 8
#define CKGR_PLLAR_PLLACOUNT_Msk (0x3fu << CKGR_PLLAR_PLLACOUNT_Pos) /**< \brief (CKGR_PLLAR) PLLA Counter */
#define CKGR_PLLAR_PLLACOUNT(value) ((CKGR_PLLAR_PLLACOUNT_Msk & ((value) << CKGR_PLLAR_PLLACOUNT_Pos)))
#define CKGR_PLLAR_MULA_Pos 16
#define CKGR_PLLAR_MULA_Msk (0xfffu << CKGR_PLLAR_MULA_Pos) /**< \brief (CKGR_PLLAR) PLLA Multiplier */
#define CKGR_PLLAR_MULA(value) ((CKGR_PLLAR_MULA_Msk & ((value) << CKGR_PLLAR_MULA_Pos)))
/* -------- PMC_MCKR : (PMC Offset: 0x0030) Master Clock Register -------- */
#define PMC_MCKR_CSS_Pos 0
#define PMC_MCKR_CSS_Msk (0x3u << PMC_MCKR_CSS_Pos) /**< \brief (PMC_MCKR) Master Clock Source Selection */
#define   PMC_MCKR_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_MCKR) Slow Clock is selected */
#define   PMC_MCKR_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_MCKR) Main Clock is selected */
#define   PMC_MCKR_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_MCKR) PLLA Clock is selected */
#define PMC_MCKR_PRES_Pos 4
#define PMC_MCKR_PRES_Msk (0x7u << PMC_MCKR_PRES_Pos) /**< \brief (PMC_MCKR) Processor Clock Prescaler */
#define   PMC_MCKR_PRES_CLK_1 (0x0u << 4) /**< \brief (PMC_MCKR) Selected clock */
#define   PMC_MCKR_PRES_CLK_2 (0x1u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 2 */
#define   PMC_MCKR_PRES_CLK_4 (0x2u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 4 */
#define   PMC_MCKR_PRES_CLK_8 (0x3u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 8 */
#define   PMC_MCKR_PRES_CLK_16 (0x4u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 16 */
#define   PMC_MCKR_PRES_CLK_32 (0x5u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 32 */
#define   PMC_MCKR_PRES_CLK_64 (0x6u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 64 */
#define   PMC_MCKR_PRES_CLK_3 (0x7u << 4) /**< \brief (PMC_MCKR) Selected clock divided by 3 */
#define PMC_MCKR_PLLADIV2 (0x1u << 12) /**< \brief (PMC_MCKR) PLLA Divisor by 2 */
/* -------- PMC_PCK[3] : (PMC Offset: 0x0040) Programmable Clock 0 Register -------- */
#define PMC_PCK_CSS_Pos 0
#define PMC_PCK_CSS_Msk (0x7u << PMC_PCK_CSS_Pos) /**< \brief (PMC_PCK[3]) Master Clock Source Selection */
#define   PMC_PCK_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_PCK[3]) Slow Clock is selected */
#define   PMC_PCK_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_PCK[3]) Main Clock is selected */
#define   PMC_PCK_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_PCK[3]) PLLA Clock is selected */
#define   PMC_PCK_CSS_MCK (0x4u << 0) /**< \brief (PMC_PCK[3]) Master Clock is selected */
#define PMC_PCK_PRES_Pos 4
#define PMC_PCK_PRES_Msk (0x7u << PMC_PCK_PRES_Pos) /**< \brief (PMC_PCK[3]) Programmable Clock Prescaler */
#define   PMC_PCK_PRES_CLK_1 (0x0u << 4) /**< \brief (PMC_PCK[3]) Selected clock */
#define   PMC_PCK_PRES_CLK_2 (0x1u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 2 */
#define   PMC_PCK_PRES_CLK_4 (0x2u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 4 */
#define   PMC_PCK_PRES_CLK_8 (0x3u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 8 */
#define   PMC_PCK_PRES_CLK_16 (0x4u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 16 */
#define   PMC_PCK_PRES_CLK_32 (0x5u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 32 */
#define   PMC_PCK_PRES_CLK_64 (0x6u << 4) /**< \brief (PMC_PCK[3]) Selected clock divided by 64 */
/* -------- PMC_IER : (PMC Offset: 0x0060) Interrupt Enable Register -------- */
#define PMC_IER_MOSCXTS (0x1u << 0) /**< \brief (PMC_IER) Main Crystal Oscillator Status Interrupt Enable */
#define PMC_IER_LOCKA (0x1u << 1) /**< \brief (PMC_IER) PLLA Lock Interrupt Enable */
#define PMC_IER_MCKRDY (0x1u << 3) /**< \brief (PMC_IER) Master Clock Ready Interrupt Enable */
#define PMC_IER_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IER) Programmable Clock Ready 0 Interrupt Enable */
#define PMC_IER_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IER) Programmable Clock Ready 1 Interrupt Enable */
#define PMC_IER_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IER) Programmable Clock Ready 2 Interrupt Enable */
#define PMC_IER_MOSCSELS (0x1u << 16) /**< \brief (PMC_IER) Main Oscillator Selection Status Interrupt Enable */
#define PMC_IER_MOSCRCS (0x1u << 17) /**< \brief (PMC_IER) Main On-Chip RC Status Interrupt Enable */
#define PMC_IER_CFDEV (0x1u << 18) /**< \brief (PMC_IER) Clock Failure Detector Event Interrupt Enable */
/* -------- PMC_IDR : (PMC Offset: 0x0064) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable */
#define PMC_IDR_LOCKA (0x1u << 1) /**< \brief (PMC_IDR) PLLA Lock Interrupt Disable */
#define PMC_IDR_MCKRDY (0x1u << 3) /**< \brief (PMC_IDR) Master Clock Ready Interrupt Disable */
#define PMC_IDR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable */
#define PMC_IDR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable */
#define PMC_IDR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IDR) Programmable Clock Ready 2 Interrupt Disable */
#define PMC_IDR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IDR) Main Oscillator Selection Status Interrupt Disable */
#define PMC_IDR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IDR) Main On-Chip RC Status Interrupt Disable */
#define PMC_IDR_CFDEV (0x1u << 18) /**< \brief (PMC_IDR) Clock Failure Detector Event Interrupt Disable */
/* -------- PMC_SR : (PMC Offset: 0x0068) Status Register -------- */
#define PMC_SR_MOSCXTS (0x1u << 0) /**< \brief (PMC_SR) Main XTAL Oscillator Status */
#define PMC_SR_LOCKA (0x1u << 1) /**< \brief (PMC_SR) PLLA Lock Status */
#define PMC_SR_MCKRDY (0x1u << 3) /**< \brief (PMC_SR) Master Clock Status */
#define PMC_SR_OSCSELS (0x1u << 7) /**< \brief (PMC_SR) Slow Clock Oscillator Selection */
#define PMC_SR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_SR) Programmable Clock Ready Status */
#define PMC_SR_MOSCSELS (0x1u << 16) /**< \brief (PMC_SR) Main Oscillator Selection Status */
#define PMC_SR_MOSCRCS (0x1u << 17) /**< \brief (PMC_SR) Main On-Chip RC Oscillator Status */
#define PMC_SR_CFDEV (0x1u << 18) /**< \brief (PMC_SR) Clock Failure Detector Event */
#define PMC_SR_CFDS (0x1u << 19) /**< \brief (PMC_SR) Clock Failure Detector Status */
#define PMC_SR_FOS (0x1u << 20) /**< \brief (PMC_SR) Clock Failure Detector Fault Output Status */
/* -------- PMC_IMR : (PMC Offset: 0x006C) Interrupt Mask Register -------- */
#define PMC_IMR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask */
#define PMC_IMR_LOCKA (0x1u << 1) /**< \brief (PMC_IMR) PLLA Lock Interrupt Mask */
#define PMC_IMR_MCKRDY (0x1u << 3) /**< \brief (PMC_IMR) Master Clock Ready Interrupt Mask */
#define PMC_IMR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask */
#define PMC_IMR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask */
#define PMC_IMR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IMR) Programmable Clock Ready 2 Interrupt Mask */
#define PMC_IMR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IMR) Main Oscillator Selection Status Interrupt Mask */
#define PMC_IMR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IMR) Main On-Chip RC Status Interrupt Mask */
#define PMC_IMR_CFDEV (0x1u << 18) /**< \brief (PMC_IMR) Clock Failure Detector Event Interrupt Mask */
/* -------- PMC_FSMR : (PMC Offset: 0x0070) Fast Startup Mode Register -------- */
#define PMC_FSMR_FSTT0 (0x1u << 0) /**< \brief (PMC_FSMR) Fast Startup Input Enable 0 */
#define PMC_FSMR_FSTT1 (0x1u << 1) /**< \brief (PMC_FSMR) Fast Startup Input Enable 1 */
#define PMC_FSMR_FSTT2 (0x1u << 2) /**< \brief (PMC_FSMR) Fast Startup Input Enable 2 */
#define PMC_FSMR_FSTT3 (0x1u << 3) /**< \brief (PMC_FSMR) Fast Startup Input Enable 3 */
#define PMC_FSMR_FSTT4 (0x1u << 4) /**< \brief (PMC_FSMR) Fast Startup Input Enable 4 */
#define PMC_FSMR_FSTT5 (0x1u << 5) /**< \brief (PMC_FSMR) Fast Startup Input Enable 5 */
#define PMC_FSMR_FSTT6 (0x1u << 6) /**< \brief (PMC_FSMR) Fast Startup Input Enable 6 */
#define PMC_FSMR_FSTT7 (0x1u << 7) /**< \brief (PMC_FSMR) Fast Startup Input Enable 7 */
#define PMC_FSMR_FSTT8 (0x1u << 8) /**< \brief (PMC_FSMR) Fast Startup Input Enable 8 */
#define PMC_FSMR_FSTT9 (0x1u << 9) /**< \brief (PMC_FSMR) Fast Startup Input Enable 9 */
#define PMC_FSMR_FSTT10 (0x1u << 10) /**< \brief (PMC_FSMR) Fast Startup Input Enable 10 */
#define PMC_FSMR_FSTT11 (0x1u << 11) /**< \brief (PMC_FSMR) Fast Startup Input Enable 11 */
#define PMC_FSMR_FSTT12 (0x1u << 12) /**< \brief (PMC_FSMR) Fast Startup Input Enable 12 */
#define PMC_FSMR_FSTT13 (0x1u << 13) /**< \brief (PMC_FSMR) Fast Startup Input Enable 13 */
#define PMC_FSMR_FSTT14 (0x1u << 14) /**< \brief (PMC_FSMR) Fast Startup Input Enable 14 */
#define PMC_FSMR_FSTT15 (0x1u << 15) /**< \brief (PMC_FSMR) Fast Startup Input Enable 15 */
#define PMC_FSMR_RTTAL (0x1u << 16) /**< \brief (PMC_FSMR) RTT Alarm Enable */
#define PMC_FSMR_RTCAL (0x1u << 17) /**< \brief (PMC_FSMR) RTC Alarm Enable */
#define PMC_FSMR_LPM (0x1u << 20) /**< \brief (PMC_FSMR) Low-power Mode */
#define PMC_FSMR_FLPM_Pos 21
#define PMC_FSMR_FLPM_Msk (0x3u << PMC_FSMR_FLPM_Pos) /**< \brief (PMC_FSMR) Flash Low-power Mode */
#define   PMC_FSMR_FLPM_FLASH_STANDBY (0x0u << 21) /**< \brief (PMC_FSMR) Flash is in Standby Mode when system enters Wait Mode */
#define   PMC_FSMR_FLPM_FLASH_DEEP_POWERDOWN (0x1u << 21) /**< \brief (PMC_FSMR) Flash is in deep-power-down mode when system enters Wait Mode */
#define   PMC_FSMR_FLPM_FLASH_IDLE (0x2u << 21) /**< \brief (PMC_FSMR) idle mode */
/* -------- PMC_FSPR : (PMC Offset: 0x0074) Fast Startup Polarity Register -------- */
#define PMC_FSPR_FSTP0 (0x1u << 0) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP1 (0x1u << 1) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP2 (0x1u << 2) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP3 (0x1u << 3) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP4 (0x1u << 4) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP5 (0x1u << 5) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP6 (0x1u << 6) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP7 (0x1u << 7) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP8 (0x1u << 8) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP9 (0x1u << 9) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP10 (0x1u << 10) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP11 (0x1u << 11) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP12 (0x1u << 12) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP13 (0x1u << 13) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP14 (0x1u << 14) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
#define PMC_FSPR_FSTP15 (0x1u << 15) /**< \brief (PMC_FSPR) Fast Startup Input Polarityx */
/* -------- PMC_FOCR : (PMC Offset: 0x0078) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR (0x1u << 0) /**< \brief (PMC_FOCR) Fault Output Clear */
/* -------- PMC_WPMR : (PMC Offset: 0x00E4) Write Protection Mode Register -------- */
#define PMC_WPMR_WPEN (0x1u << 0) /**< \brief (PMC_WPMR) Write Protection Enable */
#define PMC_WPMR_WPKEY_Pos 8
#define PMC_WPMR_WPKEY_Msk (0xffffffu << PMC_WPMR_WPKEY_Pos) /**< \brief (PMC_WPMR) Write Protection Key */
#define   PMC_WPMR_WPKEY_PASSWD (0x504D43u << 8) /**< \brief (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. */
/* -------- PMC_WPSR : (PMC Offset: 0x00E8) Write Protection Status Register -------- */
#define PMC_WPSR_WPVS (0x1u << 0) /**< \brief (PMC_WPSR) Write Protection Violation Status */
#define PMC_WPSR_WPVSRC_Pos 8
#define PMC_WPSR_WPVSRC_Msk (0xffffu << PMC_WPSR_WPVSRC_Pos) /**< \brief (PMC_WPSR) Write Protection Violation Source */
/* -------- PMC_OCR : (PMC Offset: 0x0110) Oscillator Calibration Register -------- */
#define PMC_OCR_CAL8_Pos 0
#define PMC_OCR_CAL8_Msk (0x7fu << PMC_OCR_CAL8_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 8 MHz */
#define PMC_OCR_CAL8(value) ((PMC_OCR_CAL8_Msk & ((value) << PMC_OCR_CAL8_Pos)))
#define PMC_OCR_SEL8 (0x1u << 7) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 8 MHz */
#define PMC_OCR_CAL16_Pos 8
#define PMC_OCR_CAL16_Msk (0x7fu << PMC_OCR_CAL16_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 16 MHz */
#define PMC_OCR_CAL16(value) ((PMC_OCR_CAL16_Msk & ((value) << PMC_OCR_CAL16_Pos)))
#define PMC_OCR_SEL16 (0x1u << 15) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 16 MHz */
#define PMC_OCR_CAL24_Pos 16
#define PMC_OCR_CAL24_Msk (0x7fu << PMC_OCR_CAL24_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 24 MHz */
#define PMC_OCR_CAL24(value) ((PMC_OCR_CAL24_Msk & ((value) << PMC_OCR_CAL24_Pos)))
#define PMC_OCR_SEL24 (0x1u << 23) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 24 MHz */
/* -------- PMC_SLPWK_ER0 : (PMC Offset: 0x114) SleepWalking Enable Register 0 -------- */
#define PMC_SLPWK_ER0_PID8 (0x1u << 8) /**< \brief (PMC_SLPWK_ER0) Peripheral 8 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID9 (0x1u << 9) /**< \brief (PMC_SLPWK_ER0) Peripheral 9 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID10 (0x1u << 10) /**< \brief (PMC_SLPWK_ER0) Peripheral 10 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID11 (0x1u << 11) /**< \brief (PMC_SLPWK_ER0) Peripheral 11 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID12 (0x1u << 12) /**< \brief (PMC_SLPWK_ER0) Peripheral 12 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID13 (0x1u << 13) /**< \brief (PMC_SLPWK_ER0) Peripheral 13 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID14 (0x1u << 14) /**< \brief (PMC_SLPWK_ER0) Peripheral 14 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID15 (0x1u << 15) /**< \brief (PMC_SLPWK_ER0) Peripheral 15 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID16 (0x1u << 16) /**< \brief (PMC_SLPWK_ER0) Peripheral 16 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID17 (0x1u << 17) /**< \brief (PMC_SLPWK_ER0) Peripheral 17 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID18 (0x1u << 18) /**< \brief (PMC_SLPWK_ER0) Peripheral 18 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID19 (0x1u << 19) /**< \brief (PMC_SLPWK_ER0) Peripheral 19 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID20 (0x1u << 20) /**< \brief (PMC_SLPWK_ER0) Peripheral 20 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID21 (0x1u << 21) /**< \brief (PMC_SLPWK_ER0) Peripheral 21 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID22 (0x1u << 22) /**< \brief (PMC_SLPWK_ER0) Peripheral 22 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID23 (0x1u << 23) /**< \brief (PMC_SLPWK_ER0) Peripheral 23 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID24 (0x1u << 24) /**< \brief (PMC_SLPWK_ER0) Peripheral 24 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID25 (0x1u << 25) /**< \brief (PMC_SLPWK_ER0) Peripheral 25 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID26 (0x1u << 26) /**< \brief (PMC_SLPWK_ER0) Peripheral 26 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID27 (0x1u << 27) /**< \brief (PMC_SLPWK_ER0) Peripheral 27 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID28 (0x1u << 28) /**< \brief (PMC_SLPWK_ER0) Peripheral 28 SleepWalking Enable */
#define PMC_SLPWK_ER0_PID29 (0x1u << 29) /**< \brief (PMC_SLPWK_ER0) Peripheral 29 SleepWalking Enable */
/* -------- PMC_SLPWK_DR0 : (PMC Offset: 0x118) SleepWalking Disable Register 0 -------- */
#define PMC_SLPWK_DR0_PID8 (0x1u << 8) /**< \brief (PMC_SLPWK_DR0) Peripheral 8 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID9 (0x1u << 9) /**< \brief (PMC_SLPWK_DR0) Peripheral 9 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID10 (0x1u << 10) /**< \brief (PMC_SLPWK_DR0) Peripheral 10 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID11 (0x1u << 11) /**< \brief (PMC_SLPWK_DR0) Peripheral 11 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID12 (0x1u << 12) /**< \brief (PMC_SLPWK_DR0) Peripheral 12 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID13 (0x1u << 13) /**< \brief (PMC_SLPWK_DR0) Peripheral 13 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID14 (0x1u << 14) /**< \brief (PMC_SLPWK_DR0) Peripheral 14 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID15 (0x1u << 15) /**< \brief (PMC_SLPWK_DR0) Peripheral 15 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID16 (0x1u << 16) /**< \brief (PMC_SLPWK_DR0) Peripheral 16 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID17 (0x1u << 17) /**< \brief (PMC_SLPWK_DR0) Peripheral 17 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID18 (0x1u << 18) /**< \brief (PMC_SLPWK_DR0) Peripheral 18 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID19 (0x1u << 19) /**< \brief (PMC_SLPWK_DR0) Peripheral 19 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID20 (0x1u << 20) /**< \brief (PMC_SLPWK_DR0) Peripheral 20 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID21 (0x1u << 21) /**< \brief (PMC_SLPWK_DR0) Peripheral 21 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID22 (0x1u << 22) /**< \brief (PMC_SLPWK_DR0) Peripheral 22 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID23 (0x1u << 23) /**< \brief (PMC_SLPWK_DR0) Peripheral 23 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID24 (0x1u << 24) /**< \brief (PMC_SLPWK_DR0) Peripheral 24 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID25 (0x1u << 25) /**< \brief (PMC_SLPWK_DR0) Peripheral 25 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID26 (0x1u << 26) /**< \brief (PMC_SLPWK_DR0) Peripheral 26 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID27 (0x1u << 27) /**< \brief (PMC_SLPWK_DR0) Peripheral 27 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID28 (0x1u << 28) /**< \brief (PMC_SLPWK_DR0) Peripheral 28 SleepWalking Disable */
#define PMC_SLPWK_DR0_PID29 (0x1u << 29) /**< \brief (PMC_SLPWK_DR0) Peripheral 29 SleepWalking Disable */
/* -------- PMC_SLPWK_SR0 : (PMC Offset: 0x11C) SleepWalking Status Register 0 -------- */
#define PMC_SLPWK_SR0_PID8 (0x1u << 8) /**< \brief (PMC_SLPWK_SR0) Peripheral 8 SleepWalking Status */
#define PMC_SLPWK_SR0_PID9 (0x1u << 9) /**< \brief (PMC_SLPWK_SR0) Peripheral 9 SleepWalking Status */
#define PMC_SLPWK_SR0_PID10 (0x1u << 10) /**< \brief (PMC_SLPWK_SR0) Peripheral 10 SleepWalking Status */
#define PMC_SLPWK_SR0_PID11 (0x1u << 11) /**< \brief (PMC_SLPWK_SR0) Peripheral 11 SleepWalking Status */
#define PMC_SLPWK_SR0_PID12 (0x1u << 12) /**< \brief (PMC_SLPWK_SR0) Peripheral 12 SleepWalking Status */
#define PMC_SLPWK_SR0_PID13 (0x1u << 13) /**< \brief (PMC_SLPWK_SR0) Peripheral 13 SleepWalking Status */
#define PMC_SLPWK_SR0_PID14 (0x1u << 14) /**< \brief (PMC_SLPWK_SR0) Peripheral 14 SleepWalking Status */
#define PMC_SLPWK_SR0_PID15 (0x1u << 15) /**< \brief (PMC_SLPWK_SR0) Peripheral 15 SleepWalking Status */
#define PMC_SLPWK_SR0_PID16 (0x1u << 16) /**< \brief (PMC_SLPWK_SR0) Peripheral 16 SleepWalking Status */
#define PMC_SLPWK_SR0_PID17 (0x1u << 17) /**< \brief (PMC_SLPWK_SR0) Peripheral 17 SleepWalking Status */
#define PMC_SLPWK_SR0_PID18 (0x1u << 18) /**< \brief (PMC_SLPWK_SR0) Peripheral 18 SleepWalking Status */
#define PMC_SLPWK_SR0_PID19 (0x1u << 19) /**< \brief (PMC_SLPWK_SR0) Peripheral 19 SleepWalking Status */
#define PMC_SLPWK_SR0_PID20 (0x1u << 20) /**< \brief (PMC_SLPWK_SR0) Peripheral 20 SleepWalking Status */
#define PMC_SLPWK_SR0_PID21 (0x1u << 21) /**< \brief (PMC_SLPWK_SR0) Peripheral 21 SleepWalking Status */
#define PMC_SLPWK_SR0_PID22 (0x1u << 22) /**< \brief (PMC_SLPWK_SR0) Peripheral 22 SleepWalking Status */
#define PMC_SLPWK_SR0_PID23 (0x1u << 23) /**< \brief (PMC_SLPWK_SR0) Peripheral 23 SleepWalking Status */
#define PMC_SLPWK_SR0_PID24 (0x1u << 24) /**< \brief (PMC_SLPWK_SR0) Peripheral 24 SleepWalking Status */
#define PMC_SLPWK_SR0_PID25 (0x1u << 25) /**< \brief (PMC_SLPWK_SR0) Peripheral 25 SleepWalking Status */
#define PMC_SLPWK_SR0_PID26 (0x1u << 26) /**< \brief (PMC_SLPWK_SR0) Peripheral 26 SleepWalking Status */
#define PMC_SLPWK_SR0_PID27 (0x1u << 27) /**< \brief (PMC_SLPWK_SR0) Peripheral 27 SleepWalking Status */
#define PMC_SLPWK_SR0_PID28 (0x1u << 28) /**< \brief (PMC_SLPWK_SR0) Peripheral 28 SleepWalking Status */
#define PMC_SLPWK_SR0_PID29 (0x1u << 29) /**< \brief (PMC_SLPWK_SR0) Peripheral 29 SleepWalking Status */
/* -------- PMC_SLPWK_ASR0 : (PMC Offset: 0x120) SleepWalking Activity Status Register 0 -------- */
#define PMC_SLPWK_ASR0_PID8 (0x1u << 8) /**< \brief (PMC_SLPWK_ASR0) Peripheral 8 Activity Status */
#define PMC_SLPWK_ASR0_PID9 (0x1u << 9) /**< \brief (PMC_SLPWK_ASR0) Peripheral 9 Activity Status */
#define PMC_SLPWK_ASR0_PID10 (0x1u << 10) /**< \brief (PMC_SLPWK_ASR0) Peripheral 10 Activity Status */
#define PMC_SLPWK_ASR0_PID11 (0x1u << 11) /**< \brief (PMC_SLPWK_ASR0) Peripheral 11 Activity Status */
#define PMC_SLPWK_ASR0_PID12 (0x1u << 12) /**< \brief (PMC_SLPWK_ASR0) Peripheral 12 Activity Status */
#define PMC_SLPWK_ASR0_PID13 (0x1u << 13) /**< \brief (PMC_SLPWK_ASR0) Peripheral 13 Activity Status */
#define PMC_SLPWK_ASR0_PID14 (0x1u << 14) /**< \brief (PMC_SLPWK_ASR0) Peripheral 14 Activity Status */
#define PMC_SLPWK_ASR0_PID15 (0x1u << 15) /**< \brief (PMC_SLPWK_ASR0) Peripheral 15 Activity Status */
#define PMC_SLPWK_ASR0_PID16 (0x1u << 16) /**< \brief (PMC_SLPWK_ASR0) Peripheral 16 Activity Status */
#define PMC_SLPWK_ASR0_PID17 (0x1u << 17) /**< \brief (PMC_SLPWK_ASR0) Peripheral 17 Activity Status */
#define PMC_SLPWK_ASR0_PID18 (0x1u << 18) /**< \brief (PMC_SLPWK_ASR0) Peripheral 18 Activity Status */
#define PMC_SLPWK_ASR0_PID19 (0x1u << 19) /**< \brief (PMC_SLPWK_ASR0) Peripheral 19 Activity Status */
#define PMC_SLPWK_ASR0_PID20 (0x1u << 20) /**< \brief (PMC_SLPWK_ASR0) Peripheral 20 Activity Status */
#define PMC_SLPWK_ASR0_PID21 (0x1u << 21) /**< \brief (PMC_SLPWK_ASR0) Peripheral 21 Activity Status */
#define PMC_SLPWK_ASR0_PID22 (0x1u << 22) /**< \brief (PMC_SLPWK_ASR0) Peripheral 22 Activity Status */
#define PMC_SLPWK_ASR0_PID23 (0x1u << 23) /**< \brief (PMC_SLPWK_ASR0) Peripheral 23 Activity Status */
#define PMC_SLPWK_ASR0_PID24 (0x1u << 24) /**< \brief (PMC_SLPWK_ASR0) Peripheral 24 Activity Status */
#define PMC_SLPWK_ASR0_PID25 (0x1u << 25) /**< \brief (PMC_SLPWK_ASR0) Peripheral 25 Activity Status */
#define PMC_SLPWK_ASR0_PID26 (0x1u << 26) /**< \brief (PMC_SLPWK_ASR0) Peripheral 26 Activity Status */
#define PMC_SLPWK_ASR0_PID27 (0x1u << 27) /**< \brief (PMC_SLPWK_ASR0) Peripheral 27 Activity Status */
#define PMC_SLPWK_ASR0_PID28 (0x1u << 28) /**< \brief (PMC_SLPWK_ASR0) Peripheral 28 Activity Status */
#define PMC_SLPWK_ASR0_PID29 (0x1u << 29) /**< \brief (PMC_SLPWK_ASR0) Peripheral 29 Activity Status */
/* -------- PMC_PMMR : (PMC Offset: 0x130) PLL Maximum Multiplier Value Register -------- */
#define PMC_PMMR_PLLA_MMAX_Pos 0
#define PMC_PMMR_PLLA_MMAX_Msk (0x7ffu << PMC_PMMR_PLLA_MMAX_Pos) /**< \brief (PMC_PMMR) PLLA Maximum Allowed Multiplier Value */
#define PMC_PMMR_PLLA_MMAX(value) ((PMC_PMMR_PLLA_MMAX_Msk & ((value) << PMC_PMMR_PLLA_MMAX_Pos)))

/*@}*/


#endif /* _SAMG54_PMC_COMPONENT_ */
