#ifndef I2C_H
#define I2C_H

sbit SDA=P2^0;
sbit SCL=P2^1;


#define SET_SDA_LOW  SDA=0;
#define SET_SDA_HIGH SDA=1;
#define SET_SCL_LOW SCL=0;
#define SET_SCL_HIGH SCL=1;

void delay1 (unsigned int);
void INITI2C (void);
void I2C_START (void);
void I2C_RESTART (void);
void I2C_STOP (void);
void I2C_ACK (void);
void I2C_NACK (void);
bit I2C_WRITE_BYTE (unsigned char);
unsigned char I2C_READ_BYTE (void);
#endif