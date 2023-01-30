#include <iostream>
using namespace std;

int ConvertVolume(int kiloliters) { return kiloliters * 1000; }

int ConvertVolume(int kiloliters, int liters) {
  return (kiloliters * 1000) + liters;
}

int main() {
  int kilolitersUsed;
  int litersUsed;
  int totalLiters1;
  int totalLiters2;

  cin >> kilolitersUsed;
  cin >> litersUsed;

  totalLiters1 = ConvertVolume(kilolitersUsed);
  cout << kilolitersUsed << " kiloliters yields " << totalLiters1 << " liters."
       << endl;

  totalLiters2 = ConvertVolume(kilolitersUsed, litersUsed);
  cout << kilolitersUsed << " kiloliters and " << litersUsed
       << " liters yields " << totalLiters2 << " liters." << endl;

  return 0;
}
