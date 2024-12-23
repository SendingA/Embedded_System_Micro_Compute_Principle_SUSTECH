#ifndef __MOTOR_H_
#define __MOTOR_H_
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�������������涨�����˿���ѧϰ�о�24Сʱ��24Сʱ����ɾ�����������������κ���;
//ʹ��SysTick����ͨ����ģʽ���ӳٽ��й����ʺ�STM32F10xϵ�У�
//����delay_us,delay_ms
//********************************************************************************
//////////////////////////////////////////////////////////////////////////////////  
#include "stm32f10x.h"

void TIM4_PWM_Init(unsigned short arr,unsigned short psc);
void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed);

void HJduino_run(signed char speed,int time);       //ǰ������
void HJduino_brake(int time);                       //ɲ������
void HJduino_Left(signed char speed,int time);      //��ת����
void HJduino_Spin_Left(signed char speed,int time); //����ת����
void HJduino_Right(signed char speed,int time);     //��ת����
void HJduino_Spin_Right(signed char speed,int time);//����ת����
void HJduino_back(signed char speed,int time);      //���˺���
void HJduino_HJ_ZE_L(signed char speed,int time);
void HJduino_HJ_ZE_R(signed char speed,int time);

//�������IO�ڶ��� 
/* 
LEFT_MOTOR_GO	  PB12  ��1����������
LEFT_MOTOR_PWM	PB6	��1���PWM

RIGHT_MOTOR_GO	PB14     ��1����������
RIGHT_MOTOR_PWM	PB8	  ��1������PWM


LEFT2_MOTOR_GO	  PB13  ��2����������
LEFT2_MOTOR_PWM	PB7	��2���PWM

RIGHT2_MOTOR_GO	PB15     ��2����������
RIGHT2_MOTOR_PWM	PB9	  ��2������PWM
 */
// ��ǰ1 �������
#define LEFT_MOTOR_GO             GPIO_Pin_12
#define LEFT_MOTOR_GO_GPIO        GPIOB
#define LEFT_MOTOR_GO_SET         GPIO_SetBits(LEFT_MOTOR_GO_GPIO,LEFT_MOTOR_GO)
#define LEFT_MOTOR_GO_RESET       GPIO_ResetBits(LEFT_MOTOR_GO_GPIO,LEFT_MOTOR_GO)
// ��ǰ1 PWM�ٶȿ���
#define LEFT_MOTOR_PWM            GPIO_Pin_6
#define LEFT_MOTOR_PWM_GPIO       GPIOB
#define LEFT_MOTOR_PWM_SET        GPIO_SetBits(LEFT_MOTOR_PWM_GPIO,LEFT_MOTOR_PWM)
#define LEFT_MOTOR_PWM_RESET      GPIO_ResetBits(LEFT_MOTOR_PWM_GPIO,LEFT_MOTOR_PWM)
//��1 �������
#define RIGHT_MOTOR_GO             GPIO_Pin_14
#define RIGHT_MOTOR_GPIO           GPIOB
#define RIGHT_MOTOR_GO_SET         GPIO_SetBits(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_GO)
#define RIGHT_MOTOR_GO_RESET       GPIO_ResetBits(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_GO)
//��1 PWM�ٶȿ���
#define RIGHT_MOTOR_PWM            GPIO_Pin_8
#define RIGHT_MOTOR_PWM_GPIO       GPIOB
#define RIGHT_MOTOR_PWM_SET        GPIO_SetBits(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM)
#define RIGHT_MOTOR_PWM_RESET      GPIO_ResetBits(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM)

//��2 �������
#define LEFT2_MOTOR_GO             GPIO_Pin_13
#define LEFT2_MOTOR_GO_GPIO        GPIOB
#define LEFT2_MOTOR_GO_SET         GPIO_SetBits(LEFT2_MOTOR_GO_GPIO,LEFT2_MOTOR_GO)
#define LEFT2_MOTOR_GO_RESET       GPIO_ResetBits(LEFT2_MOTOR_GO_GPIO,LEFT2_MOTOR_GO)
//��2 PWM�ٶȿ���
#define LEFT2_MOTOR_PWM            GPIO_Pin_7
#define LEFT2_MOTOR_PWM_GPIO       GPIOB
#define LEFT2_MOTOR_PWM_SET        GPIO_SetBits(LEFT2_MOTOR_PWM_GPIO,LEFT2_MOTOR_PWM)
#define LEFT2_MOTOR_PWM_RESET      GPIO_ResetBits(LEFT2_MOTOR_PWM_GPIO,LEFT2_MOTOR_PWM)
// ��2 �������
#define RIGHT2_MOTOR_GO             GPIO_Pin_15
#define RIGHT2_MOTOR_GPIO           GPIOB
#define RIGHT2_MOTOR_GO_SET         GPIO_SetBits(RIGHT2_MOTOR_GPIO,RIGHT2_MOTOR_GO)
#define RIGHT2_MOTOR_GO_RESET       GPIO_ResetBits(RIGHT2_MOTOR_GPIO,RIGHT2_MOTOR_GO)
//��2 PWM�ٶȿ���
#define RIGHT2_MOTOR_PWM            GPIO_Pin_9
#define RIGHT2_MOTOR_PWM_GPIO       GPIOB
#define RIGHT2_MOTOR_PWM_SET        GPIO_SetBits(RIGHT2_MOTOR_PWM_GPIO,RIGHT2_MOTOR_PWM)
#define RIGHT2_MOTOR_PWM_RESET      GPIO_ResetBits(RIGHT2_MOTOR_PWM_GPIO,RIGHT2_MOTOR_PWM)

#endif
