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
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
#define FRAME_SIZE 45 * 60
//#define FRAME_SIZE 4 * 6
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define STOP_COMMAND "stop"
#define RESUME_COMMAND "resume"
#define SPEED_COMMAND "speed"
#define SLOW_COMMAND "slow"
#define FRAME_RECEIVED "frame received"
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint32_t counter = 0;
uint8_t rxBuffer[2];
char buffer[100];
uint16_t img_index = 0;
uint16_t img[FRAME_SIZE];
uint8_t zoom_in = 1;
uint8_t frame_flag = 0;
uint8_t video_playing = 1;
uint8_t captured = 0;
uint32_t speed = 3;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
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
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY_WK_Pin);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY0_Pin);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY1_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
    	counter++;
    	uint16_t minute = counter / 60;
    	uint16_t second = counter % 60;
    	sprintf(buffer, "%02d min %02d sec", minute, second);
        LCD_ShowString(0, 210, 200, 24, 24, (uint8_t*)buffer);
        if (counter % 2 == 0) {
            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET); // 点亮LED0
        } else {
            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); // 熄灭LED0
        }
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	uint32_t begin_time, end_time, duration;
	switch (GPIO_Pin) {
			case KEY_WK_Pin:
				HAL_NVIC_DisableIRQ(EXTI0_IRQn);
				begin_time = HAL_GetTick();
				while (HAL_GPIO_ReadPin(KEY_WK_GPIO_Port, KEY_WK_Pin) == GPIO_PIN_SET) {
				}
				end_time = HAL_GetTick();
				duration = end_time - begin_time;
				if (duration <= 1000) {
					captured = 1;
				} else {
					speed = speed - 1;
					HAL_UART_Transmit_IT(&huart1, (uint8_t*)SLOW_COMMAND, sizeof(SLOW_COMMAND) - 1);
					LCD_ShowNum(180,245,speed,2,16);
				}
				HAL_NVIC_EnableIRQ(EXTI0_IRQn);
				break;
			case KEY0_Pin:
				HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
				begin_time = HAL_GetTick();
				while (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET) {
				}
				end_time = HAL_GetTick();
				duration = end_time - begin_time;
				if (duration <= 1000) {
						if(zoom_in == 3){
							zoom_in = 1;
						}else{
							zoom_in = zoom_in + 1;
						}
				} else {
					if(speed < 5){
						speed = speed + 1;
					}
					HAL_UART_Transmit_IT(&huart1, (uint8_t*)SPEED_COMMAND, sizeof(SPEED_COMMAND) - 1);
					LCD_ShowNum(180,245,speed,2,16);
				}
				HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
				break;
			case KEY1_Pin:
				HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
				if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){
					video_playing ^= 1;
					if(video_playing == 0){
						LCD_ShowString(80, 295, 200, 24, 24, (uint8_t *)"Suspended~");
						HAL_UART_Transmit_IT(&huart1, (uint8_t*)STOP_COMMAND, sizeof(STOP_COMMAND) - 1);
					}else{
						LCD_ShowString(80, 295, 200, 24, 24, (uint8_t *)"Displaying");
						HAL_UART_Transmit_IT(&huart1, (uint8_t*)RESUME_COMMAND, sizeof(RESUME_COMMAND) - 1);
					}
				}
				HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
				break;
			default:
				break;

		}
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

    uint16_t data;
    if (huart->Instance == USART1) {
        data = rxBuffer[0] | (rxBuffer[1] << 8);
        if (data == 0x1234) {
            img_index = 0;
//            HAL_UART_Transmit_IT(&huart1, rxBuffer ,2);
        } else {
            img[img_index] = data;
            img_index++;
            if (img_index >= FRAME_SIZE) {
            	frame_flag = 1;
                img_index = 0;
//				HAL_UART_Transmit_IT(&huart1, (uint8_t*)FRAME_RECEIVED, sizeof(FRAME_RECEIVED) - 1);

            }
        }
        HAL_UART_Receive_IT(&huart1, rxBuffer, 2);
    }
 }


/* USER CODE END 1 */
