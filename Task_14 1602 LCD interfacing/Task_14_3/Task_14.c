#include <reg51.h>
#include "header.h" // Include the header file

int main()
{
    unsigned int j;
    lcd_init();                         // Initialize the LCD
    while(1) {
        cmd(0x83);                      // Set cursor position to the beginning of the first line
        show("Welcome To ");            // Display the first line
        cmd(0xc4);                      // Set cursor position to the beginning of the second line
        show("Chip Soul");              // Display the second line
        lcd_delay();                    // Delay to keep the message on the screen
        cmd(0x01);                      // Clear the display
        lcd_delay();     // Delay before the next iteration
    }
}
