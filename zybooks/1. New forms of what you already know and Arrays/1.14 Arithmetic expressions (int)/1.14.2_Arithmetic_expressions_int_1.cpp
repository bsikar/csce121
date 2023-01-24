#include <iostream>
using namespace std;

int main() {
  int height;
  int length;
  int width;
  int boxVolume;

  cin >> height;
  cin >> length;
  cin >> width;

  boxVolume = height * length * width;

  cout << "Volume: " << boxVolume << endl;

  return 0;
}
