#include <reg51.h>

sbit LED = P2^0;      // Define LED pin
sbit K1 = P3^1;       // Define button K1 pin

unsigned char k1_btn_state = 0;
unsigned char k1_press_cntr = 0;
unsigned char k1_release_cntr = 0;

void timer0_isr(void) interrupt 1 {
   if (k1_btn_state == 0) {
       if (K1 == 0) {
           k1_press_cntr++;
           if (k1_press_cntr == 10) {  // Button pressed for 100ms
               LED = ~LED;              // Toggle LED
               k1_btn_state = 1;        // Change state to detect release
           }
       } 
			 
			 else {
           k1_press_cntr = 0;
       }
			 
   } else 
		{
				 if (K1 == 1) {
						 k1_release_cntr++;
						 if (k1_release_cntr == 10) {  // Button released for 100ms
								 k1_btn_state = 0;         // Ready for next press
						 }
				 } else {
						 k1_release_cntr = 0;
				 }
		 }
}

void main() {
   TMOD = 0x01;         // Timer0 in mode 1 (16-bit)
   IE = 0x82;           // Enable Timer0 interrupt
	 TH0 = 0xDC;         // Load timer for 10ms interrupt
   TL0 = 0x00;
   TR0 = 1;             // Start Timer0

   while (1) {
       // Main loop can do other tasks here
   }
}


