#include <reg52.h>
#define bitSelect P2
#define segSelect P0
/*
function:������
STC89C52�������������·��������ΪPNP�ͣ��͵�ƽ��ͨ�������Ϊ�������ӷ����͵�ƽ
��ͨ��
algorithm:�������λ��ʼ������Ϊ1��
*/
unsigned char segcode[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; 
unsigned char bitcode[]={0xfe,0xfd,0xfb,0xf7};
unsigned int i;
unsigned int count;
unsigned int k;
unsigned char buffer[4];

void delayMS(unsigned int n);
void buf(void);
void display(void);

void buf(void)
{
	buffer[0]=count/1000;
	buffer[1]=count/100%10;
	buffer[2]=count/10%10;
	buffer[3]=count%10;
}

void display(void)
{	
	for(i=0;i<=3;i++)
	{	
		segSelect=segcode[buffer[i]];
		bitSelect=bitcode[i];
		delayMS(2);
	}	
}

void main(void)
{
	count=0;
	if(count<=9999)
	{
		while(1)
		{
		 buf();
		 display();
		 delayMS(1000);
		 count+=1;
		}
	}
	else
	{
		count=0;
	}		
}

void delayMS(unsigned int n)
{
	unsigned char j;
	while(n--)
	{
  		for(j=0;j<113;j++);
	}
}