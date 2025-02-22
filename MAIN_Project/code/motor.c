#include "motor.h"

uint16 duty = 1.0 / 20 * 10000;			// (1ms/20ms * 10000)（10000是PWM的满占空比时候的值） 10000为PWM最大值

void Motor_Init(void)
{
	pwm_init(PWM_1, FREQ, 0);                                           // PWM 通道1 初始化频率 50Hz  占空比初始为 0
    pwm_init(PWM_2, FREQ, 0);                                           // PWM 通道2 初始化频率 50Hz  占空比初始为 0
}

// 计算无刷电调转速   （1ms - 2ms）/20ms * 10000（10000是PWM的满占空比时候的值）
// 在50Hz的控制频率下，无刷电调转速 0%   为 500
// 在50Hz的控制频率下，无刷电调转速 20%  为 600
// 在50Hz的控制频率下，无刷电调转速 40%  为 700
// 在50Hz的控制频率下，无刷电调转速 60%  为 800
// 在50Hz的控制频率下，无刷电调转速 80%  为 900
// 在50Hz的控制频率下，无刷电调转速 100% 为 1000

// 电调支持50hz-300hz的控制频率
// 50Hz的控制频率 ，从0%到100%占空比为500到1000
// 100Hz的控制频率，从0%到100%占空比为1000到2000
// 200Hz的控制频率，从0%到100%占空比为2000到4000
// 300Hz的控制频率，从0%到100%占空比为3000到6000
