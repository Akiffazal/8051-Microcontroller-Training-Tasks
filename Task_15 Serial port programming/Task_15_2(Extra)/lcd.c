#include "lcd.h"

// Global variables
char rx_buffer[BUFFER_SIZE];
unsigned int buffer_index = 0;
bit message_complete = 0;


void UART_Init(void) {
    TMOD = 0x20;  // Timer1 mode 2 (8-bit auto-reload)
    TH1 = 0xFD;   // 9600 baud rate for 11.0592 MHz clock
    SCON = 0x50;  // 8-bit data, 1 stop bit, REN enabled
    TR1 = 1;      // Start Timer1
}


void UART_Interrupt_Init(void) 
	{
    EA = 1;       // Enable global interrupts
    ES = 1;       // Enable serial interrupt
	}


// UART Interrupt Service Routine
void UART_ISR(void) interrupt 4 
	{
		char received_char; 
			if (RI) {
					RI = 0;  // Clear the receive interrupt flag

					received_char = SBUF;  // Read the received character
					if (buffer_index < sizeof(rx_buffer) - 1) {
							rx_buffer[buffer_index++] = received_char;

							// Check for message termination
							if (buffer_index >= 2 && rx_buffer[buffer_index - 2] == '\n' && rx_buffer[buffer_index - 1] == '\r') {
									message_complete = 1;
									rx_buffer[buffer_index] = '\0'; // Null-terminate the string
							}
					} else {
							// Buffer overflow, reset index
							buffer_index = 0;
					}
			}

	}

void ProcessMessage(void) {
    // Set all bits of Port 2 high to turn on all LEDs
    P2 = 0xFF;

    // Delay to keep LEDs on for a visible duration (simple delay)
    {
	  unsigned int i, j;
    for (i = 0; i < 50000; i++) {
        for (j = 0; j < 5; j++);
    }
	}

    // Turn off all LEDs
    P2 = 0x00;
}

