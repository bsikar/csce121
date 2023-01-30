#include <iostream>
using namespace std;

bool InspectVals() {
  int val;
  cin >> val;
  while (val != -1) {
    if (val < 1000 || val > 2000) {
      return false;
    }
    cin >> val;
  }
  return true;
}

int main() {
  bool allValid;

  allValid = InspectVals();
  if (allValid) {
    cout << "All valid" << endl;
  } else {
    cout << "Invalid value(s)" << endl;
  }

  return 0;
}
