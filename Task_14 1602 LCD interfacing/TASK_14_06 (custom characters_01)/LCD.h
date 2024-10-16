#ifndef LCD_H
#define LCD_H

#include <reg51.h>

// Define the data port for the LCD
#define lcd_data P0

// Define control pins for the LCD
sbit rs = P2^6;  // Register select pin
sbit rw = P2^5;  // Read/Write pin
sbit en = P2^7;  // Enable pin

// Function prototypes
void lcd_init();             // Initialize the LCD
void cmd(unsigned char a);   // Send command to the LCD
void dat(unsigned char b);   // Send data to the LCD
void show(unsigned char *s); // Display a string on the LCD
void lcd_delay();            // Delay function for LCD
void create_custom_char(unsigned char loc, unsigned char *charmap); // Create custom character
void display_custom_char(unsigned char loc); // Display custom character

#endif // LCD_H
