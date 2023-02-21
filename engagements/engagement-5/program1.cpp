#include <iostream>
using namespace std;

int main() {
  int num1, num2, num3;
  cout << "Enter 3 positive integers: ";
  cin >> num1 >> num2 >> num3;
  try {
    if (num1 < 0 || num2 < 0 || num3 < 0) {
      throw "Error: Enter a positive number.";
    } else {
      if (num1 > num2 && num1 > num3) {
        cout << "The largest integer is " << num1 << endl;
      } else if (num2 > num1 && num2 > num3) {
        cout << "The largest integer is " << num2 << endl;
      } else {
        cout << "The largest integer is " << num3 << endl;
      }
      if (num1 < num2 && num1 < num3) {
        cout << "The smallest integer is " << num1 << endl;
      } else if (num2 < num1 && num2 < num3) {
        cout << "The smallest integer is " << num2 << endl;
      } else {
        cout << "The smallest integer is " << num3 << endl;
      }
    }
  } catch (const char *msg) {
    cout << msg << endl;
  }
  return 0;
}
