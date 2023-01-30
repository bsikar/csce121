#include <iostream>
using namespace std;

int CalcNum(int num1, int num2) {
  int result;
  result = num1 - (7 * num2);
  return result;
}

int main() {
  int input1, input2;
  int result;

  cin >> input1;
  cin >> input2;

  result = CalcNum(input1, input2);

  cout << result << endl;

  return 0;
}
