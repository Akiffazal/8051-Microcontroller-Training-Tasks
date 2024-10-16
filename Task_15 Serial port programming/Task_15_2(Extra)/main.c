#include "lcd.h"

void main(void) {
    UART_Init();
    UART_Interrupt_Init();

    while (1) {
        if (message_complete) {
            // Process the complete message
            ProcessMessage();

            // Clear the buffer and reset index
            buffer_index = 0;
            message_complete = 0;
        }
    }
}
