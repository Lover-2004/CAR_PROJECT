#ifndef ___CCD_H_
#define ___CCD_H_

#include "zf_common_headfile.h"

#pragma warning disable = 177

#define PIT_CH              (TIM1_PIT )             // ʹ�õ������жϱ�� ����޸� ��Ҫͬ����Ӧ�޸������жϱ���� isr.c �еĵ���

void CCD_Display(void);

extern uint8 y1_boundary[128];
extern uint8 y2_boundary[128];
extern uint8 y3_boundary[128];

#endif
