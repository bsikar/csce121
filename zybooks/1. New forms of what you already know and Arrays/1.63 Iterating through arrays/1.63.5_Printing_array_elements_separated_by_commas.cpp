#include <iostream>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  int hourlyTemp[NUM_VALS];
  int i;

  for (i = 0; i < NUM_VALS; ++i) {
    cin >> hourlyTemp[i];
  }

  for (i = 0; i < NUM_VALS; ++i) {
    cout << hourlyTemp[i];
    if (i < NUM_VALS - 1) {
      cout << ", ";
    }
  }

  cout << endl;

  return 0;
}
