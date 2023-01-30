#include <iostream>
using namespace std;

int main() {
  int loopVal;
  int i;
  int j;

  cin >> loopVal;

  for (i = 0; i <= loopVal; i++) {
    cout << i;
    for (j = 0; j < i; j++) {
      cout << "-";
    }
    cout << endl;
  }

  return 0;
}
