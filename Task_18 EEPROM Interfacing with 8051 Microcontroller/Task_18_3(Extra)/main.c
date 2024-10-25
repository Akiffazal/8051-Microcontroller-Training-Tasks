#include <reg51.h>

#include "24C02.h"
#include "I2C.h"
#include "lcd.h"
#include <stdio.h>

//typedef unsigned int uchar;
//typedef unsigned int iint;
typedef unsigned long ulong;


void lcd_write_ulong(unsigned long num) {
  unsigned int i;
	char buffer[12];                                            // Buffer for storing the string representation of the number
    sprintf(buffer, "%lu", num);                             // Convert ka, number to a string

    for ( i = 0; buffer[i] != '\0'; i++) {
        lcd_char(buffer[i]);                             // Write each character to the LCD
    }
}

// Main function
void main()
	
{	
	ulong TotalWriteCycles;
  ulong WriteCyclesPerYear;
	ulong WriteCyclesPerDay; 
	ulong TimeBetweenWrites_ms;
	
	unsigned char RxByte = 0;
	unsigned char TxArray[4];
	unsigned char RxArray[4];

	ulong counter = 0;
 	unsigned char i;

	unsigned int readValue = 0;
	lcd_init();

	// Initialize LCD
	INITI2C();

	// Initialize	i2c pins
	      
		lcd_clear();
 		lcd_set_cursor(0,0);
	  lcd_string("Counter EEPROM:");
	
	   TotalWriteCycles = 1000000UL;                                 // Total write cycles
     WriteCyclesPerYear = TotalWriteCycles / 10;                    // Write cycles per year
     WriteCyclesPerDay = WriteCyclesPerYear / 365;                  // Write cycles per day
     TimeBetweenWrites_ms = 24 * 60 * 60 * 1000 / WriteCyclesPerDay;  // Time between writes in milliseconds  
		               


while (1)
    {

		for (i = 0; i < 4; i++) {                               // Break the counter into 4 bytes

			TxArray[i] = (counter >> (8 * (3 - i))) & 0xFF;
		}

		 Write_Page_To_24C02_EEPROM(0x0020, TxArray, 4);		          // Write the 4-byte counter value to the EEPROM at address 0x0020		
		 Read_Bytes_From_24C02_EEPROM(0x0020, RxArray, 4);		        // Read the counter value from the EEPROM at address 0x0020 (4 bytes)
     
		counter = 0;
		
// dalta ma counter 0 ko zaka chi counter incremented value already RxArray ki store shawe, bia me 4byte counter ki save ka chi display she
		
		for (i = 0; i < 4; i++) {	                                    	// Combine the bytes to form a 4-byte counter
                
			counter = (counter << 8) | RxArray[i];
		}

		// Display the counter value on the LCD
		lcd_set_cursor(1, 0);
		lcd_write_ulong(counter);

		counter++;
		delay_ms(1); // Delay for 10 years (last second)
		
		delay_ms(TimeBetweenWrites_ms); // Delay for 10 years (last second)
	}
}











//#include <reg51.h>
//#include "LCD.h"
//#include "24C02.h"
//#include "I2C.h"
//#include <stdio.h>


//void main()
//{
// long TotalWriteCycle;
// long WriteCyclePerYear;
// long WriteCyclePerDay;
// long TimeBetweenWrite_Ms;

// unsigned char RxByte=0;
// unsigned char TxArray[4];
// unsigned char RxArray[4];
//	
// long  counter=0;
//unsigned char i;


//	INITI2C();

//	lcd_init();
//	
//	lcd_clear();
//	lcd_set_cursor(0,0);
//	lcd_string("COUNTER EEPROM:");

//  TotalWriteCycle=1000000UL;
//	WriteCyclePerYear=TotalWriteCycle / 10;
//	WriteCyclePerDay=WriteCyclePerYear /365;
//	TimeBetweenWrite_Ms= 24 * 60 * 60* 1000 /WriteCyclePerDay ;
//	
//while(1)
//{
//	
//	for(i=0; i<4; i++)
//	{
//		TxArray[i]=(counter>>(8*(3 - i))) & 0xFF;
//	}
//	write_page_to_24c02_eeprom(0x0020, TxArray, 4);
//	read_bytes_from_24c02_eeprom(0x0020, RxArray, 4);
////	counter=0;
//  
//	for(i=0; i<4; i++)
//	{
//		counter=(counter << 8) | RxArray[i];
//	}
//	lcd_set_cursor(1,0);
//		
//	lcd_display_long(counter);
//  counter++;
//	delay_ms(10);
////  delay_ms(TimeBetweenWrite_Ms);
//}

//}


