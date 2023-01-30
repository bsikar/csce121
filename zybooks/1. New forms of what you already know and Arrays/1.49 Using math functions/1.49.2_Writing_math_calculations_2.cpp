#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double x;
  double y;
  double z;

  cin >> x;
  cin >> y;

  z = pow(abs(y - x), 3);

  cout << fixed
       << setprecision(1); // setprecision(1) outputs z with 1 decimal place.
  cout << z << endl;

  return 0;
}
