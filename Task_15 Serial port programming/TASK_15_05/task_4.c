#include <reg51.h>
#include "lcd.h"

// Function to initialize the UART
void UART_Init() {
    TMOD = 0x20;  // Timer 1, Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;   // Baud rate of 9600 for 11.0592 MHz clock
    SCON = 0x50;  // Mode 1, 8-bit UART, enable receiver
    TR1 = 1;      // Start Timer 1
}

// Function to receive data via UART
unsigned char RX_data(void) {
    unsigned char a;
    while (RI == 0);  // Wait until reception is complete
    RI = 0;           // Clear the reception interrupt flag
    a = SBUF;         // Read received data
    return a;
}

// Function to send data via UART
void UART_Send(unsigned char dat) {
    SBUF = dat;       // Load data into the UART buffer
    while (TI == 0);  // Wait until transmission is complete
    TI = 0;           // Clear the transmission interrupt flag
}

// Function to display time on the LCD
void display_time(unsigned char hour, unsigned char minute, unsigned char second) {
    lcd_cmd(0x80);  // Move to the first line
    show("Time: ");
    show_char(hour / 10 + '0');   // Display tens place of hour
    show_char(hour % 10 + '0');   // Display unit place of hour
    show_char(':');
    show_char(minute / 10 + '0'); // Display tens place of minute
    show_char(minute % 10 + '0'); // Display unit place of minute
    show_char(':');
    show_char(second / 10 + '0'); // Display tens place of second
    show_char(second % 10 + '0'); // Display unit place of second
}

// Function to display date on the LCD
void display_date(unsigned char day, unsigned char month, unsigned char year) {
    lcd_cmd(0xC0);  // Move to the second line
    show("Date: ");
    show_char(day / 10 + '0');   // Display tens place of day
    show_char(day % 10 + '0');   // Display unit place of day
    show_char('/');
    show_char(month / 10 + '0'); // Display tens place of month
    show_char(month % 10 + '0'); // Display unit place of month
    show_char('/');
    show_char(year / 10 + '0');  // Display tens place of year
    show_char(year % 10 + '0');  // Display unit place of year
}

// Function to send the date via UART
void send_date(unsigned char day, unsigned char month, unsigned char year) {
    UART_Send(day / 10 + '0');
    UART_Send(day % 10 + '0');
    UART_Send('/');
    UART_Send(month / 10 + '0');
    UART_Send(month % 10 + '0');
    UART_Send('/');
    UART_Send(year / 10 + '0');
    UART_Send(year % 10 + '0');
    UART_Send('\n'); // Newline for better formatting in serial output
}

void main() {
    unsigned char hour = 12, minute = 34, second = 56;
    unsigned char day = 8, month = 8, year = 24;
    
    lcd_init();      // Initialize the LCD
    UART_Init();     // Initialize UART
    
    while (1) {
        display_time(hour, minute, second); // Display time on the LCD
        display_date(day, month, year);     // Display date on the LCD
        send_date(day, month, year);        // Send date via UART continuosly

        // Update the time here if necessary (for example, increment seconds)
        // Simulate a delay for updating the time every second
        lcd_delay();
    }
}
