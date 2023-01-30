#include <iostream>
using namespace std;

int FindMinimum() {
  int min = 0;
  int num = 0;
  cin >> num;
  min = num;
  while (num <= 0) {
    cin >> num;
    if (num < min) {
      min = num;
    }
  }
  return min;
}

int main() {
  int minVal;

  minVal = FindMinimum();

  cout << minVal << endl;

  return 0;
}
