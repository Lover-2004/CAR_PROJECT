#include "time.h"

void pit_handler (void);
Timer1_Flag TFlag1;

void timer_Init()
{
	// 设置定时器1中断回调函数
	tim1_irq_handler = pit_handler;
	pit_ms_init(PIT_CH, 10);		// 初始化 PIT 为周期中断 2ms 周期

}

/******************
*功能：定时器中断入口函数，要先将定时器中断函数指针指向它,这里两毫秒进入一次
*参数：
*返回值：
******************/
void pit_handler (void)
{	
	static uint32_t time_sum=0;
	time_sum+=10;
	if(time_sum%2==0)TFlag1.T_2ms=1;
	if(time_sum%4==0)TFlag1.T_4ms=1;
	if(time_sum%6==0)TFlag1.T_6ms=1;
	if(time_sum%10==0)TFlag1.T_10ms=1;
	if(time_sum%20==0)TFlag1.T_20ms=1;
	if(time_sum%50==0)TFlag1.T_50ms=1;
	
	time_sum=time_sum>=0xfffffff0?(time_sum&0x00000111):time_sum;	//溢出检查
	Interrupt_Solution();
}
/******************
*功能：定时器中断处理函数
*参数：
*返回值：
******************/
void Interrupt_Solution()
{
	if(TFlag1.T_10ms)	//10ms中断
	{
		get_yaw_data(&gyro_z);
		encoder_get();
//		tsl1401_collect_pit_handler();
		TFlag1.T_10ms=0;
	}
}
