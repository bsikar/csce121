#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int NUM_VALS = 4;
  unsigned int i;
  vector<int> hourlyTemp(NUM_VALS);

  for (i = 0; i < hourlyTemp.size(); ++i) {
    cin >> hourlyTemp.at(i);
  }

  for (i = 0; i < hourlyTemp.size(); ++i) {
    cout << hourlyTemp.at(i);
    if (i < hourlyTemp.size() - 1) {
      cout << ", ";
    }
  }
  cout << endl;

  return 0;
}
