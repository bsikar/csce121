#include <iostream>
using namespace std;

int main() {
  int numInput;
  int inVal;
  int highestVal;
  int i;

  cin >> numInput;

  cin >> inVal;
  highestVal = inVal;
  cout << "Value read: " << inVal << endl;
  for (i = 1; i < numInput; i++) {
    cin >> inVal;
    cout << "Value read: " << inVal << endl;
    if (inVal > highestVal) {
      highestVal = inVal;
    }
  }
  cout << "Highest: " << highestVal << endl;

  return 0;
}
