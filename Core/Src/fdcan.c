/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
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
/* Includes ------------------------------------------------------------------*/
#include "fdcan.h"

/* USER CODE BEGIN 0 */
#include <stdbool.h>
#include <string.h>

FDCAN_TxHeaderTypeDef fdcan_txheader;
FDCAN_RxHeaderTypeDef fdcan_rxheader;

uint8_t fdcan_rxdata[8] = {};
uint8_t fdcan_txdata[8] = {};


/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.ClockDivider = FDCAN_CLOCK_DIV1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 10;
  hfdcan1.Init.NominalSyncJumpWidth = 2;
  hfdcan1.Init.NominalTimeSeg1 = 5;
  hfdcan1.Init.NominalTimeSeg2 = 2;
  hfdcan1.Init.DataPrescaler = 2;
  hfdcan1.Init.DataSyncJumpWidth = 2;
  hfdcan1.Init.DataTimeSeg1 = 5;
  hfdcan1.Init.DataTimeSeg2 = 2;
  hfdcan1.Init.StdFiltersNbr = 1;
  hfdcan1.Init.ExtFiltersNbr = 1;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */

  /* USER CODE END FDCAN1_Init 2 */

}

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN1;
    PeriphClkInit.Fdcan1ClockSelection = RCC_FDCAN1CLKSOURCE_PLL1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* FDCAN1 clock enable */
    __HAL_RCC_FDCAN1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PB8     ------> FDCAN1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN1_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PB8     ------> FDCAN1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9|GPIO_PIN_8);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void BSP_CAN_Start(void)
{
	/* Configure CAN reception filter */
	BSP_CAN_Filter_Config();

	/* Enable interrupts*/
	HAL_FDCAN_ActivateNotification(&hfdcan1,FDCAN_IT_RX_FIFO0_NEW_MESSAGE,0);


	/* Start CAN peripheral device  */
	if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief Configure the CAN reception filter by calling this function.
 * @attention This function should be called before starting the CAN module on your board.
 * @param None.
 * @retval None.
 */
void BSP_CAN_Filter_Config(void)
{
	FDCAN_FilterTypeDef filter_config;

	filter_config.IdType = FDCAN_STANDARD_ID;
	filter_config.FilterIndex = 0;
	filter_config.FilterType = FDCAN_FILTER_RANGE;
	filter_config.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
	filter_config.FilterID1 = 0x000;
	filter_config.FilterID2 = 0x280;


	if (HAL_FDCAN_ConfigFilter(&hfdcan1, &filter_config) != HAL_OK)
	{
		Error_Handler();
	}
	if(HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK){

		Error_Handler();
	}
}

/**
 * @brief Start CAN module, configure the filter and make it capable to transmit and receive the message.
 * @attention !This function should be called after MX_CAN_Init(), before while(1) to make CAN peripheral device correctly start.
 * @param None.
 * @retval None.
 */
void BSP_CAN_Send_Message(uint32_t message_id, uint32_t message_length, uint8_t* tx_message)
{

	fdcan_txheader.Identifier = message_id;
	fdcan_txheader.DataLength = message_length;
	fdcan_txheader.IdType = FDCAN_STANDARD_ID;
	fdcan_txheader.TxFrameType = FDCAN_DATA_FRAME;
	fdcan_txheader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	fdcan_txheader.BitRateSwitch = FDCAN_BRS_OFF;
	fdcan_txheader.FDFormat = FDCAN_CLASSIC_CAN;
	fdcan_txheader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	fdcan_txheader.MessageMarker = 0;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1,&fdcan_txheader,tx_message) != HAL_OK)
	{
		//Error_Handler();
	}
}

/**
  * @brief  Rx FIFO 0 callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo0ITs indicates which Rx FIFO 0 interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Rx_Fifo0_Interrupts.
  * @retval None
  */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE)!= 0)
	{
		if(HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &fdcan_rxheader, fdcan_rxdata)!=HAL_OK)
		{
			Error_Handler();
		}

		// Msg: VCU_Dashboard_BasicInfo
		if(fdcan_rxheader.Identifier == 0x280)
		{
			dashboard_basicinfo.mission_val = fdcan_rxdata[2] & 0x0F;
			dashboard_basicinfo.sdc_val = (fdcan_rxdata[2] & 0xF0) >> 4;
			dashboard_basicinfo.soc_val = fdcan_rxdata[3];

			// check limits
			if(dashboard_basicinfo.mission_val < 1) dashboard_basicinfo.mission_val = 1;
			else if(dashboard_basicinfo.mission_val > 13) dashboard_basicinfo.mission_val = 13;

			if(dashboard_basicinfo.sdc_val < 0) dashboard_basicinfo.sdc_val = 0;
			else if(dashboard_basicinfo.sdc_val > 15) dashboard_basicinfo.sdc_val = 15;

			if(dashboard_basicinfo.soc_val < 0) dashboard_basicinfo.soc_val = 0;
			else if(dashboard_basicinfo.soc_val > 100) dashboard_basicinfo.soc_val = 100;

			// set strings
			strcpy(dashboard_basicinfo.mission_text, missions[dashboard_basicinfo.mission_val - 1]);	// -1 because data of can frame starts with value 1
			strcpy(dashboard_basicinfo.sdc_text, sdc[dashboard_basicinfo.sdc_val]);
		}

		// Msg: VCU_ButtonStatus
		if(fdcan_rxheader.Identifier == 0x223)
		{
			current_steering_buttonstatus.shift_left = (fdcan_rxdata[1] & 0b00000100) >> 2;
			current_steering_buttonstatus.shift_right = (fdcan_rxdata[0] & 0b00000010) >> 1;
		}
	}
	HAL_FDCAN_ActivateNotification(&hfdcan1,FDCAN_IT_RX_FIFO0_NEW_MESSAGE,0);
}
/* USER CODE END 1 */
