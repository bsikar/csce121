#include <iostream>
using namespace std;

int FindUserPremium(int coverage, int age) {
  int premium = -1;

  if (coverage <= 20000) {
    if (age <= 54) {
      premium = 30;
    } else if (age >= 55 && age <= 74) {
      premium = 35;
    } else if (age > 74) {
      premium = 40;
    }
  } else if (coverage >= 20001 && coverage <= 94999) {
    if (age <= 54) {
      premium = 45;
    } else if (age >= 55 && age <= 74) {
      premium = 55;
    } else if (age > 74) {
      premium = 65;
    }
  } else if (coverage >= 95000) {
    if (age <= 54) {
      premium = 80;
    } else if (age >= 55 && age <= 74) {
      premium = 90;
    } else if (age > 74) {
      premium = 95;
    }
  }

  return premium;
}

int main() {
  int coverage;
  int userAge;

  cin >> coverage;
  cin >> userAge;

  cout << FindUserPremium(coverage, userAge) << endl;

  return 0;
}
