#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_command(unsigned char cmd);
void lcd_char(unsigned char dat);
void lcd_string(unsigned char *str);
void delay (unsigned int);
void lcd_display(unsigned char number);
void delay (unsigned int time);


#endif