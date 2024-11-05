#ifndef LCD_H__
#define LCD_H__

void Delay (unsigned int value);        
void LCD_Command (unsigned char cmd);
void LCD_Data (unsigned char Data);
void String_data (unsigned char *p);
void LCD_Intialization();
void Set_cursor(int row, int coloum);
void LCD_Clear();
int  LCD_Pow(int X,int Y) ;       
void LCD_ShowNum(unsigned char Line,unsigned char Column, int Number,unsigned char Length) ;
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char) ;  
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String) ; 
void LCD_ShowFloat(float num, int decimalPlaces) ;
#endif