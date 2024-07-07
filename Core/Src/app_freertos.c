/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern DASHBOARD_BASICINFO dashboard_basicinfo;
extern STEERING_BUTTONSTATUS current_steering_buttonstatus;
extern STEERING_BUTTONSTATUS last_steering_buttonstatus;

int8_t left_click = -1;
int8_t both_click = 0;
int8_t right_click = 1;

/* Definitions for basicinfo_queue */
osMessageQueueId_t basicinfo_queue_handle;
const osMessageQueueAttr_t basicinfo_queue_attributes = {
  .name = "basicinfo_queue"
};

/* Definitions for menuselect_queue */
osMessageQueueId_t menuselect_queue_handle;
const osMessageQueueAttr_t menuselect_queue_attributes = {
  .name = "menuselect_queue"
};

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for TouchGFXTask */
osThreadId_t TouchGFXTaskHandle;
const osThreadAttr_t TouchGFXTask_attributes = {
  .name = "TouchGFXTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 8192 * 4
};
/* Definitions for test_task */
osThreadId_t test_taskHandle;
const osThreadAttr_t test_task_attributes = {
  .name = "test_task",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for button_task */
osThreadId_t button_taskHandle;
const osThreadAttr_t button_task_attributes = {
  .name = "button_task",
  .priority = (osPriority_t) osPriorityBelowNormal,
  .stack_size = 128 * 4
};
/* Definitions for test_queue */
osMessageQueueId_t test_queueHandle;
const osMessageQueueAttr_t test_queue_attributes = {
  .name = "test_queue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void TouchGFX_Task(void *argument);
void test_task_func(void *argument);
void button_task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationMallocFailedHook(void);
void vApplicationIdleHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, char *pcTaskName);

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */
  /* creation of test_queue */
  test_queueHandle = osMessageQueueNew (2, sizeof(uint8_t), &test_queue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  basicinfo_queue_handle = osMessageQueueNew(2, sizeof(dashboard_basicinfo), &basicinfo_queue_attributes);
  menuselect_queue_handle = osMessageQueueNew(2, sizeof(int8_t), &menuselect_queue_attributes);
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of TouchGFXTask */
  TouchGFXTaskHandle = osThreadNew(TouchGFX_Task, NULL, &TouchGFXTask_attributes);

  /* creation of test_task */
  test_taskHandle = osThreadNew(test_task_func, NULL, &test_task_attributes);

  /* creation of button_task */
  button_taskHandle = osThreadNew(button_task, NULL, &button_task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartDefaultTask */
/**
* @brief Function implementing the defaultTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN defaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END defaultTask */
}

/* USER CODE BEGIN Header_test_task_func */
/**
* @brief Function implementing the test_task thread.
* @param argument: Not used
* @retval None
*/

uint8_t val = 0;
/* USER CODE END Header_test_task_func */
void test_task_func(void *argument)
{
  /* USER CODE BEGIN test_task */
  /* Infinite loop */
  for(;;)
  {
	  /* CAN Send example
	  CAN_Message can_message;
	  can_message.msg_id = (uint32_t)(0x100);
	  can_message.data_length = FDCAN_DLC_BYTES_8;
	  can_message.data[0] = 0x00;
	  can_message.data[1] = 0x00;
	  can_message.data[2] = 0x00;
	  can_message.data[3] = 0x00;
	  can_message.data[4] = 0x00;
	  can_message.data[5] = 0x00;
	  can_message.data[6] = 0x00;
	  can_message.data[7] = 0x00;
	  BSP_CAN_Send_Message(can_message.msg_id, can_message.data_length, can_message.data);
	  */
	  osMessageQueuePut(basicinfo_queue_handle, &dashboard_basicinfo, 0, 0);

	  osMessageQueuePut(test_queueHandle, &val, 0, 0);
	  val++;

	  // Task gets executed every 100 ms
	  osDelay(100);
  }
  /* USER CODE END test_task */
}

/* USER CODE BEGIN Header_button_task */
/**
* @brief Function implementing the button_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_button_task */
void button_task(void *argument)
{
  /* USER CODE BEGIN button_task */
	static int button_pressed = 0;
  /* Infinite loop */
  for(;;)
  {
	  // First check of buttons
	  if((current_steering_buttonstatus.shift_left != last_steering_buttonstatus.shift_left ||
			  current_steering_buttonstatus.shift_right != last_steering_buttonstatus.shift_right) &&
			  !button_pressed)
	  {
		  last_steering_buttonstatus.shift_left = current_steering_buttonstatus.shift_left;
		  last_steering_buttonstatus.shift_right = current_steering_buttonstatus.shift_right;

		  button_pressed = 1;
	  }

	  if(button_pressed)
	  {

		  if(current_steering_buttonstatus.shift_left && !current_steering_buttonstatus.shift_right)
		  {
			  // Left button click
			  osMessageQueuePut(menuselect_queue_handle, &left_click, 0, 0);
		  } else if(!current_steering_buttonstatus.shift_left && current_steering_buttonstatus.shift_right)
		  {
			  // Right button click
			  osMessageQueuePut(menuselect_queue_handle, &right_click, 0, 0);
		  } else if(current_steering_buttonstatus.shift_left && current_steering_buttonstatus.shift_right)
		  {
			  // Both buttons clicked
			  osMessageQueuePut(menuselect_queue_handle, &both_click, 0, 0);
		  }

		  button_pressed = 0;
	  }
    osDelay(50);
  }
  /* USER CODE END button_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

