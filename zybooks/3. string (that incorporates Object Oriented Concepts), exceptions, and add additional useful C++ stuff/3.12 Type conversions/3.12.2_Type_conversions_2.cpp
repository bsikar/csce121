#include <iostream>
using namespace std;

int main() {
  const int MILLIOUNCES_PER_OUNCE = 1000;
  double numOunces;
  int numMilliounces;

  cin >> numOunces;

  numMilliounces = numOunces * MILLIOUNCES_PER_OUNCE;

  cout << numMilliounces << " milliounces" << endl;

  return 0;
}
