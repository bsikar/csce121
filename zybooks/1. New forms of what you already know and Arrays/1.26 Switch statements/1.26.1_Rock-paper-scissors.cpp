#include <iostream>
using namespace std;

int main() {
  int nextChoice;

  cin >> nextChoice;

  switch (nextChoice) {
  case 0:
    cout << "Rock";
    break;
  case 1:
    cout << "Paper";
    break;
  case 2:
    cout << "Scissors";
    break;
  default:
    cout << "Unknown";
  }
  cout << endl;

  return 0;
}
