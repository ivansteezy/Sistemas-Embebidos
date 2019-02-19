#include <Keypad.h>

const byte numRows= 4; 
const byte numCols= 4; 

char Teclas[numRows][numCols]={{'1', '2', '3', 'A'},
                              {'4', '5', '6', 'B'},
                              {'7', '8', '9', 'C'},
                              {'*', '0', '#', 'D'}};

byte rowPins[numRows] = {6,7,8,9}; //Filukis
byte colPins[numCols]= {10,11,12,13}; //Columnukis

Keypad Teclado = Keypad(makeKeymap(Teclas), rowPins, colPins, numRows, numCols);

void Display(int a, int b, int c, int d, int e, int f, int g){
  digitalWrite(40, a);
  digitalWrite(41, b);
  digitalWrite(42, c);
  digitalWrite(43, d);
  digitalWrite(44, e);
  digitalWrite(45, f);
  digitalWrite(46, g);
}

void setup(){
  for(int i = 40; i < 47; i++)
    pinMode(i, OUTPUT);
}

void loop(){
  char Presionado = Teclado.getKey();
  switch(Presionado){
    case '0': Display(1,1,1,1,1,1,0); break;
    case '1': Display(0,1,1,0,0,0,0); break;
    case '2': Display(1,1,0,1,1,0,1); break;
    case '3': Display(1,1,1,1,0,0,1); break;
    case '4': Display(0,1,1,0,0,1,1); break;
    case '5': Display(1,0,1,1,0,1,1); break;
    case '6': Display(1,0,1,1,1,1,1); break;
    case '7': Display(1,1,1,0,0,0,0); break;
    case '8': Display(1,1,1,1,1,1,1); break;
    case '9': Display(1,1,1,1,0,1,1); break;
    case 'A': Display(1,1,1,0,1,1,1); break;
    case 'B': Display(0,0,1,1,1,1,1); break;
    case 'C': Display(1,0,0,1,1,1,0); break;
    case 'D': Display(0,1,1,1,1,0,1); break;
    case 'F': Display(1,0,0,0,1,1,1); break;
    case '*': Display(1,0,1,0,1,0,1); break;
    case '#': Display(1,0,0,0,0,0,1); break;
  }
}
