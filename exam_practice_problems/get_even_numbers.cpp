#include <iostream>
using namespace std;

int *get_even_numbers(int *A, unsigned int n, unsigned int &m) {
  int *tmp = new int[n];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] % 2 == 0) {
      tmp[cnt] = A[i];
      cnt += 1;
    }
  }
  m = cnt;
  int *tmp2 = new int[m];
  for (int i = 0; i < m; i++) {
    tmp2[i] = tmp[i];
  }
  delete[] tmp;
  return tmp2;
}

int main() {
  int *arr = new int[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }

  unsigned int m;
  int *out = get_even_numbers(arr, 10, m);

  for (int i = 0; i < m; i++) {
    cout << out[i] << " ";
  }
  cout << endl;

  delete[] arr;
  delete[] out;
  return 0;
}
