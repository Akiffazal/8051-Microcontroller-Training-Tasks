#include <reg51.h>
#include "LCD.h"
#include "I2C.h"
#include "24C02.h"


void write_byte_to_24c02_eeprom (unsigned int address,unsigned char databyte)
{
	I2C_START();
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM + 0)==1)
	{
		I2C_START();
	}
	I2C_WRITE_BYTE(address>>8);
	I2C_WRITE_BYTE((unsigned char)address);
	I2C_WRITE_BYTE(databyte);
	I2C_STOP();
}
unsigned char read_byte_from_24c02_eeprom (unsigned int address)
{
	unsigned char Byte=0;
	I2C_START();
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
	{
		I2C_START();
	}
	I2C_WRITE_BYTE(address>>8);
	I2C_WRITE_BYTE((unsigned char)address);
	I2C_RESTART();
	
	I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM+1);
	
	Byte=I2C_READ_BYTE();
	
	I2C_NACK();
	SET_SDA_LOW;
	delay1(5);
	SET_SDA_HIGH;
	delay1(5);
	return Byte;
}
// Function Purpose: Write_Page_To_24LC64_EEPROM writes a page on given address
// Address can have value 0, 32, 64, .... only and pData is pointer to the array
// containing NoOfBytes bytes in it. NoOfBytes can have a value from 1 to 32 only.
void Write_Page_To_24C02_EEPROM(unsigned int Address,unsigned char* pData,unsigned char NoOfBytes)
{
	unsigned int i;

	I2C_START();										// Start i2c communication

	// Send i2c address of 24LC64 with write command
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM + 0) == 1)     // Wait until device is free
	{	I2C_START();	}	

	I2C_WRITE_BYTE(Address>>8);							                        // Write Address upper byte
	I2C_WRITE_BYTE((unsigned char)Address);				                  // Write Address lower byte

	for(i=0;i<NoOfBytes;i++)							                          // Write NoOfBytes
		I2C_WRITE_BYTE(pData[i]);						                          // Write data byte

		I2C_STOP();										                                // Stop i2c communication
}




// Function Purpose: Read_Bytes_From_24LC64_EEPROM reads a NoOfBytes bytes from given starting address.
// Address can have any value fromm 0 to 0x1FFF. Also, NoOfBytes can have any value 0 to 0x1FFF.
// Read bytes are returned in pData array.
void Read_Bytes_From_24C02_EEPROM(unsigned int Address, unsigned char* pData, unsigned int NoOfBytes)
{
	unsigned int i;

	I2C_START();									                                	// Start i2c communication

	                                                                // Send i2c address of 24LC64 with write command
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM+ 0) == 1)      // Wait until device is free
	{	I2C_START();	}		

	I2C_WRITE_BYTE(Address>>8);						                          // Write Address upper byte
	I2C_WRITE_BYTE((unsigned char)Address);			                    // Write Address lower byte
	I2C_RESTART();									                         	      // Restart i2c

	                                                                // Send i2c address of 24LC64 EEPROM with read command	
	I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM + 1);		

	pData[0] =I2C_READ_BYTE();						                          // Read First byte from EEPROM

	for(i=1;i<NoOfBytes;i++)						                   	        // Read NoOfBytes
	{		
		I2C_ACK();					                                          // Give Ack to slave to start receiving next byte
		pData[i] = I2C_READ_BYTE();	                                  // Read next byte from EEPROM
	}

	                                                     // Make SCK low, so that slave can stop driving SDA pin
	                                                      // Send a NACK to indiacate read operation is complete
	I2C_NACK();

	                                                     // Send start bit and then stop bit to stop transmission
	SET_SDA_LOW;			                              	// Make SDA Low
	delay1(5);                       	// Half bit delay
	SET_SDA_HIGH;			                             	// Make SDA high
	delay1(5);                    	// Half bit delay
}

void delay_ms (unsigned int ms)
{
	unsigned int i, j;
	for(i=0; i<ms; i++)
	for(j=0; j<112; j++);
}



// =========================================================================================================================================================================



























//void Write_Page_To_24C02_EEPROM (unsigned int address , unsigned char* pData, unsigned char noofbytes )
//{
//	unsigned int i;
//	I2C_START();
//  while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
//	{
//		I2C_START();
//	}
//	I2C_WRITE_BYTE(address>>8);
//	I2C_WRITE_BYTE((unsigned char)address);
//	
//	for(i=1; i<noofbytes; i++)
//	{
//		I2C_WRITE_BYTE(pData[i]);
//		I2C_STOP();
//	}
//	
//}

//void Read_Bytes_From_24C02_EEPROM(unsigned int address ,unsigned char*pData,unsigned int noofbytes)
//{
//	unsigned int i;
//	I2C_START();
//	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
//	{
//		I2C_START();
//	}
//	I2C_WRITE_BYTE(address>>8);
//	I2C_WRITE_BYTE((unsigned char)address);
//	
//	I2C_RESTART();
//	I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +1);
//	
//	pData[0]=I2C_READ_BYTE();
//	
//	for(i=0; i<noofbytes; i++)
//	{
//		I2C_ACK();
//		pData[i]=I2C_READ_BYTE();
//	}
//	I2C_NACK();
//	SET_SDA_LOW;
//	delay1(5);
//	SET_SDA_HIGH;
//	delay1(5);
//}













