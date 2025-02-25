#ifndef ROCKER_H
#define ROCKER_H

#include "sys.h"

#define ROCKER_X            (ADC_CH13_P05)
#define ROCKER_Y            (ADC_CH14_P06)
#define ROCKER_KEY          IO_P07
#define SWITCH1          	IO_P00
#define SWITCH2         	IO_P10

extern float R_x_val,R_y_val;
extern uint16 Rocker_state;

typedef enum 
{
	Rocker_MEDIUM=0,	//中
	Rocker_UP,			//上
	Rocker_DOWN,		//下
	Rocker_LEFT,		//左
	Rocker_RIGHT,		//右
	Rocker_LEFTUP,		//左上
	Rocker_LEFTDOWN,	//左下
	Rocker_RIGHTUP,		//右上
	Rocker_RIGHTDOWN	//右下
}Rocker;

void rocker_init(void);
uint8_t rocker_read(void);

#endif 
