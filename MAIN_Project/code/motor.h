#ifndef ___MOTOR_H_
#define ___MOTOR_H_

#include "sys.h"

#define FREQ               (50)                                                // 控制频率为50HZ，最高支持300HZ
#define PWM_1              (PWMA_CH2P_P12)
#define PWM_2              (PWMA_CH4P_P26)

void Motor_Init(void);

extern uint16 duty;

#endif
