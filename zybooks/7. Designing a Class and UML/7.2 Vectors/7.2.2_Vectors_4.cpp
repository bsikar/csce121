#include <iostream>
#include <vector>
using namespace std;

int main() {
  int numDistance;
  int i;

  cin >> numDistance;
  vector<int> idLogs(numDistance);

  for (i = 0; i < idLogs.size(); ++i) {
    cin >> idLogs.at(i);
  }

  for (i = 0; i < idLogs.size(); i += 2) {
    cout << idLogs.at(i) << "-";
  }
  cout << endl;

  for (i = 1; i < idLogs.size(); i += 2) {
    cout << idLogs.at(i) << "-";
  }
  cout << endl;

  return 0;
}
