#include <iostream>
using namespace std;

void PrintVolume(int kiloliters) {
  cout << "Total " << kiloliters << " kiloliters" << endl;
}

void PrintVolume(int kiloliters, int liters) {
  cout << "Total " << kiloliters << " kiloliters and " << liters << " liters"
       << endl;
}

int main() {
  int kilolitersUsed;
  int litersUsed;

  cin >> kilolitersUsed;
  cin >> litersUsed;

  PrintVolume(kilolitersUsed);
  PrintVolume(kilolitersUsed, litersUsed);

  return 0;
}
