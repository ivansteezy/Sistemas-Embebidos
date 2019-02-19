  #include "U8glib.h"
  #include "Starmen.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_FAST); //Inicializacion i2c

void draw(){
  //if(frame == 0)
    u8g.drawBitmapP(0, 0, 16, 64, frame_1);
  /*else if(frame == 1)
    u8g.drawBitmapP(0, 0, 16, 64, freme2);
  else if(frame == 2)
    u8g.drawBitmapP(0, 0, 16, 64, frame3); */
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  u8g.firstPage();
  do{
   draw();
 } while(u8g.nextPage());
}
