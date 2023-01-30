#include <iostream>
using namespace std;

int main() {
  int firstNumber;
  int finalNumber;
  int i;

  cin >> firstNumber;
  cin >> finalNumber;

  for (i = firstNumber; i <= finalNumber; i++) {
    cout << i << " ";
  }

  return 0;
}
