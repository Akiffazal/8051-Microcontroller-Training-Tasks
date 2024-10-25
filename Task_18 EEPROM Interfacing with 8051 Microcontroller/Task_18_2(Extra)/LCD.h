#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_command(unsigned char cmd);
void lcd_char(unsigned char dat);
void lcd_string(unsigned char *str);
void delay (unsigned int);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_display(unsigned char number);
void lcd_display_long(unsigned long num);
void lcd_clear();


#endif





//#ifndef __LCD_H
//#define __LCD_H

////*******************
////Pin description
///*
//P2.4 to P2.7 is data bus
//P1.0 is RS
//P1.1 is E
//*/
////********************

//// Defines Pins
//sbit RS = P2^6;
//sbit E  = P2^7;

//// Constants
//#define E_Delay       250       

//// Function Declarations
//void InitLCD(void);
//void WriteCommandToLCD(int);
//void WriteDataToLCD(char);

//#endif