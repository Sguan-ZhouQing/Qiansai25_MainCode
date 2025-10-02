/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lvgl.h"
#include "gui_guider.h"
extern lv_ui guider_ui;

#include "json.h"
#include "esp.h"
#include "printf.h"
#include "Infrared_Sensor.h"
#include <stdbool.h>
#include "Buzzer.h"
#include "gpio.h"
#include "Yaocang.h"
#include "G431_Control.h"
#include "aht20.h"
#include "Key.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
SemaphoreHandle_t sharedResourceMutex;
SemaphoreHandle_t sharedResourceMutey;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId Lvgl_Main_TaskHandle;
osThreadId mianTask_OneHandle;
osThreadId mianTask_TwoHandle;
osThreadId mianTask_ThreeHandle;
osThreadId mianTickHandle;
osThreadId Lvgl_TickHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartLvgl(void const * argument);
void StartTaskOne(void const * argument);
void StartTaskTwo(void const * argument);
void StartTaskThree(void const * argument);
void StartTickMain(void const * argument);
void StartLvglTick(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  sharedResourceMutex = xSemaphoreCreateMutex();
  sharedResourceMutey = xSemaphoreCreateMutex();
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

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityLow, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of Lvgl_Main_Task */
  osThreadDef(Lvgl_Main_Task, StartLvgl, osPriorityAboveNormal, 0, 1024);
  Lvgl_Main_TaskHandle = osThreadCreate(osThread(Lvgl_Main_Task), NULL);

  /* definition and creation of mianTask_One */
  osThreadDef(mianTask_One, StartTaskOne, osPriorityBelowNormal, 0, 512);
  mianTask_OneHandle = osThreadCreate(osThread(mianTask_One), NULL);

  /* definition and creation of mianTask_Two */
  osThreadDef(mianTask_Two, StartTaskTwo, osPriorityBelowNormal, 0, 256);
  mianTask_TwoHandle = osThreadCreate(osThread(mianTask_Two), NULL);

  /* definition and creation of mianTask_Three */
  osThreadDef(mianTask_Three, StartTaskThree, osPriorityBelowNormal, 0, 256);
  mianTask_ThreeHandle = osThreadCreate(osThread(mianTask_Three), NULL);

  /* definition and creation of mianTick */
  osThreadDef(mianTick, StartTickMain, osPriorityNormal, 0, 128);
  mianTickHandle = osThreadCreate(osThread(mianTick), NULL);

  /* definition and creation of Lvgl_Tick */
  osThreadDef(Lvgl_Tick, StartLvglTick, osPriorityHigh, 0, 128);
  Lvgl_TickHandle = osThreadCreate(osThread(Lvgl_Tick), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  osThreadSuspend(mianTask_ThreeHandle);
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartLvgl */
/**
* @brief Function implementing the Lvgl_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLvgl */
void StartLvgl(void const * argument)
{
  /* USER CODE BEGIN StartLvgl */
  /* Infinite loop */
  for(;;)
  {
    if(xSemaphoreTake(sharedResourceMutex, pdMS_TO_TICKS(100)) == pdTRUE)
    {
      /* 临界区开�?????? - 安全访问共享资源 */
      lv_task_handler();
      /* 临界区结束，并释放互斥锁 */
      xSemaphoreGive(sharedResourceMutex);  // 释放�??????
    }
    osDelay(10);
  }
  /* USER CODE END StartLvgl */
}

/* USER CODE BEGIN Header_StartTaskOne */
/**
* @brief Function implementing the mianTask_One thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskOne */
void StartTaskOne(void const * argument)
{
  /* USER CODE BEGIN StartTaskOne */
  /* Infinite loop */
  for(;;)
  {
    if(xSemaphoreTake(sharedResourceMutey, pdMS_TO_TICKS(100)) == pdTRUE)
    {
      Json_ProcessData_Tick();
      Yaocang_Command_Tick();
      xSemaphoreGive(sharedResourceMutey);  // 释放互斥�?
    }
    osDelay(10);
  }
  /* USER CODE END StartTaskOne */
}

/* USER CODE BEGIN Header_StartTaskTwo */
/**
* @brief Function implementing the mianTask_Two thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskTwo */
void StartTaskTwo(void const * argument)
{
  /* USER CODE BEGIN StartTaskTwo */
  /* Infinite loop */
  for(;;)
  {
    G431_RoboticControl_Tick();
    Infrared_Tick();
    Yaocang_Button_Tick();
    osDelay(5);
  }
  /* USER CODE END StartTaskTwo */
}

/* USER CODE BEGIN Header_StartTaskThree */
/**
* @brief Function implementing the mianTask_Three thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskThree */
void StartTaskThree(void const * argument)
{
  /* USER CODE BEGIN StartTaskThree */
  /* Infinite loop */
  for(;;)
  {
    if(xSemaphoreTake(sharedResourceMutey, pdMS_TO_TICKS(100)) == pdTRUE)
    {
      AGT20_Upadte_Tick();
      GetHumanDistance_Tick();
      xSemaphoreGive(sharedResourceMutey);  // 释放互斥�?
    }
    osDelay(10);
  }
  /* USER CODE END StartTaskThree */
}

/* USER CODE BEGIN Header_StartTickMain */
/**
* @brief Function implementing the mianTick thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTickMain */
void StartTickMain(void const * argument)
{
  /* USER CODE BEGIN StartTickMain */
  /* Infinite loop */
  for(;;)
  {
    Key_Tick();
    osDelay(1);
  }
  /* USER CODE END StartTickMain */
}

/* USER CODE BEGIN Header_StartLvglTick */
/**
* @brief Function implementing the Lvgl_Tick thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLvglTick */
void StartLvglTick(void const * argument)
{
  /* USER CODE BEGIN StartLvglTick */
  /* Infinite loop */
  for(;;)
  {
    if(xSemaphoreTake(sharedResourceMutex, pdMS_TO_TICKS(100)) == pdTRUE)
    {
      /* 临界区开�????? - 安全访问共享资源 */
      lv_tick_inc(1);
      /* 临界区结束，释放互斥�????? */
      xSemaphoreGive(sharedResourceMutex);  // 释放�?????
    }
    osDelay(1);
  }
  /* USER CODE END StartLvglTick */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
