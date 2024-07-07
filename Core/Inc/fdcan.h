/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.h
  * @brief   This file contains all the function prototypes for
  *          the fdcan.c file
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
#ifndef __FDCAN_H__
#define __FDCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern FDCAN_HandleTypeDef hfdcan1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_FDCAN1_Init(void);

/* USER CODE BEGIN Prototypes */
extern DASHBOARD_BASICINFO dashboard_basicinfo;
extern STEERING_BUTTONSTATUS current_steering_buttonstatus;
extern STEERING_BUTTONSTATUS last_steering_buttonstatus;
extern const char *missions[];

void BSP_CAN_Start(void);
void BSP_CAN_Filter_Config(void);
void BSP_CAN_Send_Message(uint32_t message_id, uint32_t message_length, uint8_t* tx_message);
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __FDCAN_H__ */

