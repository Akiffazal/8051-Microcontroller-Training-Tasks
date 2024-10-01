#include <reg51.h>

// Delay function to create a short delay
void lcd_delay() {
    unsigned int i;
    for (i = 0; i <= 70; i++);
}

// Function to send a character via UART
void uart_transmit(char c) {
    SBUF = c;                   // Place character in buffer
    while (TI == 0);            // Wait until transmission is complete
    TI = 0;                     // Clear the transmission interrupt flag
}

// Function to send a string via UART
void uart_transmit_string(char *s) {
    while (*s) {
        uart_transmit(*s++);    // Send each character
    }
}

void main(void) {
    TMOD = 0x20;            // Use Timer 1, mode 2
    TH1 = 0xFD;             // 9600 baud rate
    SCON = 0x50;            // Mode 1: 8-bit UART, variable baud rate
    TR1 = 1;                // Start Timer 1

    while (1) {
        uart_transmit_string("Hello World\n\r");      // Send string via UART
        lcd_delay();                            // Short delay
    }
}
