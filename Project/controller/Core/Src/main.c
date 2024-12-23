/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "touch.h"
#include "24cxx.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
volatile uint16_t block[400] = { 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XF7BE, 0XD6DB, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XAD97, 0X94D5, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X9431, 0X834C,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XF7BF,
		0X8AE9, 0XA307, 0XDF1C, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XBE19, 0XC367, 0XDBC6, 0X9D15, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0X8C52, 0XEBE6, 0XEBE6, 0X836D, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFDF, 0X82EA, 0XEBE6, 0XEBE6, 0XA308,
		0XEF5D, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XCE7A, 0XB346, 0XEBC6,
		0XEBC6, 0XD386, 0X9D16, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X738E,
		0XA534, 0XA534, 0XA534, 0XA534, 0X73AE, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0X7BEF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X9492, 0XE73C, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XCE7A, 0XAD75, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XCE59,
		0X9CF4, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X8452, 0X8A43, 0X8A43, 0X8A43, 0X8A43,
		0X8A43, 0X8A43, 0X83AE, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X8B6C, 0XEBE6, 0XEBE6,
		0XEBE6, 0XEBE6, 0XEBE6, 0XEBE6, 0X8AC8, 0XF79E, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XD6DC, 0XA307,
		0XEBE6, 0XEBE6, 0XEBE6, 0XEBE6, 0XEBE6, 0XEBE6, 0XCB66, 0XBE19, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0X9CF5, 0XDBA6, 0XEBC6, 0XEBC6, 0XEBC6, 0XEBC6, 0XEBC6, 0XEBC6, 0XE3C6,
		0X8410, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XF7BE, 0X5AEB, 0X9CF3, 0X9CF3, 0X9CF3, 0X9CF3, 0X9CF3, 0X9CF3,
		0X9CF3, 0X9CF3, 0X73AE, 0XDEFB, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XC659, 0XB5B6, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XE71C, 0X9CF3, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X8C72, 0XF7BE, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0X7BCF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XDEFB, 0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2,
		0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2, 0X94B2,
		0X94B2, 0X94B2, 0X94B2, 0XB596, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF };
volatile uint16_t end[400] = { 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFBE, 0XFD96, 0XFBCF, 0XFAEB, 0XFAEB, 0XFBCF, 0XFD96, 0XFFBE, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFF9E, 0XFBCF, 0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF861, 0XFBCF, 0XFF9E, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFE9A, 0XF924, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFE9A, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFE9A, 0XF882, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF882, 0XFE9A,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFF9E, 0XF924, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF904, 0XFF9E, 0XFFFF, 0XFFFF, 0XFBCF, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF, 0XFFFF, 0XFFBE, 0XF861, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFAAA, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFA49, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF841, 0XFFBE, 0XFD96,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAAA, 0XFFFF, 0XFAAA,
		0XF9C7, 0XF9C7, 0XF882, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XFD96, 0XFBCF, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAAA,
		0XFFFF, 0XF924, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XFBCF, 0XFAEB, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XFAAA, 0XFFFF, 0XFB6D, 0XFAAA, 0XFA8A, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFAEB, 0XFAEB, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XFAAA, 0XFFFF, 0XFF3C, 0XFF3C, 0XFEDB, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAEB, 0XFBCF, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAAA, 0XFFFF, 0XF924, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF,
		0XFD96, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAAA, 0XFFFF,
		0XF924, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XFD75, 0XFFBE, 0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XFAAA, 0XFFFF, 0XFF3C, 0XFF3C, 0XFF3C, 0XFC10, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF861, 0XFFBE, 0XFFFF, 0XFBCF, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF8E3, 0XFAAA, 0XFAAA, 0XFAAA, 0XFAAA, 0XF986, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF, 0XFFFF, 0XFFFF, 0XFF9E, 0XF904,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFF9E, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFE9A, 0XF882, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF861, 0XFE79, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFE9A, 0XF904, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFE79,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFF9E, 0XFBCF,
		0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF861, 0XFBCF,
		0XFF9E, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFBE, 0XFD75, 0XFBAE, 0XFAEB, 0XFAEB, 0XFBAE, 0XFD96,
		0XFFBE, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF };
