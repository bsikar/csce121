#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> valElements(6);
  int valElementsSize = valElements.size();
  int removeSize;
  int i;

  valElements.at(0) = 13;
  valElements.at(1) = 9;
  valElements.at(2) = 10;
  valElements.at(3) = 12;
  valElements.at(4) = 11;
  valElements.at(5) = 8;

  cin >> removeSize;

  cout << "The beginning ";
  for (i = 0; i < valElements.size(); ++i) {
    cout << valElements.at(i) << " ";
  }
  cout << "The end" << endl;

  /* Your code goes here */
  valElements.resize(valElements.size() - removeSize);

  cout << "The beginning ";
  for (i = 0; i < valElements.size(); ++i) {
    cout << valElements.at(i) << " ";
  }
  cout << "The end" << endl;

  return 0;
}
