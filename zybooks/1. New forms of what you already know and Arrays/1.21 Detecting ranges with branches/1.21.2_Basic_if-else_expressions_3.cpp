#include <iostream>
using namespace std;

int main() {
  int inVal;

  cin >> inVal;

  if (inVal <= 50) {
    cout << "50 or fewer";
  } else {
    cout << "More than 50";
  }
  cout << endl;

  return 0;
}
