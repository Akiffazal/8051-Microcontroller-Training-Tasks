

# include <reg52.h>
# include "LCD.h"
# include "ADC.h"



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
     

//PWM SETUP
void Timer0_Intilization ()
{
  TMOD =0x02;
	TH0=0x17;
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
  Period =255 - 0x17 ;
	ON_Period =((Period/100.0)*duty_cycle);
	OFF_Period = Period -ON_Period;
	ON_Period =  255-ON_Period;
	OFF_Period=  255-OFF_Period;
	

}

//Buzzer

//Keypad

char Key_Pressed()
{
    char key;
    char prev_key;

    while (1)
    {
        key = 0;

        R1 = 0; R2 = 1; R3 = 1; R4 = 1; 
        if (C1 == 0)
        {
            key = '7';
        }
        else if (C2 == 0)
        {
            key = '8';
        }
        else if (C3 == 0)
        {
            key = '9';
        }
        else if (C4 == 0)
        {
            key = '/';
        }

        R1 = 1; R2 = 0; R3 = 1; R4 = 1; 
        if (C1 == 0)
        {
            key = '4';
        }
        else if (C2 == 0)
        {
            key = '5';
        }
        else if (C3 == 0)
        {
            key = '6';
        }
        else if (C4 == 0)
        {
            key = '.';
        }

        R1 = 1; R2 = 1; R3 = 0; R4 = 1; 
        if (C1 == 0)
        {
            key = '1';
        }
        else if (C2 == 0)
        {
            key = '2';
        }
        else if (C3 == 0)
        {
            key = '3';
        }
        else if (C4 == 0)
        {
            key = '-';
        }

        R1 = 1; R2 = 1; R3 = 1; R4 = 0; 
				  if(C1==0)
			 { 
				    Delay(10); 

            LCD_Command(0x01);  
            Delay(10);  

             LCD_Command(0x80);  
            Delay(10); 

            String_data("DutyCycle");
            Delay(10);  
				 
            LCD_Command(0xC0);  
            Delay(10);  

				    String_data("Voltage:");  
            Delay(10);  
            
				 Delay(10000);
				 
				 } 
        else if (C2 == 0)
        {
            key = '0';
        }
        else if (C3 == 0)
        {
            key = '=';
        }
        else if (C4 == 0)
        {
            key = '+';
        }

        if (key && key != prev_key)
        {
            Delay(10000); // Debounce delay
            while (C1 == 0 || C2 == 0 || C3 == 0 || C4 == 0)
            {
                //Beep(250);
            }

            prev_key = key;
            return key;
        }
    }
}

//Floating point Number

float GetFloatFromKeypad()
{
    char input[10];
    int j,i = 0;
    int decimalEntered = 0;
    int decimalPlace = 0;
    float decimal ;
  	float num ;
	  int integerPart;
    int decimalPart,digit ;
    while (1)
    {
        char pressedKey = Key_Pressed(); // Function to detect the pressed button

        if (pressedKey == '=')
            break;
        else if (pressedKey == '.' && i > 0 && !decimalEntered)
        {
            input[i++] = pressedKey;
            decimalEntered = 1;
            LCD_ShowChar(1, 11 + i, pressedKey); // Display the decimal point on the LCD
        }
        else if (pressedKey >= '0' && pressedKey <= '9')
        {
            if (i < 10)
            {
                input[i++] = pressedKey;
                LCD_ShowChar(1, 11 + i, pressedKey); // Display the entered digit on the LCD
            }
        }
    }

    input[i] = '\0';

		num = 0.0;
    decimal = 0.1;

     integerPart = 0;
     decimalPart = 0;

    for (j = 0; j < i; j++)
{
    if (input[j] == '.')
    {
        decimalPlace = 1;
    }
    else
    {
        digit = input[j] - '0';
        if (!decimalPlace)
        {
            integerPart = integerPart * 10 + digit;
        }
        else
        {
            decimalPart = decimalPart * 10 + digit;
            decimalPlace *= 0.1;
        }
    }
}

    num = integerPart + decimal * decimalPart;
    return num;
}


void main(void)                  //Main Body                
{   
	  float num1;
    LCD_Intialization();                //LCD Intilization
    Timer0_Intilization();              // Timmer Intilization
    R3 = 0;                             //Make R3 as Output ,because Multiple time Use
	  LCD_ShowString(1,0,"DutyCycle:");   
    LCD_ShowString(2,0,"Voltage:");
	
   while(1)
		 {  
			  num1 = GetFloatFromKeypad();       //Take the Floating Point Number from Keypad
			 
        if (num1 >= 0.0 && num1 <= 5.0)     //if the Floating Point Number lies in the Range (0 to 5) so
        {  LCD_ShowFloat(num1, 1);
            DutyCycle = num1;
            Set_Duty_Cycle((DutyCycle * 100.0) / 5.0);  //Set duty cycle according to it
				   	Delay(1000);
					  DAC_VOLTAGE ();                            //read DAC voltage
            Delay(500);
        }
        else                                  //Otherwise
        {
            Set_cursor(1, 0);
            String_data("Invalid Number");     //LCD Print Invalid Number
        }
				
    }
}
