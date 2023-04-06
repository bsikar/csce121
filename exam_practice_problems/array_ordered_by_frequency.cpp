#include <iostream>
using namespace std;

bool is_in(int *a, int b, int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] == b) {
      return true;
    }
  }
  return false;
}

int count(int *a, int b, int size) {
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (a[i] == b) {
      cnt += 1;
    }
  }
  return cnt;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int *get_array_ordered_by_frequency(int *a, unsigned int size_a,
                                    unsigned int &new_array_size) {
  int *counts = new int[new_array_size];
  int *sorted = new int[new_array_size];

  int size = 0;

  // check if 0 is in a (edge case!)
  if (is_in(a, 0, size_a)) {
    sorted[0] = 0;
    counts[0] = count(a, 0, size_a);
    size += 1;
  }

  for (int i = 0; i < size_a; i++) {
    if (!is_in(sorted, a[i], new_array_size)) {
      sorted[size] = a[i];
      counts[size] = count(a, a[i], size_a);
      size += 1;
    }
  }

  new_array_size = size;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      // its < to be most to least
      // > would be least to most
      if (counts[j] < counts[j + 1]) {
        swap(sorted[j], sorted[j + 1]);
        swap(counts[j], counts[j + 1]);
      }
    }
  }

  return sorted;
}

int main() {
  int *arr = new int[8];
  int x[8] = {-1, 3, -1, 1, 1, 4, 3, 3};
  for (int i = 0; i < 8; i++) {
    arr[i] = x[i];
  }

  unsigned int size = 4;
  int *tmp = get_array_ordered_by_frequency(arr, 8, size);

  for (int i = 0; i < size; i++) {
    cout << tmp[i] << " ";
  }
  cout << endl;

  delete[] arr;
  delete[] tmp;
  return 0;
}
