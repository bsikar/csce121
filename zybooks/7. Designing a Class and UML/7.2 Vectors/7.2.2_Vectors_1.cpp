#include <iostream>
#include <vector>
using namespace std;

int main() {
  double distance1;
  double distance2;
  double distance3;
  double distance4;
  unsigned int i;

  cin >> distance1;
  cin >> distance2;
  cin >> distance3;
  cin >> distance4;

  vector<double> walkingDistance(4);
  walkingDistance.at(0) = distance1;
  walkingDistance.at(1) = distance2;
  walkingDistance.at(2) = distance3;
  walkingDistance.at(3) = distance4;

  for (i = 0; i < walkingDistance.size(); ++i) {
    cout << walkingDistance.at(i) << " ";
  }
  cout << endl;

  return 0;
}
