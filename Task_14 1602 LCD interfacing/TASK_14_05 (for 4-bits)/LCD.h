#ifndef LCD_H
#define LCD_H

#include <reg51.h> 

sbit rs = P2^6;    // RS pin is connected to bit 6 of port 2
sbit rw = P2^5;    // RW pin is connected to bit 5 of port 2
sbit en = P2^7;    // EN pin is connected to bit 7 of port 2

// Define the data port for the LCD
#define text P0    // Data port is connected to port 0

// Function prototypes
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_write(unsigned char row, unsigned char col, unsigned char dat);
void lcd_clear();

#endif // LCD_H
