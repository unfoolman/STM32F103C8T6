#ifndef __MOTOR_H__
#define __MOTOR_H__

extern uint8_t PWM_CNT;
void Motor_Init(void);
void Motor_SetSpeed(int16_t Speed);

#endif
