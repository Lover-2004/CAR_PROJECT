#include "sys.h"

TxPack_P txpack;
RxPack_P rxpack;


void All_Init(void)
{
	rocker_init();  			//ң�г�ʼ��
//	icm20602_init();			//��̬��������ʼ��
	imu660ra_init();
	ips200_init();				//��Ļ��ʼ��
	Motor_Init();				//�����ʼ��
	gps_init();					//GPS��ʼ��
	tsl1401_init();				//CCD��ʼ��
//	ValuePack_Init();			//������������Э��
	encoder_Init();				//��������ʼ��
//	BL_uart_init(UART_4,115200,UART4_RX_P02,UART4_TX_P03,UART1_Callback);
	
	gpio_init(IO_P24,GPO,0,GPO_PUSH_PULL);
//	
	timer_Init();			//��ʱ������ʼ��
}
