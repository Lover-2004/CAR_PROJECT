#include "sys.h"

void All_Init(void)
{
	rocker_init();  			//ң�г�ʼ��
	icm20602_init();			//��̬��������ʼ��
//	imu660ra_init();
	ips200_init();				//��Ļ��ʼ��
	Motor_Init();				//�����ʼ��
	gps_init();					//GPS��ʼ��
	tsl1401_init();				//CCD��ʼ��
}
