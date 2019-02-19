int PinIn = 7;
int PinIn2 = 8;
int PinOut, x, y;
void setup() {
  pinMode(PinIn, INPUT);
  pinMode(PinOut, OUTPUT);
  
}

void loop() {
  x = digitalRead(PinIn);
  y = digitalRead(PinIn2);
  if(!x && !y)
    for(PinOut = 2; PinOut < 7; PinOut++){
      digitalWrite(PinOut, HIGH);
      delay(1000);
      digitalWrite(PinOut, LOW);
    }
  else if(!x && y)
    for(PinOut = 6; PinOut >= 2; PinOut--){
        digitalWrite(PinOut, HIGH);
        delay(1000);
        digitalWrite(PinOut, LOW);
      }
  else if(x && !y)
    for(PinOut = 6; PinOut >= 2; PinOut--){
        digitalWrite(PinOut, HIGH);
        delay(200);
        digitalWrite(PinOut, LOW);
      }
  else if(x && y)
  for(PinOut = 2; PinOut < 7; PinOut++){
      digitalWrite(PinOut, HIGH);
      delay(200);
      digitalWrite(PinOut, LOW);
    }
}
