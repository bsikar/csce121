#include <iostream>
using namespace std;

struct PatientData {
  int heightInches;
  int weightPounds;
};

int main() {
  PatientData lunaLovegood;

  cin >> lunaLovegood.heightInches;
  cin >> lunaLovegood.weightPounds;

  cout << "Patient data: " << lunaLovegood.heightInches << " in, "
       << lunaLovegood.weightPounds << " lbs" << endl;

  return 0;
}
