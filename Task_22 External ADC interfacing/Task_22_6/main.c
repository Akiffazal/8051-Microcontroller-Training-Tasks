#include <reg51.h>
#include "LCD.h"
#include "ADC.h"

void main()
{
	float SET_TEMP,Temperature1;
	lcd_init();
	
	
	while(1)
	{
		SET_TEMP=Set_temp();
		Delay1(1000);
		Temperature1=ADC_Temperature();
		Delay1(1000);
		
		if(Temperature1>SET_TEMP)
		{
			Beep();
		}
		
	}
}