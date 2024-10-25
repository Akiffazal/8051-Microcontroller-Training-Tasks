#ifndef __24C02_H
#define __24C02_H

#define DEVICE_ADDRESS_24C02_EEPROM 0xA0


void write_byte_to_24c02_eeprom (unsigned int , unsigned char );
unsigned char read_byte_from_24c02_eeprom (unsigned int );
void Write_Page_To_24C02_EEPROM (unsigned int address , unsigned char* pData, unsigned char noofbytes );
void Read_Bytes_From_24C02_EEPROM(unsigned int address ,unsigned char*pData,unsigned int noofbytes);
void delay_ms (unsigned int );


#endif