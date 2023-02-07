#include <iostream>
#include <string>
using namespace std;

int main() {
  string userStr;
  int idx1;
  int idx2;

  getline(cin, userStr);
  cin >> idx1;
  cin >> idx2;

  userStr[idx1] = userStr[idx2];

  cout << userStr << endl;

  return 0;
}
