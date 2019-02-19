#include <LiquidCrystal.h>
#include <Keypad.h>
#include <String.h>

const int rs = 30, en = 31, d4 = 32, d5 = 33, d6 = 34, d7 = 35;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char ant = ' ';      //Se quiere que este sea incorrecto siempre para que pueda entrar a la condicion
char Temp[6];
int x = 0; //contador para las letras
int cont = -1; //contador para las posiciones
long LastT = 0, TiempoActual = 0;
char Cadena[16];

const byte NumRows = 4; 
const byte NumCol = 4;

byte rowPins[NumRows] = {6,7,8,9}; //Filukis
byte colPins[NumCol]= {10,11,12,13}; //Columnukis

char Keymap[NumRows][NumCol] = {    { '1','2','3','A' },
                                    { '4','5','6','B' },
                                    { '7','8','9','C' },
                                    { '*','0','#','D' }};
                                    
String Letras[12] = { "1", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ", "*", "0", "#"};
Keypad Tecla(makeKeymap(Keymap), rowPins, colPins, NumRows, NumCol);

void setup() {
  lcd.begin(16,2);
  lcd.print("Ingrese su cadena");
}

void loop(){
  char k = Tecla.getKey();
  int i = (int) k;     //mi caracter indicador convertido en entero
  i -= 49;      
  if(i == -1)
  i = 10;
  else if(i == -7)
  i = 9;
  else if(i == -14)
  i = 11;
  
  Letras[i].toCharArray(Temp, 6);
  
  if(k != NO_KEY){
    if(k == 'A' ||k == 'B' ||k == 'C' ||k == 'D')
      Ordenar();
    else{
        TiempoActual = millis();
        if((TiempoActual - LastT) > 1000){ //Al menos ha pasado un segundo
          cont++;
          x = -1;
        }
        
        if(k == ant) //caracter anterior
          x++;
        else
          x = 0;
        
        if(i == 0 || i == 9 || i == 10 || i == 11)
          x = 0;
        else if(i == 6 || i == 8){
          if (x > 4)
            x = 0;
        }
        else{
          if(x > 3)
              x = 0;
        }
    
      lcd.setCursor(cont, 1);
      lcd.print(Temp[x]);
      
      ant = k;
      LastT = TiempoActual;
      Cadena[cont] = Temp[x];
    }
  }
}

void Ordenar(){
  for(int i = 0; i < cont + 1; i++ ){
    float min = Cadena[i];
    int minP = i;
  for (int j = i; j < cont + 1; j++){
      if(Cadena[j] < min){
        min = Cadena[j];
        minP = j;
      }
    }
    
    int temp = Cadena[i];
    Cadena[i] = Cadena[minP];
    Cadena[minP] = temp;
    lcd.setCursor(0,1);
  for(int g = 0; g < cont + 1; g++)
    lcd.print(Cadena[g]);
  }
}

