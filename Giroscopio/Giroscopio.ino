#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal.h>
//LiquidCrystal lcd(30, 31, 32, 33, 34, 35);
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  lcd.setCursor(5, 0);
  mpu6050.update();
  lcd.print("X : ");
  lcd.print(mpu6050.getAngleX());
   lcd.setCursor(6, 0);
  lcd.print("Y : ");
  lcd.print(mpu6050.getAngleY());
   lcd.setCursor(5, 1);
  lcd.print("Z : ");
  lcd.print(mpu6050.getAngleZ());
}
