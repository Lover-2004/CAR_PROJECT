#include "menu.h"

int8_t Choice=0;

// **************************** 一级菜单 ****************************

void Menu_display()
{
    Choice = 0;

    while(!gpio_get_level(SWITCH1))	//拨码开关
    {
//   	control_state=0;

		ips200_show_string(0, 0*16, "Trace_Debug");
		ips200_show_string(0, 1*16, "Image_set_brightness");
		ips200_show_string(0, 2*16, "Image_menu");
		ips200_show_string(0, 3*16, "flash_erase");
		ips200_show_string(0, 4*16, "Fly_PID_display");
		ips200_show_string(0, 5*16, "Drive_PID_display");
		ips200_show_string(0, 6*16, "PWM_display");
		ips200_show_string(0, 7*16, "EXTI");
		
		ips200_show_string(200, Choice*16, "<>");
		
		if(rocker_read()||Rocker_state!=Rocker_MEDIUM)
		{
			if(Rocker_state == Rocker_UP)
			{
				ips200_myclear(200, Choice*16,2);
				Choice = (Choice-1)%7;
				Choice = Choice<0?Choice+7:Choice;
			}
			else if(Rocker_state == Rocker_DOWN)
			{
				ips200_myclear(200, Choice*16,2);
				Choice = (Choice+1)%7;
			}
			
			ips200_show_string(200, Choice*16, "<>");
				
			//确定进入二级菜单
			if(Rocker_state == Rocker_RIGHT)
			{
				ips200_clear(RGB565_WHITE);
//				switch(Choice)
//				{
//					case 0 :  Trace_Debug();
//					break;
//					case 1 :  Image_set_brightness();
//					break;
//					case 2 :  Image_menu(&target_color_condi);
//					break;
//					case 3 :  flash_erase();
//					break;
//					case 4 :  Fly_PID_display();
//					break;
//					case 5 :  Drive_PID_display();
//					break;
//					case 6 :  PWM_display();
//					break;
//					default :
//					break;
//				}
			}
				
			ips200_show_float(0, 8*16,(float)Choice,3,1);
			ips200_show_float(0, 9*16,Rocker_state,3,1);
			system_delay_ms(100);
		}
//      if(!gpio_get_level(ROCKER_KEY))//此处为读取摇杆确定键
		system_delay_ms(150);
     }
}
