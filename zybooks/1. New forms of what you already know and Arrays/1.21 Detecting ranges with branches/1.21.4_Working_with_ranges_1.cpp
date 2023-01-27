#include <iostream>
using namespace std;

int main() {
  int numPassengers;

  cin >> numPassengers;

  if (numPassengers <= 8) {
    cout << "Compact van";
  } else if (numPassengers <= 17) {
    cout << "Medium van";
  } else {
    cout << "Too many passengers";
  }
  cout << endl;

  return 0;
}
