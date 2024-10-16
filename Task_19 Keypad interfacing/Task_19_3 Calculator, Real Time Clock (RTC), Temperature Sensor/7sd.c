#include <reg51.h>
#include "TEMP.h"

unsigned char indexx=0;
unsigned int select[]={0x0C, 0x08, 0x04, 0x00};
unsigned int massege[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char values[4];

void display_num7_seg(unsigned char num)
{
	int i=3;
	while(num!=0)
	{
		values[i]=num%10;
		num=num/10;
		i--;
	}
}
void values_on_ssd (void)
{
	switch(values[indexx])
	{
		case 0:
		{
			P2=select[indexx];
			P0=massege[0];
		}
		break;
		case 1:
		{
			P2=select[indexx];
			P0=massege[1];
		
		}
			break;
		case 2:
		{
			P2=select[indexx];
			P0=massege[2];
			
		}
			break;
		case 3:
		{
			P2=select[indexx];
			P0=massege[3];
			
		}
			break;
		case 4:
		{
			P2=select[indexx];
			P0=massege[4];
			
		}
			break;
		case 5:
		{
			P2=select[indexx];
			P0=massege[5];
			
		}
			break;
		case 6:
		{
			P2=select[indexx];
			P0=massege[6];
			
		}
			break;
		case 7:
		{
			P2=select[indexx];
			P0=massege[7];
			
		}
			break;
		case 8:
		{
			P2=select[indexx];
			P0=massege[8];
			
		}
			break;
		case 9:
		{
			P2=select[indexx];
			P0=massege[9];
		}
		break;
		default:
			break;
	}
	indexx+=1;
	if(indexx>3)
	{
		indexx=0;
	}
}