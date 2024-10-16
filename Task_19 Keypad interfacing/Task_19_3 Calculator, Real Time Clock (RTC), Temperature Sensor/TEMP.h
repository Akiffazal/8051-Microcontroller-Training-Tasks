#ifndef TEMP_H
#define TEMP_H

//void lcd_init();
//void lcd_command(unsigned char cmd);
//void lcd_char(unsigned char dat);
//void lcd_string(unsigned char *str);
//void delay (unsigned int);
//void lcd_set_cursor(unsigned char row, unsigned char col);
//void lcd_display(unsigned char number);



//temperature sensor and buzzer

void ow_reset (void);
unsigned char read_bytess (void);
void write_bytess (char);
void delay_18B20(unsigned int);
void read_temperature(void);
void hex2lcd (unsigned char hex);
void temp_serialdata_pc (void);

// seven segment display
void display_num7_seg (unsigned char);
void values_on_ssd (void);

//serial
//void display_num_serial(unsigned int);
//void serial_data(void);

#endif