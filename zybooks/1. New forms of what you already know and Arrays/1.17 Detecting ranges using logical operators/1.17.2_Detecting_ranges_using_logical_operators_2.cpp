#include <iostream>
using namespace std;

int main() {
  int numPeople;

  cin >> numPeople;

  if (numPeople >= 550 && numPeople <= 4050) {
    cout << "Mid-size town";
  } else {
    cout << "Not a mid-size town";
  }
  cout << endl;

  return 0;
}
