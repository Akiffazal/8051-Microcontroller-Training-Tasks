#include <reg51.h>
#include "LCD.h"
#include "string.h"


void Delay2 (unsigned int );

sbit Input =P3^4;
unsigned int Pulses;



void Delay2 (unsigned int values)
{
	unsigned int i;
	for(i=0; i<values; i++)
	{
		TH1=0xFC;
		TL1=0x66;
		TF1=0;
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}
void main (void)
{
	lcd_init();
	Input=1;
	while(1)
	{
		TMOD=0x15;
		TH0=0x00;
		TL0=0x00;
		TR0=1;
		Delay2(1000);
		TR0=0;
		Pulses=(TH0*256)+TL0;
		
		if(TH0 == 0xFF && TL0 == 0xFF)
		{
		  lcd_command(0x01);
			lcd_showstring(0, 5, "ERROR");
		}
		else
		{
			lcd_command(0x01);
			lcd_showstring(0,0 ,"FreQuency countr");
			lcd_showstring(1,1,"FreQ:");
			lcd_shownum(1,6,Pulses,5);
			lcd_showstring(1,12,"HZ");
		}
	}
}








