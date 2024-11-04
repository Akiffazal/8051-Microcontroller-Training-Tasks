#include <reg51.h>
#include "LCD.h"
#include "ADC.h"
#include "math.h"

sbit DIN =P3^4;
sbit CS  =P3^5;
sbit DCLK=P3^6;
sbit DOUT=P3^7;
sbit BP=P1^5;

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
	value= ADC_Driver(1,0,0);
	voltage= value *(5.0 /255.0);
	Delay1(1000);
	return voltage;
	
}
float ADC_Temperature ()
{
	unsigned int temp_value;
	float T, Temperature;
	temp_value = ADC_Driver(1,0,1);
	
	T =1/((1/298.15)+((1/3380.0) *log((255.0/temp_value)-1)));
	Temperature= T-273.15;
	lcd_showstring(0,10,"Temp: ");
	lcd_shownum(1,10,(unsigned int)Temperature,2);
	lcd_showchar(1,12,'.');
	lcd_shownum(1,13,(unsigned int)(Temperature *1000)%1000,3);
//	lcd_showchar(1,6,'C');
	Delay1(1000);
	return Temperature;
}	

float Set_temp()
{
	float Set_Temp,voltage1;
	voltage1=ADC_Voltage();
	Set_Temp=(40.0*voltage1)/5.0;
	lcd_showstring(0,0,"SetTemp ");
	lcd_shownum(1,0,Set_Temp,2);
	lcd_showchar(1,2,'.');
	lcd_shownum(1,3,(unsigned int)(Set_Temp* 1000) % 1000, 3);
	
	return Set_Temp;
}
void Beep ()
{
	unsigned char i;
	for(i=0; i<200; i++)
	{
		BP=0;
		Delay1(16);
		BP=1;
		Delay1(16);
	}
}















