#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double fractionTotal;

  double num1, den1, num2, den2;
  cin >> num1 >> den1 >> num2 >> den2;
  fractionTotal = (num1 / den1) + (num2 / den2);

  cout << fixed << setprecision(2) << fractionTotal << endl;

  return 0;
}
