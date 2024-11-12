#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"







sbit c4=P1^0;
sbit c3=P1^1;
sbit c2=P1^2;
sbit c1=P1^3;
sbit r4=P1^4;
sbit r3=P1^5;
sbit r2=P1^6;
sbit r1=P1^7;
char key  = '\0' ;
char keypad ()
{
	c1=c2=c3=c4=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			lcd_char('7');
		  key='7';
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('8');
	  key='8';
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('9');
		key='9';
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('/');
		key='/';
	}
	
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
			lcd_char('4');
		key='4';
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('5');
		key='5';
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('6');
		key='6';
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('*');
		key='*';
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		lcd_char('1');
		key='1';
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('2');
		key='2';
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('3');
		key='3';
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('-');
		key='-';
	}
	
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		while(c1==0);
			lcd_command(0x01);    //lcd clear
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_char('0');
		key='0';
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_char('=');
		key='=';
	}
	else if(c4==0)
	{
		while(c4==0);
		lcd_char('+');
		key='+';
	}
	
	return key;
}


//void main ()
//{
//	
//	 lcd_init();

//	while(1)
//	{
////		lcd_command(0x80);
////		lcd_string("ENTER THE KEY");
////	lcd_set_cursor(1, 0);
//	keypad();
//	

//	}
//}


