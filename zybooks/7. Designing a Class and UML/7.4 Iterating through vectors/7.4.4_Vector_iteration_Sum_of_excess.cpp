#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  vector<int> testGrades(NUM_VALS);
  unsigned int i;
  int sumExtra = -9999; // Assign sumExtra with 0 before your for loop

  for (i = 0; i < testGrades.size(); ++i) {
    cin >> testGrades.at(i);
  }

  sumExtra = 0;
  for (i = 0; i < testGrades.size(); ++i) {
    if (testGrades.at(i) > 100) {
      sumExtra += testGrades.at(i) - 100;
    }
  }

  cout << "Sum of excess: " << sumExtra << endl;

  return 0;
}
