#include <iostream>
using namespace std;

int main() {
  int outerRange;
  int innerRange;
  int count;
  int i;
  int j;

  cin >> outerRange;
  cin >> innerRange;

  count = 0;
  for (i = 0; i <= outerRange; ++i) {
    for (j = 0; j <= innerRange; ++j) {
      ++count;
    }
  }

  cout << "Inner loop ran " << count << " times" << endl;

  return 0;
}
