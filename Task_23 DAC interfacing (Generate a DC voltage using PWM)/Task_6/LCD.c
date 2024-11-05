# include <reg52.h>
# include "LCD.h"
#include  "ADC.h" 

#define LCD_DATAPORT P0                          
sbit RW=P2^5;                                     
sbit RS=P2^6;                                     
sbit EN=P2^7;                                 

sbit DB4=P0^4;                               
sbit DB5=P0^5;
sbit DB6=P0^6;
sbit DB7=P0^7;

void Delay (unsigned int value)        
{
 unsigned int j;
	   
	for (j=0; j<value ;j++)
	{  
		
		TH1=0xFC;
		TL1=0x19;
		TF1=0;
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}

	

void LCD4_write ( unsigned char Value)
  {  
	
		
		DB4=0x10 & Value;                     
		DB5=0x20 & Value;              
		DB6=0x40 & Value;          
		DB7=0x80 & Value;            
		                 
		EN=1;                    
	  Delay(4);              
	  EN=0;                    
	 
	}
	

void LCD_Command (unsigned char cmd)
{ 
	RS=0;                          
	RW=0;                         
	LCD4_write(cmd & 0xF0);     
	LCD4_write( cmd <<4 );         
}


void LCD_Data (unsigned char Data)
{ 
	RS=1;                       
	RW=0;                         
	LCD4_write ( Data & 0xF0);
	LCD4_write (Data <<4 );
	
}


void String_data (unsigned char *p)                
{
  
	while(*p)                                     
	{
		LCD_Data(*p++);                               
	}

}

void LCD_Intialization(void)
{  
	                                         
	 Delay(100);
   LCD_Command(0x02);  
   LCD_Command(0x28);
   LCD_Command(0x0C);
   LCD_Command(0x01);  
   LCD_Command(0x80);  
}



 void Set_cursor(int row, int coloum)
 {      
	 if(row==1)                                       
	    { 	LCD_Command(0x80+coloum); }                  
			else if(row==2)                               
	    { 	LCD_Command(0xC0+coloum); }              
 
 
 }


 
 int lcd_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}




void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	Set_cursor(Line,Column);                    
	for(i=Length;i>0;i--)                       
	{
		LCD_Data(Number/lcd_Pow(10,i-1)%10+'0');   
	}
}


void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{
	Set_cursor(Line,Column);
	LCD_Data(Char);
}



void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	Set_cursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_Data(String[i]);
	}
}

void LCD_ShowFloat(float num, int decimalPlaces) 
{ 
	int intValue,factor,i,decimalInt,digit; 
	float decimalPart;
     
		
	  intValue = (int)num;
     decimalPart = num - intValue;

    // Display the integer part
    LCD_ShowNum(1, 12, intValue, 1);

    // Display the decimal point
    LCD_ShowChar(1, decimalPlaces+12 , '.');

    // Calculate the factor to convert decimal part to an integer
     factor = 1;
    for ( i = 0; i < decimalPlaces; i++) {
        factor *= 10;
    }

    // Convert the decimal part to an integer
     decimalInt = (int)(decimalPart * factor);

    // Display the decimal part
    for ( i = decimalPlaces; i > 0; i--) {
         digit = decimalInt % 10;
        LCD_ShowNum(1, decimalPlaces + 12+i , digit, 1);
        decimalInt /= 10;
    }
		
		
		
		
		
		
		
		
		
}