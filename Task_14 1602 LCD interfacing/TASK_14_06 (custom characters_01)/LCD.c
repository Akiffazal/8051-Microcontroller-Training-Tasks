#include "LCD.h"

// Custom character definitions
unsigned char battery[8] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00};
unsigned char tick[8] = {0x00, 0x01, 0x02, 0x14, 0x08, 0x00, 0x00, 0x00};
unsigned char cross[8] = {0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00};

// Function to initialize the LCD
void lcd_init() {
    cmd(0x38);          // Initialize the LCD in 8-bit mode, 2 lines, 5x7 matrix
    cmd(0x0e);          // Display ON, cursor ON
    cmd(0x01);          // Clear display screen
    cmd(0x06);          // Entry mode, auto increment with no shift
    cmd(0x0c);          // Display ON, cursor OFF
    cmd(0x80);          // Set cursor position to the beginning of the first line
    
    // Create custom characters
    create_custom_char(0, battery); // Create battery symbol at location 0
    create_custom_char(1, tick);    // Create tick symbol at location 1
    create_custom_char(2, cross);   // Create cross symbol at location 2
}

// Function to send a command to the LCD
void cmd(unsigned char a) {
    lcd_data = a;          // Send command to data port
    rs = 0;                // Select command register
    rw = 0;                // Write operation
    en = 1;                // Generate enable pulse
    lcd_delay();           // Wait for the command to be processed
    en = 0;                // End enable pulse
}

// Function to send data to the LCD
void dat(unsigned char b) {
    lcd_data = b;          // Send data to data port
    rs = 1;                // Select data register
    rw = 0;                // Write operation
    en = 1;                // Generate enable pulse
    lcd_delay();           // Wait for the data to be processed
    en = 0;                // End enable pulse
}

// Function to display a string on the LCD
void show(unsigned char *s) {
    while(*s) {   // Loop until the end of the string
        dat(*s++); // Send each character to the LCD
    }
}

// Delay function for LCD timing
void lcd_delay() {
    unsigned int lcd_delay;
    for(lcd_delay = 0; lcd_delay <= 20000; lcd_delay++); // Simple delay loop
}

// Function to create a custom character
void create_custom_char(unsigned char loc, unsigned char *charmap) {
    int i;
    if(loc < 8) { // We have only 8 locations (0-7) to store custom characters
        cmd(0x40 + (loc * 8)); // Command to set CGRAM address
        for(i = 0; i < 8; i++) {
            dat(charmap[i]); // Write character pattern to CGRAM
        }
    }
}

// Function to display a custom character
void display_custom_char(unsigned char loc) {
    if(loc < 8) {
        dat(loc); // Send location to display the custom character
    }
}
