#include <iostream>
using namespace std;

int NumberOfPennies(int dollars) { return dollars * 100; }

int NumberOfPennies(int dollars, int pennies) {
  return NumberOfPennies(dollars) + pennies;
}

int main() {
  cout << NumberOfPennies(5, 6) << endl; // Should print 506
  cout << NumberOfPennies(4) << endl;    // Should print 400
  return 0;
}
