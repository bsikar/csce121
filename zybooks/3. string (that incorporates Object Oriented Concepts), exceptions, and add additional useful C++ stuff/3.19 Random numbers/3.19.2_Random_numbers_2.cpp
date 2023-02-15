#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int seedVal;
  int smallestInput;
  int largestInput;

  cin >> seedVal;
  cin >> smallestInput;
  cin >> largestInput;

  srand(seedVal);

  for (int i = 0; i < 3; i++) {
    int randNum = (rand() % (largestInput - smallestInput + 1)) + smallestInput;
    cout << randNum << endl;
  }

  return 0;
}
