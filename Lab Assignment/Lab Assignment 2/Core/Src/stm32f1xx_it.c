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
#include "lcd.h"
#include <stdio.h>
#include <math.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DATA_LENGTH 100
#define MAX_DATA_LENGTH 100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t mode = 1;  // Use extern to declare the global variable
uint8_t input_data[DATA_LENGTH];
volatile uint8_t count = 0;
uint8_t* output_data;
char data_string[DATA_LENGTH+1];
uint8_t output_length;  // 用于存储编码后的数据长度
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
IRQn_Type GPIO_PinToIRQn(uint16_t GPIO_Pin);
void DisplayEncodingMode(void);
void DisplayDecodingMode(void);
char* ConvertNumberToString(uint8_t*  data, uint8_t count);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

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
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//	HAL_NVIC_DisableIRQ(GPIO_PinToIRQn(GPIO_Pin));
//	HAL_Delay(100);
	char* data_string;
	uint8_t data_length;

	switch (GPIO_Pin) {
		case KEY_WK_Pin:
			HAL_NVIC_DisableIRQ(EXTI0_IRQn);
			HAL_Delay(100);
			if (HAL_GPIO_ReadPin(KEY_WK_GPIO_Port, KEY_WK_Pin) == GPIO_PIN_SET) {
				// Toggle mode
				mode = !mode;
				count = 0;
				// Toggle LEDs based on the mode
				if (mode == 0) {
					// Encoding mode
//					LCD_ShowString(30, 40, 200, 24, 24, (uint8_t*) "Decoding Mode");
					DisplayEncodingMode();
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
					HAL_Delay(200);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);  // LED0 flash once
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);  // LED1 flash once
				} else {
					DisplayDecodingMode();
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
					HAL_Delay(100);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);  // LED0 flash once
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);  // LED1 flash once
					HAL_Delay(100);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
					HAL_Delay(100);
					HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);  // LED0 flash once
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);  // LED1 flash once
				}

			}
			HAL_NVIC_EnableIRQ(EXTI0_IRQn);
			break;
		case KEY1_Pin:
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			HAL_Delay(100);
			if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET) {
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
				HAL_Delay(100);
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
				input_data[count++] = 1;
				LCD_ShowNum(60,220,input_data[count-1],1,10);
				if(mode == 0){
					// 调用 Hamming 编码函数
					data_string = ConvertNumberToString(input_data,count);
					LCD_ShowString(30, 110, 200, 24, 24, (uint8_t*)data_string);
					free(data_string);
					hammingEncode(input_data, count, &output_data, &output_length);
					data_string = ConvertNumberToString(output_data,output_length);
					LCD_ShowString(30, 180, 200, 24, 24, (uint8_t*)data_string);
					free(data_string);
				}else{
					data_string = ConvertNumberToString(input_data,count);
					LCD_ShowString(30, 166, 200, 24, 24, (uint8_t*)data_string);
					free(data_string);
					if(count<3){
					}else{
					hammingDecode(input_data, count, &output_data, &output_length);
					}

				}
			}
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		case KEY0_Pin:
			HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
			HAL_Delay(100);
			if (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET) {
				HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
				HAL_Delay(100);
				HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
				input_data[count++] = 0;
				LCD_ShowNum(30,220,input_data[count-1],1,10);
				if(mode == 0){
					data_string = ConvertNumberToString(input_data,count);
					LCD_ShowString(30, 110, 200, 24, 24, (uint8_t*)data_string);
					free(data_string);
					hammingEncode(input_data, count, &output_data, &output_length);
					data_string = ConvertNumberToString(output_data,output_length);
				    LCD_ShowString(30, 180, 200, 24, 24, (uint8_t*)data_string);
				    free(data_string);
				}else{
					data_string = ConvertNumberToString(input_data,count);
					LCD_ShowString(30, 166, 200, 24, 24, (uint8_t*)data_string);
					free(data_string);
					if(count <3 ){
					}else{
					hammingDecode(input_data, count, &output_data, &output_length);
					}
				}
			}
			HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		default:
			LCD_Clear(BLUE);
			break;

	}
//	HAL_NVIC_EnableIRQ(GPIO_PinToIRQn(GPIO_Pin));
}

char* ConvertNumberToString(uint8_t* data, uint8_t count){
    char* data_string = (char*)malloc(count + 1);

    if (data_string == NULL){
        return NULL;
    }


    for (uint8_t i = 0; i < count; i++){
        data_string[i] = data[i] + '0';  // 将数字转换为字符 '0' 或 '1'
    }

    data_string[count] = '\0';
    return data_string;
}



