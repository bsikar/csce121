#include <iostream>
using namespace std;

struct InventoryTag {
  int itemID;
  int quantityRemaining;
};

int main() {
  InventoryTag redSweater;

  cin >> redSweater.itemID;
  cin >> redSweater.quantityRemaining;

  cout << "Inventory ID: " << redSweater.itemID
       << ", Qty: " << redSweater.quantityRemaining << endl;

  return 0;
}
