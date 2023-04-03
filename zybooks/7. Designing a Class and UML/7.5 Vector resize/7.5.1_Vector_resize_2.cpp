#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> myVector;
  int numVals;
  unsigned int i;
  int numElements;
  int firstNum;

  cin >> numElements;
  cin >> firstNum;

  myVector.resize(numElements);
  for (i = 0; i < myVector.size(); i++) {
    myVector.at(i) = firstNum * (i / 2 + 1);
  }

  for (i = 0; i < myVector.size(); ++i) {
    cout << myVector.at(i) << " ";
  }
  cout << endl;

  return 0;
}
