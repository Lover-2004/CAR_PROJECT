#include "uart.h"

//��ɿ��Ѿ��ض���printf


/******************
*���ܣ���ʼ������
*���������ڱ�ţ������ʣ�tx���ţ�rx���ţ��ص�����ָ��
*����ֵ��
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
	
	 uart_init (uart_n, baud, tx_pin, rx_pin);   // ��ʼ������
   uart_rx_interrupt(uart_n, 1);	//Ĭ�ϴ򿪽����ж�
	 
		return 0;
}

