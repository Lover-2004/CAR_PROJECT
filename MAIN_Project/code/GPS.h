#ifndef ___GPS_H_
#define ___GPS_H_

#include "zf_common_headfile.h"

double get_two_points_distance (double lat1, double lng1, double lat2, double lng2);   // 计算从第一个点到第二个点的距离(单位：m)
double get_two_points_azimuth  (double lat1, double lon1, double lat2, double lon2);   // 计算从第一个点到第二个点的方位角(单位：°)
uint8  gps_data_parse          (void);                                                 // 解析GPS数据
void   gps_uart_callback       (uint8 uart_dat);                                       // GPS回调函数
void   gps_init                (void);                                                 // GPS初始化

void GPS_Display(void);

#endif
