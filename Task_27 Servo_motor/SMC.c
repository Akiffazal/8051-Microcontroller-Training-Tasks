#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "servo motor.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "intrins.h"
//unsigned int a,b,c;
unsigned int angle = 0;
extern char key;
int index=0;
char array[3];

void main()
{
	
	unsigned char loc = 6;
  lcd_init ();
	

			

	while(1)
	{
		
	lcd_set_cursor(0,1);
	lcd_string("Servo Motor ");

//	keypad();		
//	a=keypad();
//	b=keypad();
//	c=keypad();
//		angle=a*100+b*10+c;
	 lcd_set_cursor(1,loc);		
	 key=keypad();
	//while(key =='\0');

  if(key != '=' && key !='\0')
		{
		
		 lcd_set_cursor(1,loc);
		 lcd_char(key);			
		 array[index]=key;
     loc = loc + 1;
		 index++;
			key = '\0';
		}
	
	else if(key == '=')	{
	timer_init();

    array[index]= '\0';
		angle = atoi(array);
		servo(angle);
		loc = 6;	
		index = 0;
			key = '\0';

		}
		
//char array[3] = {"130"};        
// angle = atoi(array);
//  servo(angle);
 
		
	}
}


 