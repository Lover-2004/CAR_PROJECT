#ifndef ___CCD_H_
#define ___CCD_H_

#include "zf_common_headfile.h"

#pragma warning disable = 177

#define PIT_CH              (TIM1_PIT )             // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用

void CCD_Display(void);

extern uint8 y1_boundary[128];
extern uint8 y2_boundary[128];
extern uint8 y3_boundary[128];

#endif
