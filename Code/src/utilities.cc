#include "utilities.hpp"
std::vector<std::string> RemoveWhiteSpace (std::string str) {
  std::vector <std::string> result;
  std::string word;
  for (char c : str) {
    if (c == ' ') {
      if (!word.empty()) {
        result.push_back(word);
        word.clear();
      } 
    } else {
      word += c;
    }
  }
  if (!word.empty()) {
    result.push_back(word);
  }
  return result;
}
std::vector<std::string> WordsToVector (std::string str) {
  std::string result = ThrowPunctuation(str);
  return RemoveWhiteSpace(result);
}
std::string ThrowPunctuation(std::string str) {
  int location = 0;
  std::string output;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] != ',' && str[i] != '.' && str[i] != '?' && str[i] !='!') {
      output += str[i];
    }
  }
  return output;
}