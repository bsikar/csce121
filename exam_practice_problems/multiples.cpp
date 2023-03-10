#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void multiples(int, int, int);

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  multiples(a, b, c);

  return 0;
}

void multiples(int n, int k, int l) {
  /*
   * Given positive integers n, k and l, print the first n positive integer
   * numbers that are multiple of k, l or both. Example: n = 6, k = 2 and l = 3,
   * you should print: 2 3 4 6 8 9
   */

  int i = 1;
  int count = 0;

  while (count < n) {
    if (i % k == 0 || i % l == 0) {
      cout << i << " ";
      count++;
    }
    i++;
  }

  cout << endl;
}
