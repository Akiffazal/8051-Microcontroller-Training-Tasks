#include <reg51.h>
#include <stdio.h>
#include "LCD.h"

//#define LED P0

void main() {
    lcd_init();                 // Initialize LCD
    show("Hello, World!");     // Display "Hello, World!"
    while(1);                   // Infinite loop
}




