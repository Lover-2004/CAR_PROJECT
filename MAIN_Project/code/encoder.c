#include "encoder.h"

#define ENCODER_DIR                	(TIM0_ENCOEDER)                         // ������������Ӧʹ�õı������ӿ� ����ʹ��QTIMER1��ENCOEDER1
#define ENCODER_DIR_DIR              	(IO_P35)            				 	// DIR ��Ӧ������
#define ENCODER_DIR_PULSE            	(TIM0_ENCOEDER_P34)            			// PULSE ��Ӧ������

uint32_t encoder_data=0;
float INS_V=0;	//���ڹߵ�

float low_pass=0.7;

void encoder_Init()
{
	encoder_dir_init(ENCODER_DIR, ENCODER_DIR_DIR, ENCODER_DIR_PULSE);   	
}


/******************
*���ܣ���ñ�����ֵ����ͨ�˲�
*������
*����ֵ��
******************/
void encoder_get(void)
{
    static uint8_t times=1;
    static float encoder_dr=0;
    // ��ˢ����������
    encoder_data = encoder_get_count(ENCODER_DIR);
    // ������ ��ͨ�˲�
    INS_V = INS_V * low_pass + encoder_data * (1 - low_pass);
    encoder_dr+=INS_V;
    if(times==5){
        encoder_data=(uint32_t)encoder_dr;
        encoder_dr=0;
        times=0;
    }
    // ������������� �����´βɼ�
    encoder_clear_count(ENCODER_DIR);
    times++;
}