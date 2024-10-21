#ifndef TEMP_H
#define TEMP_H

// Declare temp_c as external since it's used across multiple files.
extern unsigned char temp_c;

// Temperature sensor and buzzer
void ow_reset(void);
unsigned char read_byte(void);
void write_byte(char);
void delay_18B20(unsigned int);
void read_temperature(void);
void hex2lcd(unsigned char hex);
void temp_serialdata_pc(void);


#endif
