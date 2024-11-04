#include <reg51.h>
#include "LCD.h"
#include "ADC.h"
#include "math.h"

sbit DIN =P3^4;
sbit CS  =P3^5;
sbit DCLK=P3^6;
sbit DOUT=P3^7;
sbit LED =P2^0;
unsigned char ADC_Driver (bit A0, bit A1, bit A2)
{
	unsigned char i, temp=0;
	DCLK=0;
	CS=0;
	
	DCLK=0;    DIN=1;    	DCLK=1; 
	DCLK=0;    DIN=A2;     DCLK=1;
	DCLK=0;    DIN=A1;     DCLK=1;
	DCLK=0;    DIN=A0;     DCLK=1;
	DCLK=0;    DIN=1;     DCLK=1; 
	DCLK=0;    DIN=1;     DCLK=1;
	DCLK=0;    DIN=1;     DCLK=1;
	DCLK=0;    DIN=1;     DCLK=1;
	
	DCLK = 0;
	Delay1(10);
	
	
	for(i=0; i<=7; i++)
	{
		temp<<=1;
		DCLK=1;
		DCLK=0;
		
		
		temp|=DOUT;
		

	}
	CS=1;
	return temp;
}
float ADC_Voltage ()
{
	unsigned int value;
	float voltage;
	value = ADC_Driver(1,0,0);
	
	voltage =value*(5.0/255.0);
	lcd_showstring(0,0,"V:");
	lcd_shownum(0,3,(unsigned int)voltage,1);
	lcd_showchar(0,4,'.');
	lcd_shownum(0,5,(unsigned int)(voltage*1000)%1000,3);
//	lcd_showchar(1,6,'V');
	Delay1(1000);
	return voltage;
}	

unsigned int LDR ()
{
	unsigned int value, scaledvalue;
  value =	ADC_Driver(0,1,0);
	scaledvalue =(value*100)/255;
	
	lcd_showstring(0,9,"LDR");
	lcd_shownum(0,13,scaledvalue,3);
	Delay1(1000);
	return scaledvalue;
}
void contactor ()
{
	float  voltage_value;
	unsigned int LDR_value;
	
	voltage_value=ADC_Voltage();
	Delay1(1000);
	LDR_value = LDR();
	Delay1(1000);
	if(LDR_value<30)
	{
		if(voltage_value>=4)
		{
			lcd_clear_secondline();
			lcd_showstring(1,0,"WAPDA SUPPLY ON");
			LED=1;
			Delay1(1000);
		}
		else
		{
			lcd_clear_secondline();
			lcd_showstring(1,0,"REMOVEHEAVY LOAD");
			LED=0;
			Delay1(1000);
		}
	}
	else
	{
		lcd_clear_secondline();
		lcd_showstring(1,0,"Enjoy Day solar");
		Delay1(1000);
	}
}















