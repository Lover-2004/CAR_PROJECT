#include "rocker.h"

#define ROCKER_X            (ADC_CH12_P04)
#define ROCKER_Y            (ADC_CH3_P13)



float R_x_val=0,R_y_val=0;
uint16 Rocker_state=0;

/******************
*功能：摇杆初始化
*参数：
*返回值：
******************/
void rocker_init(void)
{
	adc_init(ROCKER_X, ADC_12BIT);                                          // 初始化对应 ADC 通道为对应精度
	adc_init(ROCKER_Y, ADC_12BIT);              
}

/******************
*功能：读取摇杆状态
*参数：
*返回值：
******************/
void rocker_read(void)
{
	R_x_val=3.3*(double)adc_convert(ROCKER_X)/4096;
	R_y_val=3.3*(double)adc_convert(ROCKER_Y)/4096;
	
	
	if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>1.0&&R_y_val<2.0))Rocker_state=Rocker_DOWN;	
	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>1.0&&R_y_val<2.0))Rocker_state=Rocker_UP;	
	else if((R_x_val>1.0&&R_x_val<2.0)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFT;
	else if((R_x_val>1.0&&R_x_val<2.0)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHT;
	else if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFTDOWN;
	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFTUP;
	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHTUP;
	else if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHTDOWN;
	else if((R_x_val>1.7&&R_x_val<1.9)&&(R_y_val>1.7&&R_y_val<1.9))Rocker_state=Rocker_MEDIUM;
}
