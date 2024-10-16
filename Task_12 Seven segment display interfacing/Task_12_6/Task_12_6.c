#include <reg51.h>  

sbit SEG_PORT_1 = P2^2;  
sbit SEG_PORT_2 = P2^3;
sbit SEG_PORT_3 = P2^4;

void T0M1Delay(void);

void main() {
		
		while (1) 
			{
				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x3F;
				T0M1Delay();
			
				SEG_PORT_1 = 0;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x06;
				T0M1Delay();
				
				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x5B;
				T0M1Delay();
			
				SEG_PORT_1 = 0;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x4F;
				T0M1Delay();

				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x66;
				T0M1Delay();
			
				SEG_PORT_1 = 0;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x6D;
				T0M1Delay();

				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x7D;
				T0M1Delay();
			
				SEG_PORT_1 = 0;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x07;
				T0M1Delay();
				
				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x7F;
				T0M1Delay();

				SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x6F;
				T0M1Delay();
			}
	
}



void T0M1Delay(void)
	{
		unsigned int  x;
		for(x=0;x<10;x++)
			{
				TMOD=0x01;
				TL0=0xFD;
				TH0=0x4B;
				TR0=1;
				while (TF0==0);
				TR0=0;
				TF0=0;
			}
}


