#include <reg51.h>
#include "LCD.h"
#include <string.h>

#define lcd_data P0
sbit RW=P2^5;
sbit RS=P2^6;
sbit EN=P2^7;

void lcd_init()
{
	lcd_command(0x38);
	lcd_command(0x0C);
	lcd_command(0x01);
	lcd_command(0x80);
}

void lcd_command(unsigned char cmd)
{
	lcd_data=cmd;
	RW=0;
	RS=0;
	EN=1;
	delay(10);
	EN=0;
	delay(10);
}
void lcd_char(unsigned char dat)
{
	lcd_data=dat;
	RW=0;
	RS=1;
	EN=1;
	delay(10);
	EN=0;
	delay(10);
}
void lcd_string(unsigned char *str)
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		lcd_char(str[i]);
	}
	
}
void lcd_set_cursor(unsigned char row, unsigned char col)
{
	unsigned char position;
	if(row==0)
	{
		position=0x80+col;
	}
	else
	{
		position=0xC0+col;
	}
	lcd_command(position);
}

void delay (unsigned int time)
{
	unsigned int i,j;
	for(i=0; i<time; i++)
	for(j=0; j<112; j++);
	
}
void   Timmer_Delay (unsigned char k)
{
	unsigned int j;
	for(j=0; j<k; j++)
	{
	TH1=0x4B;
	TL1=0xFD;                  //50ms
	TF1=0;
	TR1=1;
	while(TF1==0);
	TF1=0;
	TR1=0;
	}
}
void Delay1 (unsigned int value)
{
	unsigned int j;
	for(j=0; j<value; j++)
	{
		TH0=0xFC;
		TL0=0x64;
		TF0=0;
		TR0=1;
		
		while(TF0==0);
		TF0=0;
		TR0=0;
		
	}
}

void lcd_clear()
{
	lcd_command(0x01);
}



int lcd_pow (int X, int Y)
{
	unsigned char i;
	int result=1;
	
	for(i=0; i<Y; i++)
	{
		result*=X;
	}
	return result;	
}

void lcd_shownum(unsigned char line, unsigned char column, int number, unsigned char length)
{
	unsigned char i;
	lcd_set_cursor(line,column);
	for(i=length; i>0; i--)
	{
		lcd_char(number/lcd_pow(10,i-1)%10+'0');
	}
}
void lcd_showchar(unsigned char line, unsigned char column, char Char)
{
	lcd_set_cursor(line,column);
	lcd_char(Char);
}
void lcd_showstring(unsigned char line, unsigned char column, char *string)
{
	unsigned char i;
	lcd_set_cursor(line,column);
	for(i=0; string[i]!='\0'; i++)
	lcd_char(string[i]);
}
















