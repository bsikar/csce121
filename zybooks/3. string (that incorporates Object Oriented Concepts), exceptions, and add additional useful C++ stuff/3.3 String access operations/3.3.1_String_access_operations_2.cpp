#include <iostream>
#include <string>
using namespace std;

int main() {
  string userStr;
  char charToFind;
  int strIndex;

  getline(cin, userStr);
  cin >> charToFind;
  cin >> strIndex;

  if (userStr[strIndex] == charToFind) {
    cout << "Found match";
  } else {
    cout << "No match";
  }
  cout << endl;

  return 0;
}
