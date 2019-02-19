//Contraseña en pantalla
#include <LiquidCrystal.h>
#include <Keypad.h>
void evaluarContrasena();
//Inicializacion para pantalla y teclado
char Psswd[8];
int rs = 40, e = 41, d4 = 42, d5 = 43, d6 = 44, d7 = 45, Pos = 3, i = 0, Cont = 0;
char Contrasena[8] = {'1', '5', '1', '0', '0', '0', '4', '2'};
const byte numRows = 4; 
const byte numCols = 4; 
char Teclas[numRows][numCols]={{'1', '2', '3', 'A'},
                               {'4', '5', '6', 'B'},
                               {'7', '8', '9', 'C'},
                               {'*', '0', '#', 'D'}};
                              
byte rowPins[numRows] = {6,7,8,9}; //Filukis
byte colPins[numCols]= {10,11,12,13}; //Columnukis
Keypad Teclado = Keypad(makeKeymap(Teclas), rowPins, colPins, numRows, numCols);  //Instancias de la pantalla
LiquidCrystal Lcd(rs, e, d4, d5, d6, d7);                                         //y teclado

void setup() {
  Lcd.begin(16, 2);  
  Lcd.setCursor(3, 0);
  Lcd.print("Contrasena:");
  for(int i = 6; i < 14; i++)
    pinMode(i, INPUT);
}

void loop(){
  char Presionado = Teclado.getKey();
  if(Cont < 8){
    if(Presionado != NO_KEY){
      Psswd[i] = Presionado;
      Lcd.setCursor(Pos, 1);
      Lcd.print("*");
      Pos++;  Cont++; i++;
      }
  }
  if(Presionado == '#')
    evaluarContrasena();
}

void evaluarContrasena(){
  for(int i = 0; i < 8; i++){
    if(Contrasena[i] != Psswd[i]){
      Lcd.setCursor(2, 1);
      Lcd.print("Incorrecto");
    }
    else{
      Lcd.setCursor(3, 1);
      Lcd.print("Correcto");
    }
  }
}
