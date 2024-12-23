#include "keysacn.h"
#include "delay.h"
#include "stm32f10x.h"                  // Device header
//������ʼ������ 
//PC4��PC5 ���ó�����
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);//ʹ��PORTA,PORTCʱ��     
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;//PC4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC4
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //������PA8 ��Ҫ�����Ļ�8
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	GPIO_InitStructure.GPIO_Pin = LED_D3_PIN;				 //LED L1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHz
  GPIO_Init(LED_D3_PIN_GPIO, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.3
	
	GPIO_InitStructure.GPIO_Pin = LED_D4_PIN;				 //LED L2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHz
  GPIO_Init(LED_D4_PIN_GPIO, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC.3
}

void keysacn()
{
  int val;
  val=KEY;  //��ȡ����
  while(!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4))//������û�б�����ʱ��һֱѭ��
  {
    val=KEY;//�ʾ��ʡ�ԣ�����ѭ���ܿ�
  }
  while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4))//������������ʱ
  {
    delay_ms(10);	  //��ʱ10ms
    val=KEY;//��ȡ���ֶ˿�PC4�ڵ�ƽֵ����Val
    if(val==1)  //�ڶ����жϰ����Ƿ񱻰���
    {
      BEEP_SET;		//��������
      while(!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4))	//�жϰ�ʱ�Ƿ��ɿ�
        BEEP_RESET;	//������ֹͣ
    }
    else
				BEEP_RESET;//������ֹͣ
  }
}
