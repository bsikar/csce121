#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/* Question 1
 * Version number: Exam 1, Version: M1240
 * Section Number: CSCE-121-508
 */

char decimal_to_digit(unsigned int decimal) {
  if (decimal > 9) {
    throw std::invalid_argument("not a decimal");
  }

  return decimal + '0';
}

unsigned int digit_length(int digit) {
  unsigned int count = 0;
  while (digit != 0) {
    count += 1;
    digit /= 10;
  }
  return count;
}

/* Inputs: num: the number to be shifted
 * Inputs: digits_to_shift: the number of digits to shift to the right
 * Returns: the unsigned int with the digits shifted
 */
unsigned int rightShift(unsigned int num, unsigned int digits_to_shift) {
  // if digits_to_shift is greater than the number of digits in num
  // then throw an invalid argugment exception

  // account for errors
  if (digits_to_shift > digit_length(num)) {
    throw std::invalid_argument("invalid digit_length");
  }

  // make a string that will store shifted values
  string shifted = "";

  // fill the shifted values string
  int factor = 10;
  for (unsigned int i = 0; i < digits_to_shift; i++) {
    int dig = num % factor;

    if (i > 0) {
      dig /= factor / 10;
    }

    factor *= 10;

    shifted.push_back(decimal_to_digit(dig));
  }

  // get the remaining number part
  num /= factor / 10;

  // create our result
  unsigned int result = 0;

  // add the shifted part to the start of the result
  int i = 0;
  for (char s : shifted) {

    if (i == 0) {
      result += s - '0';
      i = 10;
    } else {
      result += (s - '0') * i;
      i *= 10;
    }
  }

  // add the remaining part to the result
  for (unsigned int k = 0; k < digit_length(num); k++) {
    int tmp = num % i / (i / 10);

    result = result * (i / 10) + tmp;

    // i *= 10;
  }

  // return the result
  return result;
}

int get_right_most_digit(int x) {
  int last = x;

  while (x != 0) {
    int tmp = last / 10;

    if (tmp == 0) {
      return tmp;
    }

    last = tmp;
  }

  return last;
}

int getSum(int ary[], int size, int start_index) {
  // account for errors
  if (start_index >= size) {
    return -100;
  }

  int running_sum = 0;
  int current = ary[start_index];
  int curr_index = start_index;
  // get the right most digit
  while (true) {
    // int dgt = current / 10;
    int dgt = get_right_most_digit(current);

    // if its odd
    if (dgt % 2 == 0) {
      curr_index = curr_index - dgt;
    }
    // if its even
    else {
      curr_index = curr_index + dgt;
    }

    // account for errors
    if (curr_index >= size) {
      return running_sum - 100;
    }

    // if they are the same return it
    if (curr_index == dgt) {
      return running_sum;
    }

    running_sum += ary[curr_index];
  }

  // this shouldnt get ran because we return before
  return -1;
}

int main() {
  cout << rightShift(54329, 1);

  return 0;
}
