#include <iomanip>
#include <iostream>
using namespace std;

class MovingBody {
public:
  MovingBody(double forceValue, double displacementValue);
  void IncreaseForceAndDisplacement();
  void Print();

private:
  double force;
  double displacement;
};
MovingBody::MovingBody(double forceValue, double displacementValue) {
  force = forceValue;
  displacement = displacementValue;
}
void MovingBody::IncreaseForceAndDisplacement() {
  force = force * 2.0;
  displacement = displacement * 2.0;
  cout << "MovingBody's force and displacement are increased." << endl;
}
void MovingBody::Print() {
  cout << "MovingBody's force: " << fixed << setprecision(1) << force << endl;
  cout << "MovingBody's displacement: " << fixed << setprecision(1)
       << displacement << endl;
}

int main() {
  double force, displacement;
  cin >> force >> displacement;
  MovingBody *myMovingBody = new MovingBody(force, displacement);
  myMovingBody->IncreaseForceAndDisplacement();

  myMovingBody->Print();

  return 0;
}
