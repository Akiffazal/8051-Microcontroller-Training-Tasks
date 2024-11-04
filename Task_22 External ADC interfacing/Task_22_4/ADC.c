#include <reg51.h>
#include "LCD.h"
#include "ADC.h"
#include "math.h"

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
void ADC_Voltage ()
{
	float voltage ,value;
	value = ADC_Driver(1,0,0);
	
	voltage =value*(5.0/255.0);
	lcd_showstring(0,0,"Vol: ");
	lcd_shownum(1,0,(unsigned int)voltage,1);
	lcd_showchar(1,1,'.');
	lcd_shownum(1,2,(unsigned int)(voltage*1000)%1000,3);
//	lcd_showchar(1,6,'V');
	Delay1(1000);
}	
void ADC_Temperature ()
{
	unsigned int temp_value;
	float T, Temperature;
	temp_value = ADC_Driver(1,0,1);
	
	T =1/((1/298.15)+((1/3380.0) *log((255.0/temp_value)-1)));
	Temperature= T-273.15;
	lcd_showstring(0,6,"Temp: ");
	lcd_shownum(1,6,(unsigned int)Temperature,2);
	lcd_showchar(1,8,'.');
	lcd_shownum(1,9,(unsigned int)(Temperature *1000)%1000,3);
//	lcd_showchar(1,6,'C');
	Delay1(1000);
}	

void LDR ()
{
	unsigned int value, scaledvalue;
  value =	ADC_Driver(0,1,0);
	scaledvalue =(value*100)/255;
	
	lcd_showstring(0,13,"LDR ");
	lcd_shownum(1,13,scaledvalue,3);
	Delay1(1000);
}
















