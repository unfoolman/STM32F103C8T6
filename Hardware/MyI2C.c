#include "stm32f10x.h"                  // Device header
#include "DELAY.H"

void MyI2C_W_SCL(uint8_t Bit)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)Bit);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t Bit)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)Bit);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA(void)
{
	uint8_t Bit;
	Bit=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	Delay_us(10);
	return Bit;
}

void MyI2C_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);
}

void MyI2C_Start(void)
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_Stop(void)
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		MyI2C_W_SDA(Byte & (0x80>>i));
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}

uint8_t MyI2C_ReceiveByte(void)
{
	uint8_t i,ReceiveData=0x00;
	for(i=0;i<8;i++)
	{
		MyI2C_W_SCL(1);
		if(MyI2C_R_SDA()==1){ReceiveData|=(0x80>>i);}
		MyI2C_W_SCL(0);
	}
	return ReceiveData;
}

void MyI2C_SendAck(uint8_t AckBit)
{
	MyI2C_W_SDA(AckBit);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);
}

uint8_t MyI2C_ReceiveAck(void)
{
	uint8_t ReceiveData=0x00;
	MyI2C_W_SCL(1);
	ReceiveData=MyI2C_R_SDA();
	MyI2C_W_SCL(0);
	return ReceiveData;
}
