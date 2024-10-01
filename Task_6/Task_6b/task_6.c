#include <reg51.h>
sbit led=P2^0;
sbit switch1=P3^1;

void MSDelay(unsigned int);


void main()
{
	while(1)
	{
		if(switch1==0)
		{
			led=~led;
			MSDelay(250);
		}
	}
}


void MSDelay(unsigned int itime) {
    unsigned int i, j;
    for(i = 0; i < itime; i++)
        for(j = 0; j<114; j++);
}