#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
byte frame[8][12] = {
  { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

unsigned long previousActionMillis = 0;

void setup() {
  matrix.begin();
  // put your setup code here, to run once:

}

void loop() {
  unsigned long delayMillis = 30;

  unsigned long currentMillis = millis();
  if(currentMillis - previousActionMillis > delayMillis){
    previousActionMillis = currentMillis;
    for(int i = 0; i < 8; i++){
      int startBit = frame[i][0];
      for (int j = 0; j<11; j++){
       frame[i][j] = frame[i][j+1];
    }
    frame[i][11] = startBit;
  }
  }
  
matrix.renderBitmap(frame, 8, 12);
  // put your main code here, to run repeatedly:

}
