#ifndef SYS_H
#define SYS_H

#include "zf_common_headfile.h"
#include "zf_common_typedef.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

/*Õ‚…Ëƒ£øÈ*/
#include "rocker.h"
#include "imu.h"
#include "uart.h"
#include "GPS.h"
#include "imu660.h"
#include "motor.h"
#include "CCD.h"
#include "menu.h"
#include "control.h"
#include "time.h"
#include "encoder.h"
#include "valuepack.h"


void All_Init(void);

#define USER_DEBUG
#ifdef USER_DEBUG
	#define printf2(format, ...) printf( format "\r\n", ##__VA_ARGS__)
	#define info(format, ...) printf("[ user ]info:" format "\r\n", ##__VA_ARGS__)
	#define debug(format, ...) printf("[ user ]debug:" format "\r\n", ##__VA_ARGS__)
	#define error(format, ...) printf("[ user ]error:" format "\r\n",##__VA_ARGS__)
	#else
	#define user_printf(format, ...)
	#define user_info(format, ...)
	#define user_debug(format, ...)
	#define user_error(format, ...)
#endif

#endif 
