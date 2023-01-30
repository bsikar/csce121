#include <iostream>
using namespace std;

int main() {
  const int NUM_ELEMENTS = 5;
  int runTimes[NUM_ELEMENTS];
  int i;

  for (i = 0; i < NUM_ELEMENTS; ++i) {
    cin >> runTimes[i];
  }

  cout << runTimes[0] << endl;
  cout << runTimes[1] << endl;
  cout << runTimes[2] << endl;

  return 0;
}
