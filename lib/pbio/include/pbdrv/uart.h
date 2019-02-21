/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 David Lechner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * \addtogroup UARTDriver UART I/O driver
 * @{
 */

#ifndef _PBDRV_UART_H_
#define _PBDRV_UART_H_

#include <stdint.h>

#include "pbdrv/config.h"

#include "pbio/error.h"
#include "pbio/port.h"

#include "sys/process.h"


#if PBDRV_CONFIG_UART

/** @cond INTERNAL */

PROCESS_NAME(pbdrv_uart_process);

/** @endcond */

/**
 * Peeks at the next character in the UART receive buffer without removing it
 * from the buffer.
 * @param [in]  port    The I/O port
 * @param [out] c       The next character
 * @return              ::PBIO_SUCCESS if a character was available,
 *                      ::PBIO_ERROR_INVALID_PORT if the *port* does not have a
 *                      UART associated with it, or ::PBIO_ERROR_AGAIN if no
 *                      character was available to be read at this time.
 */
pbio_error_t pbdrv_uart_peek_char(pbio_port_t port, uint8_t *c);

/**
 * Reads one character from the UART receive buffer.
 * @param [in]  port    The I/O port
 * @param [out] c       The character read
 * @return              ::PBIO_SUCCESS if a character was available,
 *                      ::PBIO_ERROR_INVALID_PORT if the *port* does not have a
 *                      UART associated with it, or ::PBIO_ERROR_AGAIN if no
 *                      character was available to be read at this time.
 */
pbio_error_t pbdrv_uart_get_char(pbio_port_t port, uint8_t *c);

/**
 * Writes one character to the UART transmit buffer.
 * @param [in]  port    The I/O port
 * @param [in] c        The character write
 * @return              ::PBIO_SUCCESS if the *c* was written
 *                      ::PBIO_ERROR_INVALID_PORT if the *port* does not have a
 *                      UART associated with it, or ::PBIO_ERROR_AGAIN if the
 *                      character could not be written at this time.
 */
pbio_error_t pbdrv_uart_put_char(pbio_port_t port, uint8_t c);

/**
 * Sets the baud rate.
 * @param [in]  port    The I/O port
 * @param [in]  baud    The baud rate
 * @return              ::PBIO_SUCCESS if the baud rate was set or
 *                      ::PBIO_ERROR_INVALID_PORT if the *port* does not have a
 *                      UART associated with it.
 */
pbio_error_t pbdrv_uart_set_baud_rate(pbio_port_t port, uint32_t baud);

#else // PBDRV_CONFIG_UART

static inline pbio_error_t pbdrv_uart_peek_char(pbio_port_t port, uint8_t *c) { return PBIO_ERROR_NOT_SUPPORTED; }
static inline pbio_error_t pbdrv_uart_get_char(pbio_port_t port, uint8_t *c) { return PBIO_ERROR_NOT_SUPPORTED; }
static inline pbio_error_t pbdrv_uart_put_char(pbio_port_t port, uint8_t c) { return PBIO_ERROR_NOT_SUPPORTED; }
static inline pbio_error_t pbdrv_uart_set_baud_rate(pbio_port_t port, uint32_t baud) { return PBIO_ERROR_NOT_SUPPORTED; }

#endif // PBDRV_CONFIG_UART

#endif // _PBDRV_UART_H_

/** @}*/
