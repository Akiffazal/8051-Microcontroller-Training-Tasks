#include <reg51.h>
#include "LCD.h"

#include "servo motor.h"
#include "string.h"
#include "stdio.h"
sbit motor_pin =P2^0;

//sbit k1=P3^1;
//sbit k2=P3^0;
unsigned int servo_position=0;
unsigned int on_pulse, off_pulse;
float dutycycle;
unsigned char degree_symbol[8]= {0x06,0x09,0x06, 0x00, 0x00, 0x00, 0x00, 0x00};

void timerinterrupt () interrupt 1
{
	motor_pin = ~ motor_pin;
	if(motor_pin)
	{
		TH0= on_pulse >> 8;
		TL0= on_pulse ;
	}
	else
	{
		TH0= off_pulse >> 8 ;
		TL0= off_pulse;
	}
}





void timer_init()
{
	TMOD=0x01;
	TH0=0xB7;      //20 ms
	TL0=0xFD;
	TR0=1;
	EA=1;
	ET0=1;
	
}


void set_duty_cycle (float duty_cycle)
{
	unsigned int period;
	period = 65535 - 0xB7FD;
	on_pulse = ((period / 100.0)*duty_cycle);
	off_pulse = period - on_pulse ;
	
	on_pulse = 65535 - on_pulse;
	off_pulse = 65535- off_pulse;
	
}
void lcd_disp_num ( unsigned int number, unsigned int width)
{
	char buffer [8];
	sprintf (buffer , "%*d", width, number);
	lcd_string(buffer);
}
void lcd_custom_char(unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		lcd_command(0x40 +(loc*8));
		for(i=0; i<8; i++)
		{
			lcd_char(msg[i]);
		}
		lcd_command(0x80);
	}
}
void servo (unsigned int angle)
{
//	

				//timer_init();

//	while(1)
//	{
//		if(k1 == 0)
//		{
//			delay(200);
		
		if(angle<=180 && angle >= 0)
		{

			servo_position =angle;
			lcd_set_cursor(1,6);
			lcd_disp_num(servo_position,3);
			lcd_custom_char(1, degree_symbol);
			lcd_set_cursor(1, 9);
			lcd_char(1);
			delay(500);
			
		

		dutycycle=((servo_position + 45 )/180.0)*10;
		set_duty_cycle(dutycycle);
		delay(500);
 }
}