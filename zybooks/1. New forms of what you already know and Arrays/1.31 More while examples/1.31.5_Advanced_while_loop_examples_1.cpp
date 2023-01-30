#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double currentHeight;
  int numSuccesses;

  numSuccesses = 0;
  cin >> currentHeight;

  while (numSuccesses != 4) {
    if (currentHeight > 0) {
      cout << fixed << setprecision(1) << currentHeight << endl;
      numSuccesses += 1;
    }
    cin >> currentHeight;
  }

  return 0;
}
