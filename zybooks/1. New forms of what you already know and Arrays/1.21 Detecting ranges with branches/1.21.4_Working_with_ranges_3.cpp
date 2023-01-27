#include <iostream>
using namespace std;

int main() {
  int numTools;

  cin >> numTools;

  if (numTools <= 1) {
    cout << "Invalid number";
  } else if (numTools <= 7) {
    cout << "Personal tool box";
  } else if (numTools < 26) {
    cout << "Full-sized tool box";
  } else {
    cout << "Too many for one box";
  }
  cout << endl;

  return 0;
}