// 320*240 uint8_t *original_data, uint8_t *encoded_data
void DisplayEncodingMode(void) {
    // Clear the screen
    LCD_Clear(GREEN);
	LCD_ShowString(30, 20, 200, 24, 24, (uint8_t*) "Encoding Mode");
	LCD_DrawLine(0,70,319,70);
    // Display original data
	char* data_string = ConvertNumberToString(input_data,count);
	LCD_ShowString(30, 80, 200, 24, 16, (uint8_t*) "Original data");
	LCD_ShowString(30, 110, 200, 24, 24, (uint8_t*)data_string);
    LCD_DrawLine(0, 140, 319, 140);
    // Display Hamming code
    LCD_ShowString(30, 150, 200, 24, 16, (uint8_t*) "Hamming code");
    LCD_ShowString(30, 180, 200, 24, 24, (uint8_t*)"");   // 显示传入的编码数据
    LCD_DrawLine(0, 210, 319, 210);

    // Display "No errors"
	LCD_ShowString(30, 240, 200, 24, 16, (uint8_t*) "No errors");
}

void DisplayDecodingMode(void) {
    // Clear the screen
    LCD_Clear(BLUE);
	LCD_ShowString(30, 20, 200, 24, 24, (uint8_t*) "Decoding Mode");
	LCD_DrawLine(0,70,319,70);
    // Display original data
	char* data_string = ConvertNumberToString(input_data,count);
	LCD_ShowString(30, 80, 200, 24, 16, (uint8_t*) "Original data");
	LCD_ShowString(30, 110, 200, 24, 24, (uint8_t*)"");
	LCD_DrawLine(0,140,319,140);

    // Display Hamming code
	LCD_ShowString(30, 150, 200, 24, 16, (uint8_t*) "Hamming code");
	LCD_ShowString(30, 166, 200, 24, 24, (uint8_t*)data_string);
	LCD_ShowString(30, 190, 200, 24, 16, (uint8_t*) "with  parity bits");
	LCD_DrawLine(0,210,319,210);

    // Display "No errors"
	LCD_ShowString(30, 264, 200, 24, 12, (uint8_t*) "No errors!");


}

IRQn_Type GPIO_PinToIRQn(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)
    {
        case GPIO_PIN_0:
            return EXTI0_IRQn;
        case GPIO_PIN_1:
            return EXTI1_IRQn;
        case GPIO_PIN_2:
            return EXTI2_IRQn;
        case GPIO_PIN_3:
            return EXTI3_IRQn;
        case GPIO_PIN_4:
            return EXTI4_IRQn;
        case GPIO_PIN_5:
        case GPIO_PIN_6:
        case GPIO_PIN_7:
        case GPIO_PIN_8:
        case GPIO_PIN_9:
            return EXTI9_5_IRQn;
        case GPIO_PIN_10:
        case GPIO_PIN_11:
        case GPIO_PIN_12:
        case GPIO_PIN_13:
        case GPIO_PIN_14:
        case GPIO_PIN_15:
            return EXTI15_10_IRQn;
        default:
            // Return an invalid IRQn or handle error appropriately
            return (IRQn_Type)0xFF;  // Return 0xFF for invalid pin input
    }
}

// Function to calculate number of parity bits required
uint8_t calculateParityBits(uint8_t data_length) {
    uint8_t p = 0;
    while ((1 << p) < (data_length + p + 1)) {
        p++;
    }
    return p;
}

// Function to encode data using Hamming Code
void hammingEncode(uint8_t *data, uint8_t data_length, uint8_t **encoded, uint8_t *encoded_length) {
    uint8_t parity_bits = calculateParityBits(data_length);
    *encoded_length = data_length + parity_bits;
	LCD_ShowString(30 , 260, 200, 24, 16, (uint8_t*) "Parity Length: ");
    // 显示 parity_bits
    LCD_ShowNum(30 + 15 * 8, 260, parity_bits , 2, 16);

    // Allocate memory for encoded data
    *encoded = (uint8_t *)malloc(*encoded_length * sizeof(uint8_t));

    uint8_t j = 0;
    for (uint8_t i = 1; i < *encoded_length + 1; i++) {
        // If i is a power of two, it's a parity bit position
        if ((i & (i - 1)) == 0) {
            (*encoded)[i - 1] = 0; // Set parity bits to 0 for now
        } else {
            (*encoded)[i - 1] = data[j++]; // Insert data bits
        }
    }

    // Calculate parity bits
    for (uint8_t i = 0; i < parity_bits; i++) {
        uint8_t parity_position = (1 << i) - 1;
        uint8_t parity_value = 0;

        for (uint8_t j = parity_position; j < *encoded_length; j++) {
            // Each parity bit checks its corresponding bit of the encoded data, e.g., the first parity bit checks the bits whose 0th bit is 1
            if ((j + 1) & (1 << i)) {
                parity_value ^= (*encoded)[j ];
            }
        }

        (*encoded)[parity_position] = parity_value;
    	LCD_ShowString(30 , 280, 200, 24, 16, (uint8_t*) "Parity Bits: ");
        LCD_ShowNum(30 + 104 + 16 * i, 280, parity_value, 1, 16);

        uint16_t s_x = 10;           // Starting X position on the LCD
        uint16_t s_y = 50;          // Starting Y position on the LCD
        uint16_t e_x = 210;           // Ending X position on the LCD
        uint16_t e_y = 60;          // Ending Y position on the LCD
        // Calculate progress percentage
        float progress_percentage = ((float)(i + 1) / parity_bits);

        // Draw the progress bar (background as empty and fill with progress)
        uint16_t fill_width = s_x + (uint16_t)round((e_x - s_x) * progress_percentage);
        LCD_Color_Fill(s_x, s_y, fill_width, e_y, (uint16_t*) BLUE);
        LCD_Color_Fill(fill_width, s_y, e_x , e_y,(uint16_t*) RED);
        HAL_Delay(100);

//        // Optionally, show the percentage as text
//        char progress_text[16];
//        sprintf(progress_text, "Progress: %d%%", (int)(progress_percentage * 100));
//        LCD_ShowString(progress_x, progress_y + 30, 200, 24, 16, (uint8_t*)progress_text);

    }
}



