# DS1302 RTC Interfacing with STC89C52 Microcontroller

This project demonstrates the interfacing of the DS1302 Real-Time Clock (RTC) with the STC89C52 microcontroller. The project includes reading and displaying the current time on a 16x2 LCD and setting the time via a serial interface using the Hercules software.

## Features
- **Real-Time Clock (DS1302) Interface:** Reads and writes date and time.
- **Time Display on LCD:** Displays the time on a 16x2 LCD, updating every second.
- **Time Configuration via Serial Port:** Allows the user to set the RTC time using Hercules terminal software via a serial connection.

## Project Structure
- `DS1302.h`: Header file containing function prototypes and macro definitions for RTC operations.
- `DS1302.c`: Implementation of the RTC read, write, and configuration functions.
- `main.c`: Main code that integrates LCD, UART, and RTC functions.

## Hardware Requirements
- STC89C52 Microcontroller
- DS1302 RTC Module
- 16x2 LCD
- Serial communication setup with PC
- Hercules Setup Utility for serial communication
- Crystal Oscillator (for accurate timing)
- External Pull-Up Resistors for I2C Lines

## Software Requirements
- Keil µVision for writing and compiling the code.
- Hercules Setup Utility for setting time via UART.

## How It Works
1. **Reading Time:** The time is read from the DS1302 every second and displayed on the 16x2 LCD.
2. **Setting Time via UART:** Time can be set by sending time data (e.g., `HH:MM:SS`) through the Hercules terminal software. The MCU receives the data via UART, updates the RTC, and displays the updated time on the LCD.

## Usage
1. **Setup the Hardware:** Connect the DS1302 to the STC89C52 and the 16x2 LCD as per the datasheet pin configuration.
2. **Install Hercules Software:** [Download Hercules](https://www.hw-group.com/software/hercules-setup-utility) and configure it for serial communication.
3. **Run the Code:** Upload the code to the microcontroller using Keil and start the serial communication via Hercules.
4. **Set Time:** Use Hercules to send the desired time in `HH:MM:SS` format to set the RTC.
5. **Display Time:** The current time is automatically updated and displayed on the LCD every second.

## File Descriptions
- **`DS1302.h`:** Contains the necessary function declarations for interacting with the RTC.
- **`DS1302.c`:** Includes the implementation for reading, writing, and setting the RTC time.
- **`main.c`:** Integrates UART communication, LCD display, and RTC functionality, controlling the overall flow of the project.

## References
- [DS1302 Datasheet](https://datasheets.maximintegrated.com/en/ds/DS1302.pdf)

## License
This project is open source and available under the MIT License.
