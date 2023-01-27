#include <iostream>
using namespace std;

int main() {
  int pencilCount;

  cin >> pencilCount;

  if (pencilCount <= 9) {
    cout << "Not many pencils";
  } else {
    cout << "Enough pencils";
  }
  cout << endl;

  return 0;
}
