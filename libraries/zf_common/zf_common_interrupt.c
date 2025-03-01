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

#include "zf_common_interrupt.h"

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     指定中断设置优先级
// 参数说明     irqn            指定中断号 可查看 zf_common_interrupt.h 对应中断服务函数的标注
// 参数说明     priority        抢占式优先级 0到3，0为最低优先级，3为最高优先级
// 返回参数     void
// 使用示例     interrupt_set_priority(	TIMER0_IRQn, 3);
//                              		设置周期中断定时器0的优先级为3
//                              		禁止调用ch32v30x_misc里面的函数
// 备注信息				 其余不能设置的，中断优先级全部为最低优先级0
//-------------------------------------------------------------------------------------------------------------------
void interrupt_set_priority (irqn_type_enum irqn, uint8 priority)
{
    if((irqn >> 4) == 0)
    {
        IP  |= (priority & 0x01) << (irqn & 0x0F);
        IPH |= ((priority >> 1) & 0x01) << (irqn & 0x0F);
    }
    else if((irqn >> 4) == 1)
    {
        IP2  |= (priority & 0x01) << (irqn & 0x0F);
        IP2H |= ((priority >> 1) & 0x01) << (irqn & 0x0F);
    }
    else if((irqn >> 4) == 2)
    {
        IP3  |= (priority & 0x01) << (irqn & 0x0F);
        IP3H |= ((priority >> 1) & 0x01) << (irqn & 0x0F);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     关闭全局中断
// 参数说明     void            
// 返回参数     void
// 使用示例     
//             
// 备注信息				 
//-------------------------------------------------------------------------------------------------------------------
void interrupt_global_disable(void)
{
    EA = 0;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     开启全局中断
// 参数说明     void            
// 返回参数     void
// 使用示例     
//             
// 备注信息				 
//-------------------------------------------------------------------------------------------------------------------
void interrupt_global_enable(void)
{
    EA = 1;
}

