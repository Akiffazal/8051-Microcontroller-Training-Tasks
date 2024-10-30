#include <reg51.h>
sbit motor_pin= P2^0;



//// 8 bit timer delay 0 degree
//unsigned int i;

//void delay()
//	{
//		TMOD=0x02;
//		TH0=0xD1;
//		TR0=1;
//	}

//void main()
//	{
//		while(1)
//		{
//		motor_pin=0;
//		for(i=0; i<945; i++)
//			{
//				delay();
//			}
//			motor_pin=1;

//			for(i=0; i<23; i++)
//		{
//			delay();
//		}
//		}
//	}



	
	
// TIMER DELAY 16 BIT MODE 1 45degree

sbit led =P2^0;
unsigned int i=0;
                               
void delay()
{
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x65;
	TR0=1;
	while(TF0 == 0);
	TF0=0;
	TR0=0;
}


void main()
{
	while(1)
	{

	motor_pin=0;
		for(i=0; i<19; i++)
		{
			delay();
		}
				motor_pin=1;
		for(i=0; i<1; i++)
		{
			delay();
		}
	}
}





//void delay (unsigned int );

//void timer_init (unsigned int );

//void main()
//{

//	while(1)
//	{
//	 motor_pin=0;
//		delay(19);
//		motor_pin=1;
//		delay(1);
//		}
//		
//	
//	}
//void delay (unsigned int time)
//{
//	unsigned int i,j;
//	for(i=0; i<time; i++)
//	for(j=0; j<116; j++);
//}

























//TIMER DELAY 8 BIT MODE 2    20ms
//sbit led=P2^0;
//unsigned int i;
//void delay ();
//void delay()
//{
//	TMOD=0x02;
//	TH0=0xD1;
//	TR0=1;

//}

//void main()
//{
//	while(1)
//	{
//		
//		led=1;
//	
//		for(i=0; i<1000; i++)
//		{
//			delay();
//		}
//			led=0;
//		
//			for(i=0; i<1000; i++)
//		{
//			delay();
//		}
//	}
//}




