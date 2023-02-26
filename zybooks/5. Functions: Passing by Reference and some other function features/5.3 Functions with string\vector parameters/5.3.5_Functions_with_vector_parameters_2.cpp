#include <iostream>
#include <vector>
using namespace std;

bool isSmaller(vector<int> v1, vector<int> v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (int i = 0; i < v1.size(); ++i) {
    if (v1.at(i) >= v2.at(i)) {
      return false;
    }
  }
  return true;
}

int main() {
  int i;
  vector<int> inputVector1;
  vector<int> inputVector2;
  int size;
  int input;
  bool checkProperty;

  cin >> size;
  for (i = 0; i < size; ++i) {
    cin >> input;
    inputVector1.push_back(input);
  }

  cin >> size;
  for (i = 0; i < size; ++i) {
    cin >> input;
    inputVector2.push_back(input);
  }

  checkProperty = isSmaller(inputVector1, inputVector2);

  if (checkProperty) {
    cout
        << "True, the first vector is element-wise less than the second vector."
        << endl;
  } else {
    cout << "False, the first vector is not element-wise less than the second "
            "vector."
         << endl;
  }

  return 0;
}
