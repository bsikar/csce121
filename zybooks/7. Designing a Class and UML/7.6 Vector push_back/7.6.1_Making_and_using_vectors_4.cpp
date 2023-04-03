#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> inputIntegers;
  int value;
  int i;
  bool isPos;

  cin >> value;
  while (value != -1) {
    inputIntegers.push_back(value);
    cin >> value;
  }

  isPos = inputIntegers.back() > 0;
  for (i = 0; i < inputIntegers.size(); ++i) {
    if (isPos && inputIntegers.at(i) > 0) {
      cout << inputIntegers.at(i) << endl;
    } else if (!isPos && inputIntegers.at(i) <= 0) {
      cout << inputIntegers.at(i) << endl;
    }
  }

  return 0;
}
