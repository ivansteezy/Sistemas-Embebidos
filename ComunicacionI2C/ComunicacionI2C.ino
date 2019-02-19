#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(30, 31, 32, 33, 34, 35);

void Teclado(){
  while(1 < Wire.available()){
    char Tecla = Wire.read();
    lcd.print(Tecla);
    }
}

void setup() {
  Wire.begin(8);
  Wire.onReceive(Taclado);
  lcd.begin(16, 2);
}

void loop() {
  delay(100);
}
