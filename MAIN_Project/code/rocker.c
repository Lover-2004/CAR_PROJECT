#include "rocker.h"

float R_x_val=0,R_y_val=0;
uint16 Rocker_state=0;

/******************
*功能：摇杆初始化
*参数：
*返回值：
******************/
void rocker_init(void)
{
	adc_init(ROCKER_X, ADC_8BIT);                                          // 初始化对应 ADC 通道为对应精度
	adc_init(ROCKER_Y, ADC_8BIT);   
	gpio_init(ROCKER_KEY, GPI, 1, GPI_PULL_UP);	
}

/******************
*功能：读取摇杆状态
*参数：
*返回值：1：有更新，0：无更新
******************/
uint8_t rocker_read(void)
{
	static uint8 last_state=Rocker_MEDIUM;
	R_x_val=adc_convert(ROCKER_X);
	R_y_val=adc_convert(ROCKER_Y);
	if(R_y_val>250)Rocker_state=Rocker_UP;
	else if(R_y_val<5)Rocker_state=Rocker_DOWN;	
	else if(R_x_val>250)Rocker_state=Rocker_LEFT;
	else if(R_x_val<5)Rocker_state=Rocker_RIGHT;
	else if((R_x_val>=120&&R_x_val<130)&&(R_y_val>120&&R_y_val<130))Rocker_state=Rocker_MEDIUM;
	if(Rocker_state!=last_state){last_state=Rocker_state;return 1;}
	else return 0;
//	R_x_val=3.3*(double)adc_convert(ROCKER_X)/256;
//	R_y_val=3.3*(double)adc_convert(ROCKER_Y)/256;
//	
//	
//	if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>1.0&&R_y_val<2.0))Rocker_state=Rocker_DOWN;	
//	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>1.0&&R_y_val<2.0))Rocker_state=Rocker_UP;	
//	else if((R_x_val>1.0&&R_x_val<2.0)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFT;
//	else if((R_x_val>1.0&&R_x_val<2.0)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHT;
//	else if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFTDOWN;
//	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>2.5&&R_y_val<3.3))Rocker_state=Rocker_LEFTUP;
//	else if((R_x_val>=0&&R_x_val<0.6)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHTUP;
//	else if((R_x_val>2.5&&R_x_val<3.3)&&(R_y_val>=0.0&&R_y_val<0.6))Rocker_state=Rocker_RIGHTDOWN;
//	else if((R_x_val>1.7&&R_x_val<1.9)&&(R_y_val>1.7&&R_y_val<1.9))Rocker_state=Rocker_MEDIUM;
}
