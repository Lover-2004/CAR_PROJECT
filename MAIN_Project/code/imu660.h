#ifndef __IMU660_H
#define __IMU660_H

#include "sys.h"

void get_yaw_data(float* gyro_z);
void get_drift();
extern float gyro_x,gyro_y,gyro_z;
extern float PITCH,ROLL,YAW;
extern float zero_drift_pitch,zero_drift_roll,zero_drift_yaw;

#endif 