#include <iostream>
using namespace std;

void PrintVal(int num1, int num2) {
  int product = 1;
  for (int i = num1; i <= num2; i++) {
    product *= i;
  }
  cout << product << endl;
}

int main() {
  int numberA;
  int numberB;

  cin >> numberA;
  cin >> numberB;
  PrintVal(numberA, numberB);

  return 0;
}
