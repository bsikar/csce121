#include <iostream>
using namespace std;

int main() {
  int userInput;

  do {
    cout << "Enter a number (<100): " << endl;
    cin >> userInput;
  } while (userInput >= 100);

  cout << "Your number < 100 is: " << userInput << endl;

  return 0;
}
