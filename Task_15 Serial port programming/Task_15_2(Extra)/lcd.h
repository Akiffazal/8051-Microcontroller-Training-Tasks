#ifndef LCD_H
#define LCD_H

#include <reg51.h>

#define BUFFER_SIZE 50

// Global variables
extern char rx_buffer[BUFFER_SIZE];
extern unsigned int buffer_index;
extern bit message_complete;

// Function prototypes
void UART_Init(void);
void UART_Interrupt_Init(void);
void UART_ISR(void);
void ProcessMessage(void);

#endif // LCD_H
