#include <stdio.h>
#include <reg51.h>


// Define the data port for the LCD
#define lcd_data P0

// Define control pins for the LCD
sbit rs = P2^6;  // Register select pin
sbit rw = P2^5;  // Read/Write pin
sbit en = P2^7;  // Enable pin


// Function prototypes
void lcd_init();           // Initialize the LCD
void cmd(unsigned char a); // Send command to the LCD
void dat(unsigned char b); // Send data to the LCD
void show(unsigned char *s); // Display a string on the LCD
void lcd_delay();         // Delay function for LCD


// Function to initialize the LCD
void lcd_init()
{
    cmd(0x38); // Initialize the LCD in 8-bit mode, 2 lines, 5x7 matrix
    cmd(0x0e); // Display ON, cursor ON
    cmd(0x01); // Clear display screen
    cmd(0x06); // Entry mode, auto increment with no shift
    cmd(0x0c); // Display ON, cursor OFF
    cmd(0x80); // Set cursor position to the beginning of the first line
}


// Function to send a command to the LCD
void cmd(unsigned char a)
{
    lcd_data = a; // Send command to data port
    rs = 0;       // Select command register
    rw = 0;       // Write operation
    en = 1;       // Generate enable pulse
    lcd_delay();  // Wait for the command to be processed
    en = 0;       // End enable pulse
}


// Function to send data to the LCD
void dat(unsigned char b)
{
    lcd_data = b; // Send data to data port
    rs = 1;       // Select data register
    rw = 0;       // Write operation
    en = 1;       // Generate enable pulse
    lcd_delay();  // Wait for the data to be processed
    en = 0;       // End enable pulse
}


// Function to display a string on the LCD
void show(unsigned char *s)
{
    while(*s) {   // Loop until the end of the string
        dat(*s++); // Send each character to the LCD
    }
}


// Delay function for LCD timing
void lcd_delay()
{
    unsigned int lcd_delay;
    for(lcd_delay = 0; lcd_delay <= 20000; lcd_delay++); // Simple delay loop
}

