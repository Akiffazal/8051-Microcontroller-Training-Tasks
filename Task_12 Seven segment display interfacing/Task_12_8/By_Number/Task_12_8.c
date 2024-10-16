#include <stdio.h>
#include <reg51.h>

sbit p1 = P2^2;  
sbit p2 = P2^3;
sbit p3 = P2^4;

void T0M1Delay(void);

unsigned long num = 42354245;
//unsigned long num = 97561654;

// Convert num to array
void display_num_7seg(unsigned long num, int i)
	{	
			int num_array[8];            
			int j = 7;
		
			// Extract digits and store them in the array
			while (num > 0) 
				{
						num_array[j] = num % 10;
						num = num / 10;
						j--;
				}
			
				if(num_array[i]==0)
					P0 = 0x3F;
				
				else if(num_array[i]==1)
					P0 = 0x06;
						
				else if(num_array[i]==2)
					P0 = 0x5B;
				
				else if(num_array[i]==3)
					P0 = 0x4F;
				
				else if(num_array[i]==4)
					P0 = 0x66;
				
				else if(num_array[i]==5)
					P0 = 0x6D;
				
				else if(num_array[i]==6)
					P0 = 0x7D;
				
				else if(num_array[i]==7)
					P0 = 0x07;
				
				else if(num_array[i]==8)
					P0 = 0x7F;
				
				else if(num_array[i]==9)
					P0 = 0x6F;

	}

	
void main(void)
	{
		p1=1; p2=1; p3=1;
		display_num_7seg(num, 0);
		T0M1Delay();
		
		p1=0; p2=1; p3=1;
		display_num_7seg(num, 1);
		T0M1Delay();
		
		p1=1; p2=0; p3=1;
		display_num_7seg(num, 2);
		T0M1Delay();
		
		p1=0; p2=0; p3=1;
		display_num_7seg(num, 3);
		T0M1Delay();
		
		p1=1; p2=1; p3=0;
		display_num_7seg(num, 4);
		T0M1Delay();
		
		p1=0; p2=1; p3=0;
		display_num_7seg(num, 5);
		T0M1Delay();
		
		p1=1; p2=0; p3=0;
		display_num_7seg(num, 6);
		T0M1Delay();

		p1=0; p2=0; p3=0;
		display_num_7seg(num, 7);
		T0M1Delay();
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

