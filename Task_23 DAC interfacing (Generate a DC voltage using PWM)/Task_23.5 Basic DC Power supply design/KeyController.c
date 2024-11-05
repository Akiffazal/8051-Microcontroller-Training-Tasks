# include <reg52.h>
# include "LCD.h"
# include "KeyController.h"
# include "ADC.h"



sbit k1 = P3^1;   //Increment
sbit k2 = P3^0;   //Decrement
sbit PWM_PIN= P2^1;
unsigned int  ON_Period, OFF_Period;
unsigned int DutyCycle;
unsigned int DutyCycle_Limit ;


//PWM Setup
void Timer0_Intilization ()                    
{
  TMOD =0x02;
	TH0=0x17;
	//TL0=0xFD;
	TR0=1;
	IE=0x82;
	  
}

void Timer0 () interrupt 1                 
{ 
	PWM_PIN = ~PWM_PIN ;	
	if(PWM_PIN==1)
	   {
		   //TH0=ON_Period >> 8;
			 TL0=ON_Period;
		 }
		 else
	   {
		//   TH0=OFF_Period>> 8;
			 TL0=OFF_Period;
		 }	
}

void Set_Duty_Cycle (float duty_cycle)
{  
	unsigned int Period;
  Period =255 - 0x17 ;
	ON_Period =((Period/100.0)*duty_cycle);
	OFF_Period = Period -ON_Period;
	ON_Period =  255-ON_Period;
	OFF_Period=  255-OFF_Period;
	

}


void External_Keys()                      
{  
if(k1==0)                                  
			{ Delay(1000);                  
				
			  if(DutyCycle_Limit<100)                             
				{	
					DutyCycle_Limit +=10;          
					LCD_ShowNum(1,10,DutyCycle_Limit,3);   
					LCD_ShowString(1,13,".00");
			
					 Delay(500);
				}     
				
				while (k1 == 0);                 
     }
			
		 if(k2==0)                            
			{     
				Delay(100);                    
           			
			  if(DutyCycle_Limit>0)             
				   {	
				   DutyCycle_Limit-=10;         
					 LCD_ShowNum(1,10,DutyCycle_Limit,3);    
					 LCD_ShowString(1,13,".00");
					 Delay(500);
				   }		
				while (k2 == 0);		            
			}
			
        Set_Duty_Cycle(DutyCycle_Limit);  
        Delay(500);
}
	