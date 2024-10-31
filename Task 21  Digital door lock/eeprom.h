#ifndef eeprom_H
#define eeprom_H





void delay2 (unsigned int t);
void acknowledge ();
void no_acknowledge ();
void start_data ();
void restart ();
void stop_data ();
void sendbyte (unsigned int value);
unsigned char readbyte ();
void EEPROM_write (unsigned char address_w, unsigned char Data );
unsigned char EEPROM_read (unsigned char address_r );











#endif
