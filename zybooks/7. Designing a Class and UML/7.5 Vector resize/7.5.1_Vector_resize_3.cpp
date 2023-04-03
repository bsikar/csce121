#include <iostream>
#include <vector>
using namespace std;

int main() {
  unsigned int i;
  int initElements = 1;
  vector<int> myValues(initElements);
  int numElements;
  int startNum;

  myValues.at(0) = 35;

  cin >> numElements;
  cin >> startNum;

  // code
  /*
   *
  Given the integer vector myValues with one element and the input integers
  numElements and startNum, resize myValues to numElements. Then, assign the new
  elements of myValues with startNum * (i + 1) * 2, where i is the index of each
  new element in the vector.

  Ex: If the input is 5 9, then the output is:

  35 36 54 72 90 */

  myValues.resize(numElements);
  for (i = 0; i < myValues.size(); ++i) {
    myValues.at(i) = startNum * (i + 1) * 2;
  }

  for (i = 0; i < myValues.size(); ++i) {
    cout << myValues.at(i) << " ";
  }
  cout << endl;

  return 0;
}

// Language: cpp
// Path: 7.5.1_Vector_resize_4.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  unsigned int i;
  int initElements = 1;
  vector<int> myValues(initElements);
  int numElements;
  int startNum;

  myValues.at(0) = 35;

  cin >> numElements;
  cin >> startNum;

  myValues.resize(numElements);
  for (i = 1; i < myValues.size(); ++i) {
    myValues.at(i) = startNum * (i + 1) * 2;
  }

  for (i = 0; i < myValues.size(); ++i) {
    cout << myValues.at(i) << " ";
  }
  cout << endl;

  return 0;
}
