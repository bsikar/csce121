#include <iostream>
#include <string>
using namespace std;

int main() {
  string inputStr;
  string suffix;
  string concatStr;

  getline(cin, inputStr);
  getline(cin, suffix);

  concatStr = inputStr + suffix;

  cout << concatStr << endl;

  return 0;
}
