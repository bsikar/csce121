#include <iostream>
using namespace std;

int main() {
  int numStudents;

  cin >> numStudents;

  // Modify the following line
  if (numStudents < 9500 || numStudents > 18000) {
    cout << "Not a mid-size university" << endl;
  } else {
    cout << "Mid-size university" << endl;
  }

  return 0;
}
