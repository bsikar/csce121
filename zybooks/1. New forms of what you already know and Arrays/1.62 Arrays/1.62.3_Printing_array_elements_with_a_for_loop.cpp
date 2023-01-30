#include <iostream>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  int courseGrades[NUM_VALS];
  int i;

  for (i = 0; i < NUM_VALS; ++i) {
    cin >> courseGrades[i];
  }

  for (i = 0; i < NUM_VALS; ++i) {
    cout << courseGrades[i] << " ";
  }
  cout << endl;
  for (i -= 1; i >= 0; --i) {
    cout << courseGrades[i] << " ";
  }
  cout << endl;

  return 0;
}
