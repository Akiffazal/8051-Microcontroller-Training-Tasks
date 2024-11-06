#include <reg51.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "stdio.h"


sbit Door_switch =P2^0;
bit flag=1;
int minute,second,i,min,sec;
char input[4];
unsigned char key,key1;
char formattime[6];


typedef enum 
{
	Time_enter_state,
	Door_status_state,
	Run_counter_state
}
State;
State current_state=Time_enter_state;

void main (void)
{
	lcd_init();
	lcd_showstring (0,0,"Oven Control");
	Delay1(200);
	while(1)
	{
		switch(current_state)
		{
			case Time_enter_state:
			
       lcd_showstring(1,0,"TimeEnter");
       Delay1(200);
			 lcd_showstring(1,10,"00:00");
       		if(flag)
					{
						for(i=0; i<4; i++)
						{
							input[i]='0';
						}
						for(i=0; i<4; i++)
						{
							key=keypad();
							if(key >='0' && key <='9')
							{
								input[3] = input[2];
								input[2] = input[1];
								input[1] = input[0];
								
								input[0]=key;
								
								lcd_showchar(1,10,input[3]);
								lcd_showchar(1,11,input[2]);
								lcd_showstring(1,12,":");
								lcd_showchar(1,13,input[1]);
								lcd_showchar(1,14,input[0]);
							}
						}
						minute=(input[3] - '0') * 10 + (input[2] - '0');
						second=(input[1] - '0') * 10 + (input[0] - '0');
						
						sprintf (formattime, "%02d:%02d",minute,second);
						lcd_showstring(1,10,formattime);
						flag = 0;
						if(input[0] !='0' || input[1] != '0' || input[2] != '0'  || input[3] != '0')
						{
							current_state=Door_status_state;
						}
							
					}
         else
					 {
						 current_state=Door_status_state;
				 }
break;
			case Door_status_state:
      key1=keypad();
      if(key1 == 'C')
				{
					if(Door_switch == 0)
					{
						lcd_clear_secondline();
						lcd_showstring(1,0,"Open Door");
						Delay1(1000);
						Beep(10);
					}
					else
					{
						lcd_clear_secondline();
						lcd_showstring(1,0,"Close Door");
						Delay1(3000);
						lcd_clear_secondline();
						Delay1(1000);
						current_state=Run_counter_state;
						Delay1(1000);
					}
			}	
         else if(key1 == '=')
					 {
						 flag=1;
						 Delay1(250);
						 current_state = Time_enter_state;
						 Delay1(100);
				 }
break;
      case Run_counter_state:
        sec=second;
       min=minute;
      
       if(  min<59 && sec<59)
			 {
				 while(1)
				 {
					 while(Door_switch == 0)
					 {
						 lcd_showstring(1,0, "Open Door");
						 Beep(10);
						 while(keypad() != 'C');
						 
							 lcd_showstring(1,0,"Close Door");
							 Delay1(3000);
							 lcd_clearline(9);
						 }
						 sec--;
						 if(sec < 0)
						 {
							 sec = 59;
							 min--;
						 }
						 if(min < 0)
						 {
							 min=0;
							 sec=0;
							 
						 }
						  Timmer_Delay(160);
						 lcd_shownum(1,10,min,2);
						 lcd_showstring(1,12,":");
						 lcd_shownum(1,13,sec,2);
						 
						 if(keypad2() == 'C')
						 {
							 while(keypad() != 'C')
							 {
								 Delay1(500);
								 if(keypad2() == '=')
								 {
									 flag=1;
									 current_state= Time_enter_state;
									 break;
								 }
							 }
							 if(flag)
							 {
								 break;
							 }
						 }
						 if(min == 0 && sec == 0)
						 {
							 flag=1;
							 current_state=Time_enter_state;
							 break;
						 }
					 }
				 }
			 else
			 {
				 lcd_clear_secondline();
				 Delay1(100);
				 lcd_showstring(1,0,"invalid format");
				 Beep(10);
				 Delay1(25000);
				 lcd_clear_secondline();
				 flag=1;
				 current_state=Time_enter_state;
			 }
			 break;
			 }
			 
		}
	}









