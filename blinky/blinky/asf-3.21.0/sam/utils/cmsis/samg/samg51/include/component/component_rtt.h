/**
 * \file
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


#ifndef _SAMG51_RTT_COMPONENT_
#define _SAMG51_RTT_COMPONENT_

/* ============================================================================= */
/**  SOFTWARE API DEFINITION FOR Real-time Timer */
/* ============================================================================= */
/** \addtogroup SAMG51_RTT Real-time Timer */
/*@{*/

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief Rtt hardware registers */
typedef struct {
  __IO uint32_t RTT_MR; /**< \brief (Rtt Offset: 0x00) Mode Register */
  __IO uint32_t RTT_AR; /**< \brief (Rtt Offset: 0x04) Alarm Register */
  __I  uint32_t RTT_VR; /**< \brief (Rtt Offset: 0x08) Value Register */
  __I  uint32_t RTT_SR; /**< \brief (Rtt Offset: 0x0C) Status Register */
} Rtt;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */
/* -------- RTT_MR : (RTT Offset: 0x00) Mode Register -------- */
#define RTT_MR_RTPRES_Pos 0
#define RTT_MR_RTPRES_Msk (0xffffu << RTT_MR_RTPRES_Pos) /**< \brief (RTT_MR) Real-time Timer Prescaler Value */
#define RTT_MR_RTPRES(value) ((RTT_MR_RTPRES_Msk & ((value) << RTT_MR_RTPRES_Pos)))
#define RTT_MR_ALMIEN (0x1u << 16) /**< \brief (RTT_MR) Alarm Interrupt Enable */
#define RTT_MR_RTTINCIEN (0x1u << 17) /**< \brief (RTT_MR) Real-time Timer Increment Interrupt Enable */
#define RTT_MR_RTTRST (0x1u << 18) /**< \brief (RTT_MR) Real-time Timer Restart */
#define RTT_MR_RTTDIS (0x1u << 20) /**< \brief (RTT_MR) Real-time Timer Disable */
#define RTT_MR_RTC1HZ (0x1u << 24) /**< \brief (RTT_MR) Real-Time Clock 1 Hz Clock Selection */
/* -------- RTT_AR : (RTT Offset: 0x04) Alarm Register -------- */
#define RTT_AR_ALMV_Pos 0
#define RTT_AR_ALMV_Msk (0xffffffffu << RTT_AR_ALMV_Pos) /**< \brief (RTT_AR) Alarm Value */
#define RTT_AR_ALMV(value) ((RTT_AR_ALMV_Msk & ((value) << RTT_AR_ALMV_Pos)))
/* -------- RTT_VR : (RTT Offset: 0x08) Value Register -------- */
#define RTT_VR_CRTV_Pos 0
#define RTT_VR_CRTV_Msk (0xffffffffu << RTT_VR_CRTV_Pos) /**< \brief (RTT_VR) Current Real-time Value */
/* -------- RTT_SR : (RTT Offset: 0x0C) Status Register -------- */
#define RTT_SR_ALMS (0x1u << 0) /**< \brief (RTT_SR) Real-time Alarm Status */
#define RTT_SR_RTTINC (0x1u << 1) /**< \brief (RTT_SR) Prescaler Roll-over Status */

/*@}*/


#endif /* _SAMG51_RTT_COMPONENT_ */
