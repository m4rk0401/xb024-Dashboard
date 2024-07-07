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
#include "stm32u5xx_hal.h"

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
#define LCD_DISP_RESET_Pin GPIO_PIN_7
#define LCD_DISP_RESET_GPIO_Port GPIOH
#define CTP_RST_Pin GPIO_PIN_3
#define CTP_RST_GPIO_Port GPIOE
#define USR_BTN_1_Pin GPIO_PIN_3
#define USR_BTN_1_GPIO_Port GPIOJ
#define USR_LED_1_Pin GPIO_PIN_5
#define USR_LED_1_GPIO_Port GPIOE
#define CTP_INT_Pin GPIO_PIN_6
#define CTP_INT_GPIO_Port GPIOE
#define CTP_INT_EXTI_IRQn EXTI6_IRQn
#define USB_PWR_EN_Pin GPIO_PIN_8
#define USB_PWR_EN_GPIO_Port GPIOG
#define USB_OVERCURRENT_Pin GPIO_PIN_0
#define USB_OVERCURRENT_GPIO_Port GPIOJ
#define R_RST_Pin GPIO_PIN_4
#define R_RST_GPIO_Port GPIOF
#define R_CS_Pin GPIO_PIN_1
#define R_CS_GPIO_Port GPIOG
#define R_INT_Pin GPIO_PIN_4
#define R_INT_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* CAN message type */
typedef struct CAN_Message
{
	uint32_t msg_id;
	uint32_t data_length;
	uint8_t data[8];
} CAN_Message;

typedef enum {
	SKIDPAD = 1,
	ACCEL,
	AUTOX,
	ENDU,
	BASEMODE,
	DV_TRACKDRIVE,
	DV_ACCEL,
	DV_SKIDPAD,
	DV_AUTOX,
	DV_EBSTEST,
	BRAKETEST,
	EV_SCRUTI,
	DV_INSPECTION,
} Mission;

typedef enum {
	CLOSED = 0,
	SHUTDOWN_BUTTON_MAINHOOP,
	SHUTDOWN_BUTTON_COCKPIT,
	INERTIASWITCH,
	EBS,
	BOTS,
	AMS,
	IMD,
	MOTOR_REAR_LEFT,
	MOTOR_REAR_RIGHT,
	MOTOR_FRONT_RIGHT,
	MOTOR_FRONT_LEFT,
	HVD,
	BSPD,
	RES,
	TSMS,
} SDC;


typedef struct DASHBOARD_BASICINFO
{
	Mission mission_val;
	SDC sdc_val;
	uint8_t soc_val;

	char mission_text[12];
	char sdc_text[12];
} DASHBOARD_BASICINFO;

extern const char *missions[];
extern const char *sdc[];

typedef struct STEERING_BUTTONSTATUS
{
	uint8_t shift_left;
	uint8_t shift_right;
} STEERING_BUTTONSTATUS;

extern int last_debounce;
extern int debounce_delay;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
