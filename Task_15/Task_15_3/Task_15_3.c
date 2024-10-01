#include <reg51.h>
#include "lcd.h"

// Function to initialize the UART
void UART_Init() {
    TMOD = 0x20;     // Timer 1, Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;      // Baud rate of 9600 for 11.0592 MHz clock
    SCON = 0x50;     // Mode 1, 8-bit UART, enable receiver
    TR1 = 1;         // Start Timer 1
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
    lcd_init();           // Initialize the LCD
    UART_Init();          // Initialize UART
    while (1) {
        x = RX_data();    // Receive data from UART
				if(x=='0')
					lcd_cmd(0xC0);  // Go to 2nd line
				else if(x=='1')
					lcd_cmd(0x01);  // Clear the LCD
				else
					show_char(x);   // Display the received character on the LCD
				
				lcd_delay();      // Delay for better visualization
			
    }
}





























//#include <reg51.h>
//#include "lcd.h"

//// Define constants
//#define BUFFER_SIZE 50

//// Function to initialize the UART
//void UART_Init() {
//    TMOD = 0x20;  // Timer 1, Mode 2 (8-bit auto-reload)
//    TH1 = 0xFD;   // Baud rate of 9600 for 11.0592 MHz clock
//    SCON = 0x50;  // Mode 1, 8-bit UART, enable receiver
//    TR1 = 1;      // Start Timer 1
//}

//// Function to receive data via UART
//unsigned char RX_data(void) {
//    while (RI == 0);  // Wait until reception is complete
//    RI = 0;           // Clear the reception interrupt flag
//    return SBUF;      // Read received data
//}

//// Main function
//void main() {
//    unsigned char received_char;
//    unsigned char buffer[BUFFER_SIZE];
//    unsigned int i = 0;

//    lcd_init();      // Initialize the LCD
//    UART_Init();     // Initialize UART

//    while (1) {
//        received_char = RX_data();  // Receive data from UART

//        // Store received character in buffer
//        if (i < BUFFER_SIZE - 1) {
//            buffer[i] = received_char;
//            i++;
//        }

//        // Check if the end of the message "\n\r" is received
//        if (i >= 2 && buffer[i-2] == '\n' && buffer[i-1] == '\r') {
//            buffer[i-2] = '\0';  // Null-terminate the message
//            lcd_cmd(0x01);  // Clear the LCD
//            show_char(buffer);  // Display the received message on the LCD
//            i = 0;  // Reset buffer index for next message
//        }
//    }
//}
