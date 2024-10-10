# BAJA-UW
Github for all things BAJA SAE 

Repository Breakdown</br>

![image](https://github.com/user-attachments/assets/b95e18c9-95e1-47b1-9bae-a60cd33fd22c)
      
</br>
</br>
What does Each Directory Do?</br>
Code Base: </br>
      - This portion of the repository is the code for the data acquisition system (rpm, accelerometer, and strain gauge)</br></br>

Electrical:</br>
      - This is the part of the repo with all necessary parts for the hardware side including resistor parts, schematics for things we want to design, etc.</br>
      - NOTE: schematics for the data acquisition system will also go here</br></br>

Mech Bridge:</br>
      - This directory is used to store CAD for mounts, holders, etc. for our electrical components that will need to be mounted onto the car</br></br>


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
