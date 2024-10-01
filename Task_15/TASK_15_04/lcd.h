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
void lcd_delay();
void show(unsigned char *s);
void show_char(unsigned char c); // Added this prototype
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_write(unsigned char row, unsigned char col, unsigned char dat);
void lcd_clear();

#endif // LCD_H







/*
Description:


It looks like you've shared a screenshot of code that includes both C files and a header file. Here's a quick breakdown of what each part of the code does:

1. **UART Initialization (`UART_Init` function in `task_4.c`)**:
   - Configures Timer 1 in 8-bit auto-reload mode to set the baud rate for UART communication.
   - Initializes the Serial Control (SCON) register to enable the receiver.
   - Starts Timer 1.

2. **UART Data Reception (`RX_data` function in `task_4.c`)**:
   - Waits until data is received over UART.
   - Clears the reception interrupt flag (RI).
   - Reads the received data from the Serial Buffer (SBUF) and returns it.

3. **Main Program (`main` function in `task_4.c`)**:
   - Initializes the LCD and UART.
   - Continuously receives data from UART and displays it on the LCD using the `show_char` function.
   - The commented-out code suggests it could have handled specific characters like '0' and '1' differently by moving the cursor or clearing the display.

4. **LCD Control (`lcd.c`)**:
   - Contains functions to control the LCD, including sending commands (`lcd_cmd`), displaying characters (`show_char`), and initializing the LCD (`lcd_init`).
   - The `lcd_delay` function provides a delay to ensure proper timing between commands.

5. **Header File (`lcd.h`)**:
   - Defines the necessary pins and ports for controlling the LCD.
   - Contains function prototypes for LCD operations.

This code seems to be for a microcontroller (likely an 8051-based microcontroller), where it initializes UART for serial communication and an LCD to display received characters.
*/