// Function to perform Hamming decoding
void hammingDecode(uint8_t *encoded, uint8_t encoded_length, uint8_t **decoded, uint8_t *decoded_length) {
    // How many parity bits in total?
    uint8_t parity_count = 0;
    while ((1 << parity_count) <= encoded_length) {
        parity_count++;
    }
    char display_buffer[256];  // 创建一个足够大的缓冲区来存储拼接后的字符串
    sprintf(display_buffer, "with %d parity bits", parity_count);

    // 使用拼接好的字符串在 LCD 上显示
    LCD_ShowString(30, 190, 200, 24, 16, (uint8_t*)display_buffer);

    uint8_t error_pos = 0;

    // Calculate the error position using parity checks
    for (uint8_t i = 0; i < parity_count; i++) {
        uint8_t parity_position = (1 << i) - 1;
        uint8_t parity_value = 0;

        for (uint8_t j = parity_position; j < encoded_length; j++) {
            if ((j + 1) & (1 << i)) {
                parity_value ^= encoded[j];
            }
        }

        if (parity_value != 0) {
            error_pos |= (1 << i);
        }
    	LCD_ShowString(30 , 216, 200, 24, 12, (uint8_t*) "Parity Bits: ");
        LCD_ShowNum(30 + 78 + 12 * i, 216, parity_value, 1, 12);
        uint16_t s_x = 10;           // Starting X position on the LCD
        uint16_t s_y = 50;          // Starting Y position on the LCD
        uint16_t e_x = 210;           // Ending X position on the LCD
        uint16_t e_y = 60;          // Ending Y position on the LCD
        // Calculate progress percentage
        float progress_percentage = ((float)(i + 1) / parity_count);
        // Draw the progress bar (background as empty and fill with progress)
        uint16_t fill_width = s_x + (uint16_t)round((e_x - s_x) * progress_percentage);
        LCD_Color_Fill(s_x, s_y, fill_width, e_y, (uint16_t*) GREEN);
        LCD_Color_Fill(fill_width, s_y, e_x , e_y,(uint16_t*) RED);
        HAL_Delay(100);
    }

    // Correct the error if needed
    if (error_pos != 0) {
    	sprintf(display_buffer, "One error occurs in bit %d", error_pos);
    	LCD_ShowString(30, 230, 200, 24, 12, (uint8_t*) display_buffer);
    }else{
    	LCD_ShowString(30, 230, 200, 24, 12, (uint8_t*) "No errors!");
    }

    // Extract original data (excluding parity bits)
    *decoded_length = encoded_length - parity_count;

    *decoded = (uint8_t *)malloc(*decoded_length * sizeof(uint8_t));

    // Now, define correct_data to hold the corrected data
    uint8_t* correct_data = (uint8_t *)malloc(*decoded_length * sizeof(uint8_t));


    uint8_t j = 0;
    for (uint8_t i = 1; i < encoded_length + 1; i++) {
        if ((i & (i - 1)) != 0) {
            (*decoded)[j] = encoded[i - 1];
            correct_data[j] = encoded[i - 1];
            if(error_pos == i){
            	correct_data[j] ^= 1;
            }
            j = j + 1;
        }
    }
    char* data_string;
    if(error_pos !=0){
    	data_string = ConvertNumberToString(*decoded,*decoded_length);
    	sprintf(display_buffer, "The error data is %s", data_string);
    	LCD_ShowString(30, 264, 200, 24, 12, (uint8_t*) display_buffer);
    }else{
    	LCD_ShowString(30, 264, 200, 24, 12, (uint8_t*) "There is no error");
    }
  	data_string = ConvertNumberToString(correct_data,*decoded_length);
	LCD_ShowString(30, 110, 200, 24, 24, (uint8_t*)data_string);
  	sprintf(display_buffer, "The correct data is %s", data_string);
  	LCD_ShowString(30, 298, 200, 24, 12, (uint8_t*) display_buffer );

}



/* USER CODE END 1 */
