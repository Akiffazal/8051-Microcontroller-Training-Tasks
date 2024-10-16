#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "KEYPAD.h"


#define ledd P0
sbit c4=P1^0;
sbit c3=P1^1;
sbit c2=P1^2;
sbit c1=P1^3;
sbit r4=P1^4;
sbit r3=P1^5;
sbit r2=P1^6;
sbit r1=P1^7;
unsigned int message[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void keypad1()
{

	c1=c2=c3=c4=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			ledd=0x07;
	}
	else if(c2==0)
	{
		while(c2==0);
		ledd=0x7F;
	}
	else if(c3==0)
	{
		while(c3==0);
		ledd=0x6F;
	}
	else if(c4==0)
	{
		while(c4==0);
		ledd=0x06;
	}
	
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			ledd=0x66;
	}
	else if(c2==0)
	{
		while(c2==0);
		ledd=0x6D;
	}
	else if(c3==0)
	{
		while(c3==0);
		ledd=0x7D;
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('x');
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		ledd=0x06;
	}
	else if(c2==0)
	{
		while(c2==0);
		ledd=0x5B;
	}
	else if(c3==0)
	{
		while(c3==0);
		ledd=message[3];
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('-');
	}
	
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		while(c1==0);
			lcd_command(0x01);
	}
	else if(c2==0)
	{
		while(c2==0);
		ledd=message[0];
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('=');
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('+');
	}
	
}