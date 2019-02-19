#include <HCSR04.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (30, 31, 32, 33, 34, 35);
UltraSonicDistanceSensor EntradaSensor(13, 12);  // 13 tri  12 echo

void setup () {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("La distancia es:");
}

void loop () {
    lcd.setCursor(4, 1);
    lcd.print(EntradaSensor.measureDistanceCm());
    lcd.setCursor(10, 1);
    lcd.print("cm.");
    delay(500);
}
