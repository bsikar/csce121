#include <iostream>
using namespace std;

int main() {
  const int n = 5;
  int array[n];

  for (int i = 0; i <= n; i++) {
    array[i] = i * i;
    cout << array[i] << endl;
  }

  cout << array[n - 1] << endl;
  return 0;
}
