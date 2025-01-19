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

#include "zf_common_headfile.h"
#include "sys.h"

// STC无刷电调仅支持3S锂电池，请按照规定使用电池
// STC无刷电调仅支持3S锂电池，请按照规定使用电池
// STC无刷电调仅支持3S锂电池，请按照规定使用电池

// *************************** 例程硬件连接说明 ***************************
//      模块管脚            单片机管脚
//      PWM_1           	P02
//      PWM_2           	P26
//      GND             	GND
//
//      接线端子 +          电池正极
//      接线端子 -          电池负极
//
// 使用 学习主板 进行测试
//      将模块的电源接线端子与主板的驱动供电端子连接
//      将模块的信号接口使用配套灰排线与主板电机信号接口连接 请注意接线方向 不确定方向就是用万用表确认一下 引脚参考上方核心板连接
//      将主板与供电电池正确连接

// *************************** 例程测试说明 ***************************
// 1.核心板烧录完成本例程 主板电池供电
//
// 2.如果接了STC无刷电调，可以看到 无刷电调控制风扇转动。
//
// 3.如果没有接电机 使用万用表可以在驱动电机输出端子上测量到输出电压变化
//
// 如果发现现象与说明严重不符 请参照本文件最下方 例程常见问题说明 进行排查

// **************************** 代码区域 ****************************
#define FREQ               (50)                                                // 控制频率为50HZ，最高支持300HZ
#define PWM_1              (PWMA_CH2P_P12)
#define PWM_2              (PWMA_CH4P_P26)

uint16 duty = 0;
void main()
{
    clock_init(SYSTEM_CLOCK_40M);
	debug_init();

   
    // 此处编写用户代码 例如外设初始化代码等
    pwm_init(PWM_1, FREQ, 0);                                                   // PWM 通道1 初始化频率 50Hz  占空比初始为 0
    pwm_init(PWM_2, FREQ, 0);                                                   // PWM 通道2 初始化频率 50Hz  占空比初始为 0
    rocker_init();  
		icm20602_init();
//		imu660ra_init();
	
		// 设置周期中断回调函数
//		tim0_irq_handler = pit_hanlder;
//    pit_ms_init(PIT, 5);
	
	// 此处编写用户代码 例如外设初始化代码等

    // 电调控制是看高电平时间，范围： 1ms-2ms
    // 1ms 为 0%
    // 2ms 为 100%

    duty = 1.0 / 20 * 10000;        // (1ms/20ms * 10000)（10000是PWM的满占空比时候的值） 10000为PWM最大值

    while(1)
    {
			
//			rocker_read();
//			printf("rx:%.2f,ry:%.2f,state:%d\n",R_x_val,R_y_val,Rocker_state);
			icm20602_get_acc();                                                         // 获取ICM20602的加速度测量数值
    icm20602_get_gyro();                                                         // 获取 IMU660RA 的角速度测量数值
		printf("\r\nICM20602 acc data:  x=%5d, y=%5d, z=%5d\r\n", icm20602_acc_x, icm20602_acc_y, icm20602_acc_z);
    printf("\r\nICM20602 gyro data: x=%5d, y=%5d, z=%5d\r\n", icm20602_gyro_x, icm20602_gyro_y, icm20602_gyro_z);
    system_delay_ms(500);
		// 此处编写需要循环执行的代码

        // 计算无刷电调转速   （1ms - 2ms）/20ms * 10000（10000是PWM的满占空比时候的值）
        // 在50Hz的控制频率下，无刷电调转速 0%   为 500
        // 在50Hz的控制频率下，无刷电调转速 20%  为 600
        // 在50Hz的控制频率下，无刷电调转速 40%  为 700
        // 在50Hz的控制频率下，无刷电调转速 60%  为 800
        // 在50Hz的控制频率下，无刷电调转速 80%  为 900
        // 在50Hz的控制频率下，无刷电调转速 100% 为 1000
		
		// 电调支持50hz-300hz的控制频率
		// 50Hz的控制频率 ，从0%到100%占空比为500到1000
		// 100Hz的控制频率，从0%到100%占空比为1000到2000
		// 200Hz的控制频率，从0%到100%占空比为2000到4000
		// 300Hz的控制频率，从0%到100%占空比为3000到6000
		// 如果，看了此段话再来问，我会再次截图给你这段话。
		
        // 修改duty的值，可以修改无刷电调转速

        
        // 此处编写需要循环执行的代码
    }
}
// **************************** 代码区域 ****************************

// *************************** 例程常见问题说明 ***************************
// 遇到问题时请按照以下问题检查列表检查
//
// 问题1：电机不转或者模块输出电压无变化
//      如果使用主板测试，主板必须要用电池供电
//      检查模块是否正确连接供电 必须使用电源线供电 不能使用杜邦线
//      查看程序是否正常烧录，是否下载报错，确认正常按下复位按键
//      万用表测量对应 PWM 引脚电压是否变化，如果不变化证明程序未运行，或者引脚损坏，或者接触不良 联系技术客服




