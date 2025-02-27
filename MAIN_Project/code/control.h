#ifndef CONTROL_H
#define CONTROL_H

#include "sys.h"
 
typedef struct 
{
    float kp;     	// 比例系数
    float ki;     	// 积分系数
    float kd;     	// 微分系数
    float ek0;    	// 上次的误差
	float ek1;		// 上上次的误差
 	float ek2;		// 上上上次的误差
    float integral; // 积分项
} PID;

void PID_Init(PID *pid, float kp, float ki, float kd);
float PID_position(PID *pid, float Value_new, float goal);	//位置式PID
float PID_increment(PID *pid, float Value_new, float goal);	//增量式PID

#endif 
