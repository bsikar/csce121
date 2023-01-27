#include <iostream>
using namespace std;

int main() {
  int lightWavelength;

  cin >> lightWavelength;

  if (lightWavelength < 387) {
    cout << "Too narrow";
  } else if (lightWavelength < 750) {
    cout << "Can be seen";
  } else {
    cout << "Too wide";
  }
  cout << endl;

  return 0;
}
