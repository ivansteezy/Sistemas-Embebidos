#include <LiquidCrystal.h>
LiquidCrystal lcd(30,31, 32, 33, 34, 35);
int Cont = 0, Pin = 10, val, PinInt;
void setup(){
  lcd.begin(16, 2);
  pinMode(Pin, INPUT);
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Contador: ");
  lcd.setCursor(0, 11);
  lcd.print(Cont);
  //val = digitalRead(Pin);
  if(digitalRead(Pin))     Cont++;
  if(digitalRead(PinInt))  attachInterrupt(2, Tiempo, RISING);
}

void Tiempo(){
  lcd.print("hola");
}

void Delay(){
  delay(1000);
}

