#include <LiquidCrystal.h>
#include <Keypad.h>
#include "pitches.h"

LiquidCrystal lcd(30, 31, 32, 33, 34, 35);
int Escala[8] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int pin = 4;

const byte NumRows = 4;
const byte NumCol = 4;
byte rowPins[NumRows] = {6,  7,  8,  9}; //Filas del teclado
byte colPins[NumCol] =  {10, 11, 12, 13};//Columnas del teclado

char Keymap[NumRows][NumCol] = {{'1', '2', '3', 'A'},
                                {'4', '5', '6', 'B'},
                                {'7', '8', '9', 'C'},
                                {'*', '0', '#', 'D'}};

Keypad Tecla(makeKeymap(Keymap), rowPins, colPins, NumRows, NumCol);

void setup(){
  
}

void loop(){
  lcd.setCursor(4, 0);
  char k = Tecla.getKey();
  if(k != NO_KEY){
    switch(k){
      case '1': tone(4, Escala[0]); lcd.print("Do"); break;
      case '2': tone(4, Escala[1]); lcd.print("Re"); break;
      case '3': tone(4, Escala[2]); lcd.print("Mi"); break;
      case '4': tone(4, Escala[3]); lcd.print("Fa"); break;
      case '5': tone(4, Escala[4]); lcd.print("Sol"); break;
      case '6': tone(4, Escala[5]); lcd.print("La"); break;
      case '7': tone(4, Escala[6]); lcd.print("Si"); break;
      case '8': tone(4, Escala[7]); lcd.print("Do"); break;
    }
  }
}
