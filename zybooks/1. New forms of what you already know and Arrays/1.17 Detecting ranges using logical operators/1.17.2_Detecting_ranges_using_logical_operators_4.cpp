#include <iostream>
using namespace std;

int main() {
  int month;

  cin >> month;

  if (month < 4 || month > 12) {
    cout << "Outside the range of study";
  } else if (month <= 6) {
    cout << "The second quarter of the year";
  } else if (month <= 9) {
    cout << "The third quarter of the year";
  } else {
    cout << "The fourth quarter of the year";
  }
  cout << endl;

  return 0;
}
