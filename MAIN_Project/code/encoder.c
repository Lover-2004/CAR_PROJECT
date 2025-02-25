#include "encoder.h"

#define ENCODER_DIR                	(TIM0_ENCOEDER)                         // 正交编码器对应使用的编码器接口 这里使用QTIMER1的ENCOEDER1
#define ENCODER_DIR_DIR              	(IO_P35)            				 	// DIR 对应的引脚
#define ENCODER_DIR_PULSE            	(TIM0_ENCOEDER_P34)            			// PULSE 对应的引脚

uint32_t encoder_data=0;
float INS_V=0;	//用在惯导

float low_pass=0.7;

void encoder_Init()
{
	encoder_dir_init(ENCODER_DIR, ENCODER_DIR_DIR, ENCODER_DIR_PULSE);   	
}


/******************
*功能：获得编码器值，低通滤波
*参数：
*返回值：
******************/
void encoder_get(void)
{
    static uint8_t times=1;
    static float encoder_dr=0;
    // 有刷电机脉冲计数
    encoder_data = encoder_get_count(ENCODER_DIR);
    // 编码器 低通滤波
    INS_V = INS_V * low_pass + encoder_data * (1 - low_pass);
    encoder_dr+=INS_V;
    if(times==5){
        encoder_data=(uint32_t)encoder_dr;
        encoder_dr=0;
        times=0;
    }
    // 清除编码器计数 方便下次采集
    encoder_clear_count(ENCODER_DIR);
    times++;
}