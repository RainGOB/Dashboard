/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lvgl.h"
#include "lv_port_disp.h"
#include "ui.h"
#include "bsp_can.h"
#include "app_EC200.h"
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

/* USER CODE END Variables */
/* Definitions for ec20 */
osThreadId_t ec20Handle;
const osThreadAttr_t ec20_attributes = {
  .name = "ec20",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for lvgl_meter */
osThreadId_t lvgl_meterHandle;
const osThreadAttr_t lvgl_meter_attributes = {
  .name = "lvgl_meter",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityRealtime2,
};
/* Definitions for lvgl */
osThreadId_t lvglHandle;
const osThreadAttr_t lvgl_attributes = {
  .name = "lvgl",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityRealtime1,
};
/* Definitions for Iot_upload */
osThreadId_t Iot_uploadHandle;
const osThreadAttr_t Iot_upload_attributes = {
  .name = "Iot_upload",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for lvgl_mutex */
osMutexId_t lvgl_mutexHandle;
const osMutexAttr_t lvgl_mutex_attributes = {
  .name = "lvgl_mutex"
};
/* Definitions for Upld_data_event */
osEventFlagsId_t Upld_data_eventHandle;
const osEventFlagsAttr_t Upld_data_event_attributes = {
  .name = "Upld_data_event"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void entry_ec20(void *argument);
void entry_lvgl_meter(void *argument);
void entry_lvgl(void *argument);
void entry_Iot_upload(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of lvgl_mutex */
  lvgl_mutexHandle = osMutexNew(&lvgl_mutex_attributes);

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
  /* creation of ec20 */
  ec20Handle = osThreadNew(entry_ec20, NULL, &ec20_attributes);

  /* creation of lvgl_meter */
  lvgl_meterHandle = osThreadNew(entry_lvgl_meter, NULL, &lvgl_meter_attributes);

  /* creation of lvgl */
  lvglHandle = osThreadNew(entry_lvgl, NULL, &lvgl_attributes);

  /* creation of Iot_upload */
//  Iot_uploadHandle = osThreadNew(entry_Iot_upload, NULL, &Iot_upload_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* creation of Upld_data_event */
  Upld_data_eventHandle = osEventFlagsNew(&Upld_data_event_attributes);

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_entry_ec20 */
/**
  * @brief  Function implementing the ec20 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_entry_ec20 */
void entry_ec20(void *argument)
{
  /* USER CODE BEGIN entry_ec20 */

	//uint32_t event_bit;
  /* Infinite loop */
  for(;;)
  {
	// event_bit = osEventFlagsWait(Upld_data_eventHandle,  //等待整车数据，收不到就不运行这一任务
	//							GUI_UPDATE_EVENT,
	//							osFlagsWaitAll,
	//							osWaitForever);
	 MQTTClient_RdyFlag = EC200_MQTTInit(); 
	
	  if(MQTTClient_RdyFlag)
		Iot_uploadHandle = osThreadNew(entry_Iot_upload, NULL, &Iot_upload_attributes);
	  osDelay(500);
	  if(PUBOK_Flag == 1){
		  osThreadSuspend(ec20Handle);
	  }
  }
  /* USER CODE END entry_ec20 */
}

/* USER CODE BEGIN Header_entry_lvgl_meter */
/**
* @brief Function implementing the lvgl_meter thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_entry_lvgl_meter */
void entry_lvgl_meter(void *argument)
{
  /* USER CODE BEGIN entry_lvgl_meter */
	canfilter_init();
	uint32_t event_bit;
  /* Infinite loop */
  for(;;)
  {
	  	  
	  event_bit = osEventFlagsWait(Upld_data_eventHandle,	//等待整车数据，收不到就不运行这一任务
								GUI_UPDATE_EVENT,
								osFlagsWaitAll,
								osWaitForever);
	  osMutexWait(lvgl_mutexHandle,     /* 互斥量句柄 */ 
                          osWaitForever); 
	  if(event_bit){
		  
	      lv_label_set_text_fmt(ui_speed_num, "%03d", racingCarData.FrontSpeed);
		  lv_label_set_text_fmt(ui_LRPM, "%04d", racingCarData.lmotorSpeed);
		  lv_label_set_text_fmt(ui_RRPM, "%03d", racingCarData.rmotorSpeed);
		  lv_label_set_text_fmt(ui_LmotorTem, "%02d", racingCarData.lmotorTemp);
		  lv_label_set_text_fmt(ui_RmotorTem, "%02d", racingCarData.rmotorTemp);
		  lv_label_set_text_fmt(ui_LmcuTem,"%02d",racingCarData.mcu1Temp);
		  lv_label_set_text_fmt(ui_RmcuTem,"%02d",racingCarData.mcu2Temp);
		  lv_label_set_text_fmt(ui_power_battery_Label,"%d%%",racingCarData.batLevel);
	  
		  lv_slider_set_value(ui_power_battery_Slider,racingCarData.batLevel,LV_ANIM_ON);
		  lv_arc_set_value(ui_speed_arc,racingCarData.FrontSpeed);
		  lv_arc_set_value(ui_Arc2,racingCarData.lmotorSpeed);
		  lv_arc_set_value(ui_Arc3,racingCarData.rmotorSpeed);
		  if(racingCarData.gearMode == 1){
			  lv_obj_set_style_text_color(ui_gear, lv_color_hex(0x32C832), LV_PART_MAIN | LV_STATE_DEFAULT);
			  lv_label_set_text(ui_gear, "C");}
			  else if(racingCarData.gearMode == 0){
			      lv_obj_set_style_text_color(ui_gear, lv_color_hex(0x4195F4), LV_PART_MAIN | LV_STATE_DEFAULT);
//				  lv_obj_set_style_text_color(ui_logoLable, lv_color_hex(0x41A0FF), LV_PART_MAIN | LV_STATE_DEFAULT);
				  lv_label_set_text(ui_gear, "N");}
			  else{
				  lv_obj_set_style_text_color(ui_gear, lv_color_hex(0xF6550E), LV_PART_MAIN | LV_STATE_DEFAULT);
				  lv_label_set_text(ui_gear, "S");}
	 }
	  osMutexRelease(lvgl_mutexHandle);
  }
  /* USER CODE END entry_lvgl_meter */
}

/* USER CODE BEGIN Header_entry_lvgl */
/**
* @brief Function implementing the lvgl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_entry_lvgl */
void entry_lvgl(void *argument)
{
  /* USER CODE BEGIN entry_lvgl */
  /* Infinite loop */
  for(;;)
  {
	  osMutexWait(lvgl_mutexHandle,     /* 互斥量句柄 */ 
                          osWaitForever); 
	  	if(barFlag == 1)
		{
			sendEventCode();	
		}
	  lv_task_handler();
	  osMutexRelease(lvgl_mutexHandle);
	  
	  osDelay(1);
  }
  /* USER CODE END entry_lvgl */
}

/* USER CODE BEGIN Header_entry_Iot_upload */
/**
* @brief Function implementing the Iot_upload thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_entry_Iot_upload */
void entry_Iot_upload(void *argument)
{
  /* USER CODE BEGIN entry_Iot_upload */
	uint32_t event_bit;
  /* Infinite loop */
  for(;;)
  {
	  	 event_bit = osEventFlagsWait(Upld_data_eventHandle,  //等待整车数据，收不到就不运行这一任务
								GUI_UPDATE_EVENT,
								osFlagsWaitAll,
								osWaitForever);
	  if(eTaskGetState(ec20Handle) == eSuspended)
	  {
		  if(PUBOK_Flag == 1 )
		  {
	//	  	 if(uploadFlag)     //上车后记得解开
	//		  {
					Tx_Flag = 1;
					printf("\nuploadcardata\n");
					jsonPack();
	//		  }
	//		  uploadFlag = 0;
		 }
		  else
			 osThreadResume(ec20Handle);
	  }	
	  osDelay(100);
  }
  /* USER CODE END entry_Iot_upload */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

