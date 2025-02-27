#ifndef CONTROL_H
#define CONTROL_H

#include "sys.h"
 
typedef struct 
{
    float kp;     	// ����ϵ��
    float ki;     	// ����ϵ��
    float kd;     	// ΢��ϵ��
    float ek0;    	// �ϴε����
	float ek1;		// ���ϴε����
 	float ek2;		// �����ϴε����
    float integral; // ������
} PID;

void PID_Init(PID *pid, float kp, float ki, float kd);
float PID_position(PID *pid, float Value_new, float goal);	//λ��ʽPID
float PID_increment(PID *pid, float Value_new, float goal);	//����ʽPID

#endif 
