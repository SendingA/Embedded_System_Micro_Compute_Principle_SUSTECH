/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f1xx_it.c
 * @brief   Interrupt Service Routines.
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
#include "main.h"
#include "stm32f1xx_it.h"
#include  "lcd.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern uint8_t receiveData[50];
extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern uint8_t txCompleteFlag;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
void NMI_Handler(void) {
	/* USER CODE BEGIN NonMaskableInt_IRQn 0 */

	/* USER CODE END NonMaskableInt_IRQn 0 */
	/* USER CODE BEGIN NonMaskableInt_IRQn 1 */
	while (1) {
	}
	/* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
 * @brief This function handles Hard fault interrupt.
 */
void HardFault_Handler(void) {
	/* USER CODE BEGIN HardFault_IRQn 0 */

	/* USER CODE END HardFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_HardFault_IRQn 0 */
		/* USER CODE END W1_HardFault_IRQn 0 */
	}
}

/**
 * @brief This function handles Memory management fault.
 */
void MemManage_Handler(void) {
	/* USER CODE BEGIN MemoryManagement_IRQn 0 */

	/* USER CODE END MemoryManagement_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
		/* USER CODE END W1_MemoryManagement_IRQn 0 */
	}
}

/**
 * @brief This function handles Prefetch fault, memory access fault.
 */
void BusFault_Handler(void) {
	/* USER CODE BEGIN BusFault_IRQn 0 */

	/* USER CODE END BusFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_BusFault_IRQn 0 */
		/* USER CODE END W1_BusFault_IRQn 0 */
	}
}

/**
 * @brief This function handles Undefined instruction or illegal state.
 */
void UsageFault_Handler(void) {
	/* USER CODE BEGIN UsageFault_IRQn 0 */

	/* USER CODE END UsageFault_IRQn 0 */
	while (1) {
		/* USER CODE BEGIN W1_UsageFault_IRQn 0 */
		/* USER CODE END W1_UsageFault_IRQn 0 */
	}
}

/**
 * @brief This function handles System service call via SWI instruction.
 */
void SVC_Handler(void) {
	/* USER CODE BEGIN SVCall_IRQn 0 */

	/* USER CODE END SVCall_IRQn 0 */
	/* USER CODE BEGIN SVCall_IRQn 1 */

	/* USER CODE END SVCall_IRQn 1 */
}

/**
 * @brief This function handles Debug monitor.
 */
void DebugMon_Handler(void) {
	/* USER CODE BEGIN DebugMonitor_IRQn 0 */

	/* USER CODE END DebugMonitor_IRQn 0 */
	/* USER CODE BEGIN DebugMonitor_IRQn 1 */

	/* USER CODE END DebugMonitor_IRQn 1 */
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void) {
	/* USER CODE BEGIN PendSV_IRQn 0 */

	/* USER CODE END PendSV_IRQn 0 */
	/* USER CODE BEGIN PendSV_IRQn 1 */

	/* USER CODE END PendSV_IRQn 1 */
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void) {
	/* USER CODE BEGIN SysTick_IRQn 0 */

	/* USER CODE END SysTick_IRQn 0 */
	HAL_IncTick();
	/* USER CODE BEGIN SysTick_IRQn 1 */

	/* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles DMA1 channel4 global interrupt.
 */
void DMA1_Channel4_IRQHandler(void) {
	/* USER CODE BEGIN DMA1_Channel4_IRQn 0 */

	/* USER CODE END DMA1_Channel4_IRQn 0 */
	HAL_DMA_IRQHandler(&hdma_usart1_tx);
	/* USER CODE BEGIN DMA1_Channel4_IRQn 1 */

	/* USER CODE END DMA1_Channel4_IRQn 1 */
}

/**
 * @brief This function handles DMA1 channel5 global interrupt.
 */
void DMA1_Channel5_IRQHandler(void) {
	/* USER CODE BEGIN DMA1_Channel5_IRQn 0 */

	/* USER CODE END DMA1_Channel5_IRQn 0 */
	HAL_DMA_IRQHandler(&hdma_usart1_rx);
	/* USER CODE BEGIN DMA1_Channel5_IRQn 1 */

	/* USER CODE END DMA1_Channel5_IRQn 1 */
}

/**
 * @brief This function handles USART1 global interrupt.
 */
void USART1_IRQHandler(void) {
	/* USER CODE BEGIN USART1_IRQn 0 */

	/* USER CODE END USART1_IRQn 0 */
	HAL_UART_IRQHandler(&huart1);
	/* USER CODE BEGIN USART1_IRQn 1 */

	/* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (huart == &huart1) {
		connected=1;
//		 	 char sendBuffer[256];  // 你可以根据需要调整缓冲区的大�?
//		    // 格式化数据，添加前缀 "Received Data: " 和接收到的数�?
//		    sprintf(sendBuffer, sizeof(sendBuffer), "Received Data: %s", receiveData);
		// 通过 DMA 发�?�格式化后的数据
		receiveData[sizeof(receiveData) - 1] = '\0';
		char buffer[50];
		uint8_t header = receiveData[0];
		uint8_t *payload = &receiveData[2];
		if (0) {

		} else if (header == 'D') {
			// Distance 数据
			// 解析距离信息
//			POINT_COLOR = BLACK;
//			LCD_ShowString_o(10, 290, 200, 16, 16, "Distance: ");
//			LCD_ShowString_o(90, 290, 200, 16, 16, payload);
		} else if (header == 'B') {
			// Block 数据
//			POINT_COLOR = BLACK;
//			LCD_ShowString_o(150, 290, 200, 16, 16, "Block: ");
//			LCD_ShowString_o(206, 290, 200, 16, 16, payload);
			int a = payload[0] - '0';
			int b = payload[1] - '0';
			draw_block(10 * a + b);
		} else if(header == 'F'){
			connected=1;
			// 未知数据类型
		}
//	      LCD_ShowString(60,60,200,24,24, receiveData);
//		  HAL_UART_Transmit_DMA(&huart1, receiveData, Size);
		LCD_Fill(0,290,230,320,WHITE);
		POINT_COLOR = BLACK;
		LCD_ShowString(10, 290, 200, 16, 16, receiveData);
		memset(receiveData, 0, sizeof(receiveData));
		HAL_UARTEx_ReceiveToIdle_DMA(&huart1, receiveData, sizeof(receiveData));
		__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
	}
}

// DMA传输完成回调函数
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//    if (huart->Instance == USART1)  // 确保�? USART1 传输完毕
//    {
//    	LCD_ShowString(0,0,200,24,24, "Finish");
//        txCompleteFlag = 1;  // 设置传输完成标志
//    }
//}
/* USER CODE END 1 */
