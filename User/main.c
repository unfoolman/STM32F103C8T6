#include "stm32f10x.h"                  // Device header
#include "OLED.H"
#include "MPU6050.H"
#include "MOTOR.H"
#include "Delay.h"

int16_t ACCEL_X,ACCEL_Y,ACCEL_Z,GYRO_X,GYRO_Y,GYRO_Z;

int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"MPU6050_Data:");
	OLED_ShowString(3,1,"MotorSpeed:");
	OLED_ShowString(4,5,"%");

	Motor_Init();
	MPU6050_Init();
	while (1)
	{
		MPU6050_GetValue(&ACCEL_X,&ACCEL_Y,&ACCEL_Z,&GYRO_X,&GYRO_Y,&GYRO_Z);
		OLED_ShowSignedNum(2,1,ACCEL_X,5);
		Delay_ms(20);
		Motor_SetSpeed(ACCEL_X/20);
		OLED_ShowSignedNum(4,1,ACCEL_X/20,3);
	}
}
