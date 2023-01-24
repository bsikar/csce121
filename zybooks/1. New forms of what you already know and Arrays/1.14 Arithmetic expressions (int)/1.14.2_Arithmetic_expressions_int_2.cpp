#include <iostream>
using namespace std;

int main() {
  int urchinPounds = 3;
  int eaglePounds = 6;
  int vulturePounds = 2;
  int numUrchins;
  int numEagles;
  int numVultures;
  int combinedWeight;

  cin >> numUrchins;
  cin >> numEagles;
  cin >> numVultures;

  combinedWeight = urchinPounds * numUrchins + eaglePounds * numEagles +
                   vulturePounds * numVultures;

  cout << "Weight: " << combinedWeight << endl;

  return 0;
}
