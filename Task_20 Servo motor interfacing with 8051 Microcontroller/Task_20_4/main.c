#include <reg51.h>
#include "LCD.h"
#include "string.h"
#include "stdio.h"
sbit motor_pin =P2^0;

sbit k1=P3^1;
sbit k2=P3^0;
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
		TL0= off_pulse ;
	}
}


void timer_init()
{
	TMOD=0x01;
	TH0=0xB7;
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
void main ()
{
	lcd_init ();
	timer_init();
	lcd_set_cursor(0,1);
	lcd_string("Motor Angle");
	motor_pin=0;
	while(1)
	{
		if(k1 == 0)
		{
			delay(200);
		
		if(servo_position<180)
		{
			servo_position += 45;
			lcd_set_cursor(2,6);
			lcd_disp_num(servo_position,3);
			lcd_custom_char(1, degree_symbol);
			lcd_set_cursor(2, 9);
			lcd_char(1);
			delay(500);
			
		}
		while(k1==0);
		
	}
		if(k2==0)
		{
			delay(200);
			if(servo_position >0)
			{
				servo_position -=45;
				lcd_set_cursor(2,6);
				lcd_disp_num(servo_position, 3);
				lcd_custom_char(1, degree_symbol);
				lcd_set_cursor(2,9);
				lcd_char(1);
				delay(500);
				
			}
			while(k2==0);
		}
		dutycycle=((servo_position +45)/180.0)*10;
		set_duty_cycle(dutycycle);
		delay(500);
	}
}






//==================================================================================================================================================





















//#include <reg52.h>
//#include <intrins.h>

///* Define value to be loaded in timer for PWM period of 20 milli second */
//#define PWM_Period 0xB7FE

//sbit Servo_Motor_Pin = P2^0;

//unsigned int ON_Period, OFF_Period, DutyCycle;

///* Function to provide delay of 1ms at 11.0592 MHz */
//void delay(unsigned int count)
//{
//    int i,j;
//    for(i=0; i<count; i++)
//			for(j=0; j<112; j++);
//}

//void Timer_init()
//{
//	TMOD = 0x01;		/* Timer0 mode1 */
//	TH0 = (PWM_Period >> 8);/* 20ms timer value */
//	TL0 = PWM_Period;
//	TR0 = 1;		/* Start timer0 */
//}

///* Timer0 interrupt service routine (ISR) */
//void Timer0_ISR() interrupt 1	
//{
//	Servo_Motor_Pin = !Servo_Motor_Pin;
//	if(Servo_Motor_Pin)
//	{
//		TH0 = (ON_Period >> 8);
//		TL0 = ON_Period;
//	}	
//	else
//	{
//		TH0 = (OFF_Period >> 8);
//		TL0 = OFF_Period;
//	}	
//			
//}

///* Calculate ON & OFF period from duty cycle */
//void Set_DutyCycle_To(float duty_cycle)
//{
//	float period = 65535 - PWM_Period;
//	ON_Period = ((period/100.0) * duty_cycle);
//	OFF_Period = (period - ON_Period);	
//	ON_Period = 65535 - ON_Period;	
//	OFF_Period = 65535 - OFF_Period;
//}

//int main()
//{
//   EA  = 1;		/* Enable global interrupt */
//   ET0 = 1;         	/* Enable timer0 interrupt */
//   Timer_init();
//   while(1)
//    {
//	Set_DutyCycle_To(2.7);/* 0.54ms(2.7%) of 20ms(100%) period */
//	delay(1000);
//	Set_DutyCycle_To(7);/* 1.4ms(7%) of 20ms(100%) period */
//	delay(1000);
//	Set_DutyCycle_To(12);/* 2.4ms(12%) of 20ms(100%) period */
//	delay(1000);
//    }
//}
