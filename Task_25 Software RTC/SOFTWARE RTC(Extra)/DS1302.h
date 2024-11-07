#ifndef DS1302_H
#define DS1302_H


//#define DS1302_READ_BURST 0xBF
//#define DS1302_WRITE_BURST 0xBE
//#define DS1302_SECOND 0x80
//#define DS1302_SECOND_READ 0x81
//#define DS1302_MINUTE 0x82
//#define DS1302_MINUTE_READ 0x83
//#define DS1302_HOUR 0x84 
//#define DS1302_HOUR_READ 0x85
//#define DS1302_DATE 0x86
//#define DS1302_MONTH 0x88
//#define DS1302_DAY 0x8A
//#define DS1302_YEAR 0x8C
//#define DS1302_CONTROL 0x8E
//#define DS1302_CHARGER 0x90
//#define DS1302_RAMBURST_READ 0xFF
//#define DS1302_RAMBURST_WRITE 0xFE
//#define CLK_DELAY 10
//sbit DS1302_IO=P3^4;
//sbit DS1302_CE=P3^5;                 //RTC
//sbit DS1302_CLK=P3^6;

#define lcd_data P0
sbit RW=P2^5;
sbit RS=P2^6;
sbit EN=P2^7;                          //LCD

void lcd_init();
void lcd_command(unsigned char cmd);
void lcd_char(unsigned char dat);
void lcd_string(unsigned char *str);                     //LCD
void delay (unsigned int);
void lcd_set_cursor(unsigned char row, unsigned char col);
void inttoASCII(int num, char *buffer);
void lcd_display_int(int num);
unsigned int dayinmonth (unsigned char mon, unsigned int year);


//void lcd_display(unsigned char number);
//void write_byte(unsigned int byte);
//unsigned char read_byte(unsigned char cmd);
//void DS1302_settime(unsigned char hour, unsigned char minute, unsigned char second);
//void DS1302_setdate(unsigned char day, unsigned char month, unsigned char year);           //RTC
//void DS1302_gettime(void);
//void DS1302_getdate(void);
//void send_bit(unsigned int bitt);
//void DS1302_init();
//void DS1302_readbyte();
//void SCLK_Pulse();
//void DS1302_writebyte(unsigned char cmd, unsigned char value);




#endif
