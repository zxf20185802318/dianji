#include "time.h"
#include "stm32f10x.h"

void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能定时器3时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);//设置PC为复用推挽输出
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO时钟
  GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //设置重映射
	TIM_TimeBaseInitStruct.TIM_Period =arr;
	TIM_TimeBaseInitStruct.TIM_Prescaler =psc;
	TIM_TimeBaseInitStruct.TIM_CounterMode =TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision =0;
  TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);//初始化定时器
	TIM_OCInitStruct.TIM_OCMode =TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_Pulse=599;
  TIM_OC1Init(TIM3,&TIM_OCInitStruct);//初始化输出比较参数
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable); 
		TIM_OCInitStruct.TIM_OCMode =TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_Pulse=599;
  TIM_OC2Init(TIM3,&TIM_OCInitStruct);//初始化输出比较参数
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable); 
  TIM_Cmd(TIM3,ENABLE);//使能定时器
}

