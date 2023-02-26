#include <iostream>
using namespace std;

class Cone {
public:
  Cone(int radiusValue, int heightValue);
  void Print();

private:
  int radius;
  int height;
};
Cone::Cone(int radiusValue, int heightValue) {
  radius = radiusValue;
  height = heightValue;
}
void Cone::Print() {
  cout << "Cone's radius: " << radius << endl;
  cout << "Cone's height: " << height << endl;
}

int main() {
  Cone *myCone = nullptr;
  int radiusValue;
  int heightValue;

  cin >> radiusValue;
  cin >> heightValue;

  myCone = new Cone(radiusValue, heightValue);

  myCone->Print();

  return 0;
}
