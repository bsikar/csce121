#include <iostream>
#include <vector>
using namespace std;

int main() {
  int numTime;
  double firstTime;
  double lastTime;
  unsigned int i;

  cin >> numTime;
  cin >> firstTime;
  cin >> lastTime;

  vector<double> bikingLogs(numTime);
  bikingLogs.at(0) = firstTime;
  bikingLogs.at(numTime - 1) = lastTime;

  for (i = 0; i < bikingLogs.size(); ++i) {
    cout << bikingLogs.at(i) << " ";
  }
  cout << endl;

  return 0;
}
