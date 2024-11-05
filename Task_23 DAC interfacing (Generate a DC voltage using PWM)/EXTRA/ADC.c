#include <reg51.h>
#include "LCD.h"
#include "ADC.h"


sbit DIN =P3^4;
sbit CS  =P3^5;
sbit DCLK=P3^6;
sbit DOUT=P3^7;

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
void DAC_Voltage ()
{
	float voltage; 
		float value;
	value = ADC_Driver(0,1,1);
		Delay1(500);
	voltage =value*(5.0/255.0);
	lcd_showstring(1,0,"Voltage:");
	lcd_shownum(1,10,voltage,1);
	lcd_showchar(1,11,'.');
	lcd_shownum(1,12,(unsigned int)(voltage*1000)%1000,3);
	lcd_showchar(1,15,'V');
	Delay1(1000);
}	


















