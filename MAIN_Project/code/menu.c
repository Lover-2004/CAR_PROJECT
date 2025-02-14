#include "sys.h"

uint8 flag=1;

// **************************** 一级菜单 ****************************
int menu1(void)
{
	ips200_clear(RGB565_WHITE);					//清屏
	ips200_show_string(0,0,"*");
	ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
	ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
	ips200_show_string(8,32,"PID");
	ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
	ips200_show_string(8,48,"GPS");
	ips200_show_string(8,64,"ICM20602");
	
	while(1)
	{
		rocker_read();
		
		if(Rocker_state == Rocker_DOWN)
		{
			flag--;
			if(flag==0)flag=5;
		}
		if(Rocker_state == Rocker_UP)
		{
			flag++;
			if(flag==6)flag=1;
		}
		if(Rocker_state == Rocker_MEDIUM)
		{
			ips200_clear(RGB565_WHITE);					//清屏
			return flag;
		}
		
		switch(flag)
		{
			case 1:
			{
				ips200_show_string(0,0,"*");
				ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
				ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
				ips200_show_string(8,32,"PID");
				ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
				ips200_show_string(8,48,"GPS");
				ips200_show_string(8,64,"ICM20602");
				break ;
			}
			case 2:
			{
				ips200_show_string(0,16,"*");
				ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
				ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
				ips200_show_string(8,32,"PID");
				ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
				ips200_show_string(8,48,"GPS");
				ips200_show_string(8,64,"ICM20602");
				break ;
			}
			case 3:
			{
				ips200_show_string(0,32,"*");
				ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
				ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
				ips200_show_string(8,32,"PID");
				ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
				ips200_show_string(8,48,"GPS");
				ips200_show_string(8,64,"ICM20602");
				break ;
			}
			case 4:
			{
				ips200_show_string(0,48,"*");
				ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
				ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
				ips200_show_string(8,32,"PID");
				ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
				ips200_show_string(8,48,"GPS");
				ips200_show_string(8,64,"ICM20602");
				break ;
			}
			case 5:
			{
				ips200_show_string(0,64,"*");
				ips200_show_chinese(8, 0,16,"浮力",2,RGB565_BLACK);
				ips200_show_chinese(8,16,16,"动力",2,RGB565_BLACK);
				ips200_show_string(8,32,"PID");
				ips200_show_chinese(32,32,16,"参数",2,RGB565_BLACK);
				ips200_show_string(8,48,"GPS");
				ips200_show_string(8,64,"ICM20602");
				break ;
			}
		}
	}
}

