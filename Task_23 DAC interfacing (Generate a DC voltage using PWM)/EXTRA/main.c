#include <reg51.h>
#include "LCD.h"
#include "ADC.h"

sbit PWM_PIN= P2^1;
unsigned int  ON_Period, OFF_Period;
unsigned int DutyCycle;



sbit C1=P1^3;
sbit C2=P1^2;
sbit C3=P1^1;
sbit C4=P1^0;
                                                              
sbit R1=P1^7;
sbit R2=P1^6;
sbit R3=P1^5;
sbit R4=P1^4;

int Number[3];
unsigned char key[3];            
unsigned int k1;
unsigned int num;
unsigned char i ;
unsigned int Ent_num;

void Timer0_Intilization ()
{
  TMOD =0x10;
	TH0=0xB7;
	TL0=0xFD;
	TR0=1;
	IE=0x82;

}


void Timer0 () interrupt 1
{ 
	PWM_PIN = ~PWM_PIN ;	
	if(PWM_PIN)
	   {
		   TH0=ON_Period >> 8;
			 TL0=ON_Period;
		 }
		 else
	   {
		   TH0=OFF_Period >> 8;
			 TL0=OFF_Period;
		 }	
}

void Set_Duty_Cycle (float duty_cycle)
{  
	unsigned int Period;
  Period =65535 - 0xB7FD ;
	ON_Period =((Period/100.0)*duty_cycle);
	OFF_Period = Period -ON_Period;
	ON_Period =  65535-ON_Period;
	OFF_Period=  65535-OFF_Period;
	

}
void Beep(unsigned int duration)
{
    unsigned char i,j;
	
	//To convert passive Buzzer into Active Buzzer we Generate Crystal frequency through coding.
   for(i=0;i<duration;i++)            
	{
	  R3=0;
	  for(j=0;j<100;j++);
		R3=1;
    for(j=0;j<100;j++);

}

}
char Key_Pressed ()                 //detect the pressed button 
{  
       
while(1)                             //used in order that button is pressed forever
{ 
	R1=0; R2=1; R3=1; R4=1;            //Ground Row 1,and check coloum
	     if(C1==0)                                         //Ground coloum 1 ,if this button press
			 {    while(C1==0)
				   { Beep(250);  return '7';}
			     
			 }   //return the Value7, Delay is used for Debouning, while(C1==0) is used that button is detected only once;
	      
			 if(C2==0)                                       //
			 {     while(C2==0)
			       { Beep(250);return '8';}  
			 }       
			  
			 if(C3==0)
			 {   while(C3==0)
			    { Beep(250);return '9';}  
			 }
			 
			 if(C4==0)
			 {   
			    while(C4==0)
			    { Beep(250);return '/';} 
			 
			 }
	 
  R1=1; R2=0; R3=1; R4=1;                             //Ground Row 2,and check coloum 
	     if(C1==0)                                      //Ground coloum 1 ,if this button press
			 { 
           while(C1==0)
			    { Beep(250);return '4';} 


			 }  //return the Value4, Delay is used for Debouning, while(C1==0) is used that button is detected only once;
	      if(C2==0)
			 {  
           while(C2==0)
			    { Beep(250);return '5';} 
			 }
			  if(C3==0)
			 {  
         while(C3==0)
			    { Beep(250);return '6';} 

			 }
			  if(C4==0)
			 {  while(C4==0)
			    { Beep(250);return '*';}   }
			 
  R1=1; R2=1; R3=0; R4=1;                               //Ground Row 3,and check coloum
	     if(C1==0)
			 {  
         while(C1==0)
			    { Beep(250);return '1';} 

			 } 
	      if(C2==0)
			 {  while(C2==0)
			    { Beep(250);return '2';} 
			 }
			  if(C3==0)
			 {  while(C3==0)
			    { Beep(250);return '3';}   
			 }
			  if(C4==0)
			 {  while(C4==0)
			    { Beep(250);return '-';}   }
			 
			 
	R1=1; R2=1; R3=1; R4=0;                               //Ground Row 4,and check coloum
	     if(C1==0)
			 { 
				    Delay1(10);  // Add appropriate delay before LCD operation

            lcd_command(0x01);  // Clear the LCD screen
            Delay1(10);  // Add appropriate delay after LCD command

            lcd_command(0x80);  // Set cursor to the first line
            Delay1(10);  // Add appropriate delay after LCD command

            lcd_string("Duty Cycle");  // Display your desired text
            Delay1(10);  // Add appropriate delay after LCD data

            lcd_command(0xC1);  // Set cursor to a specific position
            Delay1(10);  // Add appropriate delay after LCD command

            while (C1 == 0);
				 
				 
				 } 
	      if(C2==0)
			 {  while(C2==0)
			    { Beep(250);return '0';}  
			 
		   }  //return the Value 0, Delay is used for Debouning, while(C1==0) is used that button is detected only once;
			  if(C3==0)
			 {  while(C3==0)
			    { Beep(250);return '=';}  
			 }
			  if(C4==0)
			 { while(C4==0)
			    { Beep(250);return '+';} 
			 }
	 
	 R4=1;
}

}
int Convert_char(unsigned char value)
{
        
 switch(value)                   //value pass
 {
	 case '0':                     //check, if 0 then return integer 0
	 { return 0; break;}
	                                //same for other cases
	  case '1':
	 { return 1; break;}
	 
	  case '2':
	 { return 2; break;}
	 
	  case '3':
	 { return 3; break;}
	 
	  case '4':
	 { return 4; break;}
	 
	  case '5':
	 { return 5; break;}
	 
	  case '6':
	 { return 6; break;}
	 
	  case '7':
	 { return 7; break;}
	 
	  case '8':
	 { return 8; break;}
	 
	  case '9':
	 { return 9; break;}
	 
 }

}

