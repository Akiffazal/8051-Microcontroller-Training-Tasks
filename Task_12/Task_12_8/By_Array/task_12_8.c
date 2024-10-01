#include <stdio.h>
#include <reg51.h>

sbit SEG_PORT_1 = P2^2;  
sbit SEG_PORT_2 = P2^3;
sbit SEG_PORT_3 = P2^4;

void T0M1Delay(void);

unsigned int num_array[] = {4, 2, 3, 5, 4, 2, 4, 5}; 

void display_num_7seg(unsigned int array[], int i)
	{
			
				if(array[i]==0)
					P0 = 0x3F;
				
				else if(array[i]==1)
					P0 = 0x06;
						
				else if(array[i]==2)
					P0 = 0x5B;
				
				else if(array[i]==3)
					P0 = 0x4F;
				
				else if(array[i]==4)
					P0 = 0x66;
				
				else if(array[i]==5)
					P0 = 0x6D;
				
				else if(array[i]==6)
					P0 = 0x7D;
				
				else if(array[i]==7)
					P0 = 0x07;
				
				else if(array[i]==8)
					P0 = 0x7F;
				
				else if(array[i]==9)
					P0 = 0x6F;

	}

	
void main(void)
	{
		SEG_PORT_1=1;
		SEG_PORT_2=1;
		SEG_PORT_3=1;
		display_num_7seg(num_array, 0);
		T0M1Delay();
		
		SEG_PORT_1=0;
		SEG_PORT_2=1;
		SEG_PORT_3=1;
		display_num_7seg(num_array, 1);
		T0M1Delay();
		
		SEG_PORT_1=1;
		SEG_PORT_2=0;
		SEG_PORT_3=1;
		display_num_7seg(num_array, 2);
		T0M1Delay();
		
		SEG_PORT_1=0;
		SEG_PORT_2=0;
		SEG_PORT_3=1;
		display_num_7seg(num_array, 3);
		T0M1Delay();
		
		SEG_PORT_1=1;
		SEG_PORT_2=1;
		SEG_PORT_3=0;
		display_num_7seg(num_array, 4);
		T0M1Delay();
		
		SEG_PORT_1=0;
		SEG_PORT_2=1;
		SEG_PORT_3=0;
		display_num_7seg(num_array, 5);
		T0M1Delay();
		
		SEG_PORT_1=1;
		SEG_PORT_2=0;
		SEG_PORT_3=0;
		display_num_7seg(num_array, 6);
		T0M1Delay();
		
		SEG_PORT_1=0;
		SEG_PORT_2=0;
		SEG_PORT_3=0;
		display_num_7seg(num_array, 7);
		T0M1Delay();
	}
	


void T0M1Delay(void)
	{
		unsigned int  x;
		for(x=0;x<20;x++)
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

