# include <reg52.h>
# include "LCD.h"
# include "ADC.h"


sbit CS =P3^5;          
sbit DCLK =P3^6;        
sbit DIN =P3^4;          
sbit DOUT =P3^7;        


unsigned char ADC_Driver (bit A0,bit A1,bit A2)         
{  
	
	unsigned char i, temp=0;
	 DCLK=0;                                
   CS=0;                                         
	 
	 DCLK=0;  DIN=1;  DCLK=1;                    
	 DCLK=0;  DIN=A2;  DCLK=1;              
   DCLK=0;  DIN=A1;  DCLK=1;              
	 DCLK=0;  DIN=A0;  DCLK=1;                 
	 DCLK=0;  DIN=1;  DCLK=1;                      
	 DCLK=0;  DIN=1;  DCLK=1;                    
	 DCLK=0;  DIN=1;  DCLK=1;                  
	 DCLK=0;  DIN=1;  DCLK=1;                 
	
   
	DCLK = 0;        
	Delay(10);


	for(i=0;i<=7;i++)
	{	 
		temp <<=1;         
		              
		 DCLK=1;              
	 	 DCLK=0; 
	   temp |=DOUT;       
		   
	}
	
	 CS=1;             
	
	return temp;     
}


float  DAC_VOLTAGE ()	      
{
	float voltage,value;    
	
  value = ADC_Driver(0,1,1);              
	
		     voltage=value*(5.0/255.0);            
         LCD_ShowString(2,0,"Voltage:");
         LCD_ShowNum(2,10,voltage,1);        
	    	 LCD_ShowChar(2,11,'.'); 
		     LCD_ShowNum(2,12,(unsigned int)(voltage*1000)%1000,3); 
		     LCD_ShowChar(2,15,'V');
		     Delay(1000);
	return voltage; 

}
	
	
	