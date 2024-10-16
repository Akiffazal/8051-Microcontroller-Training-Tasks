#include <reg51.h>
#include "LCD.h"

int main() 
	{
    while(1){
		lcd_init();    // Initialize the LCD
		lcd_clear(); // Clear the LCD
	
    lcd_write(0, 0, 'H');  // Write 'H' at the beginning of the first line
    lcd_write(0, 1, 'e');  // Write 'e' at the second position of the first line
    lcd_write(0, 2, 'l');  // Write 'l' at the third position of the first line
    lcd_write(0, 3, 'l');  // Write 'l' at the fourth position of the first line
    lcd_write(0, 4, 'o');  // Write 'o' at the fifth position of the first line

		//    lcd_set_cursor(1, 0);  // Set cursor to the beginning of the second line
    lcd_write(1, 0, 'W');  // Write 'W' at the beginning of the second line
    lcd_write(1, 1, 'o');  // Write 'o' at the second position of the second line
    lcd_write(1, 2, 'r');  // Write 'r' at the third position of the second line
    lcd_write(1, 3, 'l');  // Write 'l' at the fourth position of the second line
    lcd_write(1, 4, 'd');  // Write 'd' at the fifth position of the second line

		//    while(1); // Infinite loop to keep the microcontroller running
			}
}

















///////*Method_01*/
//////#include <reg51.h>

//////sbit wr = P2^5;
//////sbit rs = P2^6;
//////sbit en = P2^7;

//////#define text P0

//////void delay_ms() {
//////    int i, j;
//////    for(i = 0; i < 100; i++) {
//////        for (j = 0; j < 100; j++);
//////    }
//////}

//////void lcd_delay() {
//////    delay_ms();
//////}

//////void lcd_cmd(unsigned char a){
//////	text = a;
//////	rs = 0; 
//////	wr = 0; 
//////	en = 1;
//////	lcd_delay();
//////	en = 0;
//////}

//////void lcd_data(unsigned char b){
//////	text = b;
//////	rs = 1; 
//////	wr = 0;
//////	en = 1;
//////	lcd_delay();
//////	en = 0;
//////}

//////void lcd_init() {
//////		lcd_cmd(0x01); 
//////    delay_ms();    
//////    lcd_cmd(0x38);
//////    delay_ms();      
//////    lcd_cmd(0x0E); 
//////    delay_ms();     
//////    lcd_cmd(0x10); 
//////    delay_ms();      
//////    lcd_cmd(0x80);
//////    delay_ms();
//////}

//////int main() {
//////  text = 0x00;  
//////    lcd_init();  
//////    
//////    lcd_data('Z');
//////    delay_ms(); 

//////    lcd_data('U');
//////    delay_ms();

//////    lcd_data('N');
//////    delay_ms();     

//////    lcd_data('0');
//////    delay_ms();

//////    lcd_data('R');
//////    delay_ms();

//////    lcd_data('A');
//////    delay_ms();      

//////    lcd_data('I');
//////    delay_ms();  

//////    lcd_data('N');
//////    delay_ms();  
//////    
////////    lcd_data('I');
////////    delay_ms();   
////////    
////////    lcd_data('N');
////////    delay_ms();
//////    
//////    return 0;
//////}







//-------------------------------------------------------------------------------------------------------------------------------

