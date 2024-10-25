#include <reg51.h>
#include "LCD.h"
#include "I2C.h"
#include "24C02.h"
void delay1 (unsigned int T)
{
	unsigned int i, j;
  for(i=0; i<T; i++)
	for(j=0; j<20; j++);
}
void INITI2C (void)
{
	SDA=1;
	SCL=1;
}
void I2C_START (void)
{
	SET_SCL_HIGH;
	SET_SDA_HIGH;
	delay1(5);
	SET_SDA_LOW;
	delay1(5);
}
void I2C_RESTART (void)
{
	SET_SCL_LOW;
	delay1(5);
	SET_SDA_HIGH;
	delay1(5);
	SET_SCL_HIGH;
	delay1(5);
	SET_SDA_LOW;
	delay1(5);
}
void I2C_STOP (void)
{
	SET_SCL_LOW;
	delay1(5);
	SET_SDA_LOW;
	delay1(5);
	SET_SCL_HIGH;
	delay1(5);
	SET_SDA_HIGH;
	delay1(5);
}
void I2C_ACK (void)
{
	SET_SCL_LOW;
	delay1(10);
	SET_SDA_LOW;
	delay1(10);
	SET_SCL_HIGH;
	delay1(20);
}
void I2C_NACK(void)
{
	SET_SCL_LOW;
	delay1(10);
	SET_SDA_HIGH;
	delay1(10);
	SET_SCL_HIGH;
	delay1(20);
}
bit I2C_WRITE_BYTE(unsigned char Byte)
{
	unsigned char i;
	for(i=0; i<8; i++)
	{
		SET_SCL_LOW;
		delay1(5);
		if((Byte<<i)&0x80)
		{
			SET_SDA_HIGH;
		}
		else
		{
			SET_SDA_LOW;
		  delay1(5);
		}
		SET_SCL_HIGH;
		delay1(5);
		
	}
	SET_SCL_LOW;
	SET_SDA_HIGH;
	delay1(5);
	SET_SCL_HIGH;
	delay1(5);
	return SDA;
}

unsigned char I2C_READ_BYTE (void)
{
	unsigned char i,d,Rxdata=0;
	for(i=0; i<8; i++)
	{
		SET_SCL_LOW;
		SET_SDA_HIGH;
		delay1(5);
		SET_SCL_HIGH;
		delay1(5);
		d=SDA;
		Rxdata=Rxdata|(d<<(7-i));
		delay1(5);
	}
		return Rxdata;
}









