#include <iostream>
using namespace std;

int main() {
  int userInput;
  int finalNum;

  finalNum = 0;
  cin >> userInput;

  while (userInput >= 0) {
    if (userInput % 4 == 0) {
      cout << "hit";
      finalNum += 1;
    } else {
      cout << "miss";
    }
    cout << endl;
    cin >> userInput;
  }

  cout << "Final number is " << finalNum << endl;

  return 0;
}
