/*********************************************************************************************************************
* AI8051U Opensourec Library ����AI8051U ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ���STC ��Դ���һ����
*
* AI8051U ��Դ�� ��������
* �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
* �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MDK FOR C251
* ����ƽ̨          AI8051U
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����           ��ע
* 2024-08-01        ��W            first version
********************************************************************************************************************/

#include "sys.h"

// **************************** �������� ****************************
//void pit_handler (void);

void sensor_dispaly();
	
void main()
{
	clock_init(SYSTEM_CLOCK_40M);
	debug_init();

    /*�����ʼ��*/
	All_Init();
//	Motor_BottomLoad(600);
//	get_drift();
    while(1)
    {
//		encoder_get();
//		imu660ra_get_acc();                 // ��ȡICM20602�ļ��ٶȲ�����ֵ
//		imu660ra_get_gyro();                // ��ȡIMU660RA�Ľ��ٶȲ�����ֵ
//		get_yaw_data(&gyro_z);
		sensor_dispaly();
//		Menu_display();
//		GPS_Display();
//		CCD_Display();
    }
}

void sensor_dispaly()
{
	ips200_show_string(0, 0*16, "gyro_z1:");
	ips200_show_float(120, 0*16,(float)imu660ra_gyro_z,5,1);
	ips200_show_string(0, 1*16, "gyro_z2:");
	ips200_show_float(120, 1*16,gyro_z,5,1);
	ips200_show_string(0, 3*16, "encoder:");
	ips200_show_float(120, 3*16,(float)encoder_data,5,1);
	ips200_show_string(0, 4*16, "YAW:");
	ips200_show_float(120, 4*16,(float)YAW,8,3);
	
	system_delay_ms(100);
}
