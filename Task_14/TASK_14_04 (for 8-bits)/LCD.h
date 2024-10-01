#ifndef LCD_H
#define LCD_H

#include <reg51.h>

// Define the register select, read/write, and enable pins
sbit rs = P2^6;    
sbit rw = P2^5;    
sbit en = P2^7;    

// Define the data port for the LCD
#define text P0    

// Function prototypes
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_write(unsigned char row, unsigned char col, unsigned char dat);
void lcd_clear();

#endif // LCD_H
