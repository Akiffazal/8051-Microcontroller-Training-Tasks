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