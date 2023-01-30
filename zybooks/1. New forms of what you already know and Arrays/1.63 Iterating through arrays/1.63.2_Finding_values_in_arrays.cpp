#include <iostream>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  int userValues[NUM_VALS];
  int i;
  int matchValue;
  int numMatches = -99; // Assign numMatches with 0 before your for loop

  cin >> matchValue;
  for (i = 0; i < NUM_VALS; ++i) {
    cin >> userValues[i];
  }

  numMatches = 0;
  for (i = 0; i < NUM_VALS; ++i) {
    if (userValues[i] == matchValue) {
      numMatches++;
    }
  }

  cout << "matchValue: " << matchValue << ", numMatches: " << numMatches
       << endl;

  return 0;
}
