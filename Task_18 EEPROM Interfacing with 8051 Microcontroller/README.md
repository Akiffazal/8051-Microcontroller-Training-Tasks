# EEPROM Interfacing with 8051 Microcontroller

This project demonstrates how to interface an **EEPROM (24C02)** with the **8051 microcontroller** using a software-based I2C driver. The goal is to implement a counter that stores its value in EEPROM, preserving it between resets, and optimizing EEPROM write cycles to ensure long-term durability.

## Task Overview

### Task 18: EEPROM Interfacing

1. **Study the EEPROM (24C02) Datasheet**  
   - Studied the EEPROM 24C02 datasheet to understand its memory layout, I2C communication, and write cycle limitations.  

2. **I2C Driver Implementation**  
   - Developed a software-based I2C driver in C to communicate with the 24C02 EEPROM.  
   - Implemented functions for reading from and writing to EEPROM using I2C protocol.

3. **8-bit Counter Implementation**
   - Implemented an **8-bit counter** that increments every second.  
   - The counter value is displayed on **seven-segment displays**.  
   - Every second, the counter value is saved to EEPROM.
   - On **startup**, the counter reads the stored value from EEPROM, ensuring the counter resumes from where it left off before a reset.
   - If the EEPROM location is unwritten (value = `0xFF`), the counter starts from 0.
  
4. **EEPROM Write Cycle Optimization**
   - Based on the EEPROM datasheet, found the write cycle limitation (typically 1,000,000 write cycles).  
   - Reduced the frequency of writing the counter value to EEPROM to prolong its lifespan.
   - Calculated the delay between EEPROM writes to ensure the EEPROM lasts at least **10 years**.

5. **32-bit Counter Implementation**
   - Extended the counter to **4 bytes (32 bits)** to support larger numbers.  
   - The 32-bit counter is stored in **4 adjacent memory locations** in EEPROM.  
   - Used bitwise **shift** and **OR** (`|`) operations to assemble and disassemble the 4-byte values from EEPROM.
   - The counter value is also displayed on the seven-segment display.

## Project Structure

```
├── i2c_driver.c          # I2C driver for EEPROM communication
├── eeprom.c              # EEPROM read/write functions
├── counter.c             # 8-bit and 32-bit counter implementations
├── seven_segment.c       # Code to drive the seven-segment display
├── main.c                # Main program logic
└── README.md             # Project documentation
```

## Features

- **Software-based I2C communication**: No hardware I2C support required.
- **EEPROM-based counter storage**: Ensures counter value persistence across resets.
- **Optimized EEPROM writes**: Prolongs EEPROM lifespan by reducing write cycles.
- **32-bit counter support**: Allows counting larger values.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/username/eeprom-interfacing.git
   ```

2. Build and flash the program to your 8051 microcontroller using your preferred toolchain.

3. Connect the seven-segment display and EEPROM to the microcontroller as per the pin configuration.

4. Observe the counter incrementing every second and check the EEPROM persistence after resetting the board.

## Hardware Requirements

- 8051 Microcontroller (e.g., **STC89C52**)
- EEPROM IC (**24C02**)
- **Seven-segment display**
- Pull-up resistors for I2C communication
- **Push buttons** (for reset or control)

## Acknowledgements

- The EEPROM interfacing approach is based on the **Microchip 24C02** EEPROM datasheet.
  
## License

This project is licensed under the MIT License.
