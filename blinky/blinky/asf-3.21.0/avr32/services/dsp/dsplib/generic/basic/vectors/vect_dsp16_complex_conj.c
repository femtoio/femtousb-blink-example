/*****************************************************************************
 *
 * \file
 *
 * \brief generic 16-bit complex conjugate function
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
 ******************************************************************************/
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */


#include "dsp.h"
#include "preprocessor.h"

#if defined(FORCE_ALL_GENERICS) || \
    defined(FORCE_GENERIC_VECT16_COMPLEXCONJ) || \
    !defined(TARGET_SPECIFIC_VECT16_COMPLEXCONJ)

#define DSP16_COMPLEXCONJUGATE(x_num, data) \
  temp = vect1[x_num].real; \
  vect1[x_num].real = vect2[x_num].imag; \
  vect1[x_num].imag = temp;

/*********************************************************************************************
 * This function is the ending function of the conj. It is used to conjugate the last items of a vector.
 *********************************************************************************************/
#define DSP16_COMPLEXCONJ_KERNEL_X_FCT(x_num, data)    \
static void TPASTE2(dsp16_vect_complexconj_kernel_x, x_num)(dsp16_complex_t *vect1, dsp16_complex_t *vect2) \
{ \
  dsp16_t temp; \
  MREPEAT(x_num, DSP16_COMPLEXCONJUGATE, ""); \
}

static void dsp16_vect_complexconj_kernel_x0(dsp16_complex_t *vect1, dsp16_complex_t *vect2)
{
}
/*********************************************************************************************/

DSP16_COMPLEXCONJ_KERNEL_X_FCT(1, "")
DSP16_COMPLEXCONJ_KERNEL_X_FCT(2, "")
DSP16_COMPLEXCONJ_KERNEL_X_FCT(3, "")

void dsp16_vect_complex_conj(dsp16_complex_t *vect1, dsp16_complex_t *vect2, int size)
{
  typedef void (*complexconj_kernel_opti_t)(dsp16_complex_t *, dsp16_complex_t *);
  static const complexconj_kernel_opti_t complexconj_end_kernel_opti[4] = {
    dsp16_vect_complexconj_kernel_x0,
    dsp16_vect_complexconj_kernel_x1,
    dsp16_vect_complexconj_kernel_x2,
    dsp16_vect_complexconj_kernel_x3
  };
  int n;

  for(n=0; n<size-3; n+=4)
  {
    dsp16_t temp;

    DSP16_COMPLEXCONJUGATE(n, "");
    DSP16_COMPLEXCONJUGATE(n+1, "");
    DSP16_COMPLEXCONJUGATE(n+2, "");
    DSP16_COMPLEXCONJUGATE(n+3, "");
  }

  // Jump on different functions depending on the length of the vectors to compute
  complexconj_end_kernel_opti[size&0x3](&vect1[n], &vect2[n]);
}

#endif
