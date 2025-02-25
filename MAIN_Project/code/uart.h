#ifndef __UART_H
#define __UART_H

#include "sys.h"

uint8_t BL_uart_init(uart_index_enum uart_n, uint32 baud, 
uart_pin_enum tx_pin, uart_pin_enum rx_pin,void *uart_callback);


#endif 