#include <reg51.h>
sbit motor_pin= P2^0;

unsigned int x=0;

void timer0 (void) interrupt 1
	{
		x++;
		if(x==45)
		{		
			motor_pin=0;		
		}
		else if(x==400)
			{
				motor_pin=1;
				x=0;
			}	
	}

void main()
	{
		TMOD=0x02;
		TH0=0xD1;
		EA=1;
		ET0=1;
		TR0=1;
		motor_pin=0;
		while(1)
		{	 
			
		}
	}