volatile uint16_t start[400] = { 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFBE, 0XFD96, 0XFBCF, 0XFAEB, 0XFAEB, 0XFBCF, 0XFD96, 0XFFBE, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFF9E, 0XFBCF, 0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF861, 0XFBCF, 0XFF9E, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFE9A, 0XF924, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFE9A, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFE9A, 0XF882, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF882, 0XFE9A,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFF9E, 0XF924, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF904, 0XFF9E, 0XFFFF, 0XFFFF, 0XFBCF, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF, 0XFFFF, 0XFFBE, 0XF861, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFA08, 0XFEDB, 0XFFFF, 0XFFBE, 0XFD34,
		0XF841, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF841, 0XFFBE, 0XFD96,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFF3C, 0XFDF7, 0XF945,
		0XFA8A, 0XFF9E, 0XFB2C, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XFD96, 0XFBCF, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFF9E,
		0XFD14, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XFBCF, 0XFAEB, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XFCD3, 0XFFFF, 0XFE59, 0XFBAE, 0XF8E3, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFAEB, 0XFAEB, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFACB, 0XFD75, 0XFF9E, 0XFFDF, 0XFA69,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFAEB, 0XFBCF, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF861,
		0XFEBA, 0XFDF7, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF,
		0XFD96, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF945, 0XFF9E, 0XFB8E,
		0XF800, 0XF861, 0XFEBA, 0XFDB6, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XFD75, 0XFFBE, 0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XFD14, 0XFFFF, 0XFF7D, 0XFFBE, 0XFFBE, 0XFA08, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF861, 0XFFBE, 0XFFFF, 0XFBCF, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF9A6, 0XFAAA, 0XFA69, 0XF8A2, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XFBCF, 0XFFFF, 0XFFFF, 0XFF9E, 0XF904,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFF9E, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFE9A, 0XF882, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF861, 0XFE79, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFE9A, 0XF904, 0XF800, 0XF800, 0XF800,
		0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF904, 0XFE79,
		0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFF9E, 0XFBCF,
		0XF861, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF800, 0XF861, 0XFBCF,
		0XFF9E, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF,
		0XFFFF, 0XFFFF, 0XFFBE, 0XFD75, 0XFBAE, 0XFAEB, 0XFAEB, 0XFBAE, 0XFD96,
		0XFFBE, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF, 0XFFFF };
