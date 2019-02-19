#include <LiquidCrystal.h>
#include <Keypad.h>
//Inicializacion pantalla
const int rs = 30, e = 31, d4 = 32, d5 = 33, d6 = 34, d7 = 35;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
//Un arreglo para el momento de la separacion y otro que contendra las letras de las teclas
char Temp[6];
char Cadena[16];
String Tecla[12] = {"1", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ", "*", "0", "#"};
int cast, cont = 0, Sort = 0, pos;
char ant = 'ñ';
const byte numRows = 4; 
const byte numCols = 4; 
char Teclas[numRows][numCols]={{'1', '2', '3', 'A'},
                               {'4', '5', '6', 'B'},
                               {'7', '8', '9', 'C'},
                               {'*', '0', '#', 'D'}};
                               
byte rowPins[numRows] = {6,7,8,9}; //Filukis
byte colPins[numCols]= {10,11,12,13}; //Columnukis
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
Keypad Teclado = Keypad(makeKeymap(Teclas), rowPins, colPins, numRows, numCols);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hola");
}
//* -7
//# -14
//0-1
void loop(){
  char k = Teclado.getKey();
  cast = (int) k;
  cast =- 49;
  if(k == -1)   cast = 10;
  if(k == -14)  cast = 11;
  if(k == -7)   cast = 9;
  Tecla[cast].toCharArray(Temp, 6);  
  if(k != NO_KEY){
    if(k == 'A' || k == 'B' || k == 'C' || k == 'D')
      Seleccion();
    else
    Tiempo = millis();
    ResTiem = Tiempo - LastTiem;
    if(ResT > 1000){
      c++;
      x =- 1;
    }
    if(k == ant)  x++;
    else          x = 0;
    
  }
   ant = k;
   Temp[cont] = Cadena[Sort]; 
   Sort++;
    //en el caso de que sea 0, *, # u 1
   if(cast == 0 || cast == 10 || cast == 11 || cast == 9){
    cont = 0;
    lcd.print(Temp[cont]);
    ant = k;
    Temp[cont] = Cadena[Sort];
    Sort++;
   }
   
   if(Sort == 16){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Se ordenara.");
    lcd.clear();
    Ordenar();
   }
}

void Ordenar(){
  for(int i = 0; i < 16; i++){
    for(int j = i + 1; j < 16; j++){
      if(Cadena[i] > Cadena[j]){
        pos = Cadena[i];
        Cadena[i] = Cadena[j];
        Cadena[j] = pos;
      }
    }
  }
  lcd.print(Cadena);
}


