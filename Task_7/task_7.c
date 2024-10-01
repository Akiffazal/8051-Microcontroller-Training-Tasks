#include <reg51.h>
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;

sbit switch1=P3^0;    //K2 button
sbit switch2=P3^1;    //K1 button
sbit switch3=P3^2;    //K3 button
sbit switch4=P3^3;    //K4 button

void MSDelay(unsigned int);


void main()
{
	while(1)
	{
		if(switch1==0)
		{
			led2=~led2;
			MSDelay(250);
		}
		
		else if(switch2==0)
		{
			led1=~led1;
			MSDelay(250);
		}
		
		else if(switch3==0)
		{
			led3=~led3;
			MSDelay(250);
		}
		
		else if(switch4==0)
		{
			led4=~led4;
			MSDelay(250);
		}
	}
}


void MSDelay(unsigned int itime) {
    unsigned int i, j;
    for(i = 0; i < itime; i++)
        for(j = 0; j<114; j++);
}


