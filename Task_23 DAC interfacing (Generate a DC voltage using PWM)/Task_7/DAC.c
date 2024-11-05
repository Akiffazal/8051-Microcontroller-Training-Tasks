#include <reg51.h>
#include "math.h"

unsigned int  i;
sbit PWM_PIN = P2^1;

unsigned int ON_Period, OFF_Period;
unsigned int index = 0;

unsigned int sine_wave[49] = {0x80,0x90,0xA1,0xB1,0xC0,0xCD,0xDA,0xE5,0xEE,0xF6,0xFB,0xFE,0xFF, 
                              0xFE,0xFB,0xF6,0xEE,0xE5,0xDA,0xCD,0xC0,0xB1,0xA1,0x90,0x80,0x70,
                              0x80,0x5F,0x4F,0x40,0x33,0x26,0x1B,0x12,0x0A,0x05,0x02,0x00,0x02,
                              0x05, 0x0A,0x12,0x1B,0x26,0x33,0x40,0x4F,0x5F,0x80}; // Values for one cycle of the sine wave

void Timer0_Init() {
    TMOD = 0x02;  // Timer 0, Mode 1: 16-bit timer with auto-reload
    TH0 = 0x00;   // Initial timer value
    TR0 = 1;
    IE = 0x82;
}

void Timer0_ISR() interrupt 1 {
    PWM_PIN = ~PWM_PIN;  // Toggle PWM_PIN

    if (PWM_PIN == 1) {
        TH0 = ON_Period >> 8;   // Set ON period for PWM
        TL0 = ON_Period;
    } else {
        TH0 = OFF_Period >> 8;  // Set OFF period for PWM
        TL0 = OFF_Period;
    }
}

void Set_Duty_Cycle(unsigned char duty_cycle) {
    unsigned int Period = 255;
    ON_Period = ((Period / 100.0) * duty_cycle);
    OFF_Period = Period - ON_Period;
    ON_Period = 255 - ON_Period;
    OFF_Period = 255 - OFF_Period;
}

void main() {
    Timer0_Init();  // Initialize Timer 0 for PWM generation

    while (1) {
        for (index = 0; index < 49; index++) {
            Set_Duty_Cycle(sine_wave[index]);
        }
    }
}

/* 
//Sawtooth Wave Form
#include <reg52.h>
#include <math.h>
#include "LCD.h"

unsigned int i;
sbit PWM_PIN = P2^1;

unsigned int ON_Period, OFF_Period;
unsigned int index = 0;

unsigned int sawtooth_wave[50] = {0x00, 0x05, 0x0A, 0x0F, 0x14, 0x19, 0x1E, 0x23, 0x28, 0x2D, 0x32, 0x37, 0x3C, 0x41,
                                  0x46, 0x4B, 0x50, 0x55, 0x5A, 0x5F, 0x64, 0x69, 0x6E, 0x73, 0x78, 0x7D, 0x82,
                                  0x87, 0x8C, 0x91, 0x96, 0x9B, 0xA0, 0xA5, 0xAA, 0xAF, 0xB4, 0xB9, 0xBE, 0xC3,
                                  0xC8, 0xCD, 0xD2, 0xD7, 0xDC, 0xE1, 0xE6, 0xEB, 0xF0, 0xF5}; // Values for one cycle of the sawtooth wave

void Timer0_Init() {
    TMOD = 0x02;  // Timer 0, Mode 1: 16-bit timer with auto-reload
    TH0 = 0x00;   // Initial timer value
    TR0 = 1;
    IE = 0x82;
}

void Timer0_ISR() interrupt 1 {
    PWM_PIN = ~PWM_PIN;  // Toggle PWM_PIN

    if (PWM_PIN == 1) {
        TH0 = ON_Period >> 8;   // Set ON period for PWM
        TL0 = ON_Period;
    } else {
        TH0 = OFF_Period >> 8;  // Set OFF period for PWM
        TL0 = OFF_Period;
    }
}

void Set_Duty_Cycle(unsigned char duty_cycle) {
    unsigned int Period = 255;
    ON_Period = ((Period / 100.0) * duty_cycle);
    OFF_Period = Period - ON_Period;
    ON_Period = 255 - ON_Period;
    OFF_Period = 255 - OFF_Period;
}

void main() {
    Timer0_Init();  // Initialize Timer 0 for PWM generation

    while (1) {
        for (index = 0; index < 50; index++) {
            Set_Duty_Cycle(sawtooth_wave[index]);
        }
    }
}
*/