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
#include <sstream>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    6
#define LED_COUNT 484
#define SIDE_LENGTH 22

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Declaring functions
std::vector<std::pair<int, int>> convertVectorOfStringsToCoordinatePairs(std::vector<std::string> strings);
void smallDisplayTest(int loopCount);
int translateCoordinatesToPixelNumber(std::pair<int, int> coordinates);
std::vector<std::string> getLetterX();
std::vector<std::pair<int, int>> shiftListOfCoordinates(std::vector<std::pair<int, int>> listOfCoordinates, int loopCount);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(4); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(9600);
}

void loop() {


  rainbow(5);             // Flowing rainbow cycle along the whole strip
  //smallDisplayTest();
  //std::vector<std::pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(test1);
  //strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.show(); // Update strip with new contents
  //delay(100);
}

void smallDisplayTest(int loopCount){
  std::vector<std::string> letterX = getLetterX();
  std::vector<std::pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(letterX);
  std::vector<std::pair<int, int>> shiftedListOfCoordinates = shiftListOfCoordinates(listOfCoordinates, loopCount);
  for(std::pair<int, int> coord : shiftedListOfCoordinates){
    // Serial.println(coord.first);
    // Serial.println(coord.second);
    int pixelNumber = translateCoordinatesToPixelNumber(coord);
    strip.setPixelColor(pixelNumber, strip.Color(0, 0, 0));
  }
}

std::vector<std::pair<int, int>> shiftListOfCoordinates(std::vector<std::pair<int, int>> listOfCoordinates, int loopCount){
  std::vector<std::pair<int, int>> shiftedListOfCoordinates;
  for(std::pair<int, int> coord : listOfCoordinates){
    int newFirst = coord.first;
    int newSecond = (coord.second - loopCount);
    if(newSecond < 0){
      newSecond = 22 + newSecond;
    }
    shiftedListOfCoordinates.push_back(std::make_pair(newFirst, newSecond));
  }
  return shiftedListOfCoordinates;
}

std::vector<std::pair<int, int>> crazyMode(std::vector<std::pair<int, int>> listOfCoordinates, int loopCount){
  std::vector<std::pair<int, int>> shiftedListOfCoordinates;
  for(std::pair<int, int> coord : listOfCoordinates){
    int newFirst = coord.first;
    int newSecond = (coord.second - loopCount);
    if(newSecond == -1){
      newSecond = 21;
    }
    shiftedListOfCoordinates.push_back(std::make_pair(newFirst, newSecond));
  }
  return shiftedListOfCoordinates;
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

int translateCoordinatesToPixelNumber(std::pair<int, int> coordinates){
  //test A coordinates : 1,3
  //test B coordinates : 2,4
  //test C coordinates : 2,22
  //test D coordinates : 1,22
  int x = coordinates.first;
  int y = coordinates.second;
  int pixelNumber;
  int pixelRowStart = (x) * 22;
  //A pixelRowStart = 0;
  //B pixelRowStart = 22;
  //C pixelRowStart = 22;
  int pixelColumnAdjustment;
  if (x % 2 != 0){ //B,C
    pixelNumber = pixelRowStart + (22 - y) - 1;
    //B pixelNumber = 40 = 22 + (22 - y)
    //C pixelNumber = 22;
  } else {
    pixelNumber = pixelRowStart + y;
    //A pixelNumber = 2 = 0 + (3 - 1);
    //D pixelNumber = 21 = 0 + (22 - 1);
  }

  return pixelNumber;
}

std::vector<std::pair<int, int>> convertVectorOfStringsToCoordinatePairs(std::vector<std::string> strings) {
  std::vector<std::pair<int, int>> coordinatePairs;
  strings.pop_back();
  strings.erase(strings.begin());
  for (std::string s : strings) {
    std::string delimiter = ",";
    std::string endDelimiter = "]";
    int delimiterPosition = s.find(delimiter);
    int endDelimiterPosition = s.find(endDelimiter);
    int firstTokenStartPosition = 1;
    int secondTokenStartPosition = delimiterPosition + 1;
    int firstTokenLength = delimiterPosition - 1;
    int secondTokenLength = endDelimiterPosition - delimiterPosition - 1;
    std::string firstToken = s.substr(firstTokenStartPosition, firstTokenLength); // token is "scott"
    std::string secondToken = s.substr(secondTokenStartPosition, secondTokenLength);
    int first = std::stoi(firstToken);
    int second = std::stoi(secondToken);
    coordinatePairs.push_back(std::make_pair(first, second));

    // std::stringstream ss(coordinateLine);
    // ss << coordinateLine;

    // /* Running loop till the end of the stream */
    // std::string temp;
    // int found;
    // bool isFirst = true;
    // int first;
    // int second;
    // while (!ss.eof()) {

    //   /* extracting word by word from stream */
    //   ss >> temp;

    //   /* Checking the given word is integer or not */
    //   if (std::stringstream(temp) >> found){
    //     if (isFirst) {
    //       isFirst = false;
    //       first = found;
    //     } else {
    //       second = found;
    //     }
    //   }
    //   /* To save from space at the end of string */
    //   temp = "";
    // }
    //coordinatePairs.push_back(std::make_pair(first, second));
  }

  return coordinatePairs;
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  int loopCount = 1;
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 512) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    smallDisplayTest(loopCount);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
    loopCount = (loopCount + 1) % 22;
  }

  
}
