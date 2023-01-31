#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double reading;
  int hour;
  char alert;

  double *readingPointer = &reading;
  int *hourPointer = &hour;
  char *alertPointer = &alert;

  cin >> reading;
  cin >> hour;
  cin >> alert;

  cout << "Tide level: " << fixed << setprecision(1) << *readingPointer
       << " meters" << endl;
  cout << "Recorded at hour: " << *hourPointer << endl;
  cout << "Alert: " << *alertPointer << endl;

  return 0;
}
