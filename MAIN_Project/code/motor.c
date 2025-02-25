#include "motor.h"

uint16 duty = 1.0 / 20 * 10000;			// (1ms/20ms * 10000)（10000是PWM的满占空比时候的值） 10000为PWM最大值

void Motor_Init(void)
{
	pwm_init(PWM_Bottom_L, FREQ, 0);   // PWM 初始化频率 50Hz  占空比初始为 0
	pwm_init(PWM_Bottom_R, FREQ, 0);   // PWM 初始化频率 50Hz  占空比初始为 0
	pwm_init(PWM_Behind_L, FREQ, 0);
	pwm_init(PWM_Behind_R, FREQ, 0);
	pwm_init(PWM_Around_L, FREQ, 0);
	pwm_init(PWM_Around_R, FREQ, 0);

}

void Motor_BottomLoad(uint32_t duty_bottom)
{
	//输出限幅
	duty_bottom=duty_bottom>1000?1000:(duty_bottom<500?500:duty_bottom);
	
	pwm_set_duty(PWM_Bottom_L,duty_bottom);
	pwm_set_duty(PWM_Bottom_R,duty_bottom);
}

void Motor_BehindLoad(int32_t left,int32_t right)
{
	
	//方向控制
//	if(left>=0)
//	{
//		
//	}
//	else
//	{
//		
//	}		
//	if(right>=0)
//	{
//		
//	}
//	else
//	{
//		
//	
	//输出限幅
	left=func_abs(left);
	right=func_abs(right);
	left = left>1000?1000 : (left<500?500:left);
	right = right>1000?1000 : (right<500?500:right);
	
	pwm_set_duty(PWM_Behind_L,left);
	pwm_set_duty(PWM_Behind_R,right);
}

void Motor_AroundLoad(int32_t left,int32_t right)
{
	//if//方向控制
	
	//输出限幅
	left=func_abs(left);
	right=func_abs(right);
	left=left>1000?1000:(left<500?500:left);
	right=right>1000?1000:(right<500?500:right);
	
	pwm_set_duty(PWM_Around_L,left);
	pwm_set_duty(PWM_Around_R,right);
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
