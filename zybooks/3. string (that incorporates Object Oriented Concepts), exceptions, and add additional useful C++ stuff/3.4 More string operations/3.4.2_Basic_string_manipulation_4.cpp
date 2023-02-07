#include <iostream>
#include <string>
using namespace std;

int main() {
  string stringValue;
  int desiredLen;
  string finalStr;

  getline(cin, stringValue);
  cin >> desiredLen;

  finalStr = stringValue +
             stringValue.substr(stringValue.length() - desiredLen, desiredLen);
  cout << finalStr << endl;

  return 0;
}
