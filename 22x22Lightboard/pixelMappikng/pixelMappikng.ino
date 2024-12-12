// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)
#include <Adafruit_NeoPixel.h>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 484

using namespace std;
static vector<string> test1 = {
  "[",
"[2,1]",
"[3,1]",
"[4,1]",
"[4,2]",
"[1,2]",
"[2,2]",
"[3,2]",
"[5,2]",
"[1,3]",
"[2,3]",
"[3,3]",
"[4,3]",
"[6,3]",
"[5,3]",
"[6,4]",
"[7,4]",
"[5,4]",
"[4,4]",
"[3,4]",
"[2,4]",
"[1,4]",
"[2,5]",
"[3,5]",
"[4,5]",
"[5,5]",
"[6,5]",
"[7,5]",
"[8,5]",
"[8,6]",
"[9,6]",
"[7,6]",
"[6,6]",
"[5,6]",
"[4,6]",
"[3,6]",
"[4,7]",
"[5,7]",
"[5,8]",
"[6,7]",
"[6,8]",
"[6,9]",
"[7,7]",
"[7,8]",
"[7,9]",
"[8,7]",
"[9,7]",
"[10,7]",
"[11,7]",
"[11,7]",
"[11,7]",
"[12,7]",
"[13,7]",
"[14,7]",
"[15,7]",
"[16,7]",
"[17,7]",
"[13,6]",
"[13,5]",
"[12,6]",
"[14,6]",
"[14,5]",
"[14,4]",
"[15,3]",
"[15,4]",
"[15,5]",
"[15,6]",
"[16,6]",
"[16,5]",
"[16,4]",
"[16,3]",
"[16,2]",
"[17,1]",
"[18,1]",
"[19,1]",
"[17,2]",
"[18,2]",
"[20,2]",
"[19,2]",
"[20,2]",
"[19,3]",
"[20,3]",
"[18,3]",
"[17,3]",
"[17,4]",
"[18,4]",
"[19,4]",
"[20,4]",
"[19,5]",
"[18,5]",
"[17,5]",
"[17,6]",
"[18,6]",
"[8,8]",
"[9,8]",
"[8,9]",
"[9,9]",
"[10,8]",
"[10,9]",
"[11,8]",
"[11,8]",
"[12,8]",
"[11,9]",
"[12,9]",
"[13,8]",
"[13,9]",
"[14,8]",
"[14,9]",
"[15,8]",
"[15,9]",
"[16,8]",
"[7,10]",
"[8,10]",
"[9,10]",
"[10,10]",
"[11,10]",
"[12,10]",
"[13,10]",
"[14,10]",
"[14,11]",
"[13,11]",
"[12,11]",
"[11,11]",
"[10,11]",
"[9,11]",
"[8,11]",
"[7,11]",
"[6,12]",
"[6,13]",
"[6,14]",
"[6,15]",
"[6,17]",
"[6,16]",
"[7,17]",
"[7,16]",
"[7,15]",
"[7,14]",
"[7,14]",
"[7,12]",
"[7,13]",
"[8,12]",
"[9,12]",
"[10,12]",
"[11,12]",
"[12,12]",
"[13,12]",
"[14,12]",
"[15,12]",
"[8,13]",
"[8,14]",
"[8,15]",
"[8,16]",
"[9,15]",
"[9,14]",
"[9,13]",
"[10,13]",
"[10,14]",
"[11,13]",
"[11,14]",
"[12,13]",
"[12,14]",
"[12,15]",
"[13,13]",
"[13,14]",
"[13,15]",
"[13,16]",
"[15,17]",
"[14,16]",
"[14,17]",
"[15,16]",
"[14,15]",
"[15,15]",
"[14,14]",
"[15,14]",
"[14,13]",
"[15,13]",
"[17,13]",
"[16,13]",
"[16,14]",
"[17,14]",
"[16,15]",
"[17,15]",
"[16,15]",
"[16,16]",
"[17,16]",
"[18,15]",
"[18,16]",
"[19,16]",
"[18,17]",
"[17,17]",
"[16,17]",
"[19,17]",
"[20,17]",
"[20,18]",
"[20,19]",
"[19,20]",
"[19,19]",
"[19,18]",
"[18,18]",
"[18,19]",
"[18,20]",
"[17,20]",
"[17,19]",
"[17,18]",
"[16,18]",
"[16,19]",
"[15,18]",
"[6,18]",
"[5,19]",
"[5,18]",
"[5,17]",
"[5,16]",
"[5,15]",
"[5,14]",
"[5,13]",
"[4,14]",
"[4,15]",
"[4,16]",
"[4,17]",
"[4,18]",
"[4,19]",
"[4,20]",
"[3,20]",
"[3,19]",
"[3,18]",
"[3,17]",
"[3,16]",
"[3,15]",
"[2,16]",
"[2,17]",
"[2,18]",
"[2,19]",
"[2,20]",
"[1,19]",
"[1,18]",
"[1,17]",
"]"
};

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)



// setup() function -- runs once at startup --------------------------------
int randomNum(){
    return rand()%255;
}

int translate(int x, int y){
  // 22 x 22 grid
  // 1st line goes forwards, 2nd line goes backwards
  if (y%2 != 0) {
    return (y-1)*22 + (x-1);
  } else {
    return y*22 - x;
  }
}

