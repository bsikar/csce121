#include <iostream>
using namespace std;

int main() {
  int totalFlowers;
  int numFlowers;
  int numBouquets;

  cin >> totalFlowers;
  cin >> numFlowers;

  numBouquets = totalFlowers / numFlowers;

  cout << "Maximum number of bouquets: " << numBouquets << endl;

  return 0;
}
