#include "motor.h"
#include "sys.h"

void MOTOR_Init(void)
{
  
	GPIO_InitTypeDef GPIO_Initstruct;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
  GPIO_Initstruct.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8;
  GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	GPIO_ResetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_8);
}