std::vector<int> convert(std::vector<std::pair<int, int>> coordinateArray) {
  int arraySize = coordinateArray.size();
  std::vector<int> gridArray;

  for (int i = 0; i < arraySize; i++) {
    std::pair<int, int> coordinate = coordinateArray[i];
    int gridVal = translate(coordinate.first, coordinate.second);
    gridArray.push_back(gridVal);
  }

  return gridArray;
}

void printPixels(std::vector<std::pair<int, int>> coordinates, int wait) {
  std::vector<int> gridValues = convert(coordinates);
  for (int a=0; a<10; a++) { // How many times the program will run
    strip.clear();
    for (int gridValue : gridValues) {
      strip.setPixelColor(gridValue, strip.Color(255, 255, 255));
    }
    strip.show();
    delay(wait);
  }
  //strip.clear();
}

vector<string> readFile(string fileName) {
    vector<std::string> listOfStrings;
    // Open the text file named "input.txt"
    ifstream f(fileName);

    // Check if the file is successfully opened
    if (!f.is_open()) {
        Serial.println("File couldn't be opened");
        return {};
    }

    // String variable to store the read data
    string s;

    // Read each line of the file and print it to the
    // standard output stream till the whole file is
  	// completely read
    while (getline(f, s)) {
        listOfStrings.push_back(s);
    }

    // Close the file
    f.close();
    return listOfStrings;
}

vector<pair<int, int>> convertVectorOfStringsToCoordinatePairs2(vector<string> strings) {
  vector<pair<int, int>> listOfCoordinates;
  for (string coordinateString : strings) {
    stringstream ss;
    ss << coordinateString;
    pair<int, int> coordinate;
        /* Running loop till the end of the stream */
    string temp;
    int found;
    bool hasFoundFirst = false;

    while (!ss.eof()) {
 
        /* extracting word by word from stream */
        ss >> temp;
 
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) {
          if (hasFoundFirst) {
            coordinate.second = found;
          } else {
            coordinate.first = found;
            hasFoundFirst = true;
          }
        }
 
        /* To save from space at the end of string */
        temp = "";
    }
    listOfCoordinates.push_back(coordinate);

    // int num;
    // bool hasFoundFirst = false;
    // while (ss >> num) {
    //   if (hasFoundFirst) {
    //     coordinate.second = num;
    //   } else {
    //     coordinate.first = num;
    //     hasFoundFirst = true;
    //   }
    // }
    // listOfCoordinates.push_back(coordinate);
  }
  return listOfCoordinates;
}

vector<pair<int, int>> convertVectorOfStringsToCoordinatePairs(vector<string> strings) {
  vector<pair<int, int>> coordinatePairs;
  strings.erase(strings.begin());
  strings.pop_back();
  Serial.println("Strings:");
  Serial.println(strings.size());
  for (string coordinateLine : strings) {
    stringstream ss(coordinateLine);
    ss << coordinateLine;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    bool isFirst = true;
    int first;
    int second;
    while (!ss.eof()) {

      /* extracting word by word from stream */
      ss >> temp;

      /* Checking the given word is integer or not */
      if (stringstream(temp) >> found){
        if (isFirst) {
          isFirst = false;
          first = found;
        } else {
          second = found;
        }
      }
      /* To save from space at the end of string */
      temp = "";
    }
    coordinatePairs.push_back(make_pair(first, second));
  }

  return coordinatePairs;
}
void simpleTest() {
  pair<int, int> firstPair = {3, 3};
  pair<int, int> secondPair = {4, 4};
  pair<int, int> thirdPair = {5, 5};
  pair<int, int> fourthPair = {6, 6};
  vector<pair<int, int>> coordinates = {firstPair, secondPair, thirdPair, fourthPair};
  printPixels(coordinates, 1);
}

void printFromStaticVar() {
    //vector<string> testStrings = {"[4,5],","[4,6],","[5,6]"};
   // vector<pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs2(test2);
    //printPixels(listOfCoordinates, 1);
}

void printPixelsFromFile(string fileName) {
  vector<string> listOfStrings = readFile(fileName);
  //Serial.println("Size of list of strings");
  //Serial.println(listOfStrings.size());
  vector<pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(listOfStrings);
  //Serial.println("Size of list of coordinates");
  //Serial.println(listOfCoordinates.size());
  printPixels(listOfCoordinates, 30);
}





void letterXRainbow(int wait){
// Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.setPixelColor(0, strip.Color(50,   50,   50));
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }


}


// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);  
         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
  
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(2); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...
  //colorWipe(strip.Color(255,   0,   0), 1); // Red
  //colorWipe(strip.Color(  0, 255,   0), 1); // Green
  //colorWipe(strip.Color(  0,   0, 255), 1); // Blue

  // Do a theater marquee effect in various colors...
  //theaterChase(strip.Color(127, 127, 127), 20); // White, half brightness
  vector<pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(test1);
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.show();
  delay(5);  
  // vector<pair<int, int>> listOfCoordinates = {make_pair(1,2), make_pair(3,4)};
  // printPixels(listOfCoordinates, 1);
  //simpleTest();
  //theaterChase(strip.Color(127,   0,   0), 20); // Red, half brightness
  //theaterChase(strip.Color(  0,   0, 127), 20); // Blue, half brightness

  //letterXRainbow(1);             // Flowing rainbow cycle along the whole strip
  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
  //printFromStaticVar();
}