/*
function:LED��˸�����Ϊ15ms)
STC89C52��LED��com��Ϊ�������͵�ƽ������
algorithm:LED1�ĳ�ʼ״̬�ǵ����ģ����°���1��ʼ��˸��������������
*/
#include <reg52.h>
sbit led1=P1^0;
unsigned int count;

void main(void)
{
	TMOD&=0xfc;
	TMOD|=0x01;
	
	TH0=0xb1;
	TL0=0xe0;
	
	TR0=1;

	while(1)
	{
		if(TF0==1)
		{
			TF0=0;
			TH0=0xb1;
			TL0=0xe0;
			count++;
			if(count>=50)
			{
				count=0;
				led1=~led1;
			}
		}
	}
}
