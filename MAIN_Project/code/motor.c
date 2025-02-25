#include "motor.h"

uint16 duty = 1.0 / 20 * 10000;			// (1ms/20ms * 10000)��10000��PWM����ռ�ձ�ʱ���ֵ�� 10000ΪPWM���ֵ

void Motor_Init(void)
{
	pwm_init(PWM_Bottom_L, FREQ, 0);   // PWM ��ʼ��Ƶ�� 50Hz  ռ�ձȳ�ʼΪ 0
	pwm_init(PWM_Bottom_R, FREQ, 0);   // PWM ��ʼ��Ƶ�� 50Hz  ռ�ձȳ�ʼΪ 0
	pwm_init(PWM_Behind_L, FREQ, 0);
	pwm_init(PWM_Behind_R, FREQ, 0);
	pwm_init(PWM_Around_L, FREQ, 0);
	pwm_init(PWM_Around_R, FREQ, 0);

}

void Motor_BottomLoad(uint32_t duty_bottom)
{
	//����޷�
	duty_bottom=duty_bottom>1000?1000:(duty_bottom<500?500:duty_bottom);
	
	pwm_set_duty(PWM_Bottom_L,duty_bottom);
	pwm_set_duty(PWM_Bottom_R,duty_bottom);
}

void Motor_BehindLoad(int32_t left,int32_t right)
{
	
	//�������
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
	//����޷�
	left=func_abs(left);
	right=func_abs(right);
	left = left>1000?1000 : (left<500?500:left);
	right = right>1000?1000 : (right<500?500:right);
	
	pwm_set_duty(PWM_Behind_L,left);
	pwm_set_duty(PWM_Behind_R,right);
}

void Motor_AroundLoad(int32_t left,int32_t right)
{
	//if//�������
	
	//����޷�
	left=func_abs(left);
	right=func_abs(right);
	left=left>1000?1000:(left<500?500:left);
	right=right>1000?1000:(right<500?500:right);
	
	pwm_set_duty(PWM_Around_L,left);
	pwm_set_duty(PWM_Around_R,right);
}

// ������ˢ���ת��   ��1ms - 2ms��/20ms * 10000��10000��PWM����ռ�ձ�ʱ���ֵ��
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 0%   Ϊ 500
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 20%  Ϊ 600
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 40%  Ϊ 700
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 60%  Ϊ 800
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 80%  Ϊ 900
// ��50Hz�Ŀ���Ƶ���£���ˢ���ת�� 100% Ϊ 1000

// ���֧��50hz-300hz�Ŀ���Ƶ��
// 50Hz�Ŀ���Ƶ�� ����0%��100%ռ�ձ�Ϊ500��1000
// 100Hz�Ŀ���Ƶ�ʣ���0%��100%ռ�ձ�Ϊ1000��2000
// 200Hz�Ŀ���Ƶ�ʣ���0%��100%ռ�ձ�Ϊ2000��4000
// 300Hz�Ŀ���Ƶ�ʣ���0%��100%ռ�ձ�Ϊ3000��6000
