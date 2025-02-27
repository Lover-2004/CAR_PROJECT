#include "control.h"

// PID初始化函数
void PID_Init(PID *pid, float kp, float ki, float kd) 
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->ek0 = 0;
    pid->ek1 = 0;
    pid->ek2 = 0;
    pid->integral = 0;
}

float PID_position(PID *pid, float Value_new, float goal)	//位置式PID
{
    float output;
	
	pid->ek0 = goal - Value_new;
    pid->integral += pid->ek0;
	
    output = pid->kp * pid->ek0 + pid->ki * pid->integral + pid->kd * (pid->ek0 - pid->ek1);
    pid->ek1 = pid->ek0;
    return output;
}

float PID_increment(PID *pid, float Value_new, float goal)	//增量式PID
{
    float output;
	
	pid->ek0 = goal - Value_new;
	
    output = pid->kp * (pid->ek0 - pid->ek1) + pid->ki * pid->ek0 + pid->kd * (pid->ek0-2*pid->ek1+pid->ek2);
	pid->ek2 =pid->ek1;
    pid->ek1 = pid->ek0;  
    return output;
}
