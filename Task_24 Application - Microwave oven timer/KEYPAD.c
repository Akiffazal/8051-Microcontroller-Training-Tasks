#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"



unsigned char counter =0;

sbit C4=P1^0;
sbit C3=P1^1;
sbit C2=P1^2;
sbit C1=P1^3;
sbit R4=P1^4;
sbit R3=P1^5;
sbit R2=P1^6;
sbit R1=P1^7;
//char key  = '\0' ;
void Beep (unsigned int duration)
{
	//To convert passive Buzzer into Active Buzzer we Generate Crystal frequency through coding.
	unsigned char i,j,k;
	for(k=0; k<=duration; k++)
	{
		for(i=0; i<250; i++)
		{
			R3=0;
			for(j=0; j<50; j++);
			R3=1;
			for(j=0; j<50; j++);
		}
		 Delay1(500);
	}
}
char keypad ()
{
	 while(1)     
	{
	R1=0; R2=1; R3=1; R4=1;            //Ground Row 1,and check coloum
	     if(C1==0)                                         //Ground coloum 1 ,if this button press
			 {  Delay1(2000);
				 while(C1==0)
				   { Beep(1);  return '7';}
			     
			 }  
	      
			 if(C2==0)                                      
			 {     Delay1(2000);
    				 while(C2==0)
			       { Beep(1);return '8';}  
			 }       
			  
			 if(C3==0)
			 {   Delay1(2000); while(C3==0)
			    { Beep(1);return '9';}  
			 }
			 
			 if(C4==0)
			 {    Delay1(2000);
			    while(C4==0)
			    { Beep(1);return '/';} 
			 
			 }
	 
  R1=1; R2=0; R3=1; R4=1;                             //Ground Row 2,and check coloum 
	     if(C1==0)                                      //Ground coloum 1 ,if this button press
			 {   Delay1(2000);
           while(C1==0)
			    { Beep(1);return '4';} 


			 }  //return the Value4, Delay is used for Debouning, while(C1==0) is used that button is detected only once;
	      if(C2==0)
			 {  Delay1(2000);
           while(C2==0)
			    { Beep(1);return '5';} 
			 }
			  if(C3==0)
			 {  Delay1(2000);
         while(C3==0)
			    { Beep(1);return '6';} 

			 }
			  if(C4==0)
			 {  Delay1(2000);
				 while(C4==0)
			    { Beep(1);return '*';}   }
			 
  R1=1; R2=1; R3=0; R4=1;                               //Ground Row 3,and check coloum
	     if(C1==0)
			 {  Delay1(2000);
         while(C1==0)
			    { Beep(1);return '1';} 

			 } 
	      if(C2==0)
			 {  Delay1(2000);
				 while(C2==0)
			    { Beep(1);return '2';} 
			 }
			  if(C3==0)
			 {  Delay1(2000);
				 while(C3==0)
			    { Beep(1);return '3';}   
			 }
			  if(C4==0)
			 {  Delay1(2000);
				 while(C4==0)
			    { Beep(1);return '-';}   }
			 
			 
	R1=1; R2=1; R3=1; R4=0;                               //Ground Row 4,and check coloum
	     if(C1==0)
			 {   Delay1(2000);
				 while (C1 == 0 ) 
				 { Beep(1);  
            return 'C';  
				 }
				
			 } 
			 
			 
	      if(C2==0)
			 {  
				 Delay1(2000);
				 while(C2==0)
			    { Beep(1);return '0';}  
			 
		   }  
			  if(C3==0)
			 {  Delay1(2000);
				  while(C3==0)
			    { Beep(1);return '=';}  
			 }
			  if(C4==0)
			 {   Delay1(2000);
				   while(C4==0)
			    { Beep(1);return '+';} 
			 }
	 
	 R4=1;
			 
		 }
}
char keypad2 ()
{
	R1=1; R2=1; R3=1; R4=0;
	if(C1==0)
	{
		Delay1(2000);
		while(C1==0)
		{
			Beep(1); return 'C';
		}
	}
	if(C3==0)
	{
		Delay1(2000);
		while(C3==0)
		{
			Beep(1); return '=';
		}
	}
	R4=1;
}

//void main ()
//{
//	
//	 lcd_init();

//	while(1)
//	{
////		lcd_command(0x80);
////		lcd_string("ENTER THE KEY");
////	lcd_set_cursor(1, 0);
//	keypad();
//	

//	}
//}


