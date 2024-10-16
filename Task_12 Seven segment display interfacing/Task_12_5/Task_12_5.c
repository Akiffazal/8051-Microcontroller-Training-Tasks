#include <reg51.h>

sbit led = P2^0;

sbit SEG_PORT_1 = P2^2;
sbit SEG_PORT_2 = P2^3;
sbit SEG_PORT_3 = P2^4;

unsigned int count = 0;

void timer0_ISR(void) interrupt 1
{
	TH0 = 0xDB;
	TL0 = 0xFF;
//	LED = ~LED;

count++;
    if (count == 1) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 0;
			  
			  led = ~led;
    } 
	 if (count == 2) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 0;
    } 
	 if (count == 3) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 0;
    } 
	 if (count == 4) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 0;
    } 
	 if (count == 5) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 1;
    } 
	 if (count == 6) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 1;
    } 
	 if (count == 7) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 1;
    } 
	 if (count == 8) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 1;

        count = 0;
    }
}

void main()
{
	IE = 0x82;
	TMOD = 0x01;
	TH0 = 0xDB;
	TL0 = 0xFF;
	TR0 = 1;

	while (1){
	};

}