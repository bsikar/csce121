#include <iostream>
#include <vector>
using namespace std;

void SelectIndices(const string &input, char character, vector<int> &output) {
  for (unsigned int i = 0; i < input.size(); ++i) {
    if (input.at(i) != character) {
      output.push_back(i);
    }
  }
}

int main() {
  string inputString;
  int i;
  char x;
  vector<int> results;

  cin >> inputString;
  cin >> x;

  SelectIndices(inputString, x, results);

  for (i = 0; i < results.size(); ++i) {
    cout << results.at(i) << endl;
  }

  return 0;
}
