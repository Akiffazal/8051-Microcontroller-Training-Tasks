#include <reg52.h>

sbit led_1 = P2^0;
sbit led_2 = P2^1;
sbit led_3 = P2^2;

unsigned int cntr_10ms =0;
unsigned int cntr_100ms = 0; 
unsigned int cntr_1000ms = 0;

void Timer_0() interrupt 1 {
	
	cntr_10ms++;
	
	if(cntr_10ms==401)
		{
			led_1=~led_1;
		  cntr_100ms++;
			cntr_10ms=0;
		
					if(cntr_100ms==10)
						{
							led_2=~led_2;
							cntr_1000ms++;
							cntr_100ms=0;
						

									if(cntr_1000ms==10)
										{
											led_3=~led_3;
											cntr_1000ms=0;
										}									
						}				
	  }			
												
}


void main() {

  IE = 0x82;           // Enable Timer 0 interrupt
  TMOD = 0x02;         // Set Timer 0 mode to 8-bit auto reload
  TH0 = -23;           // Set initial value for Timer 0 high byte
  TR0=1;
	while(1)
	{
	}
}


