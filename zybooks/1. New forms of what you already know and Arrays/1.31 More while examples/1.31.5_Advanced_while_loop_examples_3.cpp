#include <iostream>
using namespace std;

int main() {
  int currentInput;
  int previousInput;

  cin >> previousInput;

  while (cin >> currentInput) {
    cout << previousInput << " is in a non-decreasing sequence." << endl;
    if (currentInput < previousInput) {
      break;
    }
    previousInput = currentInput;
  }

  return 0;
}
