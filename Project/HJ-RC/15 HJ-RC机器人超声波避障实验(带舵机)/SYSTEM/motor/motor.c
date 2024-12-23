//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�������������涨�����˿���ѧϰ�о�24Сʱ��24Сʱ����ɾ�����������������κ���;
//ʹ��SysTick����ͨ����ģʽ���ӳٽ��й����ʺ�STM32F10xϵ�У�
//����delay_us,delay_ms
//********************************************************************************
//////////////////////////////////////////////////////////////////////////////////  
#include "motor.h"
#include "Math.h"
#include "delay.h"
#include "stm32f10x.h"                  // Device header
//���ö�ʱ��4����PWM
void TIM4_PWM_Init(unsigned short arr,unsigned short psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// 
 	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE);  //ʹ��GPIO����ʱ��ʹ�� �����Լ��ĳ�A�ڿ��Ʒ���   
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  //ʹ��GPIO����ʱ��ʹ��  
	//ǰ���
  GPIO_InitStructure.GPIO_Pin = LEFT_MOTOR_GO;         //��1���������� PB12
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(LEFT_MOTOR_GO_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = LEFT_MOTOR_PWM;         //��1���PWM���� PB6
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	   //�����������
	GPIO_Init(LEFT_MOTOR_PWM_GPIO, &GPIO_InitStructure);  
		
	
  GPIO_InitStructure.GPIO_Pin = RIGHT_MOTOR_GO;       //��1����������  PB14
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_Init(RIGHT_MOTOR_GPIO, &GPIO_InitStructure); 
	
	
	GPIO_InitStructure.GPIO_Pin = RIGHT_MOTOR_PWM;       //��1���PWM����  PB8
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	   //�����������
	GPIO_Init(RIGHT_MOTOR_PWM_GPIO, &GPIO_InitStructure);  
	
	
	//����
	  GPIO_InitStructure.GPIO_Pin = LEFT2_MOTOR_GO;         //��2���������� PB13
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(LEFT2_MOTOR_GO_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = LEFT2_MOTOR_PWM;         //��2���PWM���� PB7
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	   //�����������
	GPIO_Init(LEFT2_MOTOR_PWM_GPIO, &GPIO_InitStructure);  
		
	
  GPIO_InitStructure.GPIO_Pin = RIGHT2_MOTOR_GO;       //��2����������  PB15
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_Init(RIGHT2_MOTOR_GPIO, &GPIO_InitStructure); 
	
	
	GPIO_InitStructure.GPIO_Pin = RIGHT2_MOTOR_PWM;       //��2���PWM����  PB9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	   //�����������
	GPIO_Init(RIGHT2_MOTOR_PWM_GPIO, &GPIO_InitStructure);  
	
	
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx ��1���CH3
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx ��1���CH1
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx ��2���CH2
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx ��2���CH4
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE);	//MOE �����ʹ��	
  
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH3Ԥװ��ʹ��	 
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH2Ԥװ��ʹ��	 
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH4Ԥװ��ʹ��
	
  TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
 	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM1   
}
//��1��1ǰ��PWM���ƺ���
void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed) 
{
//		static short sMotorSpeed = 0;
		short sPWM;//���ñ���
//	  float fDir = 1;
	
		if (cSpeed>=100) cSpeed = 100;
	  if (cSpeed<=-100) cSpeed = -100;
	
   	sPWM = 7201 - fabs(cSpeed)*72;  //��һ��ֵ������
	switch(ucChannel)
	{
		case 0://��1�� ��CH3
			TIM_SetCompare3(TIM4,sPWM);
			if (cSpeed>0) 
				RIGHT_MOTOR_GO_RESET;		
			else if(cSpeed<0) 
				RIGHT_MOTOR_GO_SET;
			break;
				
		case 1://��1�� ��CH1
		  TIM_SetCompare1(TIM4,sPWM); 
			if (cSpeed>0) 
				LEFT_MOTOR_GO_SET;
			else if (cSpeed<0)
				LEFT_MOTOR_GO_RESET;
			break;	

	}
}

//��2��2����PWM����
void SetMotorSpeed2(unsigned char ucChannel,signed char cSpeed) 
{
//		static short sMotorSpeed = 0;
		short sPWM;
//	  float fDir = 1;
	
		if (cSpeed>=100) cSpeed = 100;
	  if (cSpeed<=-100) cSpeed = -100;
	
   	sPWM = 7201 - fabs(cSpeed)*72;
	switch(ucChannel)
	{
      case 0://��2��
			TIM_SetCompare4(TIM4,sPWM);
			if (cSpeed>0) 
				RIGHT2_MOTOR_GO_RESET;
			else if(cSpeed<0) 
				RIGHT2_MOTOR_GO_SET;		
			break;		
			
			case 1://��2��
		  TIM_SetCompare2(TIM4,sPWM); 
			if (cSpeed>0) 
				LEFT2_MOTOR_GO_SET;
			else if (cSpeed<0)
				LEFT2_MOTOR_GO_RESET;
			break;
	}
}
//----------------------------------�˶�����--------------------------------
void HJduino_run(signed char speed,int time)  //ǰ������
{
		  signed char f_speed = - speed;
	    SetMotorSpeed(1,f_speed);//��1��  //Ϊ����
			SetMotorSpeed(0,speed);//��1��   //Ϊ����
	
		  SetMotorSpeed2(1,f_speed);//��2��  //Ϊ����
			SetMotorSpeed2(0,speed);//��2��   //Ϊ����
			delay_ms(time);                 //ʱ��Ϊ����

}

