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
	Rocker_MEDIUM=0,	//��
	Rocker_UP,			//��
	Rocker_DOWN,		//��
	Rocker_LEFT,		//��
	Rocker_RIGHT,		//��
	Rocker_LEFTUP,		//����
	Rocker_LEFTDOWN,	//����
	Rocker_RIGHTUP,		//����
	Rocker_RIGHTDOWN	//����
}Rocker;

void rocker_init(void);
uint8_t rocker_read(void);

#endif 
