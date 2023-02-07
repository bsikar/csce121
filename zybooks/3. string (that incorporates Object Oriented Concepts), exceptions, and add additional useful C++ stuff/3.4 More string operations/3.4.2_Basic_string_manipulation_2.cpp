#include <iostream>
#include <string>
using namespace std;

int main() {
  string workString;
  int beginPos;
  int deleteLen;

  getline(cin, workString);
  cin >> beginPos;
  cin >> deleteLen;

  workString.replace(beginPos, deleteLen, "(removed)");

  cout << workString << endl;

  return 0;
}
