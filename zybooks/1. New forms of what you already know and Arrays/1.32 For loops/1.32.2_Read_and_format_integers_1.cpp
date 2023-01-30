#include <iostream>
using namespace std;

int main() {
  int valCount;
  int value;
  int i;

  cin >> valCount;

  for (i = 1; i <= valCount; ++i) {
    cin >> value;
    cout << value << " cups" << endl;
  }

  return 0;
}
