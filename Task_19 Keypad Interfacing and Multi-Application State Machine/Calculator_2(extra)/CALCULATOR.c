#include <reg51.h>
#include "LCD.h"
#include "CALCULATOR.h"

unsigned int y , a=0; b=0;
unsigned char operator ,flag =0;

sbit r1 =P1^7;
sbit r2 =P1^6;
sbit r3 =P1^5;
sbit r4 =P1^4;
sbit c1 =P1^3;
sbit c2 =P1^2;
sbit c3 =P1^1;
sbit c4 =P1^0;

void row ()
{
	r1=0;r2=1;r3=1;r4=1;     //FOR ROW 1
	if(c1==0)
	{
		delay(30);
		while(c1==0)
		{
			lcd_char('7');
			if(flag==0)
			{
				a =a*10 +7;
			}
			else
			{
				b=b*10+7;
			}
		}
	}
	
	
	
  if(c2==0)
	{
		delay(30);
		while(c2==0)
		{
			lcd_char('8');
			if(flag==0)
			{
				a=a*10 +8;
			}
			else
			{
				b=b*10 +8;
			}
		}
	}		
	
	if(c3==0)
	{
		delay(30);
		while(c3==0)
		{
		lcd_char ('9');
			if(flag==0)
			{
				a=a*10 +9;
			}
			else
			{
				b=b*10 +9;
			}
		}			
	}
	
	
	if(c4==0)
	{
		delay(30);
		while(c4==0)
		{
		lcd_char ('/');
			flag=1;
			operator='/';
		}			
	}
	
	r1=1;r2=0;r3=1;r4=1;    //FOR ROW 2
	
	if(c1==0)
	{
		delay(30);
		while(c1==0)
		{
			lcd_char('4');
			if(flag==0)
			{
				a=a*10 +4;
			}
			else
			{
				b=b*10 +4;
			}
		}
	}
	
	
	if(c2==0)
	{
		delay(30);
		while(c2==0)
		{
			lcd_char('5');
			if(flag==0)
			{
				a=a*10 +5;
			}
			else
			{
				b=b*10 +5;
			}
		}
	}
	
	if(c3==0)
	{
		delay(30);
		while(c3==0)
		{
			lcd_char('6');
			if(flag==0)
			{
				a=a*10 +6;
			}
			else
			{
				b=b*10 +6;
			}
		}
	}
	
	if(c4==0)
	{
		delay(30);
		while(c4==0)
		{
			lcd_char('X');
			flag=1;
			operator='X';
		}
	}
	
	r1=1;r2=1;r3=0;r4=1; //for row 3
	if(c1==0)
	{
		delay(30);
		while(c1==0)
		{
			lcd_char('1');
			if(flag==0)
			{
				a=a*10 +1;
			}
			else
			{
				b=b*10 +1;
			}
		}
	}
	
	if(c2==0)
	{
		delay(30);
		while(c2==0)
		{
			lcd_char('2');
			if(flag==0)
			{
				a=a*10 +2;
			}
			else
			{
				b=b*10 +2;
			}
		}
	}
	
	if(c3==0)
	{
		delay(30);
		while(c3==0)
		{
			lcd_char('3');
			if(flag==0)
			{
				a=a*10 +3;
			}
			else
			{
				b=b*10 +3;
			}
		}
	}
	
	if(c4==0)
	{
		delay(30);
		while(c4==0)
		{
			lcd_char('-');
		flag=1;
			operator='-';
			
		}
	}
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		delay(30);
		while(c1==0)
		{
			lcd_command(0x01);
			flag= a=b= 0;
			
		}
	}
	if(c2==0)
	{
		delay(30);
		while(c2==0)
		{
			lcd_char('0');
			if(flag==0)
			{
				a=a*10 +0;
			}
			else
			{
				b=b*10 +0;
			}
		}
	}
	
	if(c3==0)
	{
		delay(30);
		while(c3==0)
		{
			lcd_char('=');
			flag=1;
			calculate();
				
		
		}
	}
	if(c4==0)
	{
		delay(30);
		while(c4==0)
		{
			lcd_char('+');
			flag=1;
			operator='+';
		}
	}
	
}

void calculate ()
{
	lcd_command(0xC0);
	if(operator=='+')
	{
		send_data(a+b);
	}
	if(operator=='-')
	{
		if(a>b)
		{
			send_data(a - b);
		}
		else if(a==b)
		{
			send_data(a-b);
		}
		else
		{
			lcd_char('-');
			send_data(b - a);
		}
	}
	if(operator=='/')
	{
		if(b != 0)
		{
			send_data(a/b);
		}
		else
		{
			lcd_command(0x01);
			lcd_string("ERROR");
		}
	}
	if(operator=='X')
	{
		send_data(a*b);
	}
}

void  send_data (unsigned int x)
{
	
	if(x>9999)
	{
		y=x/10000;
		lcd_char(y+0x30);
		x=x%10000;
		y=x/1000;
		lcd_char(y+0x30);
		x=x%1000;
		y=x/100;
		lcd_char(y+0x30);
		x=x%100;
		y=x/10;
		lcd_char(y+0x30);
		y=x%10;
		lcd_char(y+0x30);
	}
	else if(x>999 && x<9999)
	{
		y=x/1000;
		lcd_char(y+0x30);
		x=x%1000;
		y=x/100;
		lcd_char(y+0x30);
		x=x%100;
		y=x/10;
		lcd_char(y+0x30);
	  y=x%10;
		lcd_char(y+0x30);
	}
	else if(x>99 && x<999)
	{
		y=x/100;
		lcd_char(y+0x30);
		x=x%100;
		y=x/10;
		lcd_char(y+0x30);
		y=x%10;
		lcd_char(y+0x30);
	}
	else if(x>9 && x<99)
	{
		y=x/10;
		lcd_char(y+0x30);
		y=x%10;
		lcd_char(y+0x30);
	}
	else
	{
		lcd_char(x+0x30);
	}
}


void main ()
{
	lcd_init();
	lcd_command(0x80);
	lcd_string("Simple");
	lcd_command(0xC0);
	lcd_string("Calculator");
	delay(150);
	lcd_command(0x01);
	while(1)
	{
		lcd_command(0x80);
	  lcd_string("MAKE OPEARTION");
		lcd_command(0xC0);
		row();
	}
}

	


