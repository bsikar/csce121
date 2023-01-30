#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double inputVal;
  double biggestVal;
  int i;

  cin >> biggestVal;
  for (i = 0; i < 6; ++i) {
    cin >> inputVal;
    if (inputVal > biggestVal) {
      biggestVal = inputVal;
    }
  }

  cout << biggestVal << endl;

  return 0;
}
