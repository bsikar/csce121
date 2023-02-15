#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  int negVal;

  cin >> negVal;

  try {
    if (negVal >= 0) {
      throw runtime_error("Value out of range");
    }
    cout << "Negative number received: " << negVal << endl;
  } catch (runtime_error &e) {
    cout << "Negative number not found: " << e.what() << endl;
  }

  return 0;
}
