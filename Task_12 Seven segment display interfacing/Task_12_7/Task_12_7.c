#include <reg51.h>  

sbit SEG_PORT_1 = P2^2;  
sbit SEG_PORT_2 = P2^3;
sbit SEG_PORT_3 = P2^4;

void T0M1Delay(void);

void main() {
    
    while (1) 
			{
				        
				SEG_PORT_1 = 1;  
				SEG_PORT_2 = 1;
				SEG_PORT_3 = 1;
				P0 = 0x06;
				T0M1Delay();

			  SEG_PORT_1 = 0; 
				SEG_PORT_2 = 1;
				SEG_PORT_3 = 1;
				P0 = 0x5B;
				T0M1Delay();
				
        SEG_PORT_1 = 1;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 1;
				P0 = 0x4F;
			  T0M1Delay();
				
			  SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 1;
				P0 = 0x66;
				T0M1Delay();

        SEG_PORT_1 = 1;  
				SEG_PORT_2 = 1;
				SEG_PORT_3 = 0;
				P0 = 0x6D;
				T0M1Delay();

			  SEG_PORT_1 = 0; 
				SEG_PORT_2 = 1;
				SEG_PORT_3 = 0;
				P0 = 0x7D;
				T0M1Delay();
				
        		SEG_PORT_1 = 1;  
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x07;
				T0M1Delay();
				
				
			  SEG_PORT_1 = 0; 
				SEG_PORT_2 = 0;
				SEG_PORT_3 = 0;
				P0 = 0x7F;
				T0M1Delay();			
		
			} 
}



void T0M1Delay(void)
	{ unsigned int x;
		for(x=0; x<100; x++)
		{
			TMOD=0x02;
			TL0=0xFF;
	//	TH0=0x
			TR0=1;
		}
	}













////// For writing a desired character


////#include <reg51.h>

////sbit a = P0^0;
////sbit b = P0^1;
////sbit c = P0^2;
////sbit d = P0^3;
////sbit e = P0^4;
////sbit f = P0^5;
////sbit g = P0^6;
////sbit h = P0^7;

////sbit SEG_PORT_1 = P2^2;  
////sbit SEG_PORT_2 = P2^3;
////sbit SEG_PORT_3 = P2^4;

////void T0M1Delay(void);

////void main() {
////    
////    while (1) 
////			{
////				        
////				SEG_PORT_1 = 1;  
////				SEG_PORT_2 = 1;
////				SEG_PORT_3 = 1;
////				a = 1;
////				b = 1;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				
////				T0M1Delay();

////			  SEG_PORT_1 = 0; 
////				SEG_PORT_2 = 1;
////				SEG_PORT_3 = 1;
////				a = 1;
////				b = 0;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				
////				T0M1Delay();
////				
////        SEG_PORT_1 = 1;  
////				SEG_PORT_2 = 0;
////				SEG_PORT_3 = 1;
////				a = 0;
////				b = 0;
////				c = 0;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 0;
////				h = 1;
////			  T0M1Delay();
////				
////			  SEG_PORT_1 = 0; 
////				SEG_PORT_2 = 0;
////				SEG_PORT_3 = 1;
////				a = 1;
////				b = 0;
////				c = 0;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				T0M1Delay();

////        SEG_PORT_1 = 1;  
////				SEG_PORT_2 = 1;
////				SEG_PORT_3 = 0;
////				a = 1;
////				b = 1;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				T0M1Delay();

////			  SEG_PORT_1 = 0; 
////				SEG_PORT_2 = 1;
////				SEG_PORT_3 = 0;
////				a = 1;
////				b = 1;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				T0M1Delay();
////				
////        SEG_PORT_1 = 1;  
////				SEG_PORT_2 = 0;
////				SEG_PORT_3 = 0;
////				a = 1;
////				b = 1;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				T0M1Delay();
////				
////				
////			  SEG_PORT_1 = 0; 
////				SEG_PORT_2 = 0;
////				SEG_PORT_3 = 0;
////				a = 1;
////				b = 1;
////				c = 1;
////				d = 0;
////				e = 1;
////				f = 1;
////				g = 1;
////				h = 1;
////				T0M1Delay();			
////		
////			} 
////}


////void T0M1Delay(void)
////	{ unsigned int x;
////		for(x=0; x<100; x++)
////		{
////			TMOD=0x02;
////			TL0=0xFF;
////	//	TH0=0x4B;
////			TR0=1;
////		}
////	}



