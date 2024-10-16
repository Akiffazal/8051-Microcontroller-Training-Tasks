#include<reg51.h>
#include "temperature.h"


unsigned char xdata temp_lsb=0,temp_msb=0;
unsigned char xdata Unite, Ten, Hunderd, intpart, decpart;
char xdata temp_f;
//unsigned char Unite,Ten,Hunderd,intpart,decpart;
//char temp_f;
//unsigned char temp_c;
unsigned char xdata temp_c;

sbit DQ= P3^7;


void ow_reset(void)
{
DQ = 1; //pull DQ line low
delay_18B20(8); // leave it low for 480us
DQ = 0; // allow line to return high
delay_18B20(65); // wait for presence
DQ=1;
delay_18B20(20);    
} // 

// delay
void delay_18B20(unsigned int ud){
    while(ud--); //
}

// READ_BYTE - reads a byte from the one-wire bus.
unsigned char read_byte(void)
{
    unsigned char i=0;
    unsigned char dat = 0;
    for (i=8;i>0;i--){
          DQ = 0;
          dat>>=1;
          DQ = 1;
          if(DQ)
          dat |= 0x80;
          delay_18B20(4);
    }
    return(dat);
}

// WRITE_BYTE - writes a byte to the one-wire bus.
void write_byte(char dat)
{
    unsigned char i=0;
    for (i=8; i>0; i--){
        DQ = 0;
        DQ = dat&0x01;
        delay_18B20(5);
        DQ = 1;
        dat>>=1;
    }
}

void Read_Temperature(void)
{
ow_reset();
write_byte(0xCC); //Skip ROM
	
write_byte(0x44); // Start Conversion
delay_18B20(10); 
ow_reset();
write_byte(0xCC); // Skip ROM
write_byte(0xBE); // Read Scratch Pad
delay_18B20(10);
	
temp_msb = read_byte();  
temp_lsb = read_byte(); 

temp_c = ((temp_lsb*256+temp_msb)>>4);
temp_f = (((int)temp_c)* 9)/5 + 32;


}
void hex2lcd(unsigned char z){

	Hunderd=(z/100) + 0x30; //hundred
	Ten=(z%100/10) + 0x30; //ten
	Unite=(z%10) + 0x30; //uni
	intpart = (int)z;
  decpart = (z - intpart) + 0x30;
	lcd_write(Hunderd);
	lcd_write(Ten);
	lcd_write(Unite);
	lcd_string(".");
	lcd_write(decpart);
}

  

void body()
{ 

	LCD_Command(0xc0);
  Read_Temperature();
	hex2lcd(temp_c);
	lcd_string("C ");
  	hex2lcd(temp_f);
	lcd_string("F");
	

	}

  





#define LCD_data P0

sbit En=P2^7;
sbit Rs=P2^6;
sbit Wr=P2^5;


void lcd_init()
{
	delay1(20);		/* LCD Power ON Initialization time >15ms */
	LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0E);	/* Display ON Cursor blinking */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* clear display */


}
void lcd_string(unsigned char *lcd_data)
{
   while(*lcd_data)
   {
   lcd_write(*lcd_data++);
   }

}

void LCD_Command (unsigned char cmd)	
{
	LCD_data= cmd;
	Rs=0;				/* command reg. */
	Wr=0;				/* Write operation */
	En=1; 
	delay1(1);
	En=0;
	delay1(5);
}
void lcd_write(unsigned char lcd_data)
{
LCD_data=lcd_data;
Rs=1;
Wr=0;
En=1;
delay1(1);
En=0;

}
void delay1(unsigned int count)  /* Function to provide delay Approx 1ms */
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<112;j++);
}

