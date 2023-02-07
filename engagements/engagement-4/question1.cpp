#include <iostream>
using namespace std;

int main() {
  const unsigned int n = 10;
  int array[n];

  for (int i = 0; i < n; i++) {
    array[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    cout << array[i] << endl;
  }
  return 0;
}
