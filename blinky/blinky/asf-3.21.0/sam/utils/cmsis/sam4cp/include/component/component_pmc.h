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

#ifndef _SAM4CP_PMC_COMPONENT_
#define _SAM4CP_PMC_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Power Management Controller */
/* ============================================================================= */
/** \addtogroup SAM4CP_PMC Power Management Controller */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Pmc hardware registers */
typedef struct {
  __O  uint32_t PMC_SCER;      /**< \brief (Pmc Offset: 0x0000) System Clock Enable Register */
  __O  uint32_t PMC_SCDR;      /**< \brief (Pmc Offset: 0x0004) System Clock Disable Register */
  __I  uint32_t PMC_SCSR;      /**< \brief (Pmc Offset: 0x0008) System Clock Status Register */
  __I  uint32_t Reserved1[1];
  __O  uint32_t PMC_PCER0;     /**< \brief (Pmc Offset: 0x0010) Peripheral Clock Enable Register 0 */
  __O  uint32_t PMC_PCDR0;     /**< \brief (Pmc Offset: 0x0014) Peripheral Clock Disable Register 0 */
  __I  uint32_t PMC_PCSR0;     /**< \brief (Pmc Offset: 0x0018) Peripheral Clock Status Register 0 */
  __I  uint32_t Reserved2[1];
  __IO uint32_t CKGR_MOR;      /**< \brief (Pmc Offset: 0x0020) Main Oscillator Register */
  __IO uint32_t CKGR_MCFR;     /**< \brief (Pmc Offset: 0x0024) Main Clock Frequency Register */
  __IO uint32_t CKGR_PLLAR;    /**< \brief (Pmc Offset: 0x0028) PLLA Register */
  __IO uint32_t CKGR_PLLBR;    /**< \brief (Pmc Offset: 0x002C) PLLB Register */
  __IO uint32_t PMC_MCKR;      /**< \brief (Pmc Offset: 0x0030) Master Clock Register */
  __I  uint32_t Reserved3[3];
  __IO uint32_t PMC_PCK[3];    /**< \brief (Pmc Offset: 0x0040) Programmable Clock 0 Register */
  __I  uint32_t Reserved4[5];
  __O  uint32_t PMC_IER;       /**< \brief (Pmc Offset: 0x0060) Interrupt Enable Register */
  __O  uint32_t PMC_IDR;       /**< \brief (Pmc Offset: 0x0064) Interrupt Disable Register */
  __I  uint32_t PMC_SR;        /**< \brief (Pmc Offset: 0x0068) Status Register */
  __I  uint32_t PMC_IMR;       /**< \brief (Pmc Offset: 0x006C) Interrupt Mask Register */
  __IO uint32_t PMC_FSMR;      /**< \brief (Pmc Offset: 0x0070) Fast Start-up Mode Register */
  __IO uint32_t PMC_FSPR;      /**< \brief (Pmc Offset: 0x0074) Fast Start-up Polarity Register */
  __O  uint32_t PMC_FOCR;      /**< \brief (Pmc Offset: 0x0078) Fault Output Clear Register */
  __IO uint32_t PMC_CPFSMR;    /**< \brief (Pmc Offset: 0x007C) Coprocessor Fast Start-up Mode Register */
  __I  uint32_t Reserved5[25];
  __IO uint32_t PMC_WPMR;      /**< \brief (Pmc Offset: 0x00E4) Write Protect Mode Register */
  __I  uint32_t PMC_WPSR;      /**< \brief (Pmc Offset: 0x00E8) Write Protect Status Register */
  __I  uint32_t Reserved6[5];
  __O  uint32_t PMC_PCER1;     /**< \brief (Pmc Offset: 0x0100) Peripheral Clock Enable Register 1 */
  __O  uint32_t PMC_PCDR1;     /**< \brief (Pmc Offset: 0x0104) Peripheral Clock Disable Register 1 */
  __I  uint32_t PMC_PCSR1;     /**< \brief (Pmc Offset: 0x0108) Peripheral Clock Status Register 1 */
  __I  uint32_t Reserved7[1];
  __IO uint32_t PMC_OCR;       /**< \brief (Pmc Offset: 0x0110) Oscillator Calibration Register */
  __I  uint32_t Reserved8[7];
  __IO uint32_t PMC_PMMR;      /**< \brief (Pmc Offset: 0x130) PLL Maximum Multiplier Value Register */
} Pmc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- PMC_SCER : (PMC Offset: 0x0000) System Clock Enable Register -------- */
#define PMC_SCER_PCK0 (0x1u << 8) /**< \brief (PMC_SCER) Programmable Clock 0 Output Enable */
#define PMC_SCER_PCK1 (0x1u << 9) /**< \brief (PMC_SCER) Programmable Clock 1 Output Enable */
#define PMC_SCER_PCK2 (0x1u << 10) /**< \brief (PMC_SCER) Programmable Clock 2 Output Enable */
#define PMC_SCER_CPCK (0x1u << 16) /**< \brief (PMC_SCER) Coprocessor (Second Processor) Clocks Enable */
#define PMC_SCER_CPBMCK (0x1u << 17) /**< \brief (PMC_SCER) Coprocessor Bus Master Clocks Enable */
#define PMC_SCER_CPKEY_Pos 20
#define PMC_SCER_CPKEY_Msk (0xfu << PMC_SCER_CPKEY_Pos) /**< \brief (PMC_SCER) Coprocessor Clocks Enable Key */
#define   PMC_SCER_CPKEY_PASSWD (0xAu << 20) /**< \brief (PMC_SCER) This field must be written to 0xA in order to validate CPCK field. */
/* -------- PMC_SCDR : (PMC Offset: 0x0004) System Clock Disable Register -------- */
#define PMC_SCDR_PCK0 (0x1u << 8) /**< \brief (PMC_SCDR) Programmable Clock 0 Output Disable */
#define PMC_SCDR_PCK1 (0x1u << 9) /**< \brief (PMC_SCDR) Programmable Clock 1 Output Disable */
#define PMC_SCDR_PCK2 (0x1u << 10) /**< \brief (PMC_SCDR) Programmable Clock 2 Output Disable */
#define PMC_SCDR_CPCK (0x1u << 16) /**< \brief (PMC_SCDR) Coprocessor Clocks Disable */
#define PMC_SCDR_CPBMCK (0x1u << 17) /**< \brief (PMC_SCDR) Coprocessor Bus Master Clocks Disable */
#define PMC_SCDR_CPKEY_Pos 20
#define PMC_SCDR_CPKEY_Msk (0xfu << PMC_SCDR_CPKEY_Pos) /**< \brief (PMC_SCDR) Coprocessor Clocks Disable Key */
#define   PMC_SCDR_CPKEY_PASSWD (0xAu << 20) /**< \brief (PMC_SCDR) This field must be written to 0xA in order to validate CPCK field. */
/* -------- PMC_SCSR : (PMC Offset: 0x0008) System Clock Status Register -------- */
#define PMC_SCSR_PCK0 (0x1u << 8) /**< \brief (PMC_SCSR) Programmable Clock 0 Output Status */
#define PMC_SCSR_PCK1 (0x1u << 9) /**< \brief (PMC_SCSR) Programmable Clock 1 Output Status */
#define PMC_SCSR_PCK2 (0x1u << 10) /**< \brief (PMC_SCSR) Programmable Clock 2 Output Status */
#define PMC_SCSR_CPCK (0x1u << 16) /**< \brief (PMC_SCSR) Coprocessor (Second Processor) Clocks Status */
#define PMC_SCSR_CPBMCK (0x1u << 17) /**< \brief (PMC_SCSR) Coprocessor Bus Master Clock Status */
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
#define PMC_PCER0_PID23 (0x1u << 23) /**< \brief (PMC_PCER0) Peripheral Clock 23 Enable */
#define PMC_PCER0_PID24 (0x1u << 24) /**< \brief (PMC_PCER0) Peripheral Clock 24 Enable */
#define PMC_PCER0_PID25 (0x1u << 25) /**< \brief (PMC_PCER0) Peripheral Clock 25 Enable */
#define PMC_PCER0_PID26 (0x1u << 26) /**< \brief (PMC_PCER0) Peripheral Clock 26 Enable */
#define PMC_PCER0_PID27 (0x1u << 27) /**< \brief (PMC_PCER0) Peripheral Clock 27 Enable */
#define PMC_PCER0_PID28 (0x1u << 28) /**< \brief (PMC_PCER0) Peripheral Clock 28 Enable */
#define PMC_PCER0_PID29 (0x1u << 29) /**< \brief (PMC_PCER0) Peripheral Clock 29 Enable */
#define PMC_PCER0_PID31 (0x1u << 31) /**< \brief (PMC_PCER0) Peripheral Clock 31 Enable */
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
#define PMC_PCDR0_PID23 (0x1u << 23) /**< \brief (PMC_PCDR0) Peripheral Clock 23 Disable */
#define PMC_PCDR0_PID24 (0x1u << 24) /**< \brief (PMC_PCDR0) Peripheral Clock 24 Disable */
#define PMC_PCDR0_PID25 (0x1u << 25) /**< \brief (PMC_PCDR0) Peripheral Clock 25 Disable */
#define PMC_PCDR0_PID26 (0x1u << 26) /**< \brief (PMC_PCDR0) Peripheral Clock 26 Disable */
#define PMC_PCDR0_PID27 (0x1u << 27) /**< \brief (PMC_PCDR0) Peripheral Clock 27 Disable */
#define PMC_PCDR0_PID28 (0x1u << 28) /**< \brief (PMC_PCDR0) Peripheral Clock 28 Disable */
#define PMC_PCDR0_PID29 (0x1u << 29) /**< \brief (PMC_PCDR0) Peripheral Clock 29 Disable */
#define PMC_PCDR0_PID31 (0x1u << 31) /**< \brief (PMC_PCDR0) Peripheral Clock 31 Disable */
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
#define PMC_PCSR0_PID23 (0x1u << 23) /**< \brief (PMC_PCSR0) Peripheral Clock 23 Status */
#define PMC_PCSR0_PID24 (0x1u << 24) /**< \brief (PMC_PCSR0) Peripheral Clock 24 Status */
#define PMC_PCSR0_PID25 (0x1u << 25) /**< \brief (PMC_PCSR0) Peripheral Clock 25 Status */
#define PMC_PCSR0_PID26 (0x1u << 26) /**< \brief (PMC_PCSR0) Peripheral Clock 26 Status */
#define PMC_PCSR0_PID27 (0x1u << 27) /**< \brief (PMC_PCSR0) Peripheral Clock 27 Status */
#define PMC_PCSR0_PID28 (0x1u << 28) /**< \brief (PMC_PCSR0) Peripheral Clock 28 Status */
#define PMC_PCSR0_PID29 (0x1u << 29) /**< \brief (PMC_PCSR0) Peripheral Clock 29 Status */
#define PMC_PCSR0_PID31 (0x1u << 31) /**< \brief (PMC_PCSR0) Peripheral Clock 31 Status */
/* -------- CKGR_MOR : (PMC Offset: 0x0020) Main Oscillator Register -------- */
#define CKGR_MOR_MOSCXTEN (0x1u << 0) /**< \brief (CKGR_MOR) Main Crystal Oscillator Enable */
#define CKGR_MOR_MOSCXTBY (0x1u << 1) /**< \brief (CKGR_MOR) Main Crystal Oscillator Bypass */
#define CKGR_MOR_WAITMODE (0x1u << 2) /**< \brief (CKGR_MOR) Wait Mode Command */
#define CKGR_MOR_MOSCRCEN (0x1u << 3) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Enable */
#define CKGR_MOR_MOSCRCF_Pos 4
#define CKGR_MOR_MOSCRCF_Msk (0x7u << CKGR_MOR_MOSCRCF_Pos) /**< \brief (CKGR_MOR) Main On-Chip RC Oscillator Frequency Selection */
#define   CKGR_MOR_MOSCRCF_4_MHz (0x0u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 4 MHz (default) */
#define   CKGR_MOR_MOSCRCF_8_MHz (0x1u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 8 MHz */
#define   CKGR_MOR_MOSCRCF_12_MHz (0x2u << 4) /**< \brief (CKGR_MOR) The Fast RC Oscillator Frequency is at 12 MHz */
#define CKGR_MOR_MOSCXTST_Pos 8
#define CKGR_MOR_MOSCXTST_Msk (0xffu << CKGR_MOR_MOSCXTST_Pos) /**< \brief (CKGR_MOR) Main Crystal Oscillator Start-up Time */
#define CKGR_MOR_MOSCXTST(value) ((CKGR_MOR_MOSCXTST_Msk & ((value) << CKGR_MOR_MOSCXTST_Pos)))
#define CKGR_MOR_KEY_Pos 16
#define CKGR_MOR_KEY_Msk (0xffu << CKGR_MOR_KEY_Pos) /**< \brief (CKGR_MOR) Write Access Password */
#define   CKGR_MOR_KEY_PASSWD (0x37u << 16) /**< \brief (CKGR_MOR) Writing any other value in this field aborts the write operation.Always reads as 0. */
#define CKGR_MOR_MOSCSEL (0x1u << 24) /**< \brief (CKGR_MOR) Main Oscillator Selection */
#define CKGR_MOR_CFDEN (0x1u << 25) /**< \brief (CKGR_MOR) Clock Failure Detector Enable */
#define CKGR_MOR_XT32KFME (0x1u << 26) /**< \brief (CKGR_MOR) Slow Crystal Oscillator Frequency Monitoring Enable */
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
#define CKGR_PLLAR_MULA_Msk (0x7ffu << CKGR_PLLAR_MULA_Pos) /**< \brief (CKGR_PLLAR) PLLA Multiplier */
#define CKGR_PLLAR_MULA(value) ((CKGR_PLLAR_MULA_Msk & ((value) << CKGR_PLLAR_MULA_Pos)))
/* -------- CKGR_PLLBR : (PMC Offset: 0x002C) PLLB Register -------- */
#define CKGR_PLLBR_DIVB_Pos 0
#define CKGR_PLLBR_DIVB_Msk (0xffu << CKGR_PLLBR_DIVB_Pos) /**< \brief (CKGR_PLLBR) PLLB Front-End Divider */
#define CKGR_PLLBR_DIVB(value) ((CKGR_PLLBR_DIVB_Msk & ((value) << CKGR_PLLBR_DIVB_Pos)))
#define CKGR_PLLBR_PLLBCOUNT_Pos 8
#define CKGR_PLLBR_PLLBCOUNT_Msk (0x3fu << CKGR_PLLBR_PLLBCOUNT_Pos) /**< \brief (CKGR_PLLBR) PLLB Counter */
#define CKGR_PLLBR_PLLBCOUNT(value) ((CKGR_PLLBR_PLLBCOUNT_Msk & ((value) << CKGR_PLLBR_PLLBCOUNT_Pos)))
#define CKGR_PLLBR_MULB_Pos 16
#define CKGR_PLLBR_MULB_Msk (0x7ffu << CKGR_PLLBR_MULB_Pos) /**< \brief (CKGR_PLLBR) PLLB Multiplier */
#define CKGR_PLLBR_MULB(value) ((CKGR_PLLBR_MULB_Msk & ((value) << CKGR_PLLBR_MULB_Pos)))
#define CKGR_PLLBR_SRCB (0x1u << 29) /**< \brief (CKGR_PLLBR) Source for PLLB */
#define   CKGR_PLLBR_SRCB_MAINCK_IN_PLLB (0x0u << 29) /**< \brief (CKGR_PLLBR) The PLLB input clock is Main Clock */
#define   CKGR_PLLBR_SRCB_PLLA_IN_PLLB (0x1u << 29) /**< \brief (CKGR_PLLBR) The PLLB input clock is PLLA output. MAIN CK is PLLA output */
/* -------- PMC_MCKR : (PMC Offset: 0x0030) Master Clock Register -------- */
#define PMC_MCKR_CSS_Pos 0
#define PMC_MCKR_CSS_Msk (0x3u << PMC_MCKR_CSS_Pos) /**< \brief (PMC_MCKR) Master Clock Source Selection */
#define   PMC_MCKR_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_MCKR) Slow Clock is selected */
#define   PMC_MCKR_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_MCKR) Main Clock is selected */
#define   PMC_MCKR_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_MCKR) PLLA Clock is selected */
#define   PMC_MCKR_CSS_PLLB_CLK (0x3u << 0) /**< \brief (PMC_MCKR) PLLBClock is selected */
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
#define PMC_MCKR_PLLBDIV2 (0x1u << 13) /**< \brief (PMC_MCKR)  */
#define PMC_MCKR_CPCSS_Pos 16
#define PMC_MCKR_CPCSS_Msk (0x7u << PMC_MCKR_CPCSS_Pos) /**< \brief (PMC_MCKR) Coprocessor Master Clock Source Selection */
#define   PMC_MCKR_CPCSS_SLOW_CLK (0x0u << 16) /**< \brief (PMC_MCKR) Slow Clock is selected */
#define   PMC_MCKR_CPCSS_MAIN_CLK (0x1u << 16) /**< \brief (PMC_MCKR) Main Clock is selected */
#define   PMC_MCKR_CPCSS_PLLA_CLK (0x2u << 16) /**< \brief (PMC_MCKR) PLLA Clock is selected */
#define   PMC_MCKR_CPCSS_PLLB_CLK (0x3u << 16) /**< \brief (PMC_MCKR) PLLB  Clock is selected */
#define   PMC_MCKR_CPCSS_MCK (0x4u << 16) /**< \brief (PMC_MCKR) Master Clock is selected */
#define PMC_MCKR_CPPRES_Pos 20
#define PMC_MCKR_CPPRES_Msk (0xfu << PMC_MCKR_CPPRES_Pos) /**< \brief (PMC_MCKR) Coprocessor Programmable Clock Prescaler */
#define PMC_MCKR_CPPRES(value) ((PMC_MCKR_CPPRES_Msk & ((value) << PMC_MCKR_CPPRES_Pos)))
/* -------- PMC_PCK[3] : (PMC Offset: 0x0040) Programmable Clock 0 Register -------- */
#define PMC_PCK_CSS_Pos 0
#define PMC_PCK_CSS_Msk (0x7u << PMC_PCK_CSS_Pos) /**< \brief (PMC_PCK[3]) Master Clock Source Selection */
#define   PMC_PCK_CSS_SLOW_CLK (0x0u << 0) /**< \brief (PMC_PCK[3]) Slow Clock is selected */
#define   PMC_PCK_CSS_MAIN_CLK (0x1u << 0) /**< \brief (PMC_PCK[3]) Main Clock is selected */
#define   PMC_PCK_CSS_PLLA_CLK (0x2u << 0) /**< \brief (PMC_PCK[3]) PLLA Clock is selected */
#define   PMC_PCK_CSS_PLLB_CLK (0x3u << 0) /**< \brief (PMC_PCK[3]) PLLB Clock is selected */
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
#define PMC_IER_LOCKB (0x1u << 2) /**< \brief (PMC_IER) PLLB Lock Interrupt Enable */
#define PMC_IER_MCKRDY (0x1u << 3) /**< \brief (PMC_IER) Master Clock Ready Interrupt Enable */
#define PMC_IER_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IER) Programmable Clock Ready 0 Interrupt Enable */
#define PMC_IER_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IER) Programmable Clock Ready 1 Interrupt Enable */
#define PMC_IER_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IER) Programmable Clock Ready 2 Interrupt Enable */
#define PMC_IER_MOSCSELS (0x1u << 16) /**< \brief (PMC_IER) Main Oscillator Selection Status Interrupt Enable */
#define PMC_IER_MOSCRCS (0x1u << 17) /**< \brief (PMC_IER) Main On-Chip RC Status Interrupt Enable */
#define PMC_IER_CFDEV (0x1u << 18) /**< \brief (PMC_IER) Clock Failure Detector Event Interrupt Enable */
#define PMC_IER_XT32KERR (0x1u << 21) /**< \brief (PMC_IER) Slow Crystal Oscillator Error Interrupt Enable */
/* -------- PMC_IDR : (PMC Offset: 0x0064) Interrupt Disable Register -------- */
#define PMC_IDR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IDR) Main Crystal Oscillator Status Interrupt Disable */
#define PMC_IDR_LOCKA (0x1u << 1) /**< \brief (PMC_IDR) PLLA Lock Interrupt Disable */
#define PMC_IDR_LOCKB (0x1u << 2) /**< \brief (PMC_IDR) PLLB Lock Interrupt Disable */
#define PMC_IDR_MCKRDY (0x1u << 3) /**< \brief (PMC_IDR) Master Clock Ready Interrupt Disable */
#define PMC_IDR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IDR) Programmable Clock Ready 0 Interrupt Disable */
#define PMC_IDR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IDR) Programmable Clock Ready 1 Interrupt Disable */
#define PMC_IDR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IDR) Programmable Clock Ready 2 Interrupt Disable */
#define PMC_IDR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IDR) Main Oscillator Selection Status Interrupt Disable */
#define PMC_IDR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IDR) Main On-Chip RC Status Interrupt Disable */
#define PMC_IDR_CFDEV (0x1u << 18) /**< \brief (PMC_IDR) Clock Failure Detector Event Interrupt Disable */
#define PMC_IDR_XT32KERR (0x1u << 21) /**< \brief (PMC_IDR) Slow Crystal Oscillator Error Interrupt Disable */
/* -------- PMC_SR : (PMC Offset: 0x0068) Status Register -------- */
#define PMC_SR_MOSCXTS (0x1u << 0) /**< \brief (PMC_SR) Main XTAL Oscillator Status */
#define PMC_SR_LOCKA (0x1u << 1) /**< \brief (PMC_SR) PLLA Lock Status */
#define PMC_SR_LOCKB (0x1u << 2) /**< \brief (PMC_SR) PLLB Lock Status */
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
#define PMC_SR_XT32KERR (0x1u << 21) /**< \brief (PMC_SR) Slow Crystal Oscillator Error */
/* -------- PMC_IMR : (PMC Offset: 0x006C) Interrupt Mask Register -------- */
#define PMC_IMR_MOSCXTS (0x1u << 0) /**< \brief (PMC_IMR) Main Crystal Oscillator Status Interrupt Mask */
#define PMC_IMR_LOCKA (0x1u << 1) /**< \brief (PMC_IMR) PLLA Lock Interrupt Mask */
#define PMC_IMR_LOCKB (0x1u << 2) /**< \brief (PMC_IMR) PLLB Lock Interrupt Mask */
#define PMC_IMR_MCKRDY (0x1u << 3) /**< \brief (PMC_IMR) Master Clock Ready Interrupt Mask */
#define PMC_IMR_PCKRDY0 (0x1u << 8) /**< \brief (PMC_IMR) Programmable Clock Ready 0 Interrupt Mask */
#define PMC_IMR_PCKRDY1 (0x1u << 9) /**< \brief (PMC_IMR) Programmable Clock Ready 1 Interrupt Mask */
#define PMC_IMR_PCKRDY2 (0x1u << 10) /**< \brief (PMC_IMR) Programmable Clock Ready 2 Interrupt Mask */
#define PMC_IMR_MOSCSELS (0x1u << 16) /**< \brief (PMC_IMR) Main Oscillator Selection Status Interrupt Mask */
#define PMC_IMR_MOSCRCS (0x1u << 17) /**< \brief (PMC_IMR) Main On-Chip RC Status Interrupt Mask */
#define PMC_IMR_CFDEV (0x1u << 18) /**< \brief (PMC_IMR) Clock Failure Detector Event Interrupt Mask */
#define PMC_IMR_XT32KERR (0x1u << 21) /**< \brief (PMC_IMR) Slow Crystal Oscillator Error Interrupt Mask */
/* -------- PMC_FSMR : (PMC Offset: 0x0070) Fast Start-up Mode Register -------- */
#define PMC_FSMR_FSTT0 (0x1u << 0) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 0 */
#define PMC_FSMR_FSTT1 (0x1u << 1) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 1 */
#define PMC_FSMR_FSTT2 (0x1u << 2) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 2 */
#define PMC_FSMR_FSTT3 (0x1u << 3) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 3 */
#define PMC_FSMR_FSTT4 (0x1u << 4) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 4 */
#define PMC_FSMR_FSTT5 (0x1u << 5) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 5 */
#define PMC_FSMR_FSTT6 (0x1u << 6) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 6 */
#define PMC_FSMR_FSTT7 (0x1u << 7) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 7 */
#define PMC_FSMR_FSTT8 (0x1u << 8) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 8 */
#define PMC_FSMR_FSTT9 (0x1u << 9) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 9 */
#define PMC_FSMR_FSTT10 (0x1u << 10) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 10 */
#define PMC_FSMR_FSTT11 (0x1u << 11) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 11 */
#define PMC_FSMR_FSTT12 (0x1u << 12) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 12 */
#define PMC_FSMR_FSTT13 (0x1u << 13) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 13 */
#define PMC_FSMR_FSTT14 (0x1u << 14) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 14 */
#define PMC_FSMR_FSTT15 (0x1u << 15) /**< \brief (PMC_FSMR) Fast Start-up Input Enable 15 */
#define PMC_FSMR_RTTAL (0x1u << 16) /**< \brief (PMC_FSMR) RTT Alarm Enable */
#define PMC_FSMR_RTCAL (0x1u << 17) /**< \brief (PMC_FSMR) RTC Alarm Enable */
#define PMC_FSMR_LPM (0x1u << 20) /**< \brief (PMC_FSMR) Low Power Mode */
#define PMC_FSMR_FLPM_Pos 21
#define PMC_FSMR_FLPM_Msk (0x3u << PMC_FSMR_FLPM_Pos) /**< \brief (PMC_FSMR) Flash Low Power Mode */
#define   PMC_FSMR_FLPM_FLASH_STANDBY (0x0u << 21) /**< \brief (PMC_FSMR) Flash is in Standby Mode when system enters Wait Mode */
#define   PMC_FSMR_FLPM_FLASH_DEEP_POWERDOWN (0x1u << 21) /**< \brief (PMC_FSMR) Flash is in deep power down mode when system enters Wait Mode */
#define   PMC_FSMR_FLPM_FLASH_IDLE (0x2u << 21) /**< \brief (PMC_FSMR) idle mode */
/* -------- PMC_FSPR : (PMC Offset: 0x0074) Fast Start-up Polarity Register -------- */
#define PMC_FSPR_FSTP0 (0x1u << 0) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP1 (0x1u << 1) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP2 (0x1u << 2) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP3 (0x1u << 3) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP4 (0x1u << 4) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP5 (0x1u << 5) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP6 (0x1u << 6) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP7 (0x1u << 7) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP8 (0x1u << 8) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP9 (0x1u << 9) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP10 (0x1u << 10) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP11 (0x1u << 11) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP12 (0x1u << 12) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP13 (0x1u << 13) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP14 (0x1u << 14) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
#define PMC_FSPR_FSTP15 (0x1u << 15) /**< \brief (PMC_FSPR) Fast Start-up Input Polarityx */
/* -------- PMC_FOCR : (PMC Offset: 0x0078) Fault Output Clear Register -------- */
#define PMC_FOCR_FOCLR (0x1u << 0) /**< \brief (PMC_FOCR) Fault Output Clear */
/* -------- PMC_CPFSMR : (PMC Offset: 0x007C) Coprocessor Fast Start-up Mode Register -------- */
#define PMC_CPFSMR_FSTT0 (0x1u << 0) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 0 */
#define PMC_CPFSMR_FSTT1 (0x1u << 1) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 1 */
#define PMC_CPFSMR_FSTT2 (0x1u << 2) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 2 */
#define PMC_CPFSMR_FSTT3 (0x1u << 3) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 3 */
#define PMC_CPFSMR_FSTT4 (0x1u << 4) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 4 */
#define PMC_CPFSMR_FSTT5 (0x1u << 5) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 5 */
#define PMC_CPFSMR_FSTT6 (0x1u << 6) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 6 */
#define PMC_CPFSMR_FSTT7 (0x1u << 7) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 7 */
#define PMC_CPFSMR_FSTT8 (0x1u << 8) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 8 */
#define PMC_CPFSMR_FSTT9 (0x1u << 9) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 9 */
#define PMC_CPFSMR_FSTT10 (0x1u << 10) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 10 */
#define PMC_CPFSMR_FSTT11 (0x1u << 11) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 11 */
#define PMC_CPFSMR_FSTT12 (0x1u << 12) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 12 */
#define PMC_CPFSMR_FSTT13 (0x1u << 13) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 13 */
#define PMC_CPFSMR_FSTT14 (0x1u << 14) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 14 */
#define PMC_CPFSMR_FSTT15 (0x1u << 15) /**< \brief (PMC_CPFSMR) Fast Start-up Input Enable 15 */
#define PMC_CPFSMR_RTTAL (0x1u << 16) /**< \brief (PMC_CPFSMR) RTT Alarm Enable */
#define PMC_CPFSMR_RTCAL (0x1u << 17) /**< \brief (PMC_CPFSMR) RTC Alarm Enable */
/* -------- PMC_WPMR : (PMC Offset: 0x00E4) Write Protect Mode Register -------- */
#define PMC_WPMR_WPEN (0x1u << 0) /**< \brief (PMC_WPMR) Write Protect Enable */
#define PMC_WPMR_WPKEY_Pos 8
#define PMC_WPMR_WPKEY_Msk (0xffffffu << PMC_WPMR_WPKEY_Pos) /**< \brief (PMC_WPMR) Write Protect KEY */
#define   PMC_WPMR_WPKEY_PASSWD (0x504D43u << 8) /**< \brief (PMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. */
/* -------- PMC_WPSR : (PMC Offset: 0x00E8) Write Protect Status Register -------- */
#define PMC_WPSR_WPVS (0x1u << 0) /**< \brief (PMC_WPSR) Write Protect Violation Status */
#define PMC_WPSR_WPVSRC_Pos 8
#define PMC_WPSR_WPVSRC_Msk (0xffffu << PMC_WPSR_WPVSRC_Pos) /**< \brief (PMC_WPSR) Write Protect Violation Source */
/* -------- PMC_PCER1 : (PMC Offset: 0x0100) Peripheral Clock Enable Register 1 -------- */
#define PMC_PCER1_PID32 (0x1u << 0) /**< \brief (PMC_PCER1) Peripheral Clock 32 Enable */
#define PMC_PCER1_PID33 (0x1u << 1) /**< \brief (PMC_PCER1) Peripheral Clock 33 Enable */
#define PMC_PCER1_PID34 (0x1u << 2) /**< \brief (PMC_PCER1) Peripheral Clock 34 Enable */
#define PMC_PCER1_PID35 (0x1u << 3) /**< \brief (PMC_PCER1) Peripheral Clock 35 Enable */
#define PMC_PCER1_PID36 (0x1u << 4) /**< \brief (PMC_PCER1) Peripheral Clock 36 Enable */
#define PMC_PCER1_PID37 (0x1u << 5) /**< \brief (PMC_PCER1) Peripheral Clock 37 Enable */
#define PMC_PCER1_PID38 (0x1u << 6) /**< \brief (PMC_PCER1) Peripheral Clock 38 Enable */
#define PMC_PCER1_PID39 (0x1u << 7) /**< \brief (PMC_PCER1) Peripheral Clock 39 Enable */
#define PMC_PCER1_PID40 (0x1u << 8) /**< \brief (PMC_PCER1) Peripheral Clock 40 Enable */
#define PMC_PCER1_PID41 (0x1u << 9) /**< \brief (PMC_PCER1) Peripheral Clock 41 Enable */
#define PMC_PCER1_PID42 (0x1u << 10) /**< \brief (PMC_PCER1) Peripheral Clock 42 Enable */
#define PMC_PCER1_PID43 (0x1u << 11) /**< \brief (PMC_PCER1) Peripheral Clock 43 Enable */
/* -------- PMC_PCDR1 : (PMC Offset: 0x0104) Peripheral Clock Disable Register 1 -------- */
#define PMC_PCDR1_PID32 (0x1u << 0) /**< \brief (PMC_PCDR1) Peripheral Clock 32 Disable */
#define PMC_PCDR1_PID33 (0x1u << 1) /**< \brief (PMC_PCDR1) Peripheral Clock 33 Disable */
#define PMC_PCDR1_PID34 (0x1u << 2) /**< \brief (PMC_PCDR1) Peripheral Clock 34 Disable */
#define PMC_PCDR1_PID35 (0x1u << 3) /**< \brief (PMC_PCDR1) Peripheral Clock 35 Disable */
#define PMC_PCDR1_PID36 (0x1u << 4) /**< \brief (PMC_PCDR1) Peripheral Clock 36 Disable */
#define PMC_PCDR1_PID37 (0x1u << 5) /**< \brief (PMC_PCDR1) Peripheral Clock 37 Disable */
#define PMC_PCDR1_PID38 (0x1u << 6) /**< \brief (PMC_PCDR1) Peripheral Clock 38 Disable */
#define PMC_PCDR1_PID39 (0x1u << 7) /**< \brief (PMC_PCDR1) Peripheral Clock 39 Disable */
#define PMC_PCDR1_PID40 (0x1u << 8) /**< \brief (PMC_PCDR1) Peripheral Clock 40 Disable */
#define PMC_PCDR1_PID41 (0x1u << 9) /**< \brief (PMC_PCDR1) Peripheral Clock 41 Disable */
#define PMC_PCDR1_PID42 (0x1u << 10) /**< \brief (PMC_PCDR1) Peripheral Clock 42 Disable */
#define PMC_PCDR1_PID43 (0x1u << 11) /**< \brief (PMC_PCDR1) Peripheral Clock 43 Disable */
/* -------- PMC_PCSR1 : (PMC Offset: 0x0108) Peripheral Clock Status Register 1 -------- */
#define PMC_PCSR1_PID32 (0x1u << 0) /**< \brief (PMC_PCSR1) Peripheral Clock 32 Status */
#define PMC_PCSR1_PID33 (0x1u << 1) /**< \brief (PMC_PCSR1) Peripheral Clock 33 Status */
#define PMC_PCSR1_PID34 (0x1u << 2) /**< \brief (PMC_PCSR1) Peripheral Clock 34 Status */
#define PMC_PCSR1_PID35 (0x1u << 3) /**< \brief (PMC_PCSR1) Peripheral Clock 35 Status */
#define PMC_PCSR1_PID36 (0x1u << 4) /**< \brief (PMC_PCSR1) Peripheral Clock 36 Status */
#define PMC_PCSR1_PID37 (0x1u << 5) /**< \brief (PMC_PCSR1) Peripheral Clock 37 Status */
#define PMC_PCSR1_PID38 (0x1u << 6) /**< \brief (PMC_PCSR1) Peripheral Clock 38 Status */
#define PMC_PCSR1_PID39 (0x1u << 7) /**< \brief (PMC_PCSR1) Peripheral Clock 39 Status */
#define PMC_PCSR1_PID40 (0x1u << 8) /**< \brief (PMC_PCSR1) Peripheral Clock 40 Status */
#define PMC_PCSR1_PID41 (0x1u << 9) /**< \brief (PMC_PCSR1) Peripheral Clock 41 Status */
#define PMC_PCSR1_PID42 (0x1u << 10) /**< \brief (PMC_PCSR1) Peripheral Clock 42 Status */
#define PMC_PCSR1_PID43 (0x1u << 11) /**< \brief (PMC_PCSR1) Peripheral Clock 43 Status */
/* -------- PMC_OCR : (PMC Offset: 0x0110) Oscillator Calibration Register -------- */
#define PMC_OCR_CAL4_Pos 0
#define PMC_OCR_CAL4_Msk (0x7fu << PMC_OCR_CAL4_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 4 MHz */
#define PMC_OCR_CAL4(value) ((PMC_OCR_CAL4_Msk & ((value) << PMC_OCR_CAL4_Pos)))
#define PMC_OCR_SEL4 (0x1u << 7) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 4 MHz */
#define PMC_OCR_CAL8_Pos 8
#define PMC_OCR_CAL8_Msk (0x7fu << PMC_OCR_CAL8_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 8 MHz */
#define PMC_OCR_CAL8(value) ((PMC_OCR_CAL8_Msk & ((value) << PMC_OCR_CAL8_Pos)))
#define PMC_OCR_SEL8 (0x1u << 15) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 8 MHz */
#define PMC_OCR_CAL12_Pos 16
#define PMC_OCR_CAL12_Msk (0x7fu << PMC_OCR_CAL12_Pos) /**< \brief (PMC_OCR) RC Oscillator Calibration bits for 12 MHz */
#define PMC_OCR_CAL12(value) ((PMC_OCR_CAL12_Msk & ((value) << PMC_OCR_CAL12_Pos)))
#define PMC_OCR_SEL12 (0x1u << 23) /**< \brief (PMC_OCR) Selection of RC Oscillator Calibration bits for 12 MHz */

/*@}*/


#endif /* _SAM4CP_PMC_COMPONENT_ */
