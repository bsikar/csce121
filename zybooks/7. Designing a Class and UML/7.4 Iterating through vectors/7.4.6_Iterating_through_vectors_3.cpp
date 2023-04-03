#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> yearlyMiles;
  unsigned int i;
  int numValues;
  int maxSum;

  cin >> numValues;
  // Creates a vector of size numValues and initialize all values to 0
  yearlyMiles.resize(numValues);

  for (i = 0; i < yearlyMiles.size(); ++i) {
    cin >> yearlyMiles.at(i);
  }

  /*
   * Integer numValues is read from input. Given the integer vector yearlyMiles
  with the size of numValues, write a for loop that sums each integer of
  yearlyMiles together until either maxSum is greater than or equal to 100 or
  the end of the vector is reached.

  Ex: If the input is

  5

  39 55 61 73 76

  then the output is:

  maxSum: 155*/

  maxSum = 0;
  for (i = 0; i < yearlyMiles.size(); ++i) {
    maxSum += yearlyMiles.at(i);
    if (maxSum >= 100) {
      break;
    }
  }

  cout << "maxSum: " << maxSum << endl;

  return 0;
}

// Language: cpp
// Path: 7.4.6_Iterating_through_vectors_4.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> yearlyMiles;
  unsigned int i;
  int numValues;
  int maxSum;

  cin >> numValues;
  // Creates a vector of size numValues and initialize all values to 0
  yearlyMiles.resize(numValues);

  for (i = 0; i < yearlyMiles.size(); ++i) {
    cin >> yearlyMiles.at(i);
  }

  maxSum = 0;
  for (i = 0; i < yearlyMiles.size(); ++i) {
    maxSum += yearlyMiles.at(i);
    if (maxSum >= 100) {
      break;
    }
  }

  cout << "maxSum: " << maxSum << endl;

  return 0;
}
