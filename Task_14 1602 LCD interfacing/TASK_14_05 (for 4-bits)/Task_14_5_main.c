#include <reg51.h> 
#include "LCD.h" // Include the LCD header file

int main() {
    
		while(1){
		lcd_init();    // Initialize the LCD
    lcd_clear(); // Clear the LCD

    // Example usage
    lcd_write(0, 0, 'A');
    lcd_write(0, 1, 'K');
    lcd_write(0, 2, 'I');
    lcd_write(0, 3, 'F');
			
			
    lcd_set_cursor(1, 0);  // Set cursor to the beginning of the second line
    lcd_write(1, 0, 'W');  // Write 'W' at the beginning of the second line
    lcd_write(1, 1, 'o');  // Write 'o' at the second position of the second line
    lcd_write(1, 2, 'r');  // Write 'r' at the third position of the second line
    lcd_write(1, 3, 'l');  // Write 'l' at the fourth position of the second line
    lcd_write(1, 4, 'd');  // Write 'd' at the fifth position of the second line


    return 0;
		}
}