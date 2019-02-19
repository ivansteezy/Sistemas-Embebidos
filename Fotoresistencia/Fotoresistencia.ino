#include <LiquidCrystal.h>
LiquidCrystal lcd(30, 31, 32, 33, 34, 35);
int Dato = A0;
const int A = 1000;
const int B = 10;
const int Rc = 10;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(Dato, INPUT);
}

void loop(){
  lcd.clear();
  lcd.setCursor(5, 0);
  int v = analogRead(Dato);
  long lumen = (((long)v * A * 10) / ((long)B * Rc * (1024 - v)));
  lcd.print(lumen);
  delay(100);
}
