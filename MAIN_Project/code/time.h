#ifndef _TIME_H
#define _TIME_H

#include "sys.h"

#define PIT_CH              (TIM1_PIT )             // 使用的周期中断编号 如果修改 需要同步对应修改周期中断编号与 isr.c 中的调用

typedef struct {

    unsigned char T_2ms;
    unsigned char T_4ms;
    unsigned char T_6ms;
    unsigned char T_10ms;
    unsigned char T_20ms;
    unsigned char T_50ms;
    unsigned char T_100ms;
    unsigned char T_200ms;

}Timer1_Flag;

extern Timer1_Flag TFlag1;

void timer_Init();
void Interrupt_Solution();

#endif 