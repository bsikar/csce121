#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int num;

  cin >> str;

  while (cin >> num) {
    if (num <= 50 || num >= 75) {
      cout << str << ": needs attention!" << endl;
      break;
    }
    cin >> str;
  }

  return 0;
}
