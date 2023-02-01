#include "functions.h"
#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  // we are only expecting two numbers within the range [10, 10000)
  // but invalid input will be handled by the loop
  for (;;) {
    int a, b;
    cout << "Enter numbers 10 <= a <= b < 10000: ";
    cin >> a >> b;

    if (is_valid_range(a, b)) {
      count_valid_mv_numbers(a, b);
      break;
    } else {
      cout << "Invalid Input" << endl;
    }
  }
  return 0;
}
