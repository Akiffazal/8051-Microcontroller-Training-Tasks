#include <reg51.h>
#include <stdio.h>  // For sprintf function
#include "lcd.h"

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

void lcd_clear()
{
		lcd_command(0x01);

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
void lcd_display_long(unsigned long num)
{
	
	unsigned int i;
	char str[12];
	sprintf(str,"%lu",num);
  
	for(i=0; str[i]!='\0'; i++)
	{
		lcd_char(str[i]);
		
	}
}

void delay (unsigned int time)
{
	unsigned int i,j;
	for(i=0; i<time; i++)
	for(j=0; j<10; j++);
	
}

















//#include "Includes.h"

//void ToggleEpinOfLCD(void)
//{
//	E = 1;                // Give a pulse on E pin
//	__delay_us(E_Delay);  // so that LCD can latch the
//	E = 0;                // data from data bus
//	__delay_us(E_Delay); 	
//}

//void WriteDataToLCD(char t)
//{
//   RS = 1;             // This is data

//   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//   P0 |= (t&0xF0);     // Write Upper nibble of data
//   ToggleEpinOfLCD();  // Toggle E pin to send data 

//   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//   P0 |= ((t<<4)&0xF0);// Write Lower nibble of data
//   ToggleEpinOfLCD();  // Toggle E pin to send data 
//}


//void WriteCommandToLCD(int z)
//{
//   RS = 0;             // This is command

//   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//   P0 |= (z&0xF0);     // Write Upper nibble of data
//   ToggleEpinOfLCD();  // Toggle E pin to send data 

//   P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//   P0 |= ((z<<4)&0xF0);// Write Lower nibble of data
//   ToggleEpinOfLCD();  // Toggle E pin to send data 
//}

//void InitLCD(void)
//{
//	RS = 0;		 	// Make pin zero
//	E  = 0;			// Make Pin zero					

//  ///////////// Reset process from datasheet /////////
//     __delay_us(15000);

//	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//	 P0 |= 0x30;    	   // Write 0x3
//     ToggleEpinOfLCD();    // Toggle E pin to send data 

//     __delay_us(4500);

//	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//	 P0 |= 0x30;    	   // Write 0x3
//     ToggleEpinOfLCD();    // Toggle E pin to send data 

//     __delay_us(300);

//	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//	 P0 |= 0x30;    	   // Write 0x3
//     ToggleEpinOfLCD();    // Toggle E pin to send data 

//     __delay_us(650);

//	 P0 &= 0x0F;		   // Make P2.4 to P2.7 zero
//	 P0 |= 0x20;    	   // Write 0x2
//     ToggleEpinOfLCD();    // Toggle E pin to send data 

//	 __delay_us(650);

//  /////////////////////////////////////////////////////
//   WriteCommandToLCD(0x28);    //function set
//   WriteCommandToLCD(0x0c);    //display on,cursor off,blink off
//   WriteCommandToLCD(0x01);    //clear display
//   WriteCommandToLCD(0x06);    //entry mode, set increment
//}
