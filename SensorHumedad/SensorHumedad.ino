#include <LiquidCrystal.h>
#include <dht11.h>
#define DHT11_PIN 4
LiquidCrystal lcd (30, 31, 32, 33, 34, 35);
dht11 DHT;

void setup(){
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Humedad:");
  lcd.setCursor(10, 0);
  lcd.print("Temp:");
}

void loop(){
  int chk = DHT.read(DHT11_PIN);
  lcd.print(DHT.humidity);
  lcd.print(DHT.temperature);
  delay(500);
}

