#include <reg51.h>
sbit led=P2^0;

void MSDelay(unsigned int);


void external_int0() interrupt 0
{
	led=~led;
	MSDelay(250);	
}


void main()
{
	IE=0x81;
}


void MSDelay(unsigned int itime) {
    unsigned int i, j;
    for(i = 0; i < itime; i++)
        for(j = 0; j<114; j++);
}








//#include <reg51.h>
//sbit led=P2^0;
//sbit switch1=P3^2;

//void MSDelay(unsigned int);


//void external_int0() interrupt 0
//{
//	if(switch1==0)
//	{
//		led=~led;
//	  MSDelay(250);
//	}
//}


//void main()
//{
//	IE=0x81;
//	while(1)
//	{
//	}
//}


//void MSDelay(unsigned int itime) {
//    unsigned int i, j;
//    for(i = 0; i < itime; i++)
//        for(j = 0; j<114; j++);
//}