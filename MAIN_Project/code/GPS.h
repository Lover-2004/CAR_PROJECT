#ifndef ___GPS_H_
#define ___GPS_H_

#include "zf_common_headfile.h"

double get_two_points_distance (double lat1, double lng1, double lat2, double lng2);   // ����ӵ�һ���㵽�ڶ�����ľ���(��λ��m)
double get_two_points_azimuth  (double lat1, double lon1, double lat2, double lon2);   // ����ӵ�һ���㵽�ڶ�����ķ�λ��(��λ����)
uint8  gps_data_parse          (void);                                                 // ����GPS����
void   gps_uart_callback       (uint8 uart_dat);                                       // GPS�ص�����
void   gps_init                (void);                                                 // GPS��ʼ��

void GPS_Display(void);

#endif