void main (void)
{   
	  lcd_init();                        //LCD Intilization
	  lcd_string("Duty Cycle");
	  Timer0_Intilization ();                     //Timmer Intilization
    R3=0;                                       //Make the Buzzer Pin as Output pin
	
		while(1)
    {  
         	Ent_num = 0;                         //Number of key press
			 for(i=0;i<4;i++)
			{ 
				key[i]= Key_Pressed (); 	             //Keypressed function to take Duty Cycle limit		 
        k1=Convert_char(key[i]); 
	      Number[i]=k1;
				lcd_shownum(2,1+i,Number[i],1);
				Ent_num++;
				
				if (key[i]=='+')                     //if the Button press charachter is '+' break from the for loop and the prevouis value is duty Cycle
					{ Ent_num--;   break;  }
				
			}
	 
			
	     if (Ent_num > 0 || Ent_num <= 3)      //Check if the Button press is between 0 to 3 then
		   {                                     //Calculate Duty Cycle According to the Number of Button Press   
       	if(Ent_num==1)     
			      {num=Number[0]; lcd_shownum(2,1,num,1); lcd_showstring(2,2,".00");}
			   else if(Ent_num==2)
		        	{num=(Number[0]*10)+Number[1]; lcd_shownum(2,1,num,2); lcd_showstring(2,3,".00");}
		   	else if(Ent_num==3)
			        {num=(Number[0]*100+Number[1]*10+Number[2]); lcd_shownum(2,1,num,3); lcd_showstring(2,4,".00");}
		   }
	
			
			  if(num<=100  && num>=0 )              //Num is Duty Cycle,if it lies in Rang 0 to 100 
				{	                                    //So Set The Duty Cycle
				  DutyCycle = num ; 
          Set_Duty_Cycle(DutyCycle);
          Delay1(500);
				}     
				else                                 //Otherwise 
				{ 
				  lcd_set_cursor(2,1);
				  lcd_string("Invalid Number");   // Print On LCD Invalid Number
				}
		
		}			
}