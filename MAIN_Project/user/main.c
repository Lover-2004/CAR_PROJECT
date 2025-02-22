/*********************************************************************************************************************
* AI8051U Opensourec Library 即（AI8051U 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是STC 开源库的一部分
*
* AI8051U 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK FOR C251
* 适用平台          AI8051U
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者           备注
* 2024-08-01        大W            first version
********************************************************************************************************************/

#include "sys.h"

// **************************** 代码区域 ****************************
void pit_handler (void);

int8 menu2;

void main()
{
    clock_init(SYSTEM_CLOCK_40M);
	debug_init();

    /*外设初始化*/
	All_Init();
	
	// 设置定时器1中断回调函数
	tim1_irq_handler = pit_handler;
	pit_ms_init(PIT_CH, 10);                                                   // 初始化 PIT 为周期中断 10ms 周期

    while(1)
    {
		menu2=menu1();
//		if(menu2 ==1){menu2_motor ();}
//		if(menu2 ==2){}
//		if(menu2 ==3){}
//		if(menu2 ==4){}

//		rocker_read();
//		printf("rx:%.2f,ry:%.2f,state:%d\n",R_x_val,R_y_val,Rocker_state);
		
//		icm20602_get_acc();                 // 获取ICM20602的加速度测量数值
//		icm20602_get_gyro();                // 获取IMU660RA的角速度测量数值
//		printf("\r\nICM20602 acc data:  x=%5d, y=%5d, z=%5d\r\n", icm20602_acc_x, icm20602_acc_y, icm20602_acc_z);
//		printf("\r\nICM20602 gyro data: x=%5d, y=%5d, z=%5d\r\n", icm20602_gyro_x, icm20602_gyro_y, icm20602_gyro_z);
		
//		GPS_Display();
		
//		CCD_Display();
//		system_delay_ms(500);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     PIT 的周期中断处理函数 这个函数将在 PIT 对应的定时器中断调用 详见 isr.c
// 参数说明     void
// 返回参数     void
// 使用示例     pit_handler();
//-------------------------------------------------------------------------------------------------------------------
void pit_handler (void)
{	
	tsl1401_collect_pit_handler();
}
