#include <iostream>
using namespace std;

int main() {
  int inputTemp;

  cin >> inputTemp;

  if (inputTemp < 1761) {
    cout << "Solid";
  } else if (inputTemp < 3940) {
    cout << "Liquid";
  } else {
    cout << "Gas";
  }
  cout << endl;

  return 0;
}
