#include <reg51.h>

sbit motor_pin = P2^0;  // Define the motor control pin

// Function to create a delay in microseconds (approximate)
void delay_us(unsigned int us)
{
    unsigned int i;
    while(us--)
    {
        for(i = 0; i < 12; i++);  // 1 machine cycle ~1 microsecond on 12 MHz clock
    }
}

// Function to generate a PWM signal with a specified high time (in microseconds)
void generate_pwm(unsigned int high_time_us)
{
    // Set pin high for the specified high time
    motor_pin = 1;
    delay_us(high_time_us);  // High for high_time_us microseconds

    // Set pin low for the remaining period of the 20ms cycle
    motor_pin = 0;
    delay_us(20000 - high_time_us);  // Low for the rest of the 20ms period
}

void main()
{
    while(1)
    {
        // 0 degree: 0.5ms high time (500us)
//        generate_pwm(500);

        // Uncomment the below line to test 45 degrees
        // 45 degree: 1ms high time (1000us)
         generate_pwm(1000);
    }
}
