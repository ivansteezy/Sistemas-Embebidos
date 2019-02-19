#include "U8glib.h"
#include <Keypad.h>
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);  // Inicializacion para la comunicacion i2c de esta pantalla

const byte numRows = 4; 
const byte numCols = 4; 
char Teclas[numRows][numCols]={{'1', '2', '3', 'A'},
                               {'4', '5', '6', 'B'},
                               {'7', '8', '9', 'C'},
                               {'*', '0', '#', 'D'}};
                              
byte rowPins[numRows] = {6,7,8,9}; //Filukis
byte colPins[numCols]= {10,11,12,13}; //Columnukis
Keypad Teclado = Keypad(makeKeymap(Teclas), rowPins, colPins, numRows, numCols);

void GetKey(void) {
  char Presionado = Teclado.getKey();
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  
  //u8g.drawStr( 0+10, 20+10, "Anime is now");
  //u8g.drawStr(30, 60, "legal!");  
  switch(Presionado){
    case '1': u8g.drawStr(10, 30, "1"); break;
    case '2': u8g.drawStr(10, 30, "2"); break;
    case '3': u8g.drawStr(10, 30, "3"); break;
    case 'A': u8g.drawStr(10, 30, "A"); break;
  }
}

void setup(void) {
  u8g.setFont(u8g_font_unifont);
}

void lo      op(void) {
  u8g.firstPage();
  do {
    GetKey();
  } while( u8g.nextPage() );
  delay(100);
}

