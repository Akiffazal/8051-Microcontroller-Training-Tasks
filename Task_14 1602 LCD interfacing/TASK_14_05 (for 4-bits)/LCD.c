#include "LCD.h"

// Delay function to create a short delay
void delay() {
    int i, j;
    for(i = 0; i < 50; i++) {        
        for (j = 0; j < 70; j++);     
    }
}

// Define lcd_delay function to create a delay for LCD timing
void lcd_delay() {
    delay();                          // Call the delay function
}

// Function to send a nibble (4 bits) to the LCD
void lcd_send_nibble(unsigned char nibble) {
    text = (nibble & 0xF0);           // Send the higher nibble to the data port
    en = 1;                           // Generate a high-to-low pulse on the enable pin
    lcd_delay();                      // Wait for the nibble to be processed
    en = 0;                           // End the enable pulse
}

// Function to send a command to the LCD
void lcd_cmd(unsigned char cmd) {
    rs = 0;                           // Select command register (RS=0)
    rw = 0;                           // Select write operation (RW=0)
    lcd_send_nibble(cmd);             // Send the higher nibble
    lcd_send_nibble(cmd << 4);        // Send the lower nibble
}

// Function to send data to the LCD
void lcd_data(unsigned char dat) {
    rs = 1;                          // Select data register (RS=1)
    rw = 0;                          // Select write operation (RW=0)
    lcd_send_nibble(dat);            // Send the higher nibble
    lcd_send_nibble(dat << 4);       // Send the lower nibble
}

// Function to initialize the LCD
void lcd_init() {
    lcd_cmd(0x28);                  // Set LCD to 4-bit mode, 2 lines, 5x7 matrix
    lcd_delay();                    // Wait for the command to be processed
    lcd_cmd(0x0C);                  // Display ON, cursor OFF
    lcd_delay();                    // Wait for the command to be processed
    lcd_cmd(0x06);                  // Entry mode, auto increment with no shift
    lcd_delay();                    // Wait for the command to be processed
    lcd_cmd(0x01);                  // Clear the display
    lcd_delay();                    // Wait for the command to be processed
}

// Function to set the cursor position
void lcd_set_cursor(unsigned char row, unsigned char col) {
    unsigned char pos;
    if (row == 0)
        pos = 0x80 + col;          // Set cursor position for the first line
    else if (row == 1)
        pos = 0xC0 + col;          // Set cursor position for the second line
    lcd_cmd(pos);                  // Send command to set the cursor position
}

// Function to write data at a specific position
void lcd_write(unsigned char row, unsigned char col, unsigned char dat) {
    lcd_set_cursor(row, col);     // Set cursor to specified position
    lcd_data(dat);                // Write data at that position
}

// Function to clear the display
void lcd_clear() {
    lcd_cmd(0x01);               // Clear display screen
    lcd_delay();                 // Wait for the command to be processed
}
