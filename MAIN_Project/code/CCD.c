#include "CCD.h"
#include "isr.h"

uint16 i, j;

uint8 y1_boundary[128];
uint8 y2_boundary[128];
uint8 y3_boundary[128];

//-------------------------------------------------------------------------------------------------------------------
// �������     �δ�ͷ��ͺ���
// ����˵��     *buff           ��Ҫ���͵����ݵ�ַ
// ����˵��     length          ��Ҫ���͵ĳ���
// ���ز���     uint32          ʣ��δ�������ݳ���
// ʹ��ʾ��
//-------------------------------------------------------------------------------------------------------------------
uint32 seekfree_assistant_transfer   (const uint8 *buff, uint32 length)
{
	uart_write_buffer(DEBUG_UART_INDEX, buff, (uint16)length);
	return 0;
}

void CCD_Display(void)
{
	// ���ú���ָ��
	seekfree_assistant_transfer_callback = seekfree_assistant_transfer;
    seekfree_assistant_camera_information_config(SEEKFREE_ASSISTANT_MT9V03X, NULL, 128, 256);
    // ����һ������������ʾCCD����
    seekfree_assistant_camera_boundary_config(Y_BOUNDARY, 128, NULL, NULL ,NULL, y1_boundary, y2_boundary, y3_boundary);
    // ����3������ʾ����
    memset(y3_boundary, 0x80, sizeof(y3_boundary));
	
	if(tsl1401_finish_flag)
	{
		tsl1401_finish_flag = 0;
		
//		tsl1401_send_data(DEBUG_UART_INDEX, 0);
//		tsl1401_send_data(DEBUG_UART_INDEX, 1);
		
		for(j = 0; j < 128; j++)
		{
			// ��ȡCCD���ݣ������ֱ��ʽ���ѹ��
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
		// ����ͼ��
		seekfree_assistant_camera_send();
	}
}
