#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int seedVal;
  int highestInput;
  int A;
  int B;

  cin >> seedVal;
  cin >> highestInput;

  srand(seedVal);
  A = rand() % highestInput + 1;
  B = rand() % highestInput + 1;

  cout << A << " + " << B << " = " << A + B << endl;

  return 0;
}
