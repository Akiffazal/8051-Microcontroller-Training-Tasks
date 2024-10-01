#include <reg52.h>

sbit led_1 = P2^0;
unsigned int x=0;

void Timer_0() interrupt 1 {
	x++;
	if(x==401)
		{
			led_1 = ~led_1;      // Toggle LED
			x=0;
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






//#include <reg52.h>

//sbit led_1 = P2^0;

//void Timer_0() interrupt 1 {
//	unsigned char x,y;
//	
//	for (x=0;x<82;x++)
//		for (y=0;y<36;y++);
//	
//	led_1 = ~led_1;      // Toggle LED
//}

//void main() {
//  IE = 0x82;           // Enable Timer 0 interrupt
//  TMOD = 0x02;         // Set Timer 0 mode to 8-bit auto reload
//  TH0 = -23;           // Set initial value for Timer 0 high byte
//  TR0=1;
//}
