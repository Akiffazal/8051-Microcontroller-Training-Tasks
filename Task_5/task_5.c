#include <reg51.h>

sbit led1 = P2^0;
sbit switch1 = P3^1;
unsigned int x=0;
void MSDelay(unsigned int);

void main()
	{
		while(1)
		{
			if(switch1==0)
			{
				led1=~led1;
				MSDelay(300);
			}
		}
	}


void MSDelay(unsigned int itime)
  {
    unsigned int i,j;
	  for(i=0;i<itime;i++)
	    for(j=0;j<114;j++);
  }







//// 2nd Method
////	{
////		if(switch1==0)
////		{
////			x++;
////			MSDelay(500);
////		}
////		
////		if(x==1)
////		{
////			Port2=0xFE;
////		}
////		else if(x==2)
////		{
////			Port2=0xFF;
////		}
////		else if(x==3)
////		{
////			x=1;
////		}
////	}
////}
//	

//void MSDelay(unsigned int itime)
//  {
//    unsigned int i,j;
//	  for(i=0;i<itime;i++)
//	    for(j=0;j<114;j++);
//  }





//#include <reg52.h>

//sbit led_1 = P2^0;
//sbit button = P3^1;

//void delay(unsigned int milliseconds) {
//    unsigned int i, j;
//    for(i = 0; i < milliseconds; i++)
//        for(j = 0; j < 125; j++);  // Delay approximation for 1 ms
//}

//void main(void) {
//    unsigned char buttonState;

//    while(1) {
//        if(button == 1) {
//            delay(20); // Debounce delay
//            if(button == 0) {
//                led_1 = !led_1; // Toggle LED state
//                while(button == 1); // Wait for button release
//                delay(20); // Debounce delay for button release
//            }
//        }
//    }
//}
