#include "Arduino_LED_Matrix.h"

unsigned char letterA[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
unsigned char letterB[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
unsigned char letterC[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
unsigned char letterD[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
unsigned char letterE[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
unsigned char letterF[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
unsigned char letterG[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
unsigned char letterH[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
unsigned char letterI[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
unsigned char letterJ[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
unsigned char letterK[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
unsigned char letterL[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
unsigned char letterM[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
unsigned char letterN[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
unsigned char letterO[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
unsigned char letterP[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
unsigned char letterQ[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
unsigned char letterR[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
unsigned char letterS[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
unsigned char letterT[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char letterU[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
unsigned char letterV[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
unsigned char letterW[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
unsigned char letterX[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
unsigned char letterY[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
unsigned char letterZ[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte AlphabetMatrix[26][8][12] = {{{0}}};



ArduinoLEDMatrix matrix;
byte frame[8][36] = {
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
  { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
  { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
  { 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, },
  { 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, },
  { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, },
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, }
};

unsigned long previousActionMillis = 0;

unsigned int rows = 8;
unsigned int columns = 12;

unsigned char *Alphabet[] = {letterA, letterB, letterC, letterD, letterE, letterF, letterG, letterH, letterI, letterJ, letterK, letterL, letterM, letterN, letterO, letterP, letterQ, letterR, letterS, letterT, letterU, letterV, letterW, letterX, letterY, letterZ};
unsigned char AlphabetCharactersLower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


unsigned char* DisplayBuffer = nullptr;

unsigned char DisplayIndex = 0;
unsigned long DisplayLetterBeginMilliseconds = 0;
unsigned long DisplayLetterEndMilliseconds = 0;
bool DisplayActive = false;
 
//(INPUT >> N) & 1;

void setup() {
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 8; j++){
      for(int k = 0; k < 8; k++){
        bool testBit = (Alphabet[i][j] << k) & B10000000;
        AlphabetMatrix[i][j][k] = testBit;
      }
    }
  }
  matrix.begin();
  // put your setup code here, to run once:

}

//Resets the values used to time the duration of display.
void SetDisplayTiming(const unsigned displayMilliseconds)
{
    DisplayLetterBeginMilliseconds = millis();
    DisplayLetterEndMilliseconds = DisplayLetterBeginMilliseconds + displayMilliseconds;
    DisplayActive = true;
}

void UpdateDisplay()
{
    //Loop through rows.
    for(unsigned char i = 0; i < rows; i++)
    {
        //Loop through columns.
        for(unsigned char j = 0; j < columns; j++)
        {
            // //Turn column on for the corresponding bit.
            // digitalWrite(ColumnPins[j], ~DisplayBuffer[i] >> j & 1);
        }
        // //Turn on row to activate led.
        // digitalWrite(RowPins[i], 1);

        // //Uncomment the delay to increase brightness.  With 8 rows, any delay greater than 2 ms will cause flickering.  This is due to the refresh rate dropping below 60hz.
        // //delayMicroseconds(2000);

        // //Turn row back off.
        // digitalWrite(RowPins[i], 0);
    }
}


//Updates the DisplayBuffer to the corresponding letter.  Letter can be either uppercase, 'A', or lowercase 'a'.
void SetDisplayLetter(char letter)
{
    //If letter supplied is an uppercase letter, subtract 65 to zero the letter so it can be used as an index. (The 'A' character has an integer value of 65)
    if(letter > 64 && letter < 91) letter -= 65;
    //If letter supplied is a lowercase letter, subtract 97 to zero the letter so it can be used as an index.  (The 'a' character has an integer value of 97)
    else if(letter > 96 && letter < 123) letter -= 97;
    //Letter supplied is not a lowercase or uppercase letter, print error to serial.
    else
    {
        Serial.println("Error - Function: 'DisplayLetter' Cause: Specified Letter character is not an alphabet character");
        return;
    }
    DisplayBuffer = Alphabet[letter];
}
void SetDisplayLetter(const char letter, const unsigned displayMilliseconds)
{
    SetDisplayLetter(letter);
    SetDisplayTiming(displayMilliseconds);
}

//If it's time to display the next letter, do so.
void TryToDisplayNextLetter()
{
    //Letter is currently displayed, now we can check to see if enough time has elapsed for us to turn it off.
    if(DisplayActive)
    {
        //If enough time has elapsed, turn off display to allow display of the next letter.
        if(millis() > DisplayLetterEndMilliseconds)
        {
            DisplayActive = false;
        }
        return;
    }
    SetDisplayLetter(AlphabetCharactersLower[DisplayIndex],200);
    //Counts up the index for the next letter.
    DisplayIndex++;
    //Reset the index to zero if we just displayed the last letter in the alphabet.
    if(DisplayIndex == 26) DisplayIndex = 0;
}

// //This example does not use delays and is non-blocking.
// void loop()
// {
//     while(true)
//     {
//         TryToDisplayNextLetter();
//         UpdateDisplay();
//     }

//     //Add other code as necessary.
// }



void loop() {

  unsigned long delayMillis = 100;

  unsigned long currentMillis = millis();
  byte smallFrame[8][12];
  if(currentMillis - previousActionMillis > delayMillis){
    previousActionMillis = currentMillis;
    for(int i = 0; i < 8; i++){
      int startBit = frame[i][0];
      for (int j = 0; j<35; j++){
       frame[i][j] = frame[i][j+1];
    }
    frame[i][35] = startBit;
  }
  
  
  }
  for(int x = 0; x < 8; x++){
    for(int y = 0; y < 12; y++){
      smallFrame[x][y] = frame[x][y];
    }
  }
  
  
matrix.renderBitmap(AlphabetMatrix[24], 8, 12);
  // put your main code here, to run repeatedly:

}
