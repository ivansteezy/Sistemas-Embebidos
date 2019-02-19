#define IN1  0
#define IN2  1
#define IN3  2
#define IN4  3

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Stepper.h>

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
Stepper motorPasos(pasosPorRevolucion, IN1, IN2, IN3, IN4);
int contPaso = 0, contVuelta = 0;

void setup() {
    lcd.begin(16, 2);
    motorPasos.setSpeed(100);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
  char k = '0';
  do{
  k = Tecla.getKey();
    do{
      lcd.setCursor(0, 0);
      lcd.print("<-   1 Paso   ->");
      lcd.setCursor(0, 0);
      contPaso = 0;
      k = Tecla.getKey();
    }while(k != '6' && k != '5');
    
    while(k != '4' && k != '5'){
      lcd.setCursor(0, 0);
      lcd.print("<-  1/2 Paso  ->");
      lcd.setCursor(0, 0);
      contPaso = 1;
      k = Tecla.getKey();
    }
 }while(k != '5');
 //----------------------------------------
 k = '0';
 do{
    do{
      lcd.setCursor(0, 0);
      lcd.print("<-    Izq.    ->");
      lcd.setCursor(0, 0);
      contVuelta = 0;
      k = Tecla.getKey();
    }while(k != '6' && k != '5');
     
    while(k != '4' && k != '5'){
      lcd.setCursor(0, 0);
      lcd.print("<-    Der.    ->");
      lcd.setCursor(0, 0);
      contVuelta = 1;
      k = Tecla.getKey();
    }
}while(k != '5');
  Motor(contPaso, contVuelta);
  //delay(3000);
}

//si contador paso == 1 then 1 paso && si contadorvuelta == 1 vuelta a la derecha.
void Motor(int Paso, int Vuelta){
  char k = 0;
  do{
  //1/2 paso a la izquierda
    if(Paso == 0 && Vuelta == 0){
      motorPasos.step((-pasosPorRevolucion) / 2);
      delay(500);
    }
      
      
  //1 paso a la derecha     
    if(Paso == 0 && Vuelta == 1){
      motorPasos.step(pasosPorRevolucion);
      delay(500);
    }
    
  //1 paso a la izquierda    
    if(Paso == 1 && Vuelta == 0){
      motorPasos.step(-pasosPorRevolucion);
      delay(500);
    }
    
  //1/2 paso a la derecha     
    if(Paso == 1 && Vuelta == 1){
      motorPasos.step(pasosPorRevolucion / 2);
      delay(500);
    }
      k = Tecla.getKey();
  }while(k != '5'); 
}
