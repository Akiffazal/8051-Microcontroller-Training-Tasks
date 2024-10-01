#include <reg52.h>

int cntr_100ms = 0; // Variable declaration;
int cntr_1000ms = 0;
char flag_100_ms = 0;
char flag_1000_ms = 0;

sbit LED_D1 = P2^0; // LED D1 Connected to port P2^0
sbit LED_D2 = P2^1; // LED D2 Connected to port P2^1
sbit LED_D3 = P2^2; // LED D3 Connected to port P2^2
sbit LED_D4 = P2^3; // LED D4 Connected to port P2^3


void ISR_timer0(void) interrupt 1 // Interrupt service routine of 10ms overflow
{
    cntr_100ms++;

    if (cntr_100ms >= 2500) // If counter reaches 10 it means 100 ms have passed
    {
        LED_D1 = ~LED_D1; // Toggle the LED D1
        flag_100_ms = 1;  // Raise the 100 ms flag
        cntr_100ms = 0;   // Restart this counter
    }

    cntr_1000ms++;

    if (cntr_1000ms >= 25000) // If this counter reaches 100 it means 1000 ms have passed
    {
        LED_D2 = ~LED_D2; // Toggle the LED D2
        cntr_1000ms = 0;
        flag_1000_ms = 1; // Raise the 1000 ms flag
    }
}


void main(void)
{
    IE = 0x82;           // Enable Timer 0 interrupt
    TMOD = 0x02;         // Set Timer 0 mode to 8-bit auto reload
    TH0 = -23;           // Set initial value for Timer 0 high byte
    TR0 = 1;             // Start Timer 0

    while (1)
    {
        if (flag_100_ms)
        {
            flag_100_ms = 0;
            LED_D3 = ~LED_D3; // Toggle the LED D3
            // This block of code will execute after every 100 ms
        }

        if (flag_1000_ms)
        {
            flag_1000_ms = 0;
            LED_D4 = ~LED_D4; // Toggle the LED D4
            // This block of code will execute after every 1000 ms
        }
    }
}


