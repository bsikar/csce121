#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int seedVal;
  int maxNum;
  int num1;
  int num2;
  int num3;

  cin >> seedVal;
  cin >> maxNum;

  srand(seedVal);

  num1 = rand() % maxNum;
  num2 = rand() % maxNum;
  num3 = rand() % maxNum;

  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;
  cout << "Average: " << fixed << setprecision(1)
       << ((num1 + num2 + num3) / 3.0) << endl;

  return 0;
}
