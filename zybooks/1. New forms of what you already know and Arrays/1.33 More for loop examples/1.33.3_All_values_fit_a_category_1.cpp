#include <iostream>
using namespace std;

int main() {
  int inCount;
  cin >> inCount;
  bool allEven = true;
  int num;

  for (int i = 0; i < inCount; i++) {
    cin >> num;
    if (num % 2 != 0) {
      allEven = false;
    }
  }

  if (allEven) {
    cout << "All match" << endl;
  } else {
    cout << "Not all match" << endl;
  }

  return 0;
}