void HJduino_brake(int time) //ɲ������
{
	  SetMotorSpeed(1,0);//��1��   //Ϊ0
	  SetMotorSpeed(0,0);//��1��   //Ϊ0
	  RIGHT_MOTOR_GO_RESET;
	  LEFT_MOTOR_GO_RESET;
		SetMotorSpeed2(1,0);//��2��   //Ϊ0
	  SetMotorSpeed2(0,0);//��2��   //Ϊ0
	  RIGHT2_MOTOR_GO_RESET;
	  LEFT2_MOTOR_GO_RESET;
		delay_ms(time);             //ʱ��Ϊ����  
}

void HJduino_Left(signed char speed,int time) //��ת����
{
	  SetMotorSpeed(1,0);//����     //���ֲ���
	  SetMotorSpeed(0,speed);        //����Ϊ��
	
		SetMotorSpeed2(1,0);//����     //���ֲ���
	  SetMotorSpeed2(0,speed);        //����Ϊ��
		delay_ms(time);                 //ʱ��Ϊ����  

}
void HJduino_Spin_Left(signed char speed,int time) //����ת����
{
	  signed char u_speed = 100 - speed; 
 	  SetMotorSpeed(0,speed);//����     //����Ϊ��
	  SetMotorSpeed(1,u_speed);            //����Ϊ��
	
	 	SetMotorSpeed2(0,speed);//����     //����Ϊ��
	  SetMotorSpeed2(1,u_speed);            //����Ϊ��
		delay_ms(time);                    //ʱ��Ϊ����  

}
void HJduino_Right(signed char speed,int time)  //��ת����
{
	  signed char f_speed = - speed;
	  SetMotorSpeed(1,f_speed);//����     //����Ϊ��
	  SetMotorSpeed(0,0);                 //����Ϊ0
		SetMotorSpeed2(1,f_speed);//����     //����Ϊ��
	  SetMotorSpeed2(0,0);                 //����Ϊ0
		delay_ms(time);                   //ʱ��Ϊ����  

}
void HJduino_Spin_Right(signed char speed,int time) //����ת����
{
	  signed char u_speed = 100 - speed;
	  signed char f_speed = - speed;
	  SetMotorSpeed(0,-u_speed);//����     //����Ϊ��
	  SetMotorSpeed(1,f_speed);            //����Ϊ��
		SetMotorSpeed2(0,-u_speed);//����     //����Ϊ��
	  SetMotorSpeed2(1,f_speed);            //����Ϊ��
		delay_ms(time);                    //ʱ��Ϊ����  

}
void HJduino_back(signed char speed,int time) //���˺���
{
	  signed char u_speed = 100- speed;
	  signed char f_speed = - u_speed;
	  SetMotorSpeed(1,u_speed);//��1��   //Ϊ����
	  SetMotorSpeed(0,f_speed);//��1�� //Ϊ����
	
		SetMotorSpeed2(1,u_speed);//��2��   //Ϊ����
	  SetMotorSpeed2(0,f_speed);//��2�� //Ϊ����
		delay_ms(time);                 //ʱ��Ϊ����  


}

void HJduino_L1run(signed char speed,int time) //?1????
{
             signed char f_speed = - speed;
        SetMotorSpeed(1,f_speed);//?1?  //???

            delay_ms(time);                 //????? 
}

void HJduino_L2run(signed char speed,int time) //?2??????
{
          signed char f_speed = - speed;

          SetMotorSpeed2(1,f_speed);//?2?  //???

            delay_ms(time);                 //????? 
}
void HJduino_R1run(signed char speed,int time) //?1??????
{
             signed char f_speed = - speed;

            SetMotorSpeed(0,speed);//?1?   //???
            delay_ms(time);                 //????? 
}

void HJduino_R2run(signed char speed,int time) //?2??????
{
          signed char f_speed = - speed;
            SetMotorSpeed2(0,speed);//?2?   //???
            delay_ms(time);                 //????? 
}

void HJduino_L1back(signed char speed,int time) //?1??????
{
      signed char u_speed = 100- speed;
      signed char f_speed = - u_speed;
      SetMotorSpeed(1,u_speed);//?1?   //???
        delay_ms(time);                 //?????  
}

void HJduino_L2back(signed char speed,int time) //?2??????
{
      signed char u_speed = 100- speed;
      signed char f_speed = - u_speed;
    
        SetMotorSpeed2(1,u_speed);//?2?   //???

        delay_ms(time);                 //?????  
}


void HJduino_R1back(signed char speed,int time) //?1??????
{
      signed char u_speed = 100- speed;
      signed char f_speed = - u_speed;
      SetMotorSpeed(0,f_speed);//?1? //???

        delay_ms(time);                 //?????  
}


void HJduino_R2back(signed char speed,int time) //?2??????
{
      signed char u_speed = 100- speed;
      signed char f_speed = - u_speed;
      SetMotorSpeed2(0,f_speed);//?2? //???
        delay_ms(time);                 //?????  
}

void HJduino_HJ_ZE_R(signed char speed,int time) //???????
{
         HJduino_L1run(70,10);//?1??      
         HJduino_R2run(70,10);//?2??    
         HJduino_L2back(70,10);//?2??
         HJduino_R1back(70,10);//?1??  
}
void HJduino_HJ_ZE_L(signed char speed,int time) //???????
{
         HJduino_L2run(70,10);//?2??          
         HJduino_R1run(70,10);//?1??    
         HJduino_L1back(70,10);//?1??
         HJduino_R2back(70,10);//?2??  
}
