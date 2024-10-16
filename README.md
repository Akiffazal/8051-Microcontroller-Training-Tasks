# STC89C52 (8051) Training Tasks

This repository contains the completed tasks from the STC89C52 training manual, covering a range of embedded systems concepts and practical applications. Each task folder contains the code, simulations, and related resources. The tasks are performed on the STC89C52 microcontroller using C language.

## Tasks Overview

### 1. **Development Environment Setup**
   - Set up the development environment and IDE.
   - Reviewed the datasheet and board schematics.
   - Installed drivers and tools for development.

### 2. **Logic Analyzer Setup**
   - Installed and configured the Logic 1.2.18 software.
   - Set up the logic analyzer to capture and analyze digital signals.

### 3. **LED Blinking**
   - Blinks LED D1 with a 500 ms delay.
   - Measured the delay using a logic analyzer.

### 4. **LED Pattern**
   - Blinked LEDs in an alternating pattern (D1, D3, D5, D7 ON and D2, D4, D6, D8 OFF).

### 5. **Button Interfacing (Polling)**
   - Controlled LED D1 using button K1 with polling.
   - Added debouncing to avoid multiple triggers on a single press.

### 6. **Button Interfacing (Interrupt)**
   - Controlled LED D1 using button K1 with an interrupt-based approach.
   - Implemented debouncing for accurate button detection.

### 7. **LED Control Using Buttons (Polling)**
   - Used buttons K1 to K4 to control LEDs D1 to D4 using a polling mechanism.

### 8. **LED Control Using Buttons (Interrupt)**
   - Controlled LEDs D1 to D4 using interrupts for button presses, along with debouncing.

### 9. **Timer Interrupt**
   - Configured a timer to generate an interrupt every 10 ms.
   - Toggled LED D1 in the ISR (Interrupt Service Routine).

### 10. **Delay Generation with Timer**
   - Generated delays of 100 ms and 1000 ms using the timer interrupt.
   - Controlled multiple LEDs with different timing intervals (LED D1: 10 ms, LED D2: 100 ms, LED D3: 1000 ms).

### 11. **Button Debouncing Using Timer Interrupt**
   - Implemented debouncing for button K1 using a timer interrupt, ensuring reliable detection of press and release events.

### 12. **Seven-Segment Display Interfacing**
   - Controlled the 7-segment displays using multiplexing.
   - Displayed numbers and implemented a lookup table for digits 0-9.

### 13. **File Organization with `.h` and `.c` Files**
   - Organized code into `.h` and `.c` files.
   - Created reusable components like `LCD.h` and `LCD.c` for LCD functionality.

### 14. **16x2 LCD Interfacing**
   - Interfaced with a 16x2 LCD using both 8-bit and 4-bit modes.
   - Displayed custom characters on the LCD and implemented necessary drivers.

### 15. **Serial Port Programming**
   - Sent and received data over the serial port at a baud rate of 9600.
   - Implemented functions to process and display data sent via serial communication on the LCD.

### 19. **Keypad Interfacing and Multi-Application State Machine**
   - Interfaced a 4x4 keypad with the STC89C52 microcontroller.
   - Displayed the pressed key on both the LCD and seven-segment display.
   - Developed a basic calculator supporting addition, subtraction, multiplication, and division.
   - Implemented a state machine to switch between three applications:
     1. **Calculator**: Performs basic arithmetic operations.
     2. **Real-Time Clock**: Displays time and date from the RTC.
     3. **Temperature Monitor**: Displays current temperature and allows setting a threshold via the keypad.
   - Pressing the ON/C button on the keypad switches between the applications.
   - Implemented non-blocking debounce for the keypad.
   - Organized the code into separate files for each application (`calculator.c`, `RTC.c`, `temp_monitor.c`).

## Project Structure

Each task is stored in a separate folder, organized as follows:

```
.
├── Task 1 - Setup
├── Task 2 - Logic Analyzer
├── Task 3 - LED Blinking
├── Task 4 - LED Pattern
├── Task 5 - Button Polling
├── Task 6 - Button Interrupt
├── Task 7 - LED Polling Control
├── Task 8 - LED Interrupt Control
├── Task 9 - Timer Interrupt
├── Task 10 - Timer Delays
├── Task 11 - Button Debouncing
├── Task 12 - Seven Segment Display
├── Task 13 - File Organization
├── Task 14 - LCD Interfacing
├── Task 15 - Serial Port Programming
└── Task 19 - Keypad Interfacing and Multi-Application State Machine
```

## Getting Started

To run any task:
1. Navigate to the corresponding folder.
2. Use the Keil IDE or your preferred toolchain to compile and upload the code to the STC89C52 microcontroller.
3. Refer to the task description for instructions on testing and verification.

## License

This project is for educational purposes and follows the instructions provided in the STC89C52 training manual.

---

This includes the new **Task 19** while keeping the original structure intact as requested.
