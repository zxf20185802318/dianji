#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "time.h"
#include "motor.h"

int main()
{
	delay_init();
	MOTOR_Init();
	TIM3_PWM_Init(999,71);
	while(1)
	{  //正转
    	GPIO_SetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8);
		  GPIO_ResetBits(GPIOB,GPIO_Pin_3);
		delay_ms(4);
		
	    GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_7|GPIO_Pin_8);
		  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
				delay_ms(4);
		
		  GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_8);
	 	  GPIO_ResetBits(GPIOB,GPIO_Pin_7);
				delay_ms(4);
		
	  	GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7);
		  GPIO_ResetBits(GPIOB,GPIO_Pin_8);
				delay_ms(4);
	}
}

//反转
//  while(1)
//	{  
//    	GPIO_SetBits(GPIO_Pin_3|GPIOB,GPIO_Pin_5|GPIO_Pin_7);
//		  GPIO_ResetBits(GPIOB,GPIO_Pin_8);
//		   delay_ms(4);
//		
//	    GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_8);
//		  GPIO_ResetBits(GPIOB,GPIO_Pin_7);
//				delay_ms(4);
//		
//		  GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_7|GPIO_Pin_8);
//	 	  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//				delay_ms(4);
//		
//	  	GPIO_SetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8);
//		  GPIO_ResetBits(GPIOB,GPIO_Pin_3);
//				delay_ms(4);
//	}