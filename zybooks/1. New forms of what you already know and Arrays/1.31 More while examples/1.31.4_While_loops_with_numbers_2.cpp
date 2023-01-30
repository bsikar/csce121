#include <iostream>
using namespace std;

int main() {
  int dataValue;
  int numCounts;

  numCounts = 1;
  cin >> dataValue;

  while (dataValue <= 35 && dataValue >= -15) {
    numCounts += 1;
    cin >> dataValue;
  }

  cout << "Number of integers read: " << numCounts << endl;

  return 0;
}
