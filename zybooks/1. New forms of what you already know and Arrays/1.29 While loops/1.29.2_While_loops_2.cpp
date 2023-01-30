#include <iostream>
using namespace std;

int main() {
  char userInput;
  int sumChars;

  sumChars = 0;
  cin >> userInput;

  while (userInput != 'e') {
    sumChars += 1;
    cin >> userInput;
  }

  cout << sumChars << endl;

  return 0;
}
