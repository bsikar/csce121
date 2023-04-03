#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> dailyScores;
  int i;
  int numIn;

  cin >> numIn;
  // Creates a vector of size numIn and initialize all values to 0
  dailyScores.resize(numIn);

  for (i = 0; i < dailyScores.size(); ++i) {
    cin >> dailyScores.at(i);
  }

  /* Your code goes here
   *
   * Integer numIn is read from input. Given the integer vector dailyScores with
the size of numIn, write a for loop to output all the integers in dailyScores in
reverse order. Separate the integers with a dash surrounded by spaces (" - ").

Ex: If the input is

6

91 105 112 119 137 140

then the output is:

140 - 137 - 119 - 112 - 105 - 91*/

  for (i = dailyScores.size() - 1; i >= 0; --i) {
    cout << dailyScores.at(i) << " - ";
  }
  cout << endl;

  return 0;
}

// Language: cpp
// Path: 7.4.6_Iterating_through_vectors_2.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> dailyScores;
  int i;
  int numIn;

  cin >> numIn;
  // Creates a vector of size numIn and initialize all values to 0
  dailyScores.resize(numIn);

  for (i = 0; i < dailyScores.size(); ++i) {
    cin >> dailyScores.at(i);
  }

  for (i = dailyScores.size() - 1; i > 0; --i) {
    cout << dailyScores.at(i) << " - ";
  }
  cout << dailyScores.at(0);
  cout << endl;

  return 0;
}
