#include <iostream>
using namespace std;

int main() {
  int number, quantity = 0;
  cout << "Enter a number: ";
  cin >> number;
  while (number != 0) {
    number /= 10;
    quantity++;
  }
  cout << "The quantity of digits of this number is: " << quantity << endl;
  return 0;
}
