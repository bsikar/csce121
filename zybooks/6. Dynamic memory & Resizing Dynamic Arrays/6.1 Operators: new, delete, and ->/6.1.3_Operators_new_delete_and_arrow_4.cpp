#include <iomanip>
#include <iostream>
using namespace std;

class Owl {
public:
  Owl();
  void Read();
  void Print();
  ~Owl();

private:
  double age;
  double weight;
};
Owl::Owl() {
  age = 0.0;
  weight = 0.0;
}
void Owl::Read() {
  cin >> age;
  cin >> weight;
}
void Owl::Print() {
  cout << "Owl's age: " << fixed << setprecision(1) << age << endl;
  cout << "Owl's weight: " << fixed << setprecision(1) << weight << endl;
}
Owl::~Owl() { // Covered in section on Destructors.
  cout << "Owl with age " << age << " and weight " << weight
       << " is deallocated." << endl;
}

int main() {
  Owl *myOwl = nullptr;

  myOwl = new Owl();
  myOwl->Read();
  myOwl->Print();
  delete myOwl;

  return 0;
}
