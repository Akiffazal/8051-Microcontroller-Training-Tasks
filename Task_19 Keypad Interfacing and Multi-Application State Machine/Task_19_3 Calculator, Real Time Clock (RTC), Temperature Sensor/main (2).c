#include <reg51.h>
#include "LCD.h"
#include "RTC.h"
#include "CALCULATOR.h"
#include <stdio.h>

sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
sbit DS1302_CLK=P3^6;


unsigned int x;
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
void DS1302_setdate(unsigned char day, unsigned char month, unsigned char year)
{
DS1302_writebyte(DS1302_DATE,day);
DS1302_writebyte(DS1302_MONTH,month);
DS1302_writebyte(DS1302_YEAR,year);
}
void DS1302_getdate(void)
{
	lcd_set_cursor(1,0);
	lcd_string("DATE:");
	
	lcd_set_cursor(1,6);
	lcd_display(read_bytes[3]);
	lcd_char(':');
	delay(10);
	
	lcd_set_cursor(1,9);
	lcd_display(read_bytes[4]);
	lcd_char(':');
	delay(10);
	
	lcd_set_cursor(1,12);
	lcd_display(read_bytes[6]);
	delay(10);
}
//void timer_interrupt (void) interrupt 3
//{
////	x++;
////	if(x==20)
////	{


//			
//	  DS1302_CE=1;
//		DS1302_readbyte();
//		DS1302_CE=0;
//		
//		DS1302_gettime();
//		DS1302_getdate();	
//				
////	x=0;
////	}
//	}
//	

void rtc_state()
	
{

				
	DS1302_init();
	DS1302_settime(0x23,0x59,0x50);
	DS1302_setdate(0x31,0x12,0x23);
		
		
	while(1)
	{
	  DS1302_CE=1;
		DS1302_readbyte();
		DS1302_CE=0;
		
		DS1302_gettime();
		DS1302_getdate();
}
			
	}		
		
			


































//{
//	//lcd_init();
////	while(1)
////{
////	   if(rtc_flag==1)
////	{
//	
//	TMOD=0x02;
//	TH0=0xD1;
//	EA=1;
//	ET1=1;
//	TR0=1;
//	
// 

// DS1302_init();
//	DS1302_settime(0x23,0x59,0x50);
//	DS1302_setdate(0x31,0x12,0x23);	
//	}
//	 
////	

//	
////}
//}
