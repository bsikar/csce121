#include <iostream>
#include <string>
using namespace std;

int main() {
  string stringVar;
  int beginPos;
  int substrLen;
  string newString;

  getline(cin, stringVar);
  cin >> beginPos;
  cin >> substrLen;

  newString = stringVar.substr(beginPos, substrLen);

  cout << newString << endl;

  return 0;
}
