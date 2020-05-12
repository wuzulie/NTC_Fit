/*************************************
 * �ļ���  ��main.c
 * ����    ������1(USART1)����Եĳ����ն���1sΪ�����ӡ��ǰADC1��ת����ѹֵ         
 * ʵ��ƽ̨��MINI STM32������ ����STM32F103C8T6
 * ��汾  ��ST3.0.0

**********************************************************************************/

#include "stm32f10x.h"
#include "usart1.h"
#include "adc.h" 
#include "nihe.h" 

extern __IO u16 ADC_ConvertedValue[2];

#define	AD_VALUE_AVERAGE_TIMES 1000

// �����ʱ
void Delay(unsigned long time)
{unsigned long i,j;
  
	for(j=0; j<time; j++)
	{
	   for(i=0;i<12000;i++);
	}
}



void delay_us(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=10;  
      while(i--) ;    
   }
}

void USART_puts(uint8_t *s,uint8_t len)
{
    int i;
    for(i=0; i<len; i++)
    {
        putchar(s[i]);
    }
}

void pagTemDataAndSend(u8 ID , double Tem)
{
	u8 temPag[]={0xAA , 0x55 , 0x00 , 0xDD , 0x00 , 0x08 , 0x00 , 0x00 , 0x00 , 0x00 , 0x56 , 0x78 , 0x9A , 0xBC , 0xDE , 0xF0 , 0x00 , 0x00 , 0x0D , 0x0A};
		
	temPag[3] = 0xD0 + ID;
	*(short *)(&temPag[8]) = (short)(Tem*100);
	USART_puts(temPag,sizeof(temPag));

	//printf("tem=%d\n",*(short *)(&temPag[8]));
}


int main(void)
{ 
	double AD_value_PA0 ,AD_value_PA1;	
	double	Temple0=0,Temple1=0;
	u16 GetDataTimes = 0;
	u32 ADValueSum0 = 0, ADValueSum1 = 0;
	
	u32 n = 0;
	
	/* ����ϵͳʱ��Ϊ72M */      
	SystemInit();	
	/* ���ô��� */
	USART1_Config();
	/* ��ʼ��ADC1 */
	ADC1_Init();
	
	
	/*
	//��Ϻ�ʱ����
	AD_value_PA0 = 1453.38;
	while(1)
	{
		n = 100;	//��ϴ���
		while(n--)
		{
			nihe(AD_value_PA0, &Temple0);	//F103: �ܺ�ʱ771ms��Լ7.71msһ��	F405: �ܺ�ʱ346ms��Լ3.46msһ��
		}
		printf("once\n");
	}
	*/

	while (1)
	{
		Delay(500);
		ADValueSum0 = 0;
		ADValueSum1 = 0;
		for(GetDataTimes=0;GetDataTimes<AD_VALUE_AVERAGE_TIMES;GetDataTimes++)
		{
			ADValueSum0+=ADC_ConvertedValue[0];
			ADValueSum1+=ADC_ConvertedValue[1];
			delay_us(10);
		}
		
		AD_value_PA0  = (double)3300000/4096*(ADValueSum0/AD_VALUE_AVERAGE_TIMES)/1000;
		AD_value_PA1  = (double)3300000/4096*(ADValueSum1/AD_VALUE_AVERAGE_TIMES)/1000;

		//printf("tem_table[0]=%d\n",tem_table[0]);
		
		//AD_value_PA0 = 1453.38;		//20��
		//AD_value_PA1 = 2190.12;		//40��
		
		printf("\nPA0 voltage = %.2lf mV  \r\n", AD_value_PA0);
		printf("PA1 voltage = %.2lf mV  \r\n", AD_value_PA1);
		
		nihe(AD_value_PA0, &Temple0);
		nihe(AD_value_PA1, &Temple1);
		
		//nihe((u32)AD_value_PA0,&Temple);
		//Temple0 = 10.01;
		//Temple1 = 20.02;
		//pagTemDataAndSend(0,Temple0);
		//pagTemDataAndSend(1,Temple1);
		
		printf("\nTem0 = %.2lf C\r\n", Temple0);
		printf("Tem1 = %.2lf C\r\n", Temple1);
	}
}



