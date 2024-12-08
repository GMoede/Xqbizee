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

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 484

// static std::vector<std::string> test1 = {
//   "[",
// "[2,1]",
// "[3,1]",
// "[4,1]",
// "[4,2]",
// "[1,2]",
// "[2,2]",
// "[3,2]",
// "[5,2]",
// "[1,3]",
// "[2,3]",
// "[3,3]",
// "[4,3]",
// "[6,3]",
// "[5,3]",
// "[6,4]",
// "[7,4]",
// "[5,4]",
// "[4,4]",
// "[3,4]",
// "[2,4]",
// "[1,4]",
// "[2,5]",
// "[3,5]",
// "[4,5]",
// "[5,5]",
// "[6,5]",
// "[7,5]",
// "[8,5]",
// "[8,6]",
// "[9,6]",
// "[7,6]",
// "[6,6]",
// "[5,6]",
// "[4,6]",
// "[3,6]",
// "[4,7]",
// "[5,7]",
// "[5,8]",
// "[6,7]",
// "[6,8]",
// "[6,9]",
// "[7,7]",
// "[7,8]",
// "[7,9]",
// "[8,7]",
// "[9,7]",
// "[10,7]",
// "[11,7]",
// "[11,7]",
// "[11,7]",
// "[12,7]",
// "[13,7]",
// "[14,7]",
// "[15,7]",
// "[16,7]",
// "[17,7]",
// "[13,6]",
// "[13,5]",
// "[12,6]",
// "[14,6]",
// "[14,5]",
// "[14,4]",
// "[15,3]",
// "[15,4]",
// "[15,5]",
// "[15,6]",
// "[16,6]",
// "[16,5]",
// "[16,4]",
// "[16,3]",
// "[16,2]",
// "[17,1]",
// "[18,1]",
// "[19,1]",
// "[17,2]",
// "[18,2]",
// "[20,2]",
// "[19,2]",
// "[20,2]",
// "[19,3]",
// "[20,3]",
// "[18,3]",
// "[17,3]",
// "[17,4]",
// "[18,4]",
// "[19,4]",
// "[20,4]",
// "[19,5]",
// "[18,5]",
// "[17,5]",
// "[17,6]",
// "[18,6]",
// "[8,8]",
// "[9,8]",
// "[8,9]",
// "[9,9]",
// "[10,8]",
// "[10,9]",
// "[11,8]",
// "[11,8]",
// "[12,8]",
// "[11,9]",
// "[12,9]",
// "[13,8]",
// "[13,9]",
// "[14,8]",
// "[14,9]",
// "[15,8]",
// "[15,9]",
// "[16,8]",
// "[7,10]",
// "[8,10]",
// "[9,10]",
// "[10,10]",
// "[11,10]",
// "[12,10]",
// "[13,10]",
// "[14,10]",
// "[14,11]",
// "[13,11]",
// "[12,11]",
// "[11,11]",
// "[10,11]",
// "[9,11]",
// "[8,11]",
// "[7,11]",
// "[6,12]",
// "[6,13]",
// "[6,14]",
// "[6,15]",
// "[6,17]",
// "[6,16]",
// "[7,17]",
// "[7,16]",
// "[7,15]",
// "[7,14]",
// "[7,14]",
// "[7,12]",
// "[7,13]",
// "[8,12]",
// "[9,12]",
// "[10,12]",
// "[11,12]",
// "[12,12]",
// "[13,12]",
// "[14,12]",
// "[15,12]",
// "[8,13]",
// "[8,14]",
// "[8,15]",
// "[8,16]",
// "[9,15]",
// "[9,14]",
// "[9,13]",
// "[10,13]",
// "[10,14]",
// "[11,13]",
// "[11,14]",
// "[12,13]",
// "[12,14]",
// "[12,15]",
// "[13,13]",
// "[13,14]",
// "[13,15]",
// "[13,16]",
// "[15,17]",
// "[14,16]",
// "[14,17]",
// "[15,16]",
// "[14,15]",
// "[15,15]",
// "[14,14]",
// "[15,14]",
// "[14,13]",
// "[15,13]",
// "[17,13]",
// "[16,13]",
// "[16,14]",
// "[17,14]",
// "[16,15]",
// "[17,15]",
// "[16,15]",
// "[16,16]",
// "[17,16]",
// "[18,15]",
// "[18,16]",
// "[19,16]",
// "[18,17]",
// "[17,17]",
// "[16,17]",
// "[19,17]",
// "[20,17]",
// "[20,18]",
// "[20,19]",
// "[19,20]",
// "[19,19]",
// "[19,18]",
// "[18,18]",
// "[18,19]",
// "[18,20]",
// "[17,20]",
// "[17,19]",
// "[17,18]",
// "[16,18]",
// "[16,19]",
// "[15,18]",
// "[6,18]",
// "[5,19]",
// "[5,18]",
// "[5,17]",
// "[5,16]",
// "[5,15]",
// "[5,14]",
// "[5,13]",
// "[4,14]",
// "[4,15]",
// "[4,16]",
// "[4,17]",
// "[4,18]",
// "[4,19]",
// "[4,20]",
// "[3,20]",
// "[3,19]",
// "[3,18]",
// "[3,17]",
// "[3,16]",
// "[3,15]",
// "[2,16]",
// "[2,17]",
// "[2,18]",
// "[2,19]",
// "[2,20]",
// "[1,19]",
// "[1,18]",
// "[1,17]",
// "]"
// };

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
std::vector<std::pair<int, int>> convertVectorOfStringsToCoordinatePairs(std::vector<std::string> strings);
void smallDisplayTest();
int translateCoordinatesToPixelNumber(std::pair<int, int> coordinates);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(5); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(9600);
}

void loop() {


  //rainbow(10);             // Flowing rainbow cycle along the whole strip
  smallDisplayTest();
  //std::vector<std::pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(test1);
  //strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.show(); // Update strip with new contents
  delay(100);
}

void smallDisplayTest(){
  std::vector<std::string> test1 = {
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
  std::vector<std::pair<int, int>> listOfCoordinates = convertVectorOfStringsToCoordinatePairs(test1);
  for(std::pair<int, int> coord : listOfCoordinates){
    Serial.println(coord.first);
    Serial.println(coord.second);
    int pixelNumber = translateCoordinatesToPixelNumber(coord);
    strip.setPixelColor(pixelNumber, strip.Color(255, 0, 0));
  }
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
