#include <reg52.h>
#include "cal.h"
#include "temperature.h"
#include "time.h" 
#include "btn.h" 
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
unsigned int ch2,r=0,state=0,KEY;
unsigned int y, a = 0, b = 0,u,kt=0,kl=0,k=0,ktx=0;
unsigned char operator, flag = 0;
sbit CE=P3^5;
sbit CLk=P3^6;
sbit io=P3^4;
sbit k1=P3^1;
char array[32];
char jj=0,ii=0,kk=0;
int clock_data[8];
void calcbody();
int r0w_scan();
void msdelay(unsigned char t);
void lcd_dat(unsigned char ch);
void send_num(unsigned int x);
void lcd_cmd(unsigned char ch);
void lcd_stringg(unsigned char *p);
void calculate();
unsigned char lcd;

void main()
{ 

	while(1)
	{ 
		r0w_scan();

switch(state) 
{
case 0:

    temppp();
   delay_18B20(10);
    break;
case 1:
        time1();
	   delay_18B20(5);
    break;
case 2:
	      
      calcbody();
      delay_18B20(5); 
    break;

case 3:  
	   kt=0;
     k=0;
    ktx=0;
    state=0;

    delay_18B20(50);





}}}	



//
int temp_byte[8];
int temp;
int x;
unsigned int i;
unsigned int jx;


unsigned char sec,min,hour,day,month,year;




 void SCLK_Pulse (void)
{
	CLk=1;
	CLk=0;
}
void Send_Bit (unsigned int value)
{
    if (value != 0){
        io=1;
		}
    else {
        io=0;
    }
}
 void WriteByte(int content)
{

    for (i=0;i<8;i++){
             x = (content & (1 << i));  //Write to Address
             Send_Bit(x);
             SCLK_Pulse();
        }
}

void Read_Burst (void)
{
    CE=1;
    WriteByte(ADR_RD_BURST);
    for (i=0;i<8;i++){
        temp = 0;
    for (jx=0;jx<8;jx++){
            temp >>= 1;
                if (io == 1){

                    temp |= 0x80;
                       }
                       else {

                    temp  &= 0x7F;
                       }

                SCLK_Pulse();
                }
    clock_data[i] = temp;
    }
    CE=0;
}


void write_data(char cmd,char value)
{
	CE=1;
	WriteByte(cmd);  //cmd
  WriteByte(value);  //data
	CE=0;
}


 
 
 
 
void time1() 
{ 
	k++;
if(k<2)
	{
  LCDInit();
	
	write_data(ADR_WR_CREG,0x00);
  
	write_data(ADR_WR_TCR,0xAB);


	


	TL1=0xFF;

	TR1 = 1;		/* Start timer 1 */
		

   lcd_DisplayString("Time: ");
   /* Display "date" on Second line*/
  lcd_GoToLineTwo();
  lcd_DisplayString("Date: ");
	}
  
   /* Display the time and date continously */ 
  
			if (jj>ii)
			{
				if(array[ii-1]== 0x5C && array[ii]== 'r' ){
						EA  = 0;
						ES = 0; 
					
					ii=0;jj=0;
				}
				ii++;
			}
			CE=1;
			Read_Burst();
			CE=0;

 
      lcd_GoToXY(0,6); 		 
			lcd_DisplayRtcTime(clock_data[2],clock_data[1],clock_data[0]);
			if((clock_data[2]&0x80)>0){
				if((clock_data[2]&0x20)>0)
					lcd_DisplayString(" P");
				else
					lcd_DisplayString(" A");
			}
			else
				lcd_DisplayString("  ");
			
			lcd_GoToXY(1,6); 		 
			lcd_DisplayRtcDate(clock_data[3],clock_data[4],clock_data[6]);
     
}





























//


void temppp()
{
		kt++;
if(kt<2){
  lcd_init();
	lcd_string("Temprature:");
	

}
	
	
body();
	}






















