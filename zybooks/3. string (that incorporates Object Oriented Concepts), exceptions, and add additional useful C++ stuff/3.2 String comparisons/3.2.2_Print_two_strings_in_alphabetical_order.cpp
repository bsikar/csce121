#include <iostream>
#include <string>
using namespace std;

int main() {
  string firstString;
  string secondString;

  cin >> firstString;
  cin >> secondString;

  if (firstString > secondString) {
    string tmp = firstString;
    firstString = secondString;
    secondString = tmp;
  }
  cout << firstString << " " << secondString << endl;

  return 0;
}
