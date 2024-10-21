#include <reg52.h>

// DS1302 Pin Definitions
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

// LCD1602 Pin Definitions
sbit LCD_RS = P2^6;
sbit LCD_RW = P2^5;
sbit LCD_EN = P2^7;

#define LCD_DataPort P0

// DS1302 Command Definitions
#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8A
#define DS1302_YEAR 0x8C
#define DS1302_WP 0x8E 

// Time array {Year, Month, Date, Hour, Minute, Second, Day of Week}
unsigned int DS1302_Time[] = {23, 12, 31, 23, 59, 50, 6};

// Function Prototypes
void DS1302_Init();
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime();
void DS1302_ReadTime();

void LCD_Init();
void LCD_Delay();
void LCD_WriteCommand(unsigned char Command);
void LCD_WriteData(unsigned char Data);
void LCD_SetCursor(unsigned char Line, unsigned char Column);
void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char);
void LCD_ShowString(unsigned char Line, unsigned char Column, char *String);
int LCD_Pow(int X, int Y);
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length);
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);


void main() {
    LCD_Init();
    DS1302_Init();

    // Initialize the LCD with labels and placeholders
    LCD_ShowString(1, 1, "Date: ");
    LCD_ShowString(2, 1, "Time: ");

    DS1302_SetTime();

    while (1) {
        DS1302_ReadTime();

        // Display Date
        LCD_ShowNum(1, 7, DS1302_Time[2], 2); // Day
        LCD_ShowChar(1, 9, '/');
        LCD_ShowNum(1, 10, DS1302_Time[1], 2); // Month
        LCD_ShowChar(1, 12, '/');
        LCD_ShowNum(1, 13, DS1302_Time[0], 2); // Year

        // Display Time
        LCD_ShowNum(2, 7, DS1302_Time[3], 2); // Hour
        LCD_ShowChar(2, 9, ':');
        LCD_ShowNum(2, 10, DS1302_Time[4], 2); // Minute
        LCD_ShowChar(2, 12, ':');
        LCD_ShowNum(2, 13, DS1302_Time[5], 2); // Second
    }
}

// DS1302 Functions
void DS1302_Init() {
    DS1302_CE = 0;
    DS1302_SCLK = 0;
    DS1302_IO = 0; // Set IO to low as default
}

void DS1302_WriteByte(unsigned char Command, unsigned char Data) {
    unsigned int i;

    DS1302_CE = 1;

    for (i = 0; i < 8; i++) {
        DS1302_IO = Command & (0x01 << i);
        DS1302_SCLK = 1; 
        DS1302_SCLK = 0;
    }

    for (i = 0; i < 8; i++) {
        DS1302_IO = Data & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command) {
    unsigned char i, Data = 0x00;
    Command |= 0x01;
    DS1302_CE = 1;

    for (i = 0; i < 8; i++) {
        DS1302_IO = Command & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    
    DS1302_IO = 1;  // Set to input mode

    for (i = 0; i < 8; i++) {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;

        if (DS1302_IO) {
            Data |= (0x01 << i);
        }
    }

    DS1302_CE = 0;
    DS1302_IO = 0; // Set to low as default

    return Data;
}

void DS1302_SetTime() {
    DS1302_WriteByte(DS1302_WP, 0x00);
    DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0] /10*16 + DS1302_Time[0]%10);
    DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1] /10*16 + DS1302_Time[1]%10);
    DS1302_WriteByte(DS1302_DATE, DS1302_Time[2] /10*16 + DS1302_Time[2]%10);
    DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3] /10*16 + DS1302_Time[3]%10);
    DS1302_WriteByte(DS1302_MINUTE, DS1302_Time[4] /10*16 + DS1302_Time[4]%10);
    DS1302_WriteByte(DS1302_SECOND, DS1302_Time[5] /10*16 + DS1302_Time[5]%10);
    DS1302_WriteByte(DS1302_DAY, DS1302_Time[6] /10*16 + DS1302_Time[6]%10);
    DS1302_WriteByte(DS1302_WP, 0x80);
}

void DS1302_ReadTime() {
    unsigned int Temp;
    Temp = DS1302_ReadByte(DS1302_YEAR);
    DS1302_Time[0] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_MONTH);
    DS1302_Time[1] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_DATE);
    DS1302_Time[2] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_HOUR);
    DS1302_Time[3] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_MINUTE);
    DS1302_Time[4] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_SECOND);
    DS1302_Time[5] = Temp/16*10+Temp%16;
    Temp = DS1302_ReadByte(DS1302_DAY);
    DS1302_Time[6] = Temp/16*10+Temp%16;    
}

// LCD1602 Functions
void LCD_Delay() {
    unsigned char i, j;

    i = 2;
    j = 239;

    do {
        while (--j);
    } while (--i);
}

void LCD_WriteCommand(unsigned char Command) {
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_DataPort = Command;
    LCD_EN = 1;
    LCD_Delay();
    LCD_EN = 0;
    LCD_Delay();
}

void LCD_WriteData(unsigned char Data) {
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_DataPort = Data;
    LCD_EN = 1;
    LCD_Delay();
    LCD_EN = 0;
    LCD_Delay();
}

void LCD_SetCursor(unsigned char Line, unsigned char Column) {
    if (Line == 1) {
        LCD_WriteCommand(0x80 | (Column - 1));
    } else if (Line == 2) {
        LCD_WriteCommand(0x80 + (Column - 1 + 0x40));
    }
}

void LCD_Init() {
    LCD_WriteCommand(0x38); 
    LCD_WriteCommand(0x0c); 
    LCD_WriteCommand(0x06); 
    LCD_WriteCommand(0x01); 
}

void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char) {
    LCD_SetCursor(Line, Column);
    LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line, unsigned char Column, char *String) {
    unsigned char i;
    LCD_SetCursor(Line, Column);
    for (i = 0; String[i] != '\0'; i++) {
        LCD_WriteData(String[i]);
    }
}

int LCD_Pow(int X, int Y) {
    unsigned char i;
    int Result = 1;
    for (i = 0; i < Y; i++) {
        Result *= X;
    }
    return Result;
}

void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length) {
    unsigned char i;
    LCD_SetCursor(Line, Column);
    for (i = Length; i > 0; i--) {
        LCD_WriteData('0' + Number / LCD_Pow(10, i - 1) % 10);
    }
}

void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length) {
    unsigned char i;
    unsigned int Number1;
    LCD_SetCursor(Line, Column);
    if (Number >= 0) {
        LCD_WriteData('+');
        Number1 = Number;
    } else {
        LCD_WriteData('-');
        Number1 = -Number;
    }
    for (i = Length; i > 0; i--) {
        LCD_WriteData('0' + Number1 / LCD_Pow(10, i - 1) % 10);
    }
}

void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length) {
    unsigned char i, SingleNumber;
    LCD_SetCursor(Line, Column);
    for (i = Length; i > 0; i--) {
        SingleNumber = Number / LCD_Pow(16, i - 1) % 16;
        if (SingleNumber < 10) {
            LCD_WriteData('0' + SingleNumber);
        } else {
            LCD_WriteData('A' + SingleNumber - 10);
        }
    }
}

void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length) {
    unsigned char i;
    LCD_SetCursor(Line, Column);
    for (i = Length; i > 0; i--) {
        LCD_WriteData('0' + Number / LCD_Pow(2, i - 1) % 2);
    }
}
