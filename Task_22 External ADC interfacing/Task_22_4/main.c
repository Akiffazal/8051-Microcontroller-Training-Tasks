#include <reg51.h>
#include "LCD.h"
#include "ADC.h"

void main()
{
	lcd_init();
	while(1)
	{
		ADC_Voltage ();
		Delay1(1000);
		
		ADC_Temperature();
		Delay1(1000);
		
		LDR ();
		Delay1(1000);
	}
}