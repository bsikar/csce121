#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> hourlyPrices;
  unsigned int i;
  int numIn;

  cin >> numIn;
  // Creates a vector of size numIn and initialize all values to 0
  hourlyPrices.resize(numIn);

  /* Your code goes here */
  for (i = 0; i < hourlyPrices.size(); i++) {
    cin >> hourlyPrices.at(i);
  }

  for (i = 0; i < hourlyPrices.size(); i++) {
    cout << hourlyPrices.at(i) << " ";
  }
  cout << endl;

  return 0;
}
