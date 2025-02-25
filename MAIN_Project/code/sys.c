#include "sys.h"

TxPack_P txpack;
RxPack_P rxpack;


void All_Init(void)
{
	rocker_init();  			//遥感初始化
//	icm20602_init();			//姿态传感器初始化
	imu660ra_init();
	ips200_init();				//屏幕初始化
	Motor_Init();				//电机初始化
	gps_init();					//GPS初始化
	tsl1401_init();				//CCD初始化
//	ValuePack_Init();			//蓝牙串口助手协议
	encoder_Init();				//编码器初始化
//	BL_uart_init(UART_4,115200,UART4_RX_P02,UART4_TX_P03,UART1_Callback);
	
	gpio_init(IO_P24,GPO,0,GPO_PUSH_PULL);
//	
	timer_Init();			//定时器最后初始化
}
