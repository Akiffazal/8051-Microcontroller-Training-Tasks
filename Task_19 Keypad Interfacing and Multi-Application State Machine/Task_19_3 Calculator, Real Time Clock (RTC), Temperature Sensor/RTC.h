#ifndef RTC_H
#define RTC_H



void write_byte(unsigned int byte);
unsigned char read_byte(unsigned char cmd);
void DS1302_settime(unsigned char hour, unsigned char minute, unsigned char second);
void DS1302_setdate(unsigned char day, unsigned char month, unsigned char year);
void DS1302_gettime(void);
void DS1302_getdate(void);
void send_bit(unsigned int bitt);
void DS1302_init();
void DS1302_readbyte();
void DS1302_writebyte(unsigned char cmd, unsigned char value);
void SCLK_Pulse();



#define DS1302_READ_BURST 0xBF
#define DS1302_WRITE_BURST 0xBE
#define DS1302_SECOND 0x80
#define DS1302_SECOND_READ 0x81
#define DS1302_MINUTE 0x82
#define DS1302_MINUTE_READ 0x83
#define DS1302_HOUR 0x84 
#define DS1302_HOUR_READ 0x85
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8A
#define DS1302_YEAR 0x8C
#define DS1302_CONTROL 0x8E
#define DS1302_CHARGER 0x90
#define DS1302_RAMBURST_READ 0xFF
#define DS1302_RAMBURST_WRITE 0xFE
#define CLK_DELAY 10



#endif