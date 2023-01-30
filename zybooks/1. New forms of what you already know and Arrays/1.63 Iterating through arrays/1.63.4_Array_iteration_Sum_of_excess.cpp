#include <iostream>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  int testGrades[NUM_VALS];
  int i;
  int sumExtra = -9999; // Assign sumExtra with 0 before your for loop

  for (i = 0; i < NUM_VALS; ++i) {
    cin >> testGrades[i];
  }

  sumExtra = 0;
  for (i = 0; i < NUM_VALS; ++i) {
    if (testGrades[i] > 100) {
      sumExtra += testGrades[i] - 100;
    }
  }

  cout << "sumExtra: " << sumExtra << endl;
  return 0;
}
