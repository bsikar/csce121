#include <iomanip>
#include <iostream>
using namespace std;

class Cylinder {
public:
  Cylinder();
  void Read();
  void Print();
  ~Cylinder();

private:
  double radius;
  double height;
};
Cylinder::Cylinder() {
  radius = 0.0;
  height = 0.0;
}
void Cylinder::Read() {
  cin >> radius;
  cin >> height;
}
void Cylinder::Print() {
  cout << "Cylinder's radius: " << fixed << setprecision(1) << radius << endl;
  cout << "Cylinder's height: " << fixed << setprecision(1) << height << endl;
}
Cylinder::~Cylinder() { // Covered in section on Destructors.
  cout << "Cylinder with radius " << radius << " and height " << height
       << " is deallocated." << endl;
}

int main() {
  Cylinder *myCylinders = nullptr;
  int count;
  int i;

  cin >> count;
  myCylinders = new Cylinder[count];

  for (i = 0; i < count; i++) {
    myCylinders[i].Read();
    myCylinders[i].Print();
  }

  delete[] myCylinders;

  return 0;
}
