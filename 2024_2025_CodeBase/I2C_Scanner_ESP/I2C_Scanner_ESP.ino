// I2C Debugging Code  -> if we want to add multiple displays to a singular board

/* PLEASE NOTE : ONLY FOR ESP32 */

#include <Wire.h>

void setup() {
  Wire.begin(21, 22);  // Set SDA and SCL pins for the ESP32
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  scanI2C();
}

void loop() {
  // Nothing to do here
}

void scanI2C() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }

  delay(5000);  // Wait 5 seconds before next scan
}