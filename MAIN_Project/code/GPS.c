#include "GPS.h"

void GPS_Display(void)
{
	if(gps_tau1201_flag)  //�жϲɼ���־λ
	{
		gps_tau1201_flag = 0;
		
		if(!gps_data_parse())          //��ʼ��������
		{
			//��ʾ���ڼ�ʱ��
			ips200_show_uint16(   0, 16*0, gps_tau1201.time.year);
			ips200_show_uint8(  80, 16*0, gps_tau1201.time.month);
			ips200_show_uint8( 160, 16*0, gps_tau1201.time.day);
			ips200_show_uint8(   0, 16*1, gps_tau1201.time.hour);
			ips200_show_uint8(  80, 16*1, gps_tau1201.time.minute);
			ips200_show_uint8( 160, 16*1, gps_tau1201.time.second);

			//��ʾGPSλ����Ϣ
			ips200_show_uint8(  0, 16*2, gps_tau1201.state);
			ips200_show_float(120, 16*2, gps_tau1201.latitude, 4, 6);
			ips200_show_float(  0, 16*3, gps_tau1201.longitude, 4, 6);
			ips200_show_float(120, 16*3, gps_tau1201.speed, 4, 6);
			ips200_show_float(  0, 16*4, gps_tau1201.direction, 4, 6);
			ips200_show_uint8(120, 16*4, gps_tau1201.satellite_used);
			ips200_show_float(  0, 16*5, gps_tau1201.height, 4, 6);
			
			printf("now time:\r\n");                                        // ���������ʱ����
			printf("year-%d, month-%d, day-%d\r\n", gps_tau1201.time.year, gps_tau1201.time.month, gps_tau1201.time.day);           // ���������ʱ����
			printf("hour-%d, minute-%d, second-%d\r\n", gps_tau1201.time.hour, gps_tau1201.time.minute, gps_tau1201.time.second);   // ���������ʱ����
			printf("gps_state       = %d\r\n" , gps_tau1201.state);         //�����ǰ��λ��Чģʽ 1����λ��Ч  0����λ��Ч
			printf("latitude        = %lf\r\n", gps_tau1201.latitude);      //���γ����Ϣ
			printf("longitude       = %lf\r\n", gps_tau1201.longitude);     //���������Ϣ
			printf("speed           = %lf\r\n", gps_tau1201.speed);         //����ٶ���Ϣ
			printf("direction       = %lf\r\n", gps_tau1201.direction);     //���������Ϣ
			printf("satellite_used  = %d\r\n" , gps_tau1201.satellite_used);//�����ǰ���ڶ�λ����������
			printf("height          = %lf\r\n", gps_tau1201.height);        //�����ǰGPS���������߶�
		}
	}
}
