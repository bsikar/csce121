#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> integerVector;
  int value;
  int i;
  int n;

  cin >> value;
  while (value != 0) {
    integerVector.push_back(value);
    cin >> value;
  }

  n = integerVector.back();
  integerVector.pop_back();

  for (i = 0; i < n; ++i) {
    cout << integerVector.at(i) << endl;
  }

  return 0;
}
