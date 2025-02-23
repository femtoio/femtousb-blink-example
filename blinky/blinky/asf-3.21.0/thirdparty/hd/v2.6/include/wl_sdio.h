/*!
 *  \file wl_sdio.h
 *  \brief SDIO interface for wl_api.
 *  Copyright (C) 2010 HD Wireless AB
 *
 *  You should have received a copy of the license along with this library.
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef WL_SDIO_H
#define WL_SDIO_H

/** \defgroup wl_sdio SDIO Interface
 *
 * These functions implement the interface that the wl_api library
 * needs to work with a SDIO transport layer.
 *
 * The functions prototyped here must be implemented when porting the
 * wl_api library to a new platform with a different SDIO configuration
 *
 * On platforms supported by H&D Wireless these functions are
 * implemented in the file avr32_sdio.c
 *
 *  @{
 */

/**
 * Maximum transfer size. This will set an upper limit on the len parameter
 * passed to wl_sdio_tx_cb() and wl_sdio_rx_cb().
 *
 */
#define MAX_BLOCK_LEN 512


/**
 * This flag might be set when wl_sdio_cmd_cb() is called in case the cmd will
 * be followed by a data transfer. If the flag is set, the transfer direction is
 * from the device to the host (read). Otherwise, the transfer direction is
 * from the host to the device (write).
 *
 */
 #define CMD_FLAG_TO_HOST (1 << 0)


/**
 * Indicates that the sdio driver needs to be polled in order to make
 * forward progress, i.e. it does not support interrupts
 *
 * The actual polling will result in wl_sdio_cmd_cb() being called to
 * request status information from the device.
 *
 * To activate polling, this flag should be set in wl_sdio_init_cb().
 */
#define SDIO_FLAG_POLL (1 << 0)

/**
 * Indicates that the sdio driver only supports 1-bit mode.
 *
 * To set 1-bit mode, this flag should be set in wl_sdio_init_cb().
 */
#define SDIO_FLAG_1BIT_MODE (1 << 1)

/**
 * This function will be invoked when wlan initialization should be performed,
 * this happens when the wl_fw_download() function in the transport group of
 * wl_api is invoked.
 *
 * The wifi device supports sdio high speed mode and clock frequencies up to
 * 50 MHz.
 *
 * The function is responsible for doing any necessary sdio initialization such
 * as allocating gpio's, setting up the mci master, one time allocations of
 * dma buffers etc.
 *
 * @param flags is an out parameter that should hold any sdio flags upon return.
 *        The avaible flags are prefixed with SDIO_FLAG_
 *
 *
 */
void wl_sdio_init_cb(uint8_t *flags);



/**
 * This function will be invoked when an sdio cmd should be sent to the
 * device.
 *
 * @param idx is the sdio command number
 * @param arg is the sdio command argument
 * @param flags specifies other options, such as any transfer direction.
 * @param rsp should hold the command response upon return. If null, the
 *        response can be ignored.
 * @param data holds a pointer to any data that might follow the command. This
 *        allows the sdio driver to setup dma transfers while waiting for the
 *        command response. NULL if no data transfer will follow. Note that
 *        the same data pointer will be passed to wl_sdio_tx_cb(), which should
 *        start the actual transfer.
 * @param len is the length of the data buffer.
 *
 */
void wl_sdio_cmd_cb(uint8_t idx, uint32_t arg, uint8_t flags, uint32_t *rsp,
                       const uint8_t *data, uint16_t len);


/**
 * This function will be invoked when data should be transmitted to the device.
 *
 * @param data holds a pointer to the data to transmit.
 * @param len is the length of the data buffer.
 *
 */
void wl_sdio_tx_cb(const uint8_t *data, uint16_t len);


/**
 * This function will be invoked when data should be received from the device.
 *
 * @param data should hold the read data upon return.
 * @param len is the number of bytes to read.
 *
 */
void wl_sdio_rx_cb(uint8_t *data, uint16_t len);


/**
 * Invoked when sdio rx interrupts from the device should be enabled or
 * disabled.
 *
 * If SDIO_FLAG_POLL was set in wl_spi_init_cb(), then this function can be
 * left empty.
 *
 * @param enable specifies if interrupts should be enabled or disabled.
 *
 */
void wl_sdio_irq_cb(uint8_t enable);


/**
 * This function should be called whenever an interrupt is detected. It can
 * be called from an interrupt context.
 *
 * If SDIO_FLAG_POLL was set in wl_sdio_init_cb(), then wl_sdio_irq()
 * should never be called.
 *
 */
extern void wl_sdio_irq(void);

/*!  @} */

#endif
