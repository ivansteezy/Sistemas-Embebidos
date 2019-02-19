#include <Keypad.h>
#include <LiquidCrystal.h>
//Rojo encendido 
//Azul apagado

const byte NumRows = 4; 
const byte NumCol = 4;
byte rowPins[NumRows] = {6,7,8,9}; //Filukis
byte colPins[NumCol]= {10,11,12,13}; //Columnukis
const int pasosPorRevolucion = 200;
char Keymap[NumRows][NumCol] = {    { '1','2','3','A' },
                                    { '4','5','6','B' },
                                    { '7','8','9','C' },
                                    { '*','0','#','D' }};

Keypad Tecla(makeKeymap(Keymap), rowPins, colPins, NumRows, NumCol);
LiquidCrystal lcd(30, 31, 32, 33, 34, 35);
int cont = 1, Rojo = 2, Azul = 3;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);
  char k = '0';
  do{
  lcd.setCursor(0, 0);
  k = Tecla.getKey();
    if(k == '6')        cont++;
    else if (k == '4')  cont--;
    if(cont > 2 )       cont = 1;
    switch(cont){
      case 1: lcd.print("<-    Rojo    ->"); break;
      case 2: lcd.print("<-    Azul    ->"); break;
    }
 }while(k != 'B');
 
  if(cont == 1){
    lcd.print("Rojooo");
    delay(2000);
    analogWrite(Rojo, 255);
  }

  if(cont == 2){
    lcd.print("Azuuul");
    delay(2000);
    analogWrite(Azul, 255);
  }
  Serial.println(k);
}
