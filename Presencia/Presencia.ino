int Sensor = 8, Rele = 9;
void setup() {
    Serial.begin(9600);
    pinMode(Rele, OUTPUT);
    pinMode(Sensor, INPUT);   
}

void loop(){
    int val = digitalRead(Sensor);
    delay(500);
    if(val == HIGH){
      digitalWrite(Rele, LOW);
      Serial.print("Hay alguien.");
      Serial.print("\n");
    }
     else{
      Serial.print("No hay nadie.");
      Serial.print("\n");
      digitalWrite(Rele, HIGH);
     }
}
