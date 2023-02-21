#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  if (n > 3000) {
    throw "Error: Overflow!";
  }
  int a = 0, b = 1, c;
  for (int i = 0; i < n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  cout << "f(" << n << ") = " << a << endl;
  return 0;
}
