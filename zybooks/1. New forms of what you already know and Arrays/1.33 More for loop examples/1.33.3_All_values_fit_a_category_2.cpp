#include <iostream>
using namespace std;

int main() {
  int valCount;
  cin >> valCount;
  int val;
  bool allValid = true;

  for (int i = 0; i < valCount; i++) {
    cin >> val;
    if (val >= -1000 && val <= -100) {
      allValid = false;
    }
  }

  if (allValid) {
    cout << "All valid value(s)" << endl;
  } else {
    cout << "Invalid value(s)" << endl;
  }

  return 0;
}
