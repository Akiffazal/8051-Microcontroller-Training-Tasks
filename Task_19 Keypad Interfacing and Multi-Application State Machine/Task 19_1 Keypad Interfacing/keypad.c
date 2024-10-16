#include <reg51.h>
#include "LCD.h"
#include "KEYPAD_1.h"
#include "SEVEN.h"


sbit c4=P1^0;
sbit c3=P1^1;
sbit c2=P1^2;
sbit c1=P1^3;
sbit r4=P1^4;
sbit r3=P1^5;
sbit r2=P1^6;
sbit r1=P1^7;


void keypad ()
{
	c1=c2=c3=c4=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			lcd_char('7');
		  
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('8');
		
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('9');
		
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('/');
	}
	
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			lcd_char('4');
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('5');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('6');
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('*');
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		lcd_char('1');
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('2');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('3');
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
		lcd_char('0');
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





