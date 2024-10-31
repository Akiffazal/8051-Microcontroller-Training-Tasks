#include <reg51.h>
#include "eeprom.h"
#include "LCD.h"
#include "KEYPAD.h"

#define generate_password 0
#define enter_password 1
#define wrong_password 2
#define new_password 3

unsigned char gent_password[6];
unsigned char j=0,value,i=0;
unsigned char data_read,second=10,Flag=0,Flag1=0;
unsigned char password[6];
unsigned char EEPROM_password,user_pin;
unsigned char old_pin,key;
unsigned char user_password[6];
unsigned char EEPROM[6];
unsigned char EEPROM_Pass;
unsigned char old_password[6];



unsigned int on_period , off_period;
sbit servomotor_pin = P2^0;


void timer_init ()
{
	TMOD=0x01;
	TH0=0xB7;
	TL0=0xFE;
	TR0=1;
	EA=1;
	ET0=1;
	
}
void timer0 () interrupt 1
{
	servomotor_pin = ~servomotor_pin;
	if(servomotor_pin)
	{
		TH0= on_period >> 8;
		TL0= on_period ;
	}
	else
	{
		TH0= off_period >> 8;
		TL0= off_period ;
	}
}
void set_duty_cycle (float angle)
{
	float duty_cycle ;
	unsigned int period ;
	duty_cycle= (angle / 180.0) * 10.0;
	period = 65535-0xB7FE;
	on_period=(unsigned int)((period/100.0)*duty_cycle);
	off_period=period- on_period;
	on_period=65535- on_period;
	off_period=65535- off_period;
}

void randompassword()
{
	gent_password[j]= keypad();
	EEPROM_write(j,gent_password[j]);
	lcd_showchar(1,j,gent_password[j]);
	
}




void main (void)
{
	unsigned char current_state;
	lcd_init();
	timer_init();
	current_state = generate_password;
	while(1)
	{
		switch(current_state)
		{
			case generate_password :
			value = EEPROM_read (212);	
			if(value==0xFF)
			{
				lcd_showstring(0,0,"Generate Pin");
				if(j<6)
				{
					randompassword();
					j++;
				}
				else
				{
					EEPROM_write (212,0xAA);
					j=0;
					current_state=enter_password;
				  Timmer_Delay(3000);
				}
			}
			else
			{
				current_state= enter_password;
			}


			break;
			
			
			case enter_password :
				lcd_clear();
			  data_read =EEPROM_read (254);
			if(data_read!= 6)
			{
				for(i=0; i<6; i++)
				{
					password[i]=EEPROM_read (i);
				}
				EEPROM_password= (password[5]*100000)+(password[4]*10000)+(password[3]*1000)+(password[2]*100)+(password[1]*10)+(password[0]);
				lcd_showstring(0,0, "Enter Password");
				for(i=0; i<6; i++)
				{
					key=keypad ();
					if(key=='c')
					{
						current_state= new_password;
						break;
					}
					else
					{
						user_password[i]=key;
					}
					lcd_showchar(1,i ,user_password[i]);
				
				}
				Delay1(2000);
				user_pin=(user_password[5]*100000)+(user_password[4]*10000)+(user_password[3]*1000)+(user_password[2]*100)+(user_password[1]*10)+(user_password[0]);
				if(current_state==new_password)
				{
					break;
				}
				if(EEPROM_password==user_pin)
				{
					lcd_clear();
					lcd_showstring(0,0,"Door Unlock");
					Beep(5);
					Delay1(1000);
					set_duty_cycle(0.0);
					Delay1(500);
					
					for(i=0; i<10; i++)
					{
						second--;
						lcd_shownum(1,6,second,1);
						Timmer_Delay(160);
					}
					
					
					Beep(5);
					lcd_clear();
					lcd_showstring(0,0,"Door Lock");
					
					set_duty_cycle(180.0);
					Delay1(2000);
					
					lcd_clear();
					Flag=0;
					second=10;
					current_state=enter_password;
				}
				else
				{
					current_state= wrong_password;
				}
			}
			else
			{
				lcd_showstring(0,0,"System Disabled");
				Beep(5000);
			}
			break;
			
			case wrong_password :
				if(Flag<5)
				{
					lcd_clear();
					lcd_showstring(0,0,"Wrong Password");
					lcd_shownum(1,5,Flag,1);
					Beep(10);
					Flag++;
					current_state= enter_password;
				}
				else
				{
					EEPROM_write (250, 6);
					lcd_clear();
					lcd_showstring(0,0,"System Disabled");
					Beep(5000);
					
				}
				break;
				
				
			case new_password :
				  lcd_clear();
			lcd_showstring(0,0,"Enter Old Pin");
			for(i=0; i<6; i++)
			{
				EEPROM[i]=EEPROM_read(i);
			}
			EEPROM_Pass=(EEPROM[5]*100000)+(EEPROM[4]*10000)+(EEPROM[3]*1000)+(EEPROM[2]*100)+(EEPROM[1]*10)+(EEPROM[0]);
			for(i=0; i<6; i++)
			{
				old_password[i]= keypad();
				lcd_showchar(1,i,old_password[i]);
			}
				Delay1(2000);
			old_pin=(old_password[5]*100000)+(old_password[4]*10000)+(old_password[3]*1000)+(old_password[2]*100)+(old_password[1]*10)+(old_password[0]);
			
			if(	old_pin==EEPROM_Pass)
			{
				EEPROM_write (212, 0xFF);
				lcd_clear();
				current_state=generate_password;
				break;
			}
			else
			{
				if(Flag <3)
				{
					lcd_clear();
					lcd_showstring(0,0,"Wrong Password");
					lcd_shownum(1,5,Flag1,1);
					Beep(10);
					Flag1++;
					current_state = new_password;
				}
				else
				{
					EEPROM_write (250, 6);
					lcd_clear();
					lcd_showstring(0,0,"System Disable");
					Beep(5000);
				}
			}
			break;
		}
	}
}









