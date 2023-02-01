#include "functions.h"
#include <iostream>

using std::cout, std::endl;

bool is_valid_range(int a, int b) { return a >= 10 && b < 10000 && a <= b; }

int num_len(int n) {
  int length = 0;
  while (n > 0) {
    n /= 10;
    length++;
  }
  return length;
}

int *int_to_arr(int n) {
  int len = num_len(n);
  int *arr = new int[len];
  for (int i = len - 1; i >= 0; i--) {
    arr[i] = n % 10;
    n /= 10;
  }
  return arr;
}

bool is_increasing(int a, int b) { return b > a; }

char classify_mv_range_type(int number) {
  // make sure to delete the array after use
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
    // increase or decrease the count
    inc_count += (is_inc) ? 1 : -1;
  }

  delete[] arr;
  if (inc_count == dec_count) {
    return type;
  }

  return (inc_count > dec_count) ? 'M' : 'V';
}

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
