# BAJA-UW
Github for all things BAJA SAE 

Repository Breakdown
|- 2024_2025_REPO
      |- Codebase
            |- Accelerometer Code (need z value updates)
            |- ESP I2C Scanner
            |- Arduino Nano I2C Scanner (in progress)
            |- RPM Code
      |- Electrical
            |- Resistor Inventory
            |- Wiring Schematics
                  |- Fun Buzzer w/ Audio
                  |- Elvis's Kill swtich and Battery System Schematics
                  |- Harry's Full Car Schematic With All systems
      |- Mech_Bridge
            |- Battery Mount (2023-2024)
|- Archives
|- README.md

What does Each Directory Do?
Code Base: 
      - This portion of the repository is the code for the data acquisition system (rpm, accelerometer, and strain gauge)

Electrical:
      - This is the part of the repo with all of the necessary parts for the hardware side includin resistor parts, schematics for things we want to design, etc.
      - NOTE: schematics for the data acquisition system will also go here

Mech Bridge:
      - This directory is used to store CAD for mounts, holders, etc. for our electrical components that will need to be mounted onto the car


what you will need for the code to work

1. Install and add esp32 json to Arduino IDE, allows you to upload to an esp32

      Arduino -> File -> Preferences -> Additional boards manager URLs: -> https://espressif.github.io/arduino-esp32/package_esp32_index.json
   
2. Install MCP2515 Library, add functions for CAN module
   
      Download the ZIP file from https://github.com/autowp/arduino-mcp2515/archive/master.zip

      From the Arduino IDE: Sketch -> Include Library... -> Add .ZIP Library...
   
3. Install LiquidCrystal I2C library, add functions for LCD screen
   
      https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

4. Install SDfat.h library, add functions for SD card module
   
      https://github.com/greiman/SdFat

5. Install Adafruit ADXL345 library, add functions for Accelaration Module, ADXL345
   
      https://github.com/adafruit/Adafruit_ADXL345
