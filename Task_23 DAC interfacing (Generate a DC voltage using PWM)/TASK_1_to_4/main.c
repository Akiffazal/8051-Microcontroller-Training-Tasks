# include <reg52.h>
# include "LCD.h"
# include "ADC_VOLTAGE.h"


sbit PWM_PIN= P2^1;
unsigned int  ON_Period, OFF_Period;
unsigned int DutyCycle;


// Keypad Button
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
  TMOD =0x01;
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

//Buzzer
void Beep(unsigned int duration)
{
    unsigned char i,j;
	

   for(i=0;i<duration;i++)            
	{
	  R3=0;
	  for(j=0;j<100;j++);
		R3=1;
    for(j=0;j<100;j++);

}

}
// keypad 
char Key_Pressed ()               
{  
       
while(1)                            
{ 
	R1=0; R2=1; R3=1; R4=1;      
	     if(C1==0)                                         
			 {    while(C1==0)
				   { Beep(250);  return '7';}
			     
			 }   
	      
			 if(C2==0)                                      
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
	 
  R1=1; R2=0; R3=1; R4=1;                              
	     if(C1==0)                                  
			 { 
           while(C1==0)
			    { Beep(250);return '4';} 


			 }  
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
			 
  R1=1; R2=1; R3=0; R4=1;                             
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
			 
			 
	R1=1; R2=1; R3=1; R4=0;                            
	     if(C1==0)
			 { 
				    Delay(10);  

            LCD_Command(0x01);  
            Delay(10);  

            LCD_Command(0x80);
            Delay(10);  

            String_data("Duty Cycle"); 
            Delay(10);  

            LCD_Command(0xC1);  
            Delay(10);  

            while (C1 == 0);
				 
				 
				 } 
	      if(C2==0)
			 {  while(C2==0)
			    { Beep(250);return '0';}  
			 
		   } 
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
        
 switch(value)                
 {
	 case '0':                    
	 { return 0; break;}
	                              
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
	  LCD_Intialization();                   
	  String_data("Duty Cycle");
	  Timer0_Intilization ();                    
    R3=0;                                      
	
		while(1)
    {  
         	Ent_num = 0;                     
			 for(i=0;i<4;i++)
			{ 
				key[i]= Key_Pressed (); 	             	 
        k1=Convert_char(key[i]); 
	      Number[i]=k1;
				LCD_ShowNum(2,1+i,Number[i],1);
				Ent_num++;
				
				if (key[i]=='+')                   
					{ Ent_num--;   break;  }
				
			}
	 
			
	     if (Ent_num > 0 || Ent_num <= 3)      
		   {                                     
       	if(Ent_num==1)     
			      {num=Number[0]; LCD_ShowNum(2,1,num,1); LCD_ShowString(2,2,".00");}
			   else if(Ent_num==2)
		        	{num=(Number[0]*10)+Number[1]; LCD_ShowNum(2,1,num,2); LCD_ShowString(2,3,".00");}
		   	else if(Ent_num==3)
			        {num=(Number[0]*100+Number[1]*10+Number[2]); LCD_ShowNum(2,1,num,3); LCD_ShowString(2,4,".00");}
		   }
	
			
			  if(num<=100  && num>=0 )               
				{	                                    
				  DutyCycle = num ; 
          Set_Duty_Cycle(DutyCycle);
          Delay(500);
				}     
				else                               
				{ 
				  Set_cursor(2,1);
				  String_data("Invalid Number");  
				}
		
		}			
}

