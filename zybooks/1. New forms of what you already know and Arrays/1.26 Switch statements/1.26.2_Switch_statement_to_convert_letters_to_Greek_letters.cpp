#include <iostream>
using namespace std;

int main() {
  char origLetter;

  cin >> origLetter;

  switch (origLetter) {
  case 'a':
  case 'A':
    cout << "Alpha";
    break;
  case 'b':
  case 'B':
    cout << "Beta";
    break;
  default:
    cout << "Unknown";
  }
  cout << endl;

  return 0;
}
