#include "tester.h"
#include <iostream>

using namespace std;

bool is_digit_palidrome(int n) {
  int num = n;
  if (num < 0)
    num *= -1; // this works as long at the number is not INT_MIN
  int revNum = 0;
  while (num > 0) {
    int digit = num % 10;
    revNum *= 10;
    revNum += digit;
    num /= 10;
  }
  cout << "revnum: " << revNum << endl;
  cout << "n: " << n << endl;
  if (n < 0) { // n is negative
    return revNum + n == 0;
  }
  return revNum - n == 0;
}

int main() { run_good_test(121, true, 1, is_digit_palidrome); }
