#include "functions.h"
#include <iostream>
using namespace std;

void function_one(int i, int &j) {
  i += 2;
  j += 1;
}

void function_two(example &i) { i.value += 1; }

void function_three(int *k, int &l) {
  (*k) += 1;
  l += 1;
}

void function_four(int *arr, int size, int &low, int &high) {
  for (int i = 0; i < size; i++) {
    arr[i] += 2;
  }

  low = high = arr[0];

  for (int i = 0; i < size; i++) {
    if (arr[i] < low) {
      low = arr[i];
    }
    if (arr[i] > high) {
      high = arr[i];
    }
  }
}
