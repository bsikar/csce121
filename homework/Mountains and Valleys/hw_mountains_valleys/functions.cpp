#include "functions.h"
#include <iostream>

using std::cout, std::endl;

/**
 * @brief Determines if a range defined by two integers is valid.
 *
 * @param a The lower bound of the range.
 * @param b The upper bound of the range.
 *
 * @return True if the range is valid, false otherwise. A range is considered
 * valid if `a >= 10`, `b < 10000`, and `a <= b`.
 */
bool is_valid_range(int a, int b) { return a >= 10 && b < 10000 && a <= b; }

/**
 * @brief Calculates the number of digits in an integer.
 *
 * @param n The integer to find the number of digits for.
 *
 * @return The number of digits in the integer.
 */
int num_len(int n) {
  int length = 0;
  while (n > 0) {
    n /= 10;
    length++;
  }
  return length;
}

/**
 * @brief Converts an integer into an array of its digits.
 *
 * @param n The integer to convert.
 *
 * @return A dynamically allocated array of integers, representing the digits of
 * the input integer. The caller is responsible for freeing the memory of the
 * returned array.
 */
int *int_to_arr(int n) {
  int len = num_len(n);
  int *arr = new int[len];
  for (int i = len - 1; i >= 0; i--) {
    arr[i] = n % 10;
    n /= 10;
  }
  return arr;
}

/**
 * @brief Determines if a pair of integers is increasing.
 *
 * @param a The first integer.
 * @param b The second integer.
 *
 * @return True if `b > a`, false otherwise.
 */
bool is_increasing(int a, int b) { return b > a; }

/**
 * @brief Classifies if a number represents a Mountain, Vallery, or Neither.
 *
 * 'M' means Mountain, 'V' means Valley, and 'N' means Neither.
 *
 * @param number The number to classify.
 *
 * @return 'M', 'V', or 'N' depending on the type of the number.
 */
char classify_mv_range_type(int number) {
  int *arr = int_to_arr(number);
  int len = num_len(number);
  bool is_inc = is_increasing(arr[0], arr[1]);
  char type = (is_inc) ? 'M' : 'V';
  int inc_count = (is_inc) ? 1 : 0;
  int dec_count = (is_inc) ? 0 : 1;

  if (arr[0] == arr[1]) {
    delete[] arr;
    return 'N';
  }

  for (int i = 1; i < len - 1; i++) {
    int a = arr[i];
    int b = arr[i + 1];
    bool curr = is_increasing(a, b);
    if (a == b || curr == is_inc) {
      delete[] arr;
      return 'N';
    }
    is_inc = curr;
    inc_count += (is_inc) ? 1 : -1;
  }

  delete[] arr;
  if (inc_count == dec_count) {
    return type;
  }

  return (inc_count > dec_count) ? 'M' : 'V';
}

/**
 * @brief Function to count the number of valid mountain and valley ranges
 * between a and b and return prints the count of mountain and valley ranges
 *
 * @param a Starting range
 * @param b Ending range
 */
void count_valid_mv_numbers(int a, int b) {
  int mountain_count = 0;
  int valley_count = 0;

  // find the number of mountain and vally's
  for (int i = a; i <= b; i++) {
    char type = classify_mv_range_type(i);
    if (type == 'M') {
      mountain_count++;
    } else if (type == 'V') {
      valley_count++;
    }
  }
  cout << "There are " << mountain_count << " mountain ranges and "
       << valley_count << " valley ranges between " << a << " and " << b << "."
       << endl;
}
