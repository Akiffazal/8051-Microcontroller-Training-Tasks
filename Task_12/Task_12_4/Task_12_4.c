#include <reg52.h>

sbit SEG_PORT_1 = P2^2;
sbit SEG_PORT_2 = P2^3;
sbit SEG_PORT_3 = P2^4;

unsigned int count = 0; // Corrected the colon to a semicolon

void Tmr0_int() interrupt 1 {
    count++;
    if (count == 36) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 0;
    } 
	 if (count == 72) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 0;
    } 
	 if (count == 108) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 0;
    } 
	 if (count == 144) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 0;
    } 
	 if (count == 180) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 1;
    } 
	 if (count == 216) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 0;
        SEG_PORT_3 = 1;
    } 
	 if (count == 252) {
        SEG_PORT_1 = 0;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 1;
    } 
	 if (count == 288) {
        SEG_PORT_1 = 1;
        SEG_PORT_2 = 1;
        SEG_PORT_3 = 1;

        count = 0;
    }
}

void main() {
    IE = 0x82;
    TMOD = 0x02;
    TH0 = 0x00;
    TR0 = 1;

		while(1){
		
		}
}

