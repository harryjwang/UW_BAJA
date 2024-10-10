#include <MPU6050_tockn.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "sd_read_write.h"
#include "SD_MMC.h"

#define SDA 21
#define SCL 22
#define SD_MMC_CMD 15
#define SD_MMC_CLK 14
#define SD_MMC_D0  2

LiquidCrystal_I2C lcd1(0x27, 16, 2);

MPU6050 mpu6050(Wire);

int16_t ax, ay, az;
float ax_con, ay_con, az_con;
String data;
long timer = 0;


void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SCL); 

  // Start LCDs
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(0, 0);
  lcd1.print("LCD 1 Ready");
  lcd1.setCursor(0, 0);

  // Start MPU6050
  mpu6050.begin(); 
  mpu6050.calcGyroOffsets(true);

  // Start SD card
  SD_MMC.setPins(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0);

  if (!SD_MMC.begin("/sdcard", true, true, SDMMC_FREQ_DEFAULT, 5)) {
    lcd1.print("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD_MMC.cardType();
  if(cardType == CARD_NONE){
    lcd1.print("No SD_MMC card attached");
    return;
  }

  writeFile(SD_MMC, "/data.csv", "x,y,z\n");

  delay(2000);
}

void loop() {
  if (millis() - timer > 500) {   // Wait 5 seconds between updates

    // Clear and update LCD 1 with accelerometer data
    lcd1.clear();
    mpu6050.update();
    getMotion6();

    Serial.print("Accel Data - ");
    Serial.print("X: "); Serial.print(ax); Serial.print("g, ");
    Serial.print("Y: "); Serial.print(ay); Serial.print("g, ");
    Serial.print("Z: "); Serial.print(az); Serial.println("g");

    lcd1.setCursor(0, 0); 
    lcd1.print("Accel X:"); lcd1.print(ax_con, 2); 
    lcd1.setCursor(0, 1);
    lcd1.print("Y:"); lcd1.print(ay_con, 2);
    lcd1.print(" Z:"); lcd1.print(az_con, 2);

    data = String(ax_con, 4)+","+String(ay_con, 4)+","+String(az_con, 4)+"\n";
    appendFile(SD_MMC, "/data.csv", data.c_str());

    timer = millis();  // Reset the timer for the next cycle
  }
}

// Function to get accelerometer data
void getMotion6(void) {
  ax = mpu6050.getRawAccX();
  ay = mpu6050.getRawAccY();
  az = mpu6050.getRawAccZ();

  ax_con = (float)ax * 9.8 / 16384;
  ay_con = (float)ay * 9.8 / 16384;
  az_con = (float)az * 9.8 / 16384;
}
