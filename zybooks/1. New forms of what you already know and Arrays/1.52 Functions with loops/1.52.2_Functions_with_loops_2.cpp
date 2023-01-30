#include <iostream>
using namespace std;

void PrintVal(int num1, int num2) {
  int product = 1;
  for (int i = num1; i <= num2; i++) {
    if (i % 2 != 0) {
      product *= i;
    }
  }
  cout << product << endl;
}

int main() {
  int input1;
  int input2;

  cin >> input1;
  cin >> input2;
  PrintVal(input1, input2);

  return 0;
}
