#ifndef ___MOTOR_H_
#define ___MOTOR_H_

#include "sys.h"

#define FREQ               (50)                                                // 控制频率为50HZ，最高支持300HZ
#define PWM_Bottom_L              				(PWMB_CH1_P50)
#define PWM_Bottom_R              				(PWMB_CH4_P53)
#define PWM_Behind_L							(PWMB_CH2_P51)
#define PWM_Behind_R							(PWMA_CH4P_P26)
#define PWM_Around_L							(PWMB_CH3_P52)
#define PWM_Around_R							(PWMA_CH2P_P12)

void Motor_Init(void);
void Motor_BottomLoad(uint32_t duty_bottom);
void Motor_BehindLoad(int32_t left,int32_t right);
void Motor_AroundLoad(int32_t left,int32_t right);

extern uint16 duty;

#endif
