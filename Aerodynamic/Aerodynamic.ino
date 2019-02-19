//Aerodynamic intro by Daft Punk 
 #include "pitches.h"
//acordes a usar en la cancion
int roluki[] = {
  NOTE_D4, NOTE_F3,  NOTE_B3,  NOTE_F3,      // D4-F3-B3-F3
  NOTE_D4, NOTE_GS3, NOTE_B3,  NOTE_GS3,     // D4-Ab3-B3-Ab3
  NOTE_G4, NOTE_B3,  NOTE_E4,  NOTE_B3,      // G4-B3-E4-B3
  NOTE_E4, NOTE_A3,  NOTE_CS4, NOTE_A3,      // E4-A3-C#4-A3
  NOTE_D4, NOTE_FS4, NOTE_B3,  NOTE_FS4,     // D4-F#4-B3-F#4
  NOTE_D4, NOTE_GS3, NOTE_B3,  NOTE_GS3,     // D4-Ab3-B3-Ab3
  NOTE_G4, NOTE_B3,  NOTE_E4,  NOTE_B3,      // G4-B3-E4-B3
  NOTE_E4, NOTE_A3,  NOTE_CS4, NOTE_A3,      // E4-A3-C#-A3
};

int Pin             = 4;             
int Beat            = 1000/4;    // cada acorde se repite 4 veces cada nota son corcheas a un compas de 4/4
float Compas        = 0.5;     
void setup() {
}
void loop() {
  for (int Acorde = 0; Acorde < 8; Acorde++) {                    //Tocara los 8 acordes
    for (int chordTone = 0; chordTone < 4; chordTone++) {         // 4 veces cada uno 
      for (int Repeticion = 0; Repeticion < 4; Repeticion++) {    // con 4 tonos cada uno 
        tone(Pin, roluki[Acorde * 4 + Repeticion], Compas * Beat);
        delay(Compas * Beat);
        noTone(Pin);
      }
    }
  }
}
