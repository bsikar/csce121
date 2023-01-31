#include <iostream>
using namespace std;

int main() {
  int *numItemsPointer;
  int numItems;

  cin >> numItems;

  if (numItems < 0) {
    numItemsPointer = nullptr;
  } else {
    numItemsPointer = &numItems;
    *numItemsPointer *= 10;
  }

  if (numItemsPointer == nullptr) {
    cout << "Items is negative" << endl;
  } else {
    cout << "Items: " << *numItemsPointer << endl;
  }

  return 0;
}
