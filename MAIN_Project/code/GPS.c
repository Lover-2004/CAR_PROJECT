#include "GPS.h"

void GPS_Display(void)
{
	if(gps_tau1201_flag)  //判断采集标志位
	{
		gps_tau1201_flag = 0;
		
		if(!gps_data_parse())          //开始解析数据
		{
			//显示日期及时间
			ips200_show_uint16(   0, 16*0, gps_tau1201.time.year);
			ips200_show_uint8(  80, 16*0, gps_tau1201.time.month);
			ips200_show_uint8( 160, 16*0, gps_tau1201.time.day);
			ips200_show_uint8(   0, 16*1, gps_tau1201.time.hour);
			ips200_show_uint8(  80, 16*1, gps_tau1201.time.minute);
			ips200_show_uint8( 160, 16*1, gps_tau1201.time.second);

			//显示GPS位置信息
			ips200_show_uint8(  0, 16*2, gps_tau1201.state);
			ips200_show_float(120, 16*2, gps_tau1201.latitude, 4, 6);
			ips200_show_float(  0, 16*3, gps_tau1201.longitude, 4, 6);
			ips200_show_float(120, 16*3, gps_tau1201.speed, 4, 6);
			ips200_show_float(  0, 16*4, gps_tau1201.direction, 4, 6);
			ips200_show_uint8(120, 16*4, gps_tau1201.satellite_used);
			ips200_show_float(  0, 16*5, gps_tau1201.height, 4, 6);
			
			printf("now time:\r\n");                                        // 输出年月日时分秒
			printf("year-%d, month-%d, day-%d\r\n", gps_tau1201.time.year, gps_tau1201.time.month, gps_tau1201.time.day);           // 输出年月日时分秒
			printf("hour-%d, minute-%d, second-%d\r\n", gps_tau1201.time.hour, gps_tau1201.time.minute, gps_tau1201.time.second);   // 输出年月日时分秒
			printf("gps_state       = %d\r\n" , gps_tau1201.state);         //输出当前定位有效模式 1：定位有效  0：定位无效
			printf("latitude        = %lf\r\n", gps_tau1201.latitude);      //输出纬度信息
			printf("longitude       = %lf\r\n", gps_tau1201.longitude);     //输出经度信息
			printf("speed           = %lf\r\n", gps_tau1201.speed);         //输出速度信息
			printf("direction       = %lf\r\n", gps_tau1201.direction);     //输出方向信息
			printf("satellite_used  = %d\r\n" , gps_tau1201.satellite_used);//输出当前用于定位的卫星数量
			printf("height          = %lf\r\n", gps_tau1201.height);        //输出当前GPS天线所处高度
		}
	}
}
