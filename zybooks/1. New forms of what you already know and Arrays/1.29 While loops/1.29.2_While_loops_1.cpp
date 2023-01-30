#include <iostream>
using namespace std;

int main() {
  int userIn;

  cin >> userIn;

  while (userIn <= 0) {
    cout << "Input is " << userIn << endl;
    cin >> userIn;
  }

  cout << "Exit" << endl;

  return 0;
}
