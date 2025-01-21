#include "sys.h"

void All_Init(void)
{
	rocker_init();  			//遥感初始化
	icm20602_init();			//姿态传感器初始化
//	imu660ra_init();
	ips200_init();				//屏幕初始化
	Motor_Init();				//电机初始化
	gps_init();					//GPS初始化
	tsl1401_init();				//CCD初始化
}
