#include <iostream>
using namespace std;

int *seprate_even_from_odds(int *A, unsigned int n) {
  int *tmp = new int[n];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0) {
      tmp[cnt] = A[i];
      cnt += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 1) {
      tmp[cnt] = A[i];
      cnt += 1;
    }
  }
  return tmp;
}

int main() {
  int *arr = new int[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }

  int *tmp = seprate_even_from_odds(arr, 10);

  for (int i = 0; i < 10; i++) {
    cout << tmp[i] << " ";
  }
  cout << endl;

  delete[] tmp;
  delete[] arr;
  return 0;
}
