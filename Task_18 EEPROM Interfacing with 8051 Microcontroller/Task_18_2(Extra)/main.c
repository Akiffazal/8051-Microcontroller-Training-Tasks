#include "Includes.h"

// Main function
void main()
{
    unsigned char RxByte = 0;
    unsigned char TxArray[3] = { 'A', 'k', 'i'};
    unsigned char RxArray[3] = { 0 }; 
    char buffer[2];  // Declare buffer at the beginning of the function

    // Initialize LCD
    lcd_init();

    // Initialize i2c pins
    InitI2C();                                            

    // Write 'd' at 0x0001 address in EEPROM
    Write_Byte_To_24LC64_EEPROM(0x0001, 'f');
    // Read from 0x0001 address from EEPROM      
    RxByte = Read_Byte_From_24LC64_EEPROM(0x0001);        

    // Write 4 bytes of TxArray starting from 0x0020 address in EEPROM
    Write_Page_To_24LC64_EEPROM(0x0020, TxArray, 4);
    // Read 4 bytes starting from 0x0020 address in EEPROM, save these bytes into RxArray
    Read_Bytes_From_24LC64_EEPROM(0x0020, RxArray, 4);

    // Display received values on LCD display
    lcd_char(RxArray[0]);
    lcd_char(RxArray[1]);
    lcd_char(RxArray[2]);
//    lcd_char(RxArray[3]);

    buffer[0] = RxByte;  // Convert the character to a string
    buffer[1] = '\0';    // Null-terminate the string
    lcd_string(buffer);  // Display the string

    while(1)
    {   
    }
}





///*  Name     : main.c
// *  Purpose  : Main file for 24LC64 EEPROM code for AT89C51.
// *  Author   : M.Saeed Yasin
// *  Date     : 05-11-12
// *  Website  : saeedsolutions.blogspot.com
// *  Revision : None
// */
//#include "Includes.h"

//// Main function
//void main()
//{	
//	unsigned char RxByte = 0;
//	unsigned char TxArray[4] = { 'S', 'a', 'e', 'e' };
//	unsigned char RxArray[4] = { 0 }; 

//	// Initialize LCD
//	lcd_init();

//	// Initialize i2c pins
//	InitI2C();											

//	// Write 'd' at 0x0001 address in EEPROM
//	Write_Byte_To_24LC64_EEPROM(0x0001, 'd');
//	// Read from 0x0001 address	from EEPROM		
//	RxByte = Read_Byte_From_24LC64_EEPROM(0x0001);		

//	// Write 4 bytes of TxArray starting from 0x0020 address in EEPROM
//	Write_Page_To_24LC64_EEPROM(0x0020, TxArray, 4);
//	// Read 4 bytes starting from 0x0020 address in EEPROM, save these bytes into RxArray
//	Read_Bytes_From_24LC64_EEPROM(0x0020, RxArray, 4);

//	// Display received values on LCD display
//	lcd_string(RxArray[0]);
//	lcd_string(RxArray[1]);
//	lcd_string(RxArray[2]);
//	lcd_string(RxArray[3]);
//	lcd_string(RxByte);

//	while(1)
//	{	
//	}
//}