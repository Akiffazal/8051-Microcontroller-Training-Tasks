#ifndef HEADER_H
#define HEADER_H

// Function prototypes
void lcd_init();           // Initialize the LCD
void cmd(unsigned char a); // Send command to the LCD
void dat(unsigned char b); // Send data to the LCD
void show(unsigned char *s); // Display a string on the LCD
void lcd_delay();         // Delay function for LCD

#endif



