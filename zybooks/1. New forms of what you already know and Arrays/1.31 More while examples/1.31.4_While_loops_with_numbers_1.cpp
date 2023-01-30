#include <iostream>
using namespace std;

int main() {
  int dataValue;
  int totalOfSelected;

  totalOfSelected = 0;
  cin >> dataValue;

  while (dataValue != 99) {
    if (dataValue <= 0) {
      cout << dataValue << endl;
      totalOfSelected += dataValue;
    }
    cin >> dataValue;
  }

  cout << "The sum of all non-positive values is " << totalOfSelected << endl;

  return 0;
}
