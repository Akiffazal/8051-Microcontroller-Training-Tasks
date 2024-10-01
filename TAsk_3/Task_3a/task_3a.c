#include <reg51.h>

#define Port P2

void MSDelay(unsigned int);

void main(){   
	while(1)
	{
		  Port = 0x00;
			Port = Port | 0xFE;
			MSDelay(500);
		  
			Port = 0xFF;
			MSDelay(500);	  

	}
}


void MSDelay(unsigned int itime)
  {
    unsigned int i,j;
	  for(i=0;i<itime;i++)
	    for(j=0;j<114;j++);
  }