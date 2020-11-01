/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define Slave_Code 1	//从机编号
#define ADDRH "FF"		//设备高8位地址
#define ADDRL "01"		//设备低8位地址
#define POWER 3				//设备发射功率  3:  20dbm(MAX)
#define CWMODE 0			//设备工作模式配置  0：  一般模式
#define CHANNEL 21		//设备信道 
#define RATE 5				//设备无线速率  5：  19.2kbps(MAX)
#define UART_RATE	7		//串口波特率		7：  115200
#define UART_PAR	0		//数据校验位		0：	 无校验

#define Capture_Times 1

#define USART2_MAX_RECV_LEN		1024					//最大接收缓存字节数
#define REC_LENGTH 1

extern uint8_t USART2_RX_BUF[USART2_MAX_RECV_LEN]; 		//接收存储,最大USART3_MAX_RECV_LEN字节
extern uint8_t USART2_RX_Flag;		//接收完成标志
extern uint8_t USART2_RX_Cnt;		//接收数据计数器
extern uint8_t USART2_Temp[REC_LENGTH];	//接收数据缓存
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define LORA_MDO_Pin GPIO_PIN_0
#define LORA_MDO_GPIO_Port GPIOA
#define LORA_AUX_Pin GPIO_PIN_1
#define LORA_AUX_GPIO_Port GPIOA
#define ECHO_Pin GPIO_PIN_15
#define ECHO_GPIO_Port GPIOA
#define TRIG_Pin GPIO_PIN_3
#define TRIG_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
