#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> numberVector;
  int value;
  int i;

  value = 0;
  while (value != -1) {
    cin >> value;
    if (value != -1) {
      numberVector.push_back(value);
    }
  }

  for (i = 0; i < numberVector.size(); ++i) {
    cout << numberVector.at(i) << endl;
  }

  return 0;
}
