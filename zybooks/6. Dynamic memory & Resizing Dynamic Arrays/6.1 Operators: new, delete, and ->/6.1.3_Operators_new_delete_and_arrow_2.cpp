#include <iomanip>
#include <iostream>
using namespace std;

class Duck {
public:
  Duck();
  void Print();

  double age;
  double weight;
};
Duck::Duck() {
  age = 0.0;
  weight = 0.0;
}
void Duck::Print() {
  cout << "Duck's age: " << fixed << setprecision(1) << age << endl;
  cout << "Duck's weight: " << fixed << setprecision(1) << weight << endl;
}

int main() {
  double ageValue;
  double weightValue;

  /* Additional variable declarations go here */
  Duck *myDuck;

  cin >> ageValue;
  cin >> weightValue;

  myDuck = new Duck();
  myDuck->age = ageValue;
  myDuck->weight = weightValue;

  myDuck->Print();

  return 0;
}
