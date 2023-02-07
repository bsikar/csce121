#include <iostream>
#include <string>
using namespace std;

int main() {
  string userString;

  cin >> userString;

  if (userString == "Quit") {
    cout << "Goodbye";
  } else {
    cout << "Hello";
  }
  cout << endl;

  return 0;
}
