#include <iostream>
using namespace std;

int main() {
  int valCount;

  cin >> valCount;

  for (int i = 0; i < valCount; ++i) {
    int val;
    cin >> val;
    cout << val;
    if (i != valCount - 1) {
      cout << "|";
    }
  }
  cout << endl;

  return 0;
}
