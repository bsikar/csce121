#include <iostream>
using namespace std;

int main() {
  int countLimit;
  int printVal;

  // Get user input
  cin >> countLimit;

  printVal = 0;
  do {
    cout << printVal << " ";
    printVal = printVal + 1;
  } while (printVal <= countLimit);
  cout << endl;

  return 0;
}
