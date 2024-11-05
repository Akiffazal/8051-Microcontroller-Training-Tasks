
# include <reg52.h>
# include "LCD.h"
# include "KeyController.h"
# include "ADC.h"



extern unsigned int DutyCycle_Limit;
float voltage, value;

void main (void)
{
  LCD_Intialization();               
	Timer0_Intilization ();               
	DutyCycle_Limit = 0.00;
	LCD_ShowNum(1,10,DutyCycle_Limit,3);
	Set_cursor(1,0);
	String_data("DutyCycle:");
	
	while(1)
    { 
		  External_Keys();              
			Delay(1000);
   
			DAC_VOLTAGE ();                 
			Delay(1000);
		   	
		}
}
