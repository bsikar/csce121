#include <iostream>
using namespace std;

int main() {
  int numIn;

  cin >> numIn;

  for (int i = 0; i < numIn; i++) {
    int num;
    cin >> num;
    cout << "<" << num << ">";
  }
  cout << endl;

  return 0;
}
