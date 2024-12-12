vector<pair<int, int>> convertVectorOfStringsToCoordinatePairs(vector<string> strings) {
  vector<pair<int, int>> coordinatePairs;
  strings.erase(strings.begin());
  strings.pop_back();
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
    strip.setPixelColor(first+second, strip.Color(100, 100, 100));
    strip.show(); 
    coordinatePairs.push_back(make_pair(first, second));
  }

  return coordinatePairs;
}