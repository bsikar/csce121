#include <iostream>
using namespace std;

int main() {
  int userNum;
  int i;

  cin >> userNum;

  cout << "Ready!" << endl;
  for (i = userNum; i > 0; i--) {
    cout << i << endl;
  }
  cout << "Run!" << endl;

  return 0;
}
