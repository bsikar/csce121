#include <iostream>
using namespace std;

int FindCharacters(string inputString, char x) {
  int count = 0;
  for (int i = 0; i < inputString.length(); ++i) {
    if (inputString.at(i) == x) {
      ++count;
    }
  }
  return count;
}

int main() {
  string inString;
  char x;
  int result;

  cin >> inString;
  cin >> x;

  result = FindCharacters(inString, x);

  cout << result << endl;

  return 0;
}
