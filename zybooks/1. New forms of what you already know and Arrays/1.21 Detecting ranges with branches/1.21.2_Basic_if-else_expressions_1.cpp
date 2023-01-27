#include <iostream>
using namespace std;

int main() {
  int inVal;

  cin >> inVal;

  if (inVal < 70) {
    cout << "Less than 70" << endl;
  } else {
    cout << "70 or more" << endl;
  }

  return 0;
}
