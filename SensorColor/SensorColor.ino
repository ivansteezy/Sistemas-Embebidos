#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define datoSensor 8
#include <LiquidCrystal.h>
LiquidCrystal lcd(28, 31, 32, 33, 34, 35);
int ComponenteR =0, ComponenteG = 0, ComponenteB = 0;
void AnalizarDatos(int R, int G, int B);
void setup() {
  lcd.begin(16, 2);
  pinMode(datoSensor, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);
}
/*
      |  L   |  L  |    ROJO
      |  L   |  H  |    AZUL  
      |  L   |  L  |    NO FILTRO
      |  H   |  H  |    VERDE
 */
void loop() {
  lcd.setCursor(5, 0);
  //rojo
  digitalWrite(S2, LOW);            
  digitalWrite(S3, LOW);
  ComponenteR = pulseIn(datoSensor, LOW);
  Serial.print("R = ");
  Serial.print(ComponenteR);
  Serial.print("  ");
  //delay(500);
  
  //verde
  digitalWrite(S2, HIGH);            
  digitalWrite(S3, HIGH);
  ComponenteG = pulseIn(datoSensor, LOW);
  Serial.print("G = ");
  Serial.print(ComponenteB);
  Serial.print("  ");
  //delay(500);

  //azul
  digitalWrite(S2, LOW);            
  digitalWrite(S3, HIGH);
  ComponenteB = pulseIn(datoSensor, LOW);
  Serial.print("B = ");
  Serial.print(ComponenteB);
  Serial.print("  ");
  //delay(500);
  Serial.print(" \n ");
  AnalizarDatos(ComponenteR, ComponenteG, ComponenteB);
}

void AnalizarDatos(int R, int G, int B){
  if((R <= 12 && R >= 10) && (G <= 12 && G >= 10) && (B <= 12 && B >= 10)){
      lcd.print("Azul");
      delay(500);
      lcd.clear();
  }
  if((R <= 27 && R >= 25) && (G <= 27 && G >= 25) && (B <= 27 && B >= 25)){
      lcd.print("Rojo");
      delay(500);
      lcd.clear();
  }
  
  if((R <= 23 && R >= 21) && (G <= 23 && G >= 21) && (B <= 23 && B >= 21)){
      lcd.print("Naranja");
      delay(500);
      lcd.clear();
  }
 if((R <= 17 && R >= 15) && (G <= 17 && G >= 15) && (B <= 17&& B >= 15)){
      lcd.print("Verde");
      delay(500);
      lcd.clear();
  }
  
}
