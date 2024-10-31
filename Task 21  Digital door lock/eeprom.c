#include <reg51.h>
#include "eeprom.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "intrins.h"

sbit SDA = P2^0;
sbit SCL = P2^1;
unsigned char a , b, Data;
bit ack;

void delay2 (unsigned int t)
{
	unsigned int i ,j;
	for(i=0; i<=t; i++)
	for(j=0; j<=113; j++);
}
void start_data ()
{
	SDA=1;
	_nop_();_nop_();        // HIGH TO LOW
	SCL=1;
	_nop_();_nop_();
	SDA=0;
	_nop_();_nop_();
}
void restart ()
{
	SCL=0;
	SDA=1;
	SCL=1;
	SDA=0;

}
void stop_data ()
{
	SCL=0;
	SDA=0;                //LOW TO HIGH
	SCL=1;
	SDA=1;
	
}

void acknowledge ()
{
	SCL=0;
	SDA=1;
	SCL=1;
	while(SDA);
}
void no_acknowledge ()
{
	SCL=0;
	SDA=1;
	SCL=1;
}
void sendbyte (unsigned int value)
{
	for(a=0; a<8; a++)
	{
		SCL=0;
		SDA=(value & (0x80>>a))?1:0;
		SCL=1;
	}
}
unsigned char readbyte ()
{
	Data=0;
	for(b=0; b<8; b++)
	{
		SCL=0;
		SCL=1;
		if(SDA)
		{
			Data |=(0x80>>b);
		}
	}
	return Data;
	
}
void EEPROM_write (unsigned char address_w, unsigned char Data )
{
	start_data ();
	sendbyte(0xA0);
	acknowledge ();
	sendbyte(address_w);
	acknowledge ();
	sendbyte(Data);
	acknowledge ();
	stop_data ();
	delay2(10);
}

unsigned char EEPROM_read (unsigned char address_r )
{
	unsigned char Data;
		start_data ();
	sendbyte(0xA0);
	acknowledge ();
	sendbyte(address_r);
	acknowledge ();
	restart ();
	sendbyte(0xA1);
	acknowledge ();
	Data=readbyte ();
	no_acknowledge ();
	stop_data ();
	return Data;
}









