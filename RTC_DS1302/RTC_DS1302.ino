
// DS1302:  CE pin    -> Arduino Digital 2
//          I/O pin   -> Arduino Digital 3
//          SCLK pin  -> Arduino Digital 4
// LCD:     DB7       -> Arduino Digital 6
//          DB6       -> Arduino Digital 7
//          DB5       -> Arduino Digital 8
//          DB4       -> Arduino Digital 9
//          E         -> Arduino Digital 10
//          RS        -> Arduino Digital 11

#include <LiquidCrystal.h>
#include <DS1302.h>

// Inicializar el DS1302
DS1302 rtc(2, 3, 4);

LiquidCrystal lcd(11, 10, 9, 8, 7, 6);
void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  
  // Setup LCD to 16x2 characters
  lcd.begin(16, 2);
/*
  // Estas lineas pueden ser descomentadas para usar los que se han guardado previamente
  rtc.setDOW(FRIDAY);        // el dia a FRIDAY
  rtc.setTime(12, 0, 0);     // tiempo a 12:00:00 (formato 24hr)
  rtc.setDate(10, 05, 2018);   // 10 de mayo 2018
*/}

void loop()
{

  lcd.setCursor(4, 0);
  lcd.print(rtc.getTimeStr());
  

  lcd.setCursor(0, 1);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  
  
  lcd.setCursor(6, 1);
  lcd.print(rtc.getDateStr());

  delay (1000);
}
