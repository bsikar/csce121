#include <iostream>
#include <vector>
using namespace std;

void SwapVectorEnds(vector<int> &v) {
  int temp = v[0];
  v[0] = v[v.size() - 1];
  v[v.size() - 1] = temp;
}

int main() {
  vector<int> sortVector(4);
  unsigned int i;
  int userNum;

  for (i = 0; i < sortVector.size(); ++i) {
    cin >> userNum;
    sortVector.at(i) = userNum;
  }

  SwapVectorEnds(sortVector);

  for (i = 0; i < sortVector.size(); ++i) {
    cout << sortVector.at(i) << " ";
  }
  cout << endl;

  return 0;
}
