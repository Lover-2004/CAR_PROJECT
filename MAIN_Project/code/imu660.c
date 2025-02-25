#include "imu660.h"

float zero_drift_pitch=-1.1,zero_drift_roll=0,zero_drift_yaw=-13.65340;
float gyro_x,gyro_y,gyro_z;
float PITCH=0,ROLL=0,YAW=0;
double yaw_e=0.00059809;
//10910,32947,43825
//10845,21974,32184,42743

void get_yaw_data(float* gyro_z)  
{
	short gyro_yaw;
	static int32_t gyro_z_sum=0;
	imu660ra_get_gyro();
	gyro_yaw=imu660ra_gyro_z;
	gyro_yaw-=zero_drift_yaw;
	*gyro_z=-(float)gyro_yaw;
	gyro_z_sum+=gyro_yaw;
	gyro_z_sum=gyro_z_sum>150478*2?-150478*4+gyro_z_sum:(gyro_z_sum<-150478*2?150478*4+gyro_z_sum:gyro_z_sum);
	YAW=gyro_z_sum*yaw_e;
	YAW=-YAW;
//	YAW=gyro_z_sum;
	
}

void get_drift()		//¼ÆËãÆ«º½½Ç
{
	int32_t drift_sum=0;
//	short gyro_yaw;
	
	uint32_t i=0;
	for(i=0;i<5000;i++)
	{
		imu660ra_get_gyro();
//		gyro_yaw=imu660ra_gyro_z;
		drift_sum+=imu660ra_gyro_z;
		system_delay_ms(10);
	}
	zero_drift_yaw=(float)drift_sum/5000;
	ips200_show_string(0, 16*16, "drift:");
	ips200_show_float(120, 16*16,(float)zero_drift_yaw,5,5);
//	printf2("drift:%f",zero_drift_yaw);
}