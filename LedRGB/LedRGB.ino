#define Verde 4
#define Azul 3
#define Rojo 2
int redFade, blueFade, greenFade;
void setup() {
  
}

void loop(){
  int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for(int i = 0, redFade =  255, blueFade = 0; i < 255 ; i ++, redFade--, greenFade++){
    analogWrite(Verde, 255 - greenFade);
    analogWrite(Rojo, 255 - redFade);
    delay(20);
  }

  for(int i = 0, greenVal = 255, blueFade = 0; i < 255 ; i++, blueFade++, greenFade--){
    analogWrite(Azul, 255 - blueFade);
    analogWrite(Verde, 255 - greenFade);
    delay(20);
  }

  for(int i = 0, blueFade = 255, redFade = 0; i < 255 ; i++, redFade++, blueFade--){
    analogWrite(Rojo, 255 - redFade);
    analogWrite(Azul, 255 - blueFade);
    delay(20);
  }
}
