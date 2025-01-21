#include "CCD.h"
#include "isr.h"

uint16 i, j;

uint8 y1_boundary[128];
uint8 y2_boundary[128];
uint8 y3_boundary[128];

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     滴答客发送函数
// 参数说明     *buff           需要发送的数据地址
// 参数说明     length          需要发送的长度
// 返回参数     uint32          剩余未发送数据长度
// 使用示例
//-------------------------------------------------------------------------------------------------------------------
uint32 seekfree_assistant_transfer   (const uint8 *buff, uint32 length)
{
	uart_write_buffer(DEBUG_UART_INDEX, buff, (uint16)length);
	return 0;
}

void CCD_Display(void)
{
	// 设置函数指针
	seekfree_assistant_transfer_callback = seekfree_assistant_transfer;
    seekfree_assistant_camera_information_config(SEEKFREE_ASSISTANT_MT9V03X, NULL, 128, 256);
    // 设置一个边线用于显示CCD波形
    seekfree_assistant_camera_boundary_config(Y_BOUNDARY, 128, NULL, NULL ,NULL, y1_boundary, y2_boundary, y3_boundary);
    // 边线3用于显示中线
    memset(y3_boundary, 0x80, sizeof(y3_boundary));
	
	if(tsl1401_finish_flag)
	{
		tsl1401_finish_flag = 0;
		
//		tsl1401_send_data(DEBUG_UART_INDEX, 0);
//		tsl1401_send_data(DEBUG_UART_INDEX, 1);
		
		for(j = 0; j < 128; j++)
		{
			// 获取CCD数据，并按分辨率进行压缩
			switch(TSL1401_AD_RESOLUTION)
			{
				case ADC_8BIT:
				{
					y1_boundary[j] = (uint8)(128 - tsl1401_data[0][j] / 2);
					y2_boundary[j] = (uint8)(256 - tsl1401_data[1][j] / 2);
					break;
				}
				case ADC_10BIT:
				{
					y1_boundary[j] = (uint8)(128 - tsl1401_data[0][j] / 8);
					y2_boundary[j] = (uint8)(256 - tsl1401_data[1][j] / 8);
					break;
				}
				case ADC_12BIT:
				{
					y1_boundary[j] = (uint8)(128 - tsl1401_data[0][j] / 32);
					y2_boundary[j] = (uint8)(256 - tsl1401_data[1][j] / 32);
					break;
				}
			}
		}
		// 发送图像
		seekfree_assistant_camera_send();
	}
}
