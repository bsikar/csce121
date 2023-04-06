#include <iostream>
using namespace std;

int beta(int r, int s) {
  cout << "r | stack : " << r << endl;
  cout << "s | stack : " << s << endl;
  r /= 5;
  s *= 3;
  cout << "r | stack : " << r << endl;
  cout << "s | stack : " << s << endl;
  return r + s;
}

int alpha(int p, int &q) {
  cout << "p | stack : " << p << endl;
  cout << "q | stack : " << q << endl;

  q = p + q;
  cout << "q | stack : " << q << endl;
  return 2 * q + 1;
}

int gamma(int *arr, int &n, int &m) {
  cout << "arr | stack : " << arr << endl;
  cout << "arr | heap : " << *arr << endl;
  cout << "n | stack : " << n << endl;
  cout << "m | stack : " << m << endl;

  arr[0] = alpha(n, m);
  cout << "arr[0] | stack : " << &arr[0] << endl;
  cout << "arr[0] | heap : " << arr[0] << endl;
  arr[1] = beta(n, m);
  cout << "arr[1] | stack : " << &arr[1] << endl;
  cout << "arr[1] | heap : " << arr[1] << endl;
  return arr[0] + arr[1];
}

int main() {
  int a = 9;
  cout << "a | stack : " << a << endl;

  int b = 6;
  cout << "b | stack : " << b << endl;
  int *c = new int(7);
  cout << "c | stack : " << c << endl;
  cout << "c | heap : " << *c << endl;
  int *arr1 = new int[2];
  cout << "arr1 | stack : " << arr1 << endl;
  cout << "arr1 | heap : " << *arr1 << endl;
  arr1[0] = 0;
  cout << "arr1[0] | stack : " << &arr1[0] << endl;
  cout << "arr1[0] | heap : " << arr1[0] << endl;
  arr1[1] = 0;
  cout << "arr1[1] | stack : " << &arr1[1] << endl;
  cout << "arr1[1] | heap : " << arr1[1] << endl;

  *c = gamma(arr1, a, b);
  cout << "c | stack : " << c << endl;
  cout << "c | heap : " << *c << endl;

  // cout << a << " " << b << " " << *c << endl;
  // cout << arr1[0] << " " << arr1[1] << endl;
  arr1 = nullptr;
  cout << "arr1 | stack : " << arr1 << endl;
  delete c;
  return 0;
}
