#include <reg51.h>
#include "TEMP.h"
#include "LCD.h"
#include "7SD.h"


//sbit A= P2^2;
//sbit D= P2^3;
//sbit C= P2^4;

unsigned int index=0;
sbit buzzer_pin=P1^5;

void timer0_interupt (void) interrupt 1   //50 ms
{
  index+=1;
  if(index==400)
	{
		lcd_command (0x80);
		lcd_string("TEMPERATURE IS:");
		
		lcd_command (0xC0);
		read_temperature();
		hex2lcd(temp_c);
		lcd_string("c");
		index=0;
	}		
	display_num7_seg(temp_c);
	values_on_ssd();
	
	if(temp_c>=32)
	{
		buzzer_pin=0;
		delay(2);
		buzzer_pin=1;
		delay(2);
	}
	buzzer_pin=1;
	TH0=0xFC;
	TL0=0x18;
}
	
	
void main ()
{ 	
//	A=1; D=1; C=1;
//	P0=0xFF;
//	A=1; D=1; C=0;
//	P0=0x79;
	
	lcd_init();

	IE=0x82;
	//EA=1;
	//ET0=1;
	
	TMOD=0x21;
	SCON=0x50;                     
	TH1=0xFD;   // 9600
	TH0=0xFC;
	TL0=0x18;
	TR0=1;
	TR1=1;
	while(1)
	{
		
	 temp_serialdata_pc ();
   // display_num_serial(temp_c);
    //serial_data();
	}
}



