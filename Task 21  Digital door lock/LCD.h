#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_command(unsigned char cmd);
void lcd_char(unsigned char dat);
void lcd_string(unsigned char *str);
void delay (unsigned int);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_display(unsigned char number);
void  Timmer_Delay (unsigned char k);
void Delay1 (unsigned int value1);
void lcd_clear();
int lcd_pow (int X, int Y);
void lcd_shownum(unsigned char line, unsigned char column, int number, unsigned char length);
void lcd_showchar(unsigned char line, unsigned char column, char Char);
void lcd_showstring(unsigned char line, unsigned char column, char *string);


#endif