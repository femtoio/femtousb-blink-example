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

#ifndef _SAM3S_UDP_INSTANCE_
#define _SAM3S_UDP_INSTANCE_

/* ========== Register definition for UDP peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_UDP_FRM_NUM           (0x40034000U) /**< \brief (UDP) Frame Number Register */
#define REG_UDP_GLB_STAT          (0x40034004U) /**< \brief (UDP) Global State Register */
#define REG_UDP_FADDR             (0x40034008U) /**< \brief (UDP) Function Address Register */
#define REG_UDP_IER               (0x40034010U) /**< \brief (UDP) Interrupt Enable Register */
#define REG_UDP_IDR               (0x40034014U) /**< \brief (UDP) Interrupt Disable Register */
#define REG_UDP_IMR               (0x40034018U) /**< \brief (UDP) Interrupt Mask Register */
#define REG_UDP_ISR               (0x4003401CU) /**< \brief (UDP) Interrupt Status Register */
#define REG_UDP_ICR               (0x40034020U) /**< \brief (UDP) Interrupt Clear Register */
#define REG_UDP_RST_EP            (0x40034028U) /**< \brief (UDP) Reset Endpoint Register */
#define REG_UDP_CSR               (0x40034030U) /**< \brief (UDP) Endpoint Control and Status Register */
#define REG_UDP_FDR               (0x40034050U) /**< \brief (UDP) Endpoint FIFO Data Register */
#define REG_UDP_TXVC              (0x40034074U) /**< \brief (UDP) Transceiver Control Register */
#else
#define REG_UDP_FRM_NUM  (*(RoReg*)0x40034000U) /**< \brief (UDP) Frame Number Register */
#define REG_UDP_GLB_STAT (*(RwReg*)0x40034004U) /**< \brief (UDP) Global State Register */
#define REG_UDP_FADDR    (*(RwReg*)0x40034008U) /**< \brief (UDP) Function Address Register */
#define REG_UDP_IER      (*(WoReg*)0x40034010U) /**< \brief (UDP) Interrupt Enable Register */
#define REG_UDP_IDR      (*(WoReg*)0x40034014U) /**< \brief (UDP) Interrupt Disable Register */
#define REG_UDP_IMR      (*(RoReg*)0x40034018U) /**< \brief (UDP) Interrupt Mask Register */
#define REG_UDP_ISR      (*(RoReg*)0x4003401CU) /**< \brief (UDP) Interrupt Status Register */
#define REG_UDP_ICR      (*(WoReg*)0x40034020U) /**< \brief (UDP) Interrupt Clear Register */
#define REG_UDP_RST_EP   (*(RwReg*)0x40034028U) /**< \brief (UDP) Reset Endpoint Register */
#define REG_UDP_CSR      (*(RwReg*)0x40034030U) /**< \brief (UDP) Endpoint Control and Status Register */
#define REG_UDP_FDR      (*(RwReg*)0x40034050U) /**< \brief (UDP) Endpoint FIFO Data Register */
#define REG_UDP_TXVC     (*(RwReg*)0x40034074U) /**< \brief (UDP) Transceiver Control Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAM3S_UDP_INSTANCE_ */
