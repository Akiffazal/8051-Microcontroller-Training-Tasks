#include <reg51.h>
#include "lcd.h"
#include <stdio.h>

struct __time {                         // structure to represent time
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct __time current_time = {23, 59, 55, 31,12,2023};                                // Initial time aur date
unsigned int daysinmonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

char time_str[14]; 
char date_str[13]; 

unsigned int count = 0;
unsigned int dayinthismonth;

void update_lcd() {

	sprintf(time_str, "%02d:%02d:%02d", current_time.hour, current_time.minute,current_time.second); //initiall values formatted shwe
	sprintf(date_str, "%02d:%02d:%04d", current_time.day, current_time.month, current_time.year);
		
    lcd_set_cursor(0, 0);
	  lcd_write_string("Time: ");
    lcd_write_string(time_str);
	  lcd_set_cursor(1, 0);
		lcd_write_string("Date: ");
    lcd_write_string(date_str);
}

int is_leafyear(int year)
	{
	
		if(year % 4 == 0  && year % 100 == 0 || (year % 400 == 0))
		{
			return 1;
		}
		
		else {
			return 0;
		}
}


void int0_isr(void) interrupt 1
{
	count++;                                          // Increment ka counter

	if(count == 10){                                   
		
    current_time.second++;                            // Increment ka second
		  if (current_time.second >= 60){
				  current_time.second = 0;
				  current_time.minute++; 
				
				if (current_time.minute >= 60){
				   	current_time.minute = 0;
					  current_time.hour++;
				
				  if (current_time.hour >= 24){
					    current_time.hour = 0;
					    current_time.day++;
						
						  dayinthismonth = daysinmonth[current_time.month];           //da haree miyashtee wraze
						 
				      if (current_time.day > dayinthismonth){
					        current_time.day = 1;
					        current_time.month++;
							 
								 if (current_time.month > 12){
					           current_time.month = 1;
					           current_time.year++;									
							
										if (is_leafyear(current_time.year))
										{
											 daysinmonth[2] = 29;
										}
										else
										{
											daysinmonth[2] = 28;
										}					 
							}						
						}						
					}
				}
			}   

		  update_lcd();
			count = 0;
	}
   TF0 = 0;        // Clear Timer 0 interrupt flag
}

void timer_init()
{
    TMOD = 0x01;
    TH0 = 0xFF;               // 100ms delay 
    TL0 = 0x9C;
    TR0 = 1; 
	
  	ET0 = 1;
		EA = 1;
}


void main(){
    
    lcd_init();
	  lcd_write_string("RTC SOFTWARE");
	  delay_ms(1000);
		lcd_clear();
	
	  timer_init();

    while(1){

    }
}
