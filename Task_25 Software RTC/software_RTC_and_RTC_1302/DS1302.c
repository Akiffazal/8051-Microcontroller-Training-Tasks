#include <reg51.h>
#include "DS1302.h"
#include <string.h>
#include "stdio.h"



unsigned int read_bytes[12];    
void SCLK_Pulse()
{
	DS1302_CLK=1;
	DS1302_CLK=0;
}
void send_bit(unsigned int bitt)
{
	if(bitt!=0)
	{
		DS1302_IO=1;                    //one bit write
	}
	else
	{
		DS1302_IO=0;
	}
}
void write_byte(unsigned int byte)
{
	unsigned int i,Bit;
	for(i=0; i<8; i++)
	{                                        //rtc write byte
		Bit =byte &(1<<i);
		send_bit(Bit);
		SCLK_Pulse();
	}
}
unsigned char read_byte(unsigned char cmd)
{
	unsigned int j,dat=0;
	write_byte(cmd);
	for(j=0; j<8; j++)
	{
		dat>>=1;
		if(DS1302_IO)
		{
			dat|=0x80;
		}
		else
		{
			dat&=0x7F;
		}
		SCLK_Pulse();
	}
	return dat;
}
void DS1302_writebyte(unsigned char cmd, unsigned char value)
{
	DS1302_CE=1;
	write_byte(cmd);                      //rtc write byte at address
	write_byte(value);
	DS1302_CE=0;
}
void DS1302_readbyte()
{
	unsigned int dat=0,i,j;
	DS1302_CE=1;
	
	write_byte(DS1302_READ_BURST);
	for(i=0; i<8; i++)           //store in array
	{
		dat=0;
		for(j=0; j<8; j++)         //bit by bit read
		{
			dat>>=1;
		if(DS1302_IO)
		{                                           //reading ta enable
			dat|=0x80;
		}
		else
		{
			dat&=0x7F;
		}
		SCLK_Pulse();
		}
		read_bytes[i]=dat;
	}	
	DS1302_CE=0;	
}
void DS1302_init()
{
	unsigned char r;
	DS1302_CE=0; 
	DS1302_CLK=0;
	DS1302_writebyte(DS1302_CONTROL,0x00);
	DS1302_writebyte(DS1302_CHARGER,0xAB);
	
	r=read_byte(DS1302_SECOND_READ);                
	if((r&DS1302_SECOND_READ)!=0)
		DS1302_writebyte(DS1302_SECOND,0);              //zarah value zero ka
}

void DS1302_settime(unsigned char hour, unsigned char minute, unsigned char second)
{
	DS1302_writebyte(DS1302_SECOND,second);
	DS1302_writebyte(DS1302_MINUTE,minute);
	DS1302_writebyte(DS1302_HOUR,hour);

}
void lcd_display(unsigned char number)
{
	lcd_char(((number>>4)&0x0F)+0x30); //ten
	lcd_char((number&0x0F)+0x30);   //unit
}

void DS1302_gettime(void)
{
	lcd_set_cursor(0,0);
	lcd_string("TIME:");
	
	lcd_set_cursor(0,6);
	lcd_display(read_bytes[2]);
	lcd_char(':');
	delay(10);
	
	
	lcd_set_cursor(0,9);
	lcd_display(read_bytes[1]);
	lcd_char(':');
	delay(10);
	
	lcd_set_cursor(0,12);
	lcd_display(read_bytes[0]);
	delay(10);
		
}
//void DS1302_setdate(unsigned char day, unsigned char month, unsigned char year)
//{
//DS1302_writebyte(DS1302_DATE,day);
//DS1302_writebyte(DS1302_MONTH,month);
//DS1302_writebyte(DS1302_YEAR,year);
//}
//void DS1302_getdate(void)
//{
//	lcd_set_cursor(1,0);
//	lcd_string("DATE:");
//	
//	lcd_set_cursor(1,6);
//	lcd_display(read_bytes[3]);
//	lcd_char(':');
//	delay(10);
//	
//	lcd_set_cursor(1,9);
//	lcd_display(read_bytes[4]);
//	lcd_char(':');
//	delay(10);
//	
//	lcd_set_cursor(1,12);
//	lcd_display(read_bytes[6]);
//	delay(10);
//}
void inttoASCII(int num, char *buffer)
{
	sprintf(buffer, "%d", num);
}
void lcd_display_int(int num)
{
	char buffer[10];
	inttoASCII(num, buffer);
	lcd_string(buffer);
	
}


//unsigned int dayinmonth (unsigned char mon, unsigned int year)
//	{
//		unsigned int day;
//		switch(mon)
//		{
//			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//				day=31;
//			break;
//			case 4: case 6: case 9: case 11:
//				day=30;
//			break;
//			case 2:
//				if((year % 4 == 0 && year % 100 != 0) || (year % 400 ==0))
//				{
//					day=29;
//				}
//				else
//				{
//					day=28;
//				}
//				break;
//			default:
//				day=0;
//			
//		}
//		return day;
//	}

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
	for(j=0; j<127; j++);
	
}