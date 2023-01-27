#include <iostream>
using namespace std;

int main() {
  int userInput;

  cin >> userInput;

  if (userInput >= 30) {
    cout << "30 or more" << endl;
  } else {
    cout << "Under 30" << endl;
  }

  return 0;
}
