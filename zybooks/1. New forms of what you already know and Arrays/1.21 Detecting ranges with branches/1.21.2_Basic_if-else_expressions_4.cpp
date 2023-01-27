#include <iostream>
using namespace std;

int main() {
  int userAge;

  cin >> userAge;

  if (userAge > 19) {
    cout << "I am an adult";
  } else {
    cout << "I am a teenager";
  }
  cout << endl;

  return 0;
}
