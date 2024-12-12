
void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(2);  // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(9600);
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...
  //colorWipe(strip.Color(255,   0,   0), 1); // Red
  //colorWipe(strip.Color(  0, 255,   0), 1); // Green
  //colorWipe(strip.Color(  0,   0, 255), 1); // Blue

  // Do a theater marquee effect in various colors...
  //theaterChase(strip.Color(127, 127, 127), 20); // White, half brightness
  //theaterChase(strip.Color(127,   0,   0), 20); // Red, half brightness
  //theaterChase(strip.Color(  0,   0, 127), 20); // Blue, half brightness

  //letterXRainbow(1);             // Flowing rainbow cycle along the whole strip
  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
  std::string str = "This string contains 12 integers and 45 floats";
  vector<string> testVectorOfStrings = {"23", "24", " 25"};
  // std::stringstream ss(str);
  std::vector<std::pair<int, int> > result = convertVectorOfStringsToCoordinatePairs(testVectorOfStrings);
  /* Storing the whole string into string stream */
  // ss << str;

  /* Running loop till the end of the stream */
  // string temp;
  // int found;
  // while (!ss.eof()) {

  //   /* extracting word by word from stream */
  //   ss >> temp;

  //   /* Checking the given word is integer or not */
  //   if (stringstream(temp) >> found)
  //     Serial.println(found);
  //   delay(1000);
  //   /* To save from space at the end of string */
  //   temp = "";
  }

  // int num;
  // while (ss >> num) {
  //     cout << num << endl;
  // }