volatile uint16_t connected = 0;
uint8_t board[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //1 is start,2 is end, 3 is block
uint8_t path[16] = { 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17 }; //1 is path
uint8_t path_p = 0;
uint8_t path_set = 0;
uint8_t path_valid = 0;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */
uint8_t txCompleteFlag = 0;
uint8_t receiveData[50];
//---------------------------------------------------------
//Task1 Commands:
//ONA:FORWARD;
//ONB:BACKWARD
//ONC:TURN LEFT
//OND:TURN RIGHT
//ONE:LEFT
//ONF:RIGHT
//STP:STOP
//PAT:PATH DESIGN
//BLO:BLOCK
//------------------------------------------------------------
uint8_t sendData[11][4] = { "ONA", "ONB", "ONC", "OND", "ONE", "ONF", "STP",
		"PAT", "BLO", "T3", "FFF" }; // 要发送的数据
uint8_t task4Command[3][5] = { "STPT", "EDPT", "BEGN" };
uint8_t block_cnt = 1;
/* USER CODE END PV */
int bluetooth_connected = 0;
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
void reset_board() {
	block_cnt = 1;
	for (int i = 0; i < 16; i++) {
		board[i] = 0;
	}
}
void draw_board_line() {
	POINT_COLOR = BLACK;
	for (int x = 40; x < 200; x++) {
		LCD_DrawPoint(x, 50);
	}
	for (int x = 40; x < 200; x++) {
		LCD_DrawPoint(x, 90);
	}
	for (int x = 40; x < 200; x++) {
		LCD_DrawPoint(x, 130);
	}
	for (int x = 40; x < 200; x++) {
		LCD_DrawPoint(x, 170);
	}
	for (int x = 40; x < 200; x++) {
		LCD_DrawPoint(x, 210);
	}
	for (int x = 50; x < 210; x++) {
		LCD_DrawPoint(40, x);
	}
	for (int x = 50; x < 210; x++) {
		LCD_DrawPoint(80, x);
	}
	for (int x = 50; x < 210; x++) {
		LCD_DrawPoint(120, x);
	}
	for (int x = 50; x < 210; x++) {
		LCD_DrawPoint(160, x);
	}
	for (int x = 50; x < 210; x++) {
		LCD_DrawPoint(200, x);
	}
}
void draw_board() {
	for (int i = 0; i < 16; i++) {
		if (board[i] == 1) {
			lcd_showpic((i / 4 + 1) * 40 + 20, (i % 4 + 1) * 40 + 10, 20, 20, 1,
					start);
		} else if (board[i] == 2) {
			lcd_showpic((i / 4 + 1) * 40 + 20, (i % 4 + 1) * 40 + 10, 20, 20, 1,
					end);
		} else if (board[i] == 3) {
			lcd_showpic((i / 4 + 1) * 40 + 20, (i % 4 + 1) * 40 + 10, 20, 20, 1,
					block);
		}
	}

}
void draw_block(int i) {
	lcd_showpic((i / 4 + 1) * 40 + 20, (i % 4 + 1) * 40 + 10, 20, 20, 1, block);
}
void reset_path() {
	block_cnt = 1;
	for (int i = 0; i < 16; i++) {
		path[i] = 17;
	}
	path_p = 0;
	path_set = 0;
	path_valid = 0;
	LCD_Fill(40, 50, 200, 210, WHITE);
	draw_board_line();
	draw_board();
}
void valid_path() {
	path_valid = 1;
	for (int i = 0; i < path_p; i++) {
		if (path[i] == 17) {
			path_valid = 0;
			break;
		} else if (board[path[i]] == 3) {
			path_valid = 0;
			break;
		}
	}
	if (board[path[0]] != 1) {
		path_valid = 0;
	}
	if (board[path[path_p - 1]] != 2) {
		path_valid = 0;
	}
}

void bluetooth_state(int state) {
	if (state == 0) {
		POINT_COLOR = WHITE;
		LCD_ShowString(5, 5, 250, 16, 16, "Bluetooth connected!         ");
		POINT_COLOR = RED;
		LCD_ShowString(5, 5, 250, 16, 16, "Bluetooth connect failed!    ");
	} else {
		POINT_COLOR = WHITE;
		LCD_ShowString(5, 5, 250, 16, 16, "Bluetooth connect failed!    ");
		POINT_COLOR = BLACK;
		LCD_ShowString(5, 5, 250, 16, 16, "Bluetooth connected!         ");
	}
}
void T3_state(int state, u16 pc) {
	POINT_COLOR = pc;
	switch (state) {
	case 0:
		LCD_ShowString(2, 25, 250, 16, 16, "Set start point");
		break;
	case 1:
		LCD_ShowString(2, 25, 250, 16, 16, "Set end point");
		break;
	case 2:
		LCD_ShowString(2, 25, 250, 16, 16, "Set block");
		break;
	case 3:
		LCD_ShowString(2, 25, 250, 16, 16, "Start");
		break;
	case 4:
		LCD_ShowString(2, 25, 250, 16, 16, "Go forward");
		break;
	case 5:
		LCD_ShowString(2, 25, 250, 16, 16, "Go backward");
		break;
	case 6:
		LCD_ShowString(2, 25, 250, 16, 16, "Go left");
		break;
	case 7:
		LCD_ShowString(2, 25, 250, 16, 16, "Go right");
		break;
	case 8:
		LCD_ShowString(2, 25, 250, 16, 16, "Turn left");
		break;
	case 9:
		LCD_ShowString(2, 25, 250, 16, 16, "Turn right");
		break;
	case 10:
		LCD_ShowString(2, 25, 250, 16, 16, "Stop");
		break;
	case 11:
		LCD_ShowString(2, 25, 250, 16, 16, "Path design");
		break;
	case 12:
		LCD_ShowString(2, 25, 250, 16, 16, "Block detection");
		break;
	case 13:
		LCD_ShowString(2, 25, 250, 16, 16, "Start point set!");
		break;
	case 14:
		LCD_ShowString(2, 25, 250, 16, 16, "End point set!");
		break;
	case 15:
		LCD_ShowString(2, 25, 250, 16, 16, "Draw line");
		break;
	case 16:
		LCD_ShowString(2, 25, 250, 16, 16, "Please redesign path!");
		break;
	case 17:
		LCD_ShowString(2, 25, 250, 16, 16, "Path set!");
		break;
	case 18:
		LCD_ShowString(2, 25, 250, 16, 16, "Reset!");
		break;
	default:
		break;
	}
}
/* USER CODE BEGIN PFP */
//电阻触摸屏测试函数
void rtp_test(void) {
	u8 key;
	u8 i = 0;
	uint8_t state = 100;
	uint8_t task = 1; //1是基础，2是T3，3是T4
	uint8_t task_changed = 1;
	uint8_t delay = 1;
	uint8_t last_t = 0;
	delay_ms(5);

	while (1) {
		if (connected == 0) {
			HAL_UART_Transmit_DMA(&huart1, sendData[10],
					strlen((char*) sendData[10]));
			HAL_Delay(10);
		}
		bluetooth_state(connected); // todo: need to change the input state
		// 展示区域
		if (task_changed == 1) {

			reset_board();
			task_changed = 0;
			LCD_Clear(WHITE);

			block_cnt = 1;
			switch (task) {
			case 0:
				break;
			case 1:
				POINT_COLOR = WHITE;
				LCD_draw_round_rect(5, 80, 40, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 80, 40, 16, 16, "Left");
				LCD_draw_round_rect(47, 80, 50, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(52, 80, 50, 16, 16, "TurnL");
				LCD_draw_round_rect(195, 80, 50, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(200, 80, 50, 16, 16, "Right");
				LCD_draw_round_rect(142, 80, 50, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(147, 80, 50, 16, 16, "TurnR");
				LCD_draw_round_rect(85, 50, 70, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(90, 50, 70, 16, 16, "Forward");
				LCD_draw_round_rect(100, 80, 40, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(105, 80, 40, 16, 16, "Stop");
				LCD_draw_round_rect(80, 110, 80, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(85, 110, 80, 16, 16, "Backward");
				LCD_draw_round_rect(10, 180, 120, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(15, 180, 120, 16, 16, "Path design");
				LCD_draw_round_rect(10, 210, 150, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(15, 210, 150, 16, 16, "Block detection");
				break;
			case 2:
				reset_path();
				POINT_COLOR = WHITE;
				LCD_draw_round_rect(5, 220, 80, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 220, 80, 24, 24, "StartP");
				LCD_draw_round_rect(90, 220, 60, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(95, 220, 60, 24, 24, "EndP");
				LCD_draw_round_rect(155, 220, 70, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(160, 220, 70, 24, 24, "Block");
				LCD_draw_round_rect(5, 255, 70, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 255, 70, 24, 24, "Start");
				LCD_draw_round_rect(80, 255, 60, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(85, 255, 60, 24, 24, "Back");
				LCD_draw_round_rect(150, 255, 60, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(155, 255, 60, 24, 24, "Draw");
				break;
			case 3:
				reset_path();
				POINT_COLOR = WHITE;
				LCD_draw_round_rect(5, 220, 80, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 220, 80, 24, 24, "StartP");
				LCD_draw_round_rect(90, 220, 60, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(95, 220, 60, 24, 24, "EndP");
				LCD_draw_round_rect(155, 220, 70, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(160, 220, 70, 24, 24, "Reset");
				LCD_draw_round_rect(5, 255, 70, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 255, 70, 24, 24, "Start");
				LCD_draw_round_rect(80, 255, 60, 30, 5, BLUE,
				BLUE);
				LCD_ShowString(85, 255, 60, 24, 24, "Back");
				LCD_draw_round_rect(5, 40, 20, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 40, 70, 16, 16, "1");
				LCD_draw_round_rect(5, 65, 20, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 65, 70, 16, 16, "2");
				LCD_draw_round_rect(5, 90, 20, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 90, 70, 16, 16, "3");
				LCD_draw_round_rect(5, 115, 20, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 115, 70, 16, 16, "4");
				LCD_draw_round_rect(5, 140, 20, 20, 5, BLUE,
				BLUE);
				LCD_ShowString(10, 140, 70, 16, 16, "5");
				LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
				RED);
				LCD_ShowString(10, 165, 70, 16, 16, "1");
//				LCD_draw_round_rect(150, 255, 60, 30, 5, BLUE,
//				BLUE);
//				LCD_ShowString(155, 255, 60, 24, 24, "Reset");
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
			}
		}
		key = KEY_Scan(0);
		tp_dev.scan(0);
		// 检测点击
		////////////////////////////////////////////////////////////////////////////////////////////////////
		if (tp_dev.sta & TP_PRES_DOWN)			//触摸屏被按下
		{
//			LCD_DrawPoint(tp_dev.x[0], tp_dev.y[0]);
			if (last_t == 0) {
				last_t = 1;
				delay = 0;
				switch (task) {
				case 0:
					break;
				case 1:
					last_t = 0;
					if (tp_dev.x[0] > 5 && tp_dev.y[0] > 80 && tp_dev.x[0] < 45
							&& tp_dev.y[0] < 100) {
						T3_state(state, WHITE);
						state = 6;
						T3_state(state, BLACK);
						//Left
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[4],
								strlen((char*) sendData[4]));
//					}
					} else if (tp_dev.x[0] > 47 && tp_dev.y[0] > 80
							&& tp_dev.x[0] < 97 && tp_dev.y[0] < 100) {
						T3_state(state, WHITE);
						state = 8;
						T3_state(state, BLACK);
						//TurnL
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[2],
								strlen((char*) sendData[2]));

//					}
					} else if (tp_dev.x[0] > 195 && tp_dev.y[0] > 80
							&& tp_dev.x[0] < 245 && tp_dev.y[0] < 100) {
						T3_state(state, WHITE);
						state = 7;
						T3_state(state, BLACK);
						//Right
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[5],
								strlen((char*) sendData[5]));
//					}
					} else if (tp_dev.x[0] > 142 && tp_dev.y[0] > 80
							&& tp_dev.x[0] < 192 && tp_dev.y[0] < 100) {
						T3_state(state, WHITE);
						state = 9;
						T3_state(state, BLACK);
						//TurnR
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[3],
								strlen((char*) sendData[3]));
//					}
					} else if (tp_dev.x[0] > 85 && tp_dev.y[0] > 50
							&& tp_dev.x[0] < 155 && tp_dev.y[0] < 70) {
						T3_state(state, WHITE);
						state = 4;
						T3_state(state, BLACK);
						//Forward
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[0],
								strlen((char*) sendData[0]));
//					}
					} else if (tp_dev.x[0] > 100 && tp_dev.y[0] > 80
							&& tp_dev.x[0] < 140 && tp_dev.y[0] < 100) {
						T3_state(state, WHITE);
						state = 10;
						T3_state(state, BLACK);
						//Stop
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[6],
								strlen((char*) sendData[6]));
//					}
					} else if (tp_dev.x[0] > 80 && tp_dev.y[0] > 110
							&& tp_dev.x[0] < 160 && tp_dev.y[0] < 130) {
						T3_state(state, WHITE);
						state = 5;
						T3_state(state, BLACK);
						//Backward
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[1],
								strlen((char*) sendData[1]));
//					}
					} else if (tp_dev.x[0] > 10 && tp_dev.y[0] > 180
							&& tp_dev.x[0] < 160 && tp_dev.y[0] < 200) {
						T3_state(state, WHITE);
						state = 11;
						T3_state(state, BLACK);
						task = 2;
						task_changed = 1;
						//Path design
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[7],
								strlen((char*) sendData[7]));
//					}
						//----------------------------------------------
						//

						//----------------------------------------------
					} else if (tp_dev.x[0] > 10 && tp_dev.y[0] > 210
							&& tp_dev.x[0] < 160 && tp_dev.y[0] < 230) {
						T3_state(state, WHITE);
						state = 12;
						T3_state(state, BLACK);
						task = 3;
						task_changed = 1;
						//Block detection
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
						HAL_UART_Transmit_DMA(&huart1, sendData[8],
								strlen((char*) sendData[8]));
//					}
					} else {
//					POINT_COLOR = BLACK;
//					LCD_DrawPoint(tp_dev.x[0], tp_dev.y[0]);
//					if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY) {
//						HAL_UART_Transmit_DMA(&huart1, sendData[6], strlen((char *)sendData[6]));
//					}
					}
					break;
				case 2:
					if (tp_dev.x[0] > 5 && tp_dev.y[0] > 220 && tp_dev.x[0] < 85
							&& tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 0;
						T3_state(state, BLACK);
						//StartP
					} else if (tp_dev.x[0] > 90 && tp_dev.y[0] > 220
							&& tp_dev.x[0] < 150 && tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 1;
						T3_state(state, BLACK);
						//EndP
					} else if (tp_dev.x[0] > 155 && tp_dev.y[0] > 220
							&& tp_dev.x[0] < 225 && tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 2;
						T3_state(state, BLACK);
						//Block
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 255
							&& tp_dev.x[0] < 75 && tp_dev.y[0] < 285) {
						valid_path();
						if (path_valid) {
							T3_state(state, WHITE);
							state = 3;
							T3_state(state, BLACK);
							//Start 在这里发送path串即可，可以全发也可以只发前path_p个，后续补全部分为全17
							//HAL_UART_Transmit_DMA(&huart1, sendData[9], strlen((char *)sendData[9]));
							uint8_t buffer[3 + sizeof(path)];
							memcpy(buffer, sendData[9], 2); // 拷贝 "T3"，注意 "T3" 是 2 字节，加一个 '\0' 是 3 字节
							memcpy(buffer + 2, path, sizeof(path)); // 拷贝 path 到 buffer 后面
							last_t = 0;
							// 使用 DMA 发送
							HAL_UART_Transmit_DMA(&huart1, buffer,
									sizeof(buffer));
						} else {
							T3_state(state, WHITE);
							state = 16;
							T3_state(state, RED);
						}

					} else if (tp_dev.x[0] > 80 && tp_dev.y[0] > 255
							&& tp_dev.x[0] < 140 && tp_dev.y[0] < 285) {
						T3_state(state, WHITE);
						state = 100;
						T3_state(state, BLACK);
						task = 1;
						task_changed = 1;
						//Back
					} else if (tp_dev.x[0] > 150 && tp_dev.y[0] > 255
							&& tp_dev.x[0] < 210 && tp_dev.y[0] < 285) {
						T3_state(state, WHITE);
						state = 15;
						T3_state(state, BLACK);
						reset_path();
						//Draw line
					}

					else if (tp_dev.x[0] > 40 && tp_dev.y[0] > 50
							&& tp_dev.x[0] < 200 && tp_dev.y[0] < 210) {
						u8 v_str[100];
						u8 x = tp_dev.x[0] / 40 - 1;
						u8 y = (tp_dev.y[0] - 10) / 40 - 1;
						u8 index = x + 4 * y;
//					sprintf(v_str, "x_o:%u,y_o:%u,x:%u,y:%u,%u", tp_dev.x[0],
//							tp_dev.y[0], x, y, index);
//					LCD_ShowString_o(5, 295, 230, 16, 16, v_str);
						if (state == 2) {
							if (board[index] != 1 && board[index] != 2) {
								if (board[index] != 3) {
									lcd_showpic((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
									board[index] = 3;
								} else {
									lcd_rm_pic_w((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
									board[index] = 0;
								}
							}

						} else if (state == 0) {
							if (board[index] != 2) {
								u8 is_set = 17;
								for (int i = 0; i < 16; i++) {
									if (board[i] == 1) {
										is_set = i;
										board[i] = 0;
										break;
									}
								}
								if (is_set != 17) {
									lcd_rm_pic_w((is_set / 4 + 1) * 40 + 20,
											(is_set % 4 + 1) * 40 + 10, 20, 20,
											1, start);
								}
								if (board[index] == 3) {
									lcd_rm_pic_w((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
								}
								lcd_showpic((y + 1) * 40 + 20,
										(x + 1) * 40 + 10, 20, 20, 1, start);
								board[index] = 1;
								T3_state(state, WHITE);
								state = 13;
								T3_state(state, BLACK);
							}
						} else if (state == 1) {
							if (board[index] != 1) {
								u8 is_set = 17;
								for (int i = 0; i < 16; i++) {
									if (board[i] == 2) {
										is_set = i;
										board[i] = 0;
										break;
									}
								}
								if (is_set != 17) {
									lcd_rm_pic_w((is_set / 4 + 1) * 40 + 20,
											(is_set % 4 + 1) * 40 + 10, 20, 20,
											1, end);
								}
								if (board[index] == 3) {
									lcd_rm_pic_w((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
								}
								lcd_showpic((y + 1) * 40 + 20,
										(x + 1) * 40 + 10, 20, 20, 1, end);
								board[index] = 2;
								T3_state(state, WHITE);
								state = 14;
								T3_state(state, BLACK);
							}
						} else if (state == 15) {
							delay = 0;
							last_t = 0;
							POINT_COLOR = BLACK;
							LCD_Fast_DrawPoint(tp_dev.x[0], tp_dev.y[0], BLACK);
							if (path_p == 0) {
								path[path_p] = index;
								path_p++;
							} else if (path_p == 1) {
								if (path[0] != index) {
									path[path_p] = index;
									path_p++;
								}
							} else if (path[path_p - 1] == index) {
							} else if (path[path_p - 2] == index) {
								path[path_p - 1] = 17;
								path_p--;
							} else {
								path[path_p] = index;
								path_p++;
							}
						}
					}

					break;
				case 3:
					if (tp_dev.x[0] > 5 && tp_dev.y[0] > 220 && tp_dev.x[0] < 85
							&& tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 0;
						T3_state(state, BLACK);
//					//StartP
//					//--------------------------------------------------------
//					//TODO:起点，给我返回一个“STPT 11”格式的变量，表示第12个格子被设置为了起点
//					//--------------------------------------------------------
//					HAL_UART_Transmit_DMA(&huart1, task4Command[0], sizeof(task4Command[0]));
					} else if (tp_dev.x[0] > 90 && tp_dev.y[0] > 220
							&& tp_dev.x[0] < 150 && tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 1;
						T3_state(state, BLACK);
//					EndP
//					--------------------------------------------------------
//					TODO:终点，给我返回一个“EDPT 11”格式的变量，表示第12个格子被设置为了终点
//					--------------------------------------------------------
//					HAL_UART_Transmit_DMA(&huart1, task4Command[1], sizeof(task4Command[1]));
					} else if (tp_dev.x[0] > 155 && tp_dev.y[0] > 220
							&& tp_dev.x[0] < 225 && tp_dev.y[0] < 250) {
						T3_state(state, WHITE);
						state = 18;
						T3_state(state, BLACK);
						reset_board();
						reset_path();
						//Reset1
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 255
							&& tp_dev.x[0] < 75 && tp_dev.y[0] < 285) {
						uint8_t s = 16;
						uint8_t e = 16;
						for (int i = 0; i < 16; i++) {
							if (board[i] == 1) {
								s = i;
							} else if (board[i] == 2) {
								e = i;
							}
						}
						if (s != 16 && e != 16) {
							T3_state(state, WHITE);
							state = 3;
							T3_state(state, BLACK);
							//Start
						} else {
							T3_state(state, WHITE);
							state = 16;
							T3_state(state, RED);
						}
						char command[12]; // 用于存储命令字符串
						//TODO: Max Number of Blocks
						snprintf(command, sizeof(command), "T4 %d %d %d", s, e,
								block_cnt); // 构造字符串
						HAL_UART_Transmit_DMA(&huart1, command,
								strlen(command));

					} else if (tp_dev.x[0] > 80 && tp_dev.y[0] > 255
							&& tp_dev.x[0] < 140 && tp_dev.y[0] < 285) {
						T3_state(state, WHITE);
						state = 100;
						T3_state(state, BLACK);
						task = 1;
						task_changed = 1;
						//Back
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 40
							&& tp_dev.x[0] < 25 && tp_dev.y[0] < 60) {
						//set 1
						LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
						RED);
						LCD_ShowString(10, 165, 70, 16, 16, "1");
						block_cnt = 1;
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 65
							&& tp_dev.x[0] < 25 && tp_dev.y[0] < 85) {
						//set 2
						LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
						RED);
						LCD_ShowString(10, 165, 70, 16, 16, "2");
						block_cnt = 2;
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 90
							&& tp_dev.x[0] < 25 && tp_dev.y[0] < 110) {
						//set 3
						LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
						RED);
						LCD_ShowString(10, 165, 70, 16, 16, "3");
						block_cnt = 3;
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 115
							&& tp_dev.x[0] < 25 && tp_dev.y[0] < 135) {
						//set 4
						LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
						RED);
						LCD_ShowString(10, 165, 70, 16, 16, "4");
						block_cnt = 4;
					} else if (tp_dev.x[0] > 5 && tp_dev.y[0] > 140
							&& tp_dev.x[0] < 25 && tp_dev.y[0] < 160) {
						//set 5
						LCD_draw_round_rect(5, 165, 20, 20, 5, RED,
						RED);
						LCD_ShowString(10, 165, 70, 16, 16, "5");
						block_cnt = 5;
					} else if (tp_dev.x[0] > 40 && tp_dev.y[0] > 50
							&& tp_dev.x[0] < 200 && tp_dev.y[0] < 210) {
						u8 v_str[100];
						u8 x = tp_dev.x[0] / 40 - 1;
						u8 y = (tp_dev.y[0] - 10) / 40 - 1;
						u8 index = x + 4 * y;
						//					sprintf(v_str, "x_o:%u,y_o:%u,x:%u,y:%u,%u", tp_dev.x[0],
						//							tp_dev.y[0], x, y, index);
						//					LCD_ShowString_o(5, 295, 230, 16, 16, v_str);
						if (state == 0) {
							if (board[index] != 2) {
								u8 is_set = 17;
								for (int i = 0; i < 16; i++) {
									if (board[i] == 1) {
										is_set = i;
										board[i] = 0;
										break;
									}
								}
								if (is_set != 17) {
									lcd_rm_pic_w((is_set / 4 + 1) * 40 + 20,
											(is_set % 4 + 1) * 40 + 10, 20, 20,
											1, start);
								}
								if (board[index] == 3) {
									lcd_rm_pic_w((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
								}
								lcd_showpic((y + 1) * 40 + 20,
										(x + 1) * 40 + 10, 20, 20, 1, start);
								board[index] = 1;
								T3_state(state, WHITE);
								state = 13;
								T3_state(state, BLACK);
							}
						} else if (state == 1) {
							if (board[index] != 1) {
								u8 is_set = 17;
								for (int i = 0; i < 16; i++) {
									if (board[i] == 2) {
										is_set = i;
										board[i] = 0;
										break;
									}
								}
								if (is_set != 17) {
									lcd_rm_pic_w((is_set / 4 + 1) * 40 + 20,
											(is_set % 4 + 1) * 40 + 10, 20, 20,
											1, end);
								}
								if (board[index] == 3) {
									lcd_rm_pic_w((y + 1) * 40 + 20,
											(x + 1) * 40 + 10, 20, 20, 1,
											block);
								}
								lcd_showpic((y + 1) * 40 + 20,
										(x + 1) * 40 + 10, 20, 20, 1, end);
								board[index] = 2;
								T3_state(state, WHITE);
								state = 14;
								T3_state(state, BLACK);
							}
						}
					}

					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				default:
					break;
				}
			}
		} else {
			last_t = 0;
		}
		if (delay)
			HAL_Delay(10);
		//没有按键按下的时�?
		//////////////////////////////////////////////////////////////////////////////////////
		if (key == KEY0_PRES)	//KEY0按下,则执行校准程�?
		{
			LCD_Clear(WHITE);	//清屏
			TP_Adjust();  		//屏幕校准
			TP_Save_Adjdata();
			task_changed = 1;
		}
		i++;
		if (i % 20 == 0)
			LED0 = !LED0;
		///////////////////////////////////////////////////////////////////////////////////////
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */
	LCD_Init();
	LED_Init();							//初始化LED
	KEY_Init();							//初始化按�?
	tp_dev.init();				   		//触摸屏初始化
	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_USART1_UART_Init();
	/* USER CODE BEGIN 2 */
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, receiveData, sizeof(receiveData));
	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
	rtp_test();
//  char sendBuffer[256];  // 你可以根据需要调整缓冲区的大小
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
//  while (1)
	{
		/* USER CODE END WHILE */
		// 格式化数据，添加前缀 "Received Data: " 和接收到的数据
//	  for (uint8_t i = 0; i < 6; i++)
//	      {
//	          // 清除传输完成标志
//	          txCompleteFlag = 0;
//
//	          // 通过DMA发送当前字符串
//	          if (HAL_UART_Transmit_DMA(&huart1, sendData[i], strlen((char *)sendData[i])) != HAL_OK)
//	          {
//	              // 如果传输失败，执行错误处理
//	              Error_Handler();
//	          }
//
//	          // 等待DMA传输完成
//	          while (txCompleteFlag == 0)
//	          {
//	          }
//	      }
		/* USER CODE BEGIN 3 */

	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void) {

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 9600;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/**
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {

	/* DMA controller clock enable */
	__HAL_RCC_DMA1_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA1_Channel4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
	/* DMA1_Channel5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
