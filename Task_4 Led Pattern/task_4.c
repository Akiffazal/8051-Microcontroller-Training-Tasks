#include <reg51.h>

#define Port2 P2

void MSDelay(unsigned int);

void main(){
	while(1)
	{
		Port2 = 0xAA;
		MSDelay(500);
		
		Port2 = 0x55;
		MSDelay(500);
	}
}
	

void MSdelay(unsigned int itime)
{
	unsigned int i,j;
	  for(i=0;i<itime;i++)
	  for(j=0;j<114;j++);
}