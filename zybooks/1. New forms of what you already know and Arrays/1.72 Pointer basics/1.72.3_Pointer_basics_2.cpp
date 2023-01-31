#include <iostream>
using namespace std;

int main() {
  int velocity1;
  int velocity2;
  int *velocityPointer;

  cin >> velocity1;
  cin >> velocity2;

  if (velocity1 > velocity2) {
    velocityPointer = &velocity1;
  } else if (velocity2 > velocity1) {
    velocityPointer = &velocity2;
  } else {
    velocityPointer = nullptr;
  }

  if (velocityPointer == nullptr) {
    cout << "The velocities are the same." << endl;
  } else {
    cout << *velocityPointer << " is the higher velocity." << endl;
  }

  return 0;
}
