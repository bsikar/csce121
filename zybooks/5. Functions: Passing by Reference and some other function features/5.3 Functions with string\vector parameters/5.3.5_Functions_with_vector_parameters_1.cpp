#include <iostream>
#include <vector>
using namespace std;

bool TestSelectiveSum(vector<int> &v, int num) {
  int sum = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v.at(i) < num) {
      sum += v.at(i);
    }
  }
  if (sum % 2 != 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  vector<int> inputVector;
  int size;
  int input;
  int i;
  int x;
  bool result;

  // Read the vector's size, and then the vector's elements
  cin >> size;
  for (i = 0; i < size; ++i) {
    cin >> input;
    inputVector.push_back(input);
  }

  cin >> x;

  result = TestSelectiveSum(inputVector, x);

  if (result) {
    cout << "True, the sum of the elements that are less than " << x
         << " is odd." << endl;
  } else {
    cout << "False, the sum of the elements that are less than " << x
         << " is not odd." << endl;
  }

  return 0;
}
