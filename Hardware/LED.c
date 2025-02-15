#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void LED2_SetBits(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
void LED2_ResetBits(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
void LED4_SetBits(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}
void LED4_ResetBits(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}

void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
}
void LED4_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_4)==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	}
}
