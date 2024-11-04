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
	
float ADC_Temperature ()
{
	unsigned int temp_value;
	float T, Temperature;
	temp_value = ADC_Driver(1,0,1);
	
	T =1/((1/298.15)+((1/3380.0) *log((255.0/temp_value)-1)));
	Temperature= T-273.15;
	lcd_showstring(0,0,"T: ");
	lcd_shownum(0,2,(unsigned int)Temperature,2);
	lcd_showchar(0,4,'.');
	lcd_shownum(0,5,(unsigned int)(Temperature *1000)%1000,3);
//	lcd_showchar(1,6,'C');
	Delay1(1000);
	return Temperature; 
}	

unsigned int LDR ()
{
	unsigned int value, scaledvalue;
  value =	ADC_Driver(0,1,0);
	scaledvalue =(value*100)/255;
	
	lcd_showstring(0,9,"LDR: ");
	lcd_shownum(0,13,scaledvalue,3);
	Delay1(1000);
	return scaledvalue;
}

void AC_Controller()
{
	float LDR_value;
	unsigned int Temperature_value;
	LDR_value=LDR ();
	Temperature_value=ADC_Temperature ();
	if(LDR_value>30)
	{
		if(Temperature_value<26)
		{
			lcd_clear_secondline();
			lcd_showstring(1,0, "Control: AC OFF");
			Delay1(10000);
		}
		else if(Temperature_value>29)
		{
			lcd_clear_secondline();
			lcd_showstring(1,0,"Control:AC ON");
			Delay1(10000);
		}
	}
	else
	{
		lcd_clear_secondline();
		lcd_showstring(1,0,"NightTime AC OFF");
		Delay1(10000);
	}
}














