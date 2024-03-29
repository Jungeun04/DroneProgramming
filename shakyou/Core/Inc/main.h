/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin LL_GPIO_PIN_0
#define LED1_GPIO_Port GPIOC
#define LED2_Pin LL_GPIO_PIN_1
#define LED2_GPIO_Port GPIOC
#define LED3_Pin LL_GPIO_PIN_2
#define LED3_GPIO_Port GPIOC
#define SPI1_20602_MISO_Pin LL_GPIO_PIN_6
#define SPI1_20602_MISO_GPIO_Port GPIOA
#define SPI1_20602_MOSI_Pin LL_GPIO_PIN_7
#define SPI1_20602_MOSI_GPIO_Port GPIOA
#define SPI1_20602_CS_Pin LL_GPIO_PIN_4
#define SPI1_20602_CS_GPIO_Port GPIOC
#define ICM20602_Interrupt_Pin LL_GPIO_PIN_5
#define ICM20602_Interrupt_GPIO_Port GPIOC
#define Buzzer_Pin LL_GPIO_PIN_1
#define Buzzer_GPIO_Port GPIOB
#define BNO080_CS_Pin LL_GPIO_PIN_12
#define BNO080_CS_GPIO_Port GPIOB
#define SPI_BNO080_MISO_Pin LL_GPIO_PIN_14
#define SPI_BNO080_MISO_GPIO_Port GPIOB
#define SPI2_BNO080_MOSI_Pin LL_GPIO_PIN_15
#define SPI2_BNO080_MOSI_GPIO_Port GPIOB
#define BNO080_Interrupt_Pin LL_GPIO_PIN_8
#define BNO080_Interrupt_GPIO_Port GPIOC
#define BNO080_RESET_Pin LL_GPIO_PIN_9
#define BNO080_RESET_GPIO_Port GPIOC
#define BNO080_WAKE_Pin LL_GPIO_PIN_8
#define BNO080_WAKE_GPIO_Port GPIOA
#define SPI3_LPS22_MISO_Pin LL_GPIO_PIN_4
#define SPI3_LPS22_MISO_GPIO_Port GPIOB
#define SPI3_LPS22_MOSI_Pin LL_GPIO_PIN_5
#define SPI3_LPS22_MOSI_GPIO_Port GPIOB
#define LPS22_CS_Pin LL_GPIO_PIN_6
#define LPS22_CS_GPIO_Port GPIOB
#define LPS22_Interrupt_Pin LL_GPIO_PIN_7
#define LPS22_Interrupt_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
