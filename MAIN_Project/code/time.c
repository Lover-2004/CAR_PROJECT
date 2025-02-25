#include "time.h"

void pit_handler (void);
Timer1_Flag TFlag1;

void timer_Init()
{
	// ���ö�ʱ��1�жϻص�����
	tim1_irq_handler = pit_handler;
	pit_ms_init(PIT_CH, 10);		// ��ʼ�� PIT Ϊ�����ж� 2ms ����

}

/******************
*���ܣ���ʱ���ж���ں�����Ҫ�Ƚ���ʱ���жϺ���ָ��ָ����,�������������һ��
*������
*����ֵ��
******************/
void pit_handler (void)
{	
	static uint32_t time_sum=0;
	time_sum+=10;
	if(time_sum%2==0)TFlag1.T_2ms=1;
	if(time_sum%4==0)TFlag1.T_4ms=1;
	if(time_sum%6==0)TFlag1.T_6ms=1;
	if(time_sum%10==0)TFlag1.T_10ms=1;
	if(time_sum%20==0)TFlag1.T_20ms=1;
	if(time_sum%50==0)TFlag1.T_50ms=1;
	
	time_sum=time_sum>=0xfffffff0?(time_sum&0x00000111):time_sum;	//������
	Interrupt_Solution();
}
/******************
*���ܣ���ʱ���жϴ�����
*������
*����ֵ��
******************/
void Interrupt_Solution()
{
	if(TFlag1.T_10ms)	//10ms�ж�
	{
		get_yaw_data(&gyro_z);
		encoder_get();
//		tsl1401_collect_pit_handler();
		TFlag1.T_10ms=0;
	}
}
