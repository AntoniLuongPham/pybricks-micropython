// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2020 The Pybricks Authors

#ifndef _PBDRVCONFIG_H_
#define _PBDRVCONFIG_H_

#define PBDRV_CONFIG_HUB_ID                         (PBIO_IODEV_TYPE_ID_NONE)

#define PBDRV_CONFIG_ADC                            (1)
#define PBDRV_CONFIG_ADC_STM32_HAL                  (1)
#define PBDRV_CONFIG_ADC_STM32_HAL_ADC_INSTANCE     ADC3
#define PBDRV_CONFIG_ADC_STM32_HAL_ADC_NUM_CHANNELS 6
#define PBDRV_CONFIG_ADC_STM32_HAL_DMA_INSTANCE     DMA2_Stream0
#define PBDRV_CONFIG_ADC_STM32_HAL_DMA_CHANNEL      DMA_CHANNEL_2
#define PBDRV_CONFIG_ADC_STM32_HAL_DMA_IRQ          DMA2_Stream0_IRQn
#define PBDRV_CONFIG_ADC_STM32_HAL_TIMER_INSTANCE   TIM2
#define PBDRV_CONFIG_ADC_STM32_HAL_TIMER_TRIGGER    ADC_EXTERNALTRIGCONV_T2_TRGO

#define PBDRV_CONFIG_BUTTON                         (1)
#define PBDRV_CONFIG_BUTTON_GPIO                    (1)
#define PBDRV_CONFIG_BUTTON_GPIO_NUM_BUTTON         (1)

#define PBDRV_CONFIG_GPIO                           (1)
#define PBDRV_CONFIG_GPIO_STM32F4                   (1)

#define PBDRV_CONFIG_IOPORT                         (1)

#define PBDRV_CONFIG_LIGHT                          (1)

#define PBDRV_CONFIG_UART                           (1)
#define PBDRV_CONFIG_UART_STM32_HAL                 (1)
#define PBDRV_CONFIG_UART_STM32_HAL_NUM_UART        (1)

#define PBDRV_CONFIG_HAS_PORT_1 (1)

#define PBDRV_CONFIG_FIRST_IO_PORT          PBIO_PORT_1
#define PBDRV_CONFIG_LAST_IO_PORT           PBIO_PORT_1
#define PBDRV_CONFIG_NUM_IO_PORT            (1)

#define PBDRV_CONFIG_SYS_CLOCK_RATE 48000000

#endif // _PBDRVCONFIG_H_
