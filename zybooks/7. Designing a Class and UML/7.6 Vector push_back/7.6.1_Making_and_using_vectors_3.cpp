#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> integerVector;
  int value;
  int i;

  cin >> value;
  while (value != -1) {
    integerVector.push_back(value);
    cin >> value;
  }

  for (i = integerVector.size() - 1; i >= 0; --i) {
    if (integerVector.at(i) < 0) {
      cout << integerVector.at(i) << endl;
    }
  }

  return 0;
}
