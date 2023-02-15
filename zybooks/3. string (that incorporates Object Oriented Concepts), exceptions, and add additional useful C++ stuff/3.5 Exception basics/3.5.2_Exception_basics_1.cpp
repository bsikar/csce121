#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  int numCents;

  cin >> numCents;

  try {
    if (numCents % 5 != 0) {
      throw runtime_error("The amount entered cannot be converted to nickels");
    }
    cout << numCents << " cents converts to " << numCents / 5 << " nickels"
         << endl;
  } catch (runtime_error &excpt) {
    cout << "Error: " << excpt.what() << endl;
  }

  return 0;
}
