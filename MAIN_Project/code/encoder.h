#ifndef __ENCODER_H
#define __ENCODER_H

#include "sys.h"

extern uint32_t encoder_data;
extern float INS_V;	//���ڹߵ�

void encoder_Init();
void encoder_get(void);

#endif 