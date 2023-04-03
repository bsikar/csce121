#include <iostream>
#include <vector>
using namespace std;

int main() {
  int numTime;
  unsigned int i;

  cin >> numTime;
  vector<int> idLogs(numTime);

  for (i = 0; i < idLogs.size(); ++i) {
    cin >> idLogs.at(i);
  }

  for (i = 0; i < idLogs.size(); ++i) {
    if (idLogs.at(i) != 8) {
      cout << idLogs.at(i) << endl;
    }
  }

  return 0;
}