///
int r0w_scan()
{ 
	  
    //---r0W 1---//
    r0 = 0;
    r1 = r2 = r3 = 1;
    if(c0 == 0)
    {
        msdelay(32);
        while(c0 == 0)
        {
            lcd_dat('7');
            if(flag == 0)
                a = a*10 + 7;
            else
                b = b*10 + 7;
						return 7;
        }
    }
    if(c1 == 0)
    {
        msdelay(32);
        while(c1 == 0)
        {
            lcd_dat('8');
            if(flag == 0)
                a = a*10 + 8;
            else
                b = b*10 + 8;
        }
    }
    if(c2 == 0)
    {
        msdelay(32);
        while(c2 == 0)
        {
            lcd_dat('9');
            if(flag == 0)
                a = a*10 + 9;
            else
                b = b*10 + 9;
        }
    }
    if(c3 == 0)
    {
        msdelay(32);
        while(c3 == 0)
        {
            flag = 1;
            lcd_dat('/');
            operator = '/';
        }
    }

    //---r0W 2---//
    r1 = 0;
    r0 = r2 = r3 = 1;
    if(c0 == 0)
    {
        msdelay(32);
        while(c0 == 0)
        {
            lcd_dat('4');
            if(flag == 0)
                a = a*10 + 4;
            else
                b = b*10 + 4;
        }
    }
    if(c1 == 0)
    {
        msdelay(32);
        while(c1 == 0)
        {
            lcd_dat('5');
            if(flag == 0)
                a = a*10 + 5;
            else
                b = b*10 + 5;
        }
    }
    if(c2 == 0)
    {
        msdelay(32);
        while(c2 == 0)
        {
            lcd_dat('6');
            if(flag == 0)
                a = a*10 + 6;
            else
                b = b*10 + 6;
        }
    }
    if(c3 == 0)
    {
        msdelay(32);
        while(c3 == 0)
        {
            flag = 1;
            lcd_dat('x');
            operator = 'x';
        }
    }

    //---r0W 3---//
    r2 = 0;
    r1 = r0 = r3 = 1;
    if(c0 == 0)
    {
        msdelay(32);
        while(c0 == 0)
        {
            lcd_dat('1');
            if(flag == 0)
                a = a*10 + 1;
            else
                b = b*10 + 1;
        }
    }
    if(c1 == 0)
    {
        msdelay(32);
        while(c1 == 0)
        {
            lcd_dat('2');
            if(flag == 0)
                a = a*10 + 2;
            else
                b = b*10 + 2;
        }
    }
    if(c2 == 0)
    {
        msdelay(32);
        while(c2 == 0)
        {
            lcd_dat('3');
            if(flag == 0)
                a = a*10 + 3;
            else
                b = b*10 + 3;
        }
    }
    if(c3 == 0)
    {
        msdelay(32);
        while(c3 == 0)
        {
            flag = 1;
            lcd_dat('-');
            operator = '-';
				
        }
    }

    //---r0W 4---//
    r3 = 0;
    r1 = r2 = r0 = 1;
    if(c0 == 0)
    {
		
        msdelay(32);
        while(c0 == 0)
        {  
				   
            if(flag == 0)
                a = a*10 + 0;
            else
                b = b*10 + 0;
					state++;
					 
        }
    }
    if(c1 == 0)
    {
        msdelay(32);
        while(c1 == 0)
        {
            lcd_dat('0');
            if(flag == 0)
                a = a*10 + 0;
            else
                b = b*10 + 0;
					       
        }
    }
    if(c2 == 0)
    {
        msdelay(32);
        while(c2 == 0)
        {
            lcd_dat('=');
            calculate();
        }
    }
    if(c3 == 0)
    {
        msdelay(32);
        while(c3 == 0)
        {
            flag = 1;
            lcd_dat('+');
            operator = '+';
        }
    }
		return 0;
}




void calculate()
{
 
    if(operator == '+')
    {
        send_num(a + b);
    }

    if(operator == '-')
    {
        if(a > b)
            send_num(a - b);
        else
        {
            lcd_dat('-');
            send_num(b - a);
        }
    }

    if(operator == '/')
    {
        if(b != 0)
            send_num(a/b);
        else
        {
            lcd_cmd(0x01);
            lcd_stringg("NaN");
        }
    }

    if(operator == 'x')
    {
        send_num(a*b);
    }
}

void send_num(unsigned int x)
{
    if(x > 9999)
    {
        y = x/10000;
        lcd_dat(y + 0x30);
        x = x%10000;
        y = x/1000;
        lcd_dat(y + 0x30);
        x = x%1000;
        y = x/100;
        lcd_dat(y + 0x30);
        x = x%100;
        y = x/10;
        lcd_dat(y + 0x30);
        y = x%10;
        lcd_dat(y + 0x30);
    }
    else if(x > 999 && x < 9999)
    {
        y = x/1000;
        lcd_dat(y + 0x30);
        x = x%1000;
        y = x/100;
        lcd_dat(y + 0x30);
        x = x%100;
        y = x/10;
        lcd_dat(y + 0x30);
        y = x%10;
        lcd_dat(y + 0x30);
    }
    else if(x > 99 && x < 999)
    {
        y = x/100;
        lcd_dat(y + 0x30);
        x = x%100;
        y = x/10;
        lcd_dat(y + 0x30);
        y = x%10;
        lcd_dat(y + 0x30);
    }
    else if(x > 9 && x < 99)
    {
        y = x/10;
        lcd_dat(y + 0x30);
        y = x%10;
        lcd_dat(y + 0x30);
    }
    else
    {
        lcd_dat(x + 0x30);
    }
}

void lcd_initt()
{
		delay1(20);		/* LCD Power ON Initialization time >15ms */
	lcd_cmd (0x01);
	lcd_cmd (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	lcd_cmd (0x0E);	/* Display ON Cursor blinking */
	lcd_cmd (0x06);	/* Auto Increment cursor */
	lcd_cmd (0x01);	/* clear display */
	lcd_cmd (0x80);	/* cursor at home position */

}

// send commands

void lcd_cmd(unsigned char ch)
{
	lcd = ch;
	rs = 0;
	rw = 0;
	en = 1;
	msdelay(20);
	en = 0;
	
}

// send data

void lcd_dat(unsigned char ch)
{
	lcd = ch;
	rs = 1;
	rw = 0;
	en = 1;
	msdelay(40);
	en = 0;
}

// delay

void msdelay(unsigned char t)
{
	unsigned int i, j;
	for(i = 0; i < t; i++)
	for(j = 0; j < 1275; j++);
}
	
					 
					

void calcbody()
{ 	ktx++;

if(ktx<2){
	lcd_initt();
	lcd_string("SIM CALCULATOR ");
    lcd_cmd(0xC0);}
        r0w_scan();
}  



// send a string of data

void lcd_stringg(unsigned char *p)
{
	while(*p != '\0')
	{
		lcd_dat(*p);
		p++;
	}
}