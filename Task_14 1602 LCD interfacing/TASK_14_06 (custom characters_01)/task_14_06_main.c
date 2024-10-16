#include "LCD.h"

int main() {
  
		while(1){	
		lcd_init();               // Initialize the LCD

    // Display custom characters
    cmd(0x80);                // Set cursor position to the beginning of the first line
    show("Battery: ");
    display_custom_char(0);   // Display the battery symbol
    
    cmd(0xc0);                // Set cursor position to the beginning of the second line
    show("Tick: ");
    display_custom_char(1);   // Display the tick symbol
    show(" Cross: ");
    display_custom_char(2);   // Display the cross symbol
			
    return 0;
		}
}
