#include <iostream>
using namespace std;

int CalculateVal(int num) { return num - 7; }

int main() {
  int input;
  int result;

  cin >> input;

  result = CalculateVal(input);

  cout << result << endl;

  return 0;
}
