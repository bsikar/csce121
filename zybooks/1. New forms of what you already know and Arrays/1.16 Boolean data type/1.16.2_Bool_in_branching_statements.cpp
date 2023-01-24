#include <iostream>
using namespace std;

int main() {
  bool isRed;
  bool isBalloon;

  cin >> isRed;
  cin >> isBalloon;

  if (!isBalloon) {
    cout << "Not a balloon";
  } else if (isRed) {
    cout << "Red balloon";
  } else {
    cout << "Balloon";
  }
  cout << endl;

  return 0;
}
