#ifndef ROCKER_H
#define ROCKER_H

#include "sys.h"

extern float R_x_val,R_y_val;
extern uint16 Rocker_state;

typedef enum 
{
	Rocker_MEDIUM=0,
	Rocker_UP,
	Rocker_DOWN,
	Rocker_LEFT,
	Rocker_RIGHT,
	Rocker_LEFTUP,
	Rocker_LEFTDOWN,
	Rocker_RIGHTUP,
	Rocker_RIGHTDOWN
	
}Rocker;

void rocker_init(void);
void rocker_read(void);

#endif 
