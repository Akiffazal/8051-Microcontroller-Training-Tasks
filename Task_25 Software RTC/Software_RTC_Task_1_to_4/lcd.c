// Define LCD control pins
#include <reg51.h>
#include "lcd.h"

sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;

sbit D0 = P0^0;
sbit D1 = P0^1;
sbit D2 = P0^2;
sbit D3 = P0^3;
sbit D4 = P0^4;
sbit D5 = P0^5;
sbit D6 = P0^6;
sbit D7 = P0^7;

//const unsigned char specialcharacter[8][8] ={
// {0x00,0x0a,0x1f,0x1f,0x0e,0x04,0x00}, {0x04,0x0e,0x0e,0x0e,0x1f,0x00,0x04,0x00},{0x1f,0x15,0x1f,0x1f,0x0e,0x0a,0x1b,0x00},{0x00,0x01,0x03,0x16,0x1c,0x08,0x00,0x00},
// {0x01,0x03,0x0f,0x0f,0x0f,0x0f,0x03,0x01},{0x01,0x03,0x05,0x09,0x09,0x0b,0x1b,0x18},{0x00,0x0e,0x15,0x1b,0x0e,0x0e,0x00,0x00},{0x0e,0x11,0x11,0x1f,0x1b,0x1b,0x1b,0x1f},
//};



void delay_ms(unsigned int ms) {
  unsigned int i, j;
  for (i = 0; i < ms; i++)
    for (j = 0; j < 127; j++);
}

void lcd_write_byte(unsigned char dataa, unsigned char rs) {
	
  RS = rs;
  EN = 1;
  delay_ms(10);
	
	port0 = dataa;
//  D0 = (dataa & 0x01);
//  D1 = (dataa & 0x02) >> 1;
//  D2 = (dataa & 0x04) >> 2;
//  D3 = (dataa & 0x08) >> 3;
//  D4 = (dataa & 0x10) >> 4;
//  D5 = (dataa & 0x20) >> 5;
//  D6 = (dataa & 0x40) >> 6;
//  D7 = (dataa & 0x80) >> 7;
  delay_ms(10);
  EN = 0;
}

void lcd_write_command(unsigned char command) {
	RW = 0;
  lcd_write_byte(command, 0);
}

void lcd_write_data(unsigned char dataa) {
	RW = 0;
  lcd_write_byte(dataa, 1);
}

void lcd_clear(void) {
  lcd_write_command(LCD_CLEAR_DISPLAY);
}

void lcd_blink_cursor(void){
			
		  lcd_write_command(0x0E);

}

void lcd_init(void) {
//	unsigned char i;
  lcd_write_command(LCD_FUNCTION_SET);
	  delay_ms(20);

  lcd_write_command(LCD_DISPLAY_ON);
	  delay_ms(20);
	
  lcd_write_command(LCD_FUNCTION_SET_8BIT);
	  delay_ms(20);

  lcd_write_command(LCD_FUNCTION_SET_2LINE );
	  delay_ms(20);

  lcd_write_command(LCD_FUNCTION_SET_5X8DOTS);
	  delay_ms(20);

	lcd_write_command(LCD_DISPLAY_ON_OFF_CONTROL);
	  delay_ms(20);
	
   lcd_clear();
    delay_ms(20);
	
	
//  for (i = 0; i <8; i++) {
//    lcd_write_symbol(i, specialcharacter[i]);
//  }
                                                                             // Entry mode set
  lcd_write_command(LCD_ENTRY_MODE_SET);
	//lcd_write_command(LCD_ENTRY_MODE_SET_INCREMENT);


}

void lcd_set_cursor(unsigned char row, unsigned char col) {
	
  unsigned char address;
  if (row == 0) {
    address = LCD_SET_DDRAM_ADDRESS | col;
  } else {
    address = LCD_SET_DDRAM_ADDRESS | (0x40 + col);
  }
  lcd_write_command(address);
}




void lcd_write_string(char *str) {
  unsigned int i = 0;
  while (str[i] != '\0') {
    lcd_write_data(str[i]);
    i++;
  }
}

//void lcd_write_symbol(unsigned char location, const unsigned char* scharacter){
//	unsigned char j;
//	lcd_write_command(LCD_SET_CGRAM_ADDRESS | (location <<3));
//	
//		for (j = 0; j<8; j++){
//		lcd_write_data(scharacter[j]);
//		}
//}