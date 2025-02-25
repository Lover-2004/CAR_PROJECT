#include "uart.h"

//逐飞库已经重定向printf


/******************
*功能：初始化串口
*参数：串口编号，波特率，tx引脚，rx引脚，回调函数指针
*返回值：
******************/
uint8_t BL_uart_init(uart_index_enum uart_n, uint32 baud, uart_pin_enum tx_pin, uart_pin_enum rx_pin,void *uart_callback)
{
		if(uart_n == UART_1)
    {
        uart1_irq_handler = uart_callback;
    }
    else if(uart_n == UART_2)
    {
        uart2_irq_handler = uart_callback;
    }
    else if(uart_n == UART_3)
    {
        uart3_irq_handler = uart_callback;
    }
    else if(uart_n == UART_4)
    {
        uart4_irq_handler = uart_callback;
    }
	
	 uart_init (uart_n, baud, tx_pin, rx_pin);   // 初始化串口
   uart_rx_interrupt(uart_n, 1);	//默认打开接收中断
	 
		return 0;
}

