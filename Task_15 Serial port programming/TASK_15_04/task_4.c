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


void main() {
    unsigned char x;
    lcd_init();      // Initialize the LCD
    UART_Init();     // Initialize UART
    while (1) {
        x = RX_data();  // Receive data from UART
					show_char(x);   // Display the received character on the LCD
				
				lcd_delay();    // Delay for better visualization
			
    }
}
