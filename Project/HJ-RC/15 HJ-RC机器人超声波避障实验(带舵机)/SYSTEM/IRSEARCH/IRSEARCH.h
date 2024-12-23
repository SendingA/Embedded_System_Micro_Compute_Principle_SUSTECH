#ifndef __IRSEARCH_H_
#define __IRSEARCH_H_

#include "stm32f10x.h"

void IRSearchInit(void);
void SearchRun(void);

//ѭ�����Թ�
/* 
��ѭ��	SEARCH_R_PIN	PC13
��ѭ��	SEARCH_L_PIN	PC11
 */

#define SEARCH_R_PIN         GPIO_Pin_13
#define SEARCH_R_GPIO        GPIOC
#define SEARCH_R_IO          GPIO_ReadInputDataBit(SEARCH_R_GPIO, SEARCH_R_PIN)

#define SEARCH_L_PIN         GPIO_Pin_11
#define SEARCH_L_GPIO        GPIOC
#define SEARCH_L_IO          GPIO_ReadInputDataBit(SEARCH_L_GPIO, SEARCH_L_PIN)
#define BLACK_AREA 1
#define WHITE_AREA 0


//ָ���
#define COMM_STOP  'I'//ֹͣ
#define COMM_UP    'A'//ǰ��
#define COMM_DOWN  'B'//����
#define COMM_LEFT  'C'//��ת
#define COMM_RIGHT 'D'//��ת



#endif